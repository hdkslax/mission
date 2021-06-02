#pragma once
#include "solution.h"

void *producerFunction(void *para) {
  timer t;
  t.start();
  // Parse the _arg passed to the function.
  // Enqueue `n` items into the `production_buffer`. The items produced should be 0, 1, 2,..., (n-1).  
  long max_length = ((Para*)para)->problem->getNItems()/((Para*)para)->problem->getNProducers();
  
  if(((Para*)para)->id < ((Para*)para)->problem->getNItems()%((Para*)para)->problem->getNProducers()){
    max_length++;
  }
  // std::cout << "测试数据1 = " << ((Para*)para)->item_counter << std::endl;
  //  std::cout << "producer_max_length = " << max_length << std::endl;
  while(((Para*)para)->item_counter < max_length) {
    
    long item_value = ((Para*)para)->item_counter * ((Para*)para)->problem->getNProducers() + ((Para*)para)->id;
    // std::cout << "测试数据 = " << item_value << std::endl;
    pthread_mutex_lock(&mtx);
    // std::cout << "---这里是分割线1---" << std::endl;
    bool ret = ((Para*)para)->problem->getProductionBuffer()->enqueue(item_value, ((Para*)para)->id);
    // std::cout << "到底有没有enqueue成功？" << ret << std::endl;
    
    // std::cout << "---这里是分割线2---" << std::endl;
    if(ret == true) {
      // std::cout << "enqueue成功" << std::endl;
      // std::cout << "item_counter = " << ((Para*)para)->item_counter << std::endl;
      // std::cout << "item_value = " << ((Para*)para)->item_value << std::endl;
      // std::cout << "item_count = " << ((Para*)para)->problem->getProductionBuffer()->itemCount() << std::endl;
      
      if (((Para*)para)->problem->getProductionBuffer()->itemCount() >= 1){
        // The queue is no longer empty
        // Signal all consumers indicating queue is not empty
        // pthread_mutex_lock(&mtx);
        // std::cout << "---consumers起来干活啦！---" << std::endl;
        pthread_cond_signal(&consumer_cv);
        // std::cout << "---consumers起来干活啦！v2---" << std::endl;
        // pthread_mutex_unlock(&mtx);
      }
      // Keep track of the number of items produced and the value produced by the thread.
      // items_produced++;
      // value_produced += item_value;
      total_item_count++;
      ((Para*)para)->item_counter++;
      ((Para*)para)->item_value += item_value;
      // std::cout << "---这里是分割线4---" << std::endl;
      
    } else {
      // production_buffer is full, so block on conditional variable waiting for consumer to signal.
      // pthread_mutex_lock(&mtx);
      // std::cout << "已经满咯，等着consumer叫我" << std::endl;
      pthread_cond_wait(&producer_cv,&mtx);
      // pthread_mutex_unlock(&mtx);
    }
    pthread_mutex_unlock(&mtx);
  }
  // The producer that was last active should ensure that all the consumers have finished. 
  // NOTE: Each thread will enqueue `n` items.
  --active_producer_count;
  // Use mutex variables and conditional variables as necessary.
  while(active_producer_count <= 1){
    pthread_mutex_lock(&mtx);
    // std::cout << "提示：已进入最后一个thread" << std::endl;
    pthread_cond_signal(&consumer_cv);
    pthread_mutex_unlock(&mtx);
    // std::cout << "提示：consumer重新开始工作啦" << std::endl;
    if(((Para*)para)->problem->getProductionBuffer()->isEmpty()){
      // std::cout << "提示：即将结束" << std::endl;
      active_producer_count--;
      // std::cout << "提示：#active_producer_count" << active_producer_count << std::endl;
      break;
    }
  }

  if(((Para*)para)->item_counter == max_length){
    // std::cout << "提示：此线任务已完成，结束" << std::endl;
    
  }
  double time_taken = t.stop();
  ((Para*)para)->time_taken += time_taken;
}

