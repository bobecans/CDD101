/*! \Author: Robert Scully
    \Created: 3-10-17
    \license: GNU GENERAL PUBLIC LICENSE
    \Update: 13-11-17

  Using a semaphore to make a rendezvous of outputs.

*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

/**< create the first thread with share pointer to the semphore */
void threadA1(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "must "<<std::endl;
  theSemaphore->Signal(); /**< call semphore to go */
}
/**< create the second thread with share pointer to the semphore */
void threadA2(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait(); /**< make semphore stop or wait */
  std::cout << "I "<<std::endl;
  theSemaphore->Signal(); /**< call semphore to go */
}
/**< create the thrid thread with share pointer to the semphore */
void threadB1(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait(); /**< make semphore stop or wait */
  std::cout << "mad."<<std::endl;
  theSemaphore->Signal(); /**< call semphore to go */
}
/**< create the fourth thread with share pointer to the semphore */
void threadB2(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();/**< make semphore stop or wait */
  std::cout << "be "<<std::endl;
  theSemaphore->Signal(); /**< call semphore to go */
}

/**< using main to output threads in a rendezvous  */
int main(void){
  std::thread threadOne, threadTwo, threadThree, threadFour;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(threadB1,sem);
  threadTwo=std::thread(threadA2,sem);
  threadThree=std::thread(threadA1,sem);
  threadFour=std::thread(threadB2,sem);
  std::cout << "Launched from the main\n";
  /**< Join all threads */
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  threadFour.join();
  return 0;
}
