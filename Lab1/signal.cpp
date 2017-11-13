/*! \Author: Robert Scully
    \Created: 3-10-17
    \license: GNU GENERAL PUBLIC LICENSE
    \Update: 13-11-17

  To show the semaphores can be used to stop a thread from been first in.

*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

/**< create the first thread with share pointer to the semphore */
void firstThread(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "be ";
  std::cout << "Mad."<<std::endl;
  theSemaphore->Signal(); /**< call semphore to go */
}
/**< create the second thread with share pointer to the semphore */
void secondThread(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait(); /**< make semphore stop or wait */
  std::cout <<"Or ";
  std::cout << "Am ";
  std::cout << "I ";
  std::cout << "Good."<<std::endl;
}
/**< Main function */
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(secondThread,sem);
  threadTwo=std::thread(firstThread,sem);
  std::cout << "Launched from the main\n";
  /**< Join each thread */
  threadOne.join();
  threadTwo.join();
  return 0;
}