void *consumerFunction(void *para) {
  timer t;
  t.start();
  // Parse the _arg passed to the function.
  long item_value;
  long items_consumed = 0;
  long value_consumed = 0;  
  int producer_id;
  // long max_length = ((Para*)para)->problem->getNItems()/((Para*)para)->problem->getNConsumers();
  
  // if(((Para*)para)->id < ((Para*)para)->problem->getNItems()%((Para*)para)->problem->getNConsumers()){
  //   max_length++;
  // }

  // std::cout << "consumer_max_length = " << max_length << std::endl;
  while(true) {
    pthread_mutex_lock(&mtx);
    // std::cout << "小标记：" << (((Para*)para)->problem->getProductionBuffer().isEmpty()) << std::endl;
    bool ret = ((Para*)para)->problem->getProductionBuffer()->dequeue(&item_value, &producer_id);
    pthread_mutex_unlock(&mtx);
    if(ret == true) {
      std::cout << "item_value = " << item_value << "," << "pid = " << producer_id << std::endl;
      for(int i=0; i<((Para*)para)->problem->getNProducers(); i++){
        if(i == producer_id){
          ((Para*)para)->producer_id[i]++;
        }
      }
      // ((Para*)para)->producer_id = producer_id;
      if(((Para*)para)->problem->getProductionBuffer()->itemCount() == ((Para*)para)->problem->getProductionBuffer()->getCapacity() - 1){
        // The queue is no longer full
        // Signal all producers indicating queue is not full
        pthread_mutex_lock(&mtx);
        // std::cout << "---producers干活啦---" << std::endl;
        pthread_cond_signal(&producer_cv);
        pthread_mutex_unlock(&mtx);
      }
      // value_consumed+=item_value;
      // items_consumed++;
      ((Para*)para)->item_counter++;
      ((Para*)para)->item_value += item_value;
    } 
    else {
            // production_buffer is empty, so block on conditional variable waiting for producer to signal.
            // std::cout << "提示: queue空啦！" << std::endl;
            // std::cout << ((Para*)para)->problem->getProductionBuffer()->isEmpty() << std::endl;
            // std::cout << (active_producer_count<=0) << std::endl;
            // std::cout << (items_consumed == max_length) << std::endl;

            if(((Para*)para)->problem->getProductionBuffer()->isEmpty() 
                  && active_producer_count<=0 ){
                  // && items_consumed == max_length){
              // std::cout << "提示：consumer即将结束" << std::endl;
              break;
            }
            pthread_mutex_lock(&mtx);
            pthread_cond_wait(&consumer_cv,&mtx);
            pthread_mutex_unlock(&mtx);
            // The thread can wake up because of 2 scenarios:
            // Scenario 1: There are no more active producers (i.e., production is complete) and the queue is empty. This is the exit condition for consumers, and at this point consumers should decrement `active_consumer_count`. 
            // Scenario 2: The queue is not empty and/or the producers are active. Continue consuming.
            
    }
    // pthread_mutex_unlock(&mtx);
    double time_taken = t.stop();
    ((Para*)para)->time_taken += time_taken;
    // std::cout << "提示：consumer " << ((Para*)para)->id << " 结束" << std::endl;
  }
  // The consumer thread will consume items by dequeueing the items from the
  // `production_buffer`.
  // Keep track of the number of items consumed and the value consumed by the
  // thread.
  // Once the productions is complete and the queue is also empty, the thread
  // will exit. NOTE: The number of items consumed by each thread need not be
  // same.
  // Use mutex variables and conditional variables as necessary.
}

ProducerConsumerProblem::ProducerConsumerProblem(long _n_items,
                                                 int _n_producers,
                                                 int _n_consumers,
                                                 long _queue_size)
    : n_items(_n_items), n_producers(_n_producers), n_consumers(_n_consumers),
      production_buffer(_queue_size) {
  std::cout << "Constructor\n";
  std::cout << "Number of items: " << n_items << "\n";
  std::cout << "Number of producers: " << n_producers << "\n";
  std::cout << "Number of consumers: " << n_consumers << "\n";
  std::cout << "Queue size: " << _queue_size << "\n";

  producer_threads = new pthread_t[n_producers];
  consumer_threads = new pthread_t[n_consumers];

  producers = new Para*[n_producers];
  consumers = new Para*[n_consumers];
  
  // Initialize all mutex and conditional variables here.
  pthread_mutex_init(&mtx, NULL);

  pthread_cond_init(&producer_cv, NULL);
  pthread_cond_init(&consumer_cv, NULL);
  
}

ProducerConsumerProblem::~ProducerConsumerProblem() {
  std::cout << "Destructor\n";
  if(producers != NULL){
    for(int i=0; i<n_producers; i++){
      if (producers[i] != NULL){
        // delete producers[i];
        free(producers[i]);
        // producers[i] = NULL;
      }
    }
    delete[] producers;
    producers = NULL;
  }
  if(consumers != NULL){
  //   std::cout << "---这里是分割线---" << std::endl;
  for(int i=0; i<n_consumers; i++){
      if (consumers[i] != NULL){
        delete[] consumers[i]->producer_id;
        free(consumers[i]);
      }
    }
    delete[] consumers;
    consumers = NULL;
  }
 
  
  // Destroy all mutex and conditional variables here.
  pthread_mutex_destroy(&mtx);
  pthread_cond_destroy(&producer_cv);
  pthread_cond_destroy(&consumer_cv);
}

