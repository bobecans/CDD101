#include "Semaphore.h"
#include <iostream>
#include <thread>

int N = 3;
int count = 0;
Semaphore mutex(1);
Semaphore barrier1(0);
Semaphore barrier2(1);

int main(void)
{
  mutex.wait();
  count++;
  if(count == N){
	barrier2.wait();
	barrier1.singal();
  }
  mutex.singal();
  barrier1.wait();
  barrier1.singal();

  mutex.wait();
  count--;
  if(count == 0){
	barrier1.wait();
	barrier2.singal();
  }
  mutex.singal();
  barrier2.wait();
  barrier2.singal();
}
