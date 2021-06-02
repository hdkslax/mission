#include "core/circular_queue.h"
#include "core/utils.h"
#include <pthread.h>
#include <stdlib.h>


// pthread_mutex_t producer_mtx;
// pthread_mutex_t consumer_mtx;
pthread_mutex_t mtx;
pthread_cond_t producer_cv;
pthread_cond_t consumer_cv;

long total_item_count = 0;
int active_producer_count = 1;
int active_consumer_count = 1;

// int global_pid = 0;
// int total_producer; // The total number of producers
// int active_producer_count = 0;



class ProducerConsumerProblem {
  long n_items;
  int n_producers;
  int n_consumers;
  CircularQueue production_buffer;

  // Dynamic array of thread identifiers for producer and consumer threads.
  // Use these identifiers while creating the threads and joining the threads.
  pthread_t *producer_threads;
  pthread_t *consumer_threads;

  int active_producer_count;
  int active_consumer_count;

public:


  // The following 6 methods should be defined in the implementation file (solution.cpp)
  ProducerConsumerProblem(long _n_items, int _n_producers, int _n_consumers,
                          long _queue_size);
  ~ProducerConsumerProblem();
  void startProducers();
  void startConsumers();
  void joinProducers();
  void joinConsumers();
  void printStats();

  long getNItems(){return n_items;}
  long getNProducers(){return n_producers;}
  long getNConsumers(){return n_consumers;}
  CircularQueue* getProductionBuffer(){return &production_buffer;}


};


struct Para{
  int id = 0;
  ProducerConsumerProblem * problem;
  int item_counter = 0; // the # of items produced / consumed
  int item_value = 0; // the total value of the items produced / consumed
  double time_taken = 0.0;
  int *producer_id;
};

Para **producers;
Para **consumers;

