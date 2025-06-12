#ifndef CLASSQUEUE_H_
#define CLASSQUEUE_H_

#include "classDoublyLinkedList.h"
#include "classIContainer.h"

// Queue class based on a doubly-linked list
template<typename T>
class Queue: public IContainer<T> 
{
    //implementation
private:
    DoublyLinkedList<T> list;

public:

    // Adding an element to the list end
    void add(const T& data) override {
        list.push_back(data);
    }

    //  Deleting the first element
    void remove() override {
        if (!list.empty()) {
            list.pop_front();
        }
    }

    // Checking for emptiness
    bool isEmpty() const override {
        return list.empty();
    }

    //Getting the first element
    T front() const {
        if (!list.empty()) {
            return list.getFront();
        }
        throw std::out_of_range("Queue is empty");
    }

    T back() const {
        if (!list.empty()) {
            return list.getBack();
        }
        throw std::out_of_range("Queue is empty");
    }

    //The queue size
    size_t size() const {
        return list.getSize();
    }
};
#endif //CLASSQUEUE_H_
