#include "core/utils.h"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include <atomic>
#include <vector>

#define sqr(x) ((x) * (x))
#define DEFAULT_NUMBER_OF_POINTS "1000000000"
#define DEFAULT_MAJOR_RADIUS "2"
#define DEFAULT_MINOR_RADIUS "1"
#define DEFAULT_RANDOM_SEED "1"
#define DEFAULT_NUMBER_OF_THREADS "1"

std::atomic<size_t> ellipse_count(0);

struct ThreadInfo{
  unsigned long points_generated = 0;
  unsigned long local_ellipse_count = 0;
  double time_taken = 0.0;
};
struct Arg{
  unsigned long n;
  uint random_seed;
  float maj_radius;
  float min_radius;
  ThreadInfo *ti;
};

uint c_const = (uint)RAND_MAX + (uint)1;
inline double get_random_coordinate(uint *random_seed) {
  return ((double)rand_r(random_seed)) / c_const;
}

// unsigned long get_points_in_ellipse(unsigned long n, uint random_seed, float maj_radius, float min_radius) {
void get_points_in_ellipse(void *arg) {
  // unsigned long ellipse_count = 0;
  timer thread_timer;
  thread_timer.start();
  double x_coord, y_coord;
  for (unsigned long i = 0; i < ((Arg*)arg)->n; i++) {
    x_coord = ((Arg*)arg)->maj_radius * ((2.0 * get_random_coordinate(&(((Arg*)arg)->random_seed))) - 1.0);
    y_coord = ((Arg*)arg)->min_radius * ((2.0 * get_random_coordinate(&(((Arg*)arg)->random_seed))) - 1.0);
    ((Arg*)arg)->ti->points_generated++;
    if ((sqr(x_coord)/sqr(((Arg*)arg)->maj_radius) + sqr(y_coord)/sqr(((Arg*)arg)->min_radius)) <= 1.0){
      ellipse_count++;
      ((Arg*)arg)->ti->local_ellipse_count++;
    }
      
  }
  // return ellipse_count;
  ((Arg*)arg)->ti->time_taken = thread_timer.stop();
}

void ellipse_area_calculation_serial(unsigned long n, float maj_radius, float min_radius, uint r_seed, uint n_threads) {
  timer serial_timer;
  double time_taken = 0.0;
  uint random_seed = r_seed;

  serial_timer.start();

  // create threads
  std::vector<std::thread> threads;
  ThreadInfo **threads_info = new ThreadInfo*[n_threads];
  for (int i = 0; i < n_threads; i++){
    Arg *arg = new Arg();
    arg->n = n/n_threads;
    if(i<n%n_threads){
      arg->n++;
    }
    arg->random_seed = r_seed;
    arg->maj_radius = maj_radius;
    arg->min_radius = min_radius;
    arg->ti = new ThreadInfo();
    threads.push_back(std::thread(get_points_in_ellipse, arg)); 
    threads_info[i] = new ThreadInfo();
    threads_info[i] = arg->ti;
  }

  std:: cout << "The # of threads using: " << threads.size() << std::endl;
		
  
  for (auto&thad : threads){
    thad.join();
    
  }
		
 
  // unsigned long ellipse_points = get_points_in_ellipse(n, r_seed, maj_radius, min_radius);

  
  
  // double area_value = (double)maj_radius * (double)min_radius * 4.0 * (double)ellipse_points / (double)n;
  double area_value = (double)maj_radius * (double)min_radius * 4.0 * (double)ellipse_count / (double)n;

  //*------------------------------------------------------------------------
  time_taken = serial_timer.stop();

  std::cout << "thread_id, points_generated, ellipse_points, time_taken\n";
  for (int i=0; i<n_threads; i++){
    std::cout << i << ", " << threads_info[i]->points_generated << ", "
              << threads_info[i]->local_ellipse_count << ", " << std::setprecision(TIME_PRECISION)
              << threads_info[i]->time_taken << "\n";
  }
  

  std::cout << "Total points generated : " << n << "\n";
  std::cout << "Total points in ellipse : " << ellipse_count << "\n";
  std::cout << "Result : " << std::setprecision(VAL_PRECISION) << area_value
            << "\n";
  std::cout << "Time taken (in seconds) : " << std::setprecision(TIME_PRECISION)
            << time_taken << "\n";
}

int main(int argc, char *argv[]) {
  // Initialize command line arguments
  cxxopts::Options options("Ellipse_area_calculation",
                           "Calculate area of an ellipse using serial and parallel execution");
  options.add_options(
      "custom",
      {
          {"nPoints", "Number of points",         
           cxxopts::value<unsigned long>()->default_value(DEFAULT_NUMBER_OF_POINTS)},
	  {"majorRad", "Major radius",
	   cxxopts::value<float>()->default_value(DEFAULT_MAJOR_RADIUS)},
          {"minorRad", "Minor radius",
           cxxopts::value<float>()->default_value(DEFAULT_MINOR_RADIUS)},
          {"rSeed", "Random Seed",
           cxxopts::value<uint>()->default_value(DEFAULT_RANDOM_SEED)},
           {"nThreads", "Number of threads",
           cxxopts::value<uint>()->default_value(DEFAULT_NUMBER_OF_THREADS)}
      });
  auto cl_options = options.parse(argc, argv);
  unsigned long n_points = cl_options["nPoints"].as<unsigned long>();
  float maj_radius = cl_options["majorRad"].as<float>();
  float min_radius = cl_options["minorRad"].as<float>();
  uint r_seed = cl_options["rSeed"].as<uint>();
  uint n_threads = cl_options["nThreads"].as<uint>();
  std::cout << "Number of threads: " << n_threads << std::endl;
  std::cout << "Number of points : " << n_points << std::endl;
  std::cout << "Major Radius : " << maj_radius << std::endl << "Minor Radius : " << min_radius << std::endl;
  std::cout << "Random Seed : " << r_seed << std::endl;

  ellipse_area_calculation_serial(n_points, maj_radius, min_radius, r_seed, n_threads);
  return 0;
}
