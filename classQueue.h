#include "classIContainer.h"

#ifndef CLASS_Queue
#define CLASS_Queue

// Queue class based on a doubly linked list
template<typename T>

class Queue
{
private:
    DoublyLinkedList<T> list;

public:

    // Adding an element to the queue
    void enqueue(const T& data)
    {
        list.add(&data);
    }

    // Removing an element from the queue
    T dequeue()
    {

        if (list.isEmpty())
        {
            throw std::runtime_error("The queue is empty");
        }

        T data = list.getFirstData();
        list.remove();
        return data;
    }

    // Checking for emptiness
    bool isEmpty() const
    {
        return list.isEmpty();
    }

    // List size
    size_t size() const
    {
        return list.getSize();
    }
};
#endif