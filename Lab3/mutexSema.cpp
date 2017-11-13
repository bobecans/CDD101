/*! \Author: Robert Scully
    \Created: 3-10-17
    \license: GNU GENERAL PUBLIC LICENSE
    \Update: 13-11-17

  Using a mutex semaphore to control the value of count. 
  Or in order words making the count safe from invaled updates.

*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

/**< Global Variable  */
int count = 1;

/**< setting threads with a mutex wait call.  */
void firstThread(std::shared_ptr<Semaphore> mutex){
  mutex->Wait(); /**< make semphore stop or wait */
  count = count + 1;
  mutex->Signal(); /**< call semphore to go */
  std::cout << count <<std::endl;
}

/**< setting threads with a mutex wait call.  */
void secondThread(std::shared_ptr<Semaphore> mutex){
  mutex->Wait(); /**< make semphore stop or wait */
  count = count + 1;
  mutex->Signal(); /**< call semphore to go */
  std::cout << count <<std::endl;
}

/**< The main is calling the threads in a random order.  */
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> s/**< Join all threads */em( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(secondThread,sem);
  threadTwo=std::thread(firstThread,sem);
  std::cout << "Launched from the main\n";
  /**< Join all threads */
  threadOne.join();
  threadTwo.join();
  /**< Outputting final count */
  std::cout << count <<std::endl;
  return 0;
}
