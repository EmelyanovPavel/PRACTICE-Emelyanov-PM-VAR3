#include "classIContainer.h"
#include "classDoublyLinkedList.h"

#ifndef CLASS_Queue
#define CLASS_Queue

// Queue class based on a container interface
template<typename T>

class Queue : public IContainer
{
private:
    DoublyLinkedList<void*> list;

public:
    Queue() {}

    // Adding an element to the list end
    void add(const void* data) override {
        list.add(&data);
    }

    //  Deleting the first element
    void remove() override {
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

#endif