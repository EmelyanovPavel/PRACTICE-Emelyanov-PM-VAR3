#ifndef CLASSQUEUE_H
#define CLASSQUEUE_H

#include "classDoublyLinkedList.h"
#include "classIContainer.h"

// Queue class based on a doubly-linked list
class Queue: public IContainer 
{
    //implementation
private:
    DoublyLinkedList<void*> list;

public:
    Queue() {}
    ~Queue() override {}

    // Adding an element to the list end
    void addElement(const void* data) override {
        list.add(&data);
    }

    //  Deleting the first element
    void removeElement() override {
        list.remove();
    }

    // Checking for emptiness
    bool isEmpty() const override {
        return list.isEmpty();
    }

    //Getting the first element
    void* front() const {
        if (!isEmpty()) {
            return *(void**)list.getFirstData();
        }
        throw std::runtime_error("The list is empty");
    }

    //The queue size
    size_t size() const {
        return list.getSize();
    }

};
#endif //CLASSQUEUE_H
