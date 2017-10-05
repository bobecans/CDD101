#include "Semaphore.h"
#include <iostream>
#include <thread>

void threadA1(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "must "<<std::endl;
  theSemaphore->Signal();
}
void threadA2(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "I "<<std::endl;
  theSemaphore->Signal();
}
  
void threadB1(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "mad."<<std::endl;
  theSemaphore->Signal();
}

void threadB2(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "be "<<std::endl;
  theSemaphore->Signal();
}

int main(void){
  std::thread threadOne, threadTwo, threadThree, threadFour;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(threadB1,sem);
  threadTwo=std::thread(threadA2,sem);
  threadThree=std::thread(threadA1,sem);
  threadFour=std::thread(threadB2,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  threadFour.join();
  return 0;
}
