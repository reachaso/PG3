#include <iostream>
#include <thread>

using namespace std;

int main() {

  thread t1([]() { printf("thread1\n"); });
  thread t2([]() { printf("thread2\n"); });
  thread t3([]() { printf("thread3\n"); });

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