void ProducerConsumerProblem::startProducers() {
  std::cout << "Starting Producers\n";
  active_producer_count = n_producers;
  // Para *para;
  for(int i=0; i<n_producers; i++){
    producers[i] = (Para*)malloc(sizeof(struct Para));
    (*producers[i]).id = i;
    (*producers[i]).problem = this;
    (*producers[i]).item_counter = 0;
    (*producers[i]).item_value = 0;
    (*producers[i]).time_taken = 0;
    pthread_create(&producer_threads[i], NULL, producerFunction, (producers[i]));
  }
}

void ProducerConsumerProblem::startConsumers() {
  std::cout << "Starting Consumers\n";
  active_consumer_count = n_consumers;
  // Create consumer threads C1, C2, C3,.. using pthread_create.
  // Para *para;
  for(int i=0; i<n_consumers; i++){

    consumers[i] = (Para*)malloc(sizeof(struct Para));
    (*consumers[i]).id = i;
    (*consumers[i]).problem = this;
    (*consumers[i]).item_counter = 0;
    (*consumers[i]).item_value = 0;
    (*consumers[i]).time_taken = 0;
    (*consumers[i]).producer_id = new int[n_producers]{0};

    std::cout << consumers[i] << std::endl;
    pthread_create(&consumer_threads[i],NULL, consumerFunction, (consumers[i]));
  }
}

void ProducerConsumerProblem::joinProducers() {
  std::cout << "Joining Producers\n";
  // Join the producer threads with the main thread using pthread_join
  for(int i=0; i<n_producers; i++){
    // pthread_mutex_lock(&producer_mtx);
    std::cout << "joining producer " << i << std::endl;
    pthread_join(producer_threads[i], NULL);
    // pthread_mutex_unlock(&producer_mtx);
  }
}

void ProducerConsumerProblem::joinConsumers() {
  std::cout << "Joining Consumers\n";
  // Join the consumer threads with the main thread using pthread_join
  for(int i=0; i<n_consumers; i++){
    // pthread_mutex_lock(&consumer_mtx);
    std::cout << "joining consumer " << i << std::endl;
    pthread_join(consumer_threads[i], NULL);
    // pthread_mutex_unlock(&consumer_mtx);
  }
}

void ProducerConsumerProblem::printStats() {
  std::cout << "Producer stats\n";
  std::cout << "producer_id, items_produced, value_produced, time_taken \n";
  // Make sure you print the producer stats in the following manner
  // 0, 1000, 499500, 0.00123596
  // 1, 1000, 499500, 0.00154686
  // 2, 1000, 499500, 0.00122881 
  long total_produced = 0;
  long total_value_produced = 0;
  // std::cout << "The produced value is " << producers[0]->getProducedValue() << std::endl;
  for (int i = 0; i < n_producers; i++) {
    
    // // ---
    std::cout << producers[i]->id << ", " 
              << producers[i]->item_counter << ", " 
              << producers[i]->item_value << ", " 
              << producers[i]->time_taken <<  std::endl;
    total_produced += producers[i]->item_counter;
    total_value_produced += producers[i]->item_value;
    
    // ---
  }
  std::cout << "Total produced = " << total_produced << "\n";
  std::cout << "Total value produced = " << total_value_produced << "\n";
  std::cout << "Consumer stats\n";
  std::cout << "consumer_id, items_consumed, value_consumed, time_taken, ";
  // value_from_producer_0, value_from_producer_1
  for(int i=0; i<n_producers;i++){
    std::cout << "value_from_producer_" << i << ", " << std::endl;
  }
  // Make sure you print the consumer stats in the following manner
  // 0, 677, 302674, 0.00147414, 120000, 130000, 140000
  // 1, 648, 323301, 0.00142694, 130000, 140000, 120000
  // 2, 866, 493382, 0.00139689, 140000, 120000, 130000
  // 3, 809, 379143, 0.00134516, 109500, 109500, 109500
  long total_consumed = 0;
  long total_value_consumed = 0;
  for (int i = 0; i < n_consumers; i++) {
    // ---
    std::cout << consumers[i]->id << ", " 
              << consumers[i]->item_counter << ", " 
              << consumers[i]->item_value << ", " 
              << consumers[i]->time_taken << ", ";
              // << consumers[i]->producer_id
    for(int j=0; j<n_producers;j++){
        std::cout << consumers[i]->producer_id[j] << ", ";
    }
    std::cout << std::endl;
    total_consumed += consumers[i]->item_counter;
    total_value_consumed += consumers[i]->item_value;
              
    // ---
  }
  std::cout << "Total consumed = " << total_consumed << "\n";
  std::cout << "Total value consumed = " << total_value_consumed << "\n";
}
