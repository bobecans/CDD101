#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 1;

void firstThread(std::shared_ptr<Semaphore> mutex){
  mutex->Wait();
  count = count + 1;
  mutex->Signal();
}
void secondThread(std::shared_ptr<Semaphore> mutex){
  mutex->Wait();
  count = count + 1;
  mutex->Signal();
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
  std::cout << count <<std::endl;
  return 0;
}
