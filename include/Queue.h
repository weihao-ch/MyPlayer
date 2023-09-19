//
// Created by 13918 on 2023/9/4.
//

#ifndef MYPLAYER_QUEUE_H
#define MYPLAYER_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T, size_t size = 50>
class Queue {
public:
    void push(const T *data);

    T pop();

    void clear();

private:
    std::queue<T> queue;
    std::mutex mutex;
    std::condition_variable empty;
    std::condition_variable full;
};

template<typename T, size_t size>
void Queue<T, size>::push(const T *data)
{
    std::unique_lock<std::mutex> lk(mutex);
    full.wait(lk, [&] { return queue.size() < size; });
    queue.push(*data);
    empty.notify_all();
}

template<typename T, size_t size>
T Queue<T, size>::pop()
{
    std::unique_lock<std::mutex> lk(mutex);
    empty.wait(lk, [&] { return !queue.empty(); });
    T&& data = std::move(queue.front());
    queue.pop();
    full.notify_all();
    return data;
}

template<typename T, size_t size>
void Queue<T, size>::clear()
{
    std::unique_lock<std::mutex> lk(mutex);
    std::queue<T> emptyQueue;
    std::swap(queue, emptyQueue);
}

#endif //MYPLAYER_QUEUE_H
