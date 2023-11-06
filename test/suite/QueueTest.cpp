//
// Created by 13918 on 2023/9/18.
//

#include <thread>
#include "gtest/gtest.h"
#include "Queue.h"

//TEST(QueueTest, queue_test)
//{
//    Queue<int> q;
//    auto f1 = [&] {
//        for (int i = 0; i < 500; ++i) {
//            int j = i;
//            std::this_thread::sleep_for(std::chrono::microseconds(50));
//            q.push(&j);
//        }
//    };
//
//    auto f2 = [&] {
//    for (int i = 0; i < 500; ++i) {
//        q.pop();
//    }
//};
//
//std::thread t1(f1);
//std::thread t2(f2);
//t1.join();
//t2.join();
//}
//
//struct A {
//
//};
//
//TEST(QueueTest, shared_ptra)
//{
//    Queue<A> q;
//    A a;
//    q.push(&a);
//    q.push(&a);
//    q.push(&a);
//    q.push(&a);
//    q.push(&a);
//    q.clear();
//}