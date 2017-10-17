/*! /Author: Robert Scully
    /Created: 3-10-17

  To show the semaphores can be used to stop a thread from been first in.

*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

void firstThread(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "be ";
  std::cout << "Mad."<<std::endl;
  theSemaphore->Signal();
}
void secondThread(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"Or ";
  std::cout << "Am ";
  std::cout << "I ";
  std::cout << "Good."<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(secondThread,sem);
  threadTwo=std::thread(firstThread,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
