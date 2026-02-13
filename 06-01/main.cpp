#include <condition_variable>
#include <cstdio>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int main() {
  mutex mtx;
  condition_variable cv;
  int turn = 1;

  thread t1([&]() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [&]() { return turn == 1; });
    printf("thread1\n");
    turn = 2;
    cv.notify_all();
  });

  thread t2([&]() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [&]() { return turn == 2; });
    printf("thread2\n");
    turn = 3;
    cv.notify_all();
  });

  thread t3([&]() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [&]() { return turn == 3; });
    printf("thread3\n");
    turn = 4;
    cv.notify_all();
  });

  t1.join();
  t2.join();
  t3.join();

  return 0;
}
