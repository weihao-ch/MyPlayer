//
// Created by 13918 on 2023/9/4.
//

#ifndef MYPLAYER_QUEUE_H
#define MYPLAYER_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

template<typename T, size_t size = 20>
class Queue {
public:
    explicit Queue(std::function<void(T *)> unrefFunc = [](T *) {});

    ~Queue();

    void push(T data);

    T pop();

    void clear();

private:
    std::function<void(T *)> unref;
    std::queue<T> queue;
    std::mutex mutex;
    std::condition_variable empty;
    std::condition_variable full;
};

template<typename T, size_t size>
Queue<T, size>::Queue(std::function<void(T *)> unrefFunc)
{
    unref = std::move(unrefFunc);
}

template<typename T, size_t size>
Queue<T, size>::~Queue()
{
    clear();
}

template<typename T, size_t size>
void Queue<T, size>::push(T data)
{
    std::unique_lock<std::mutex> lk(mutex);
    full.wait(lk, [&] { return queue.size() < size; });
    queue.push(data);
    empty.notify_all();
}

template<typename T, size_t size>
T Queue<T, size>::pop()
{
    std::unique_lock<std::mutex> lk(mutex);
    empty.wait(lk, [&] { return !queue.empty(); });
    T data = queue.front();
    queue.pop();
    full.notify_all();
    return data;
}

template<typename T, size_t size>
void Queue<T, size>::clear()
{
    std::unique_lock<std::mutex> lk(mutex);
    while (!queue.empty()) {
        T data = queue.front();
        queue.pop();
        unref(&data);
    }
}

#endif //MYPLAYER_QUEUE_H
