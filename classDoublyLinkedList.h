#include "classIContainer.h"

#ifndef CLASS_DoublyLinkedList
#define CLASS_DoublyLinkedList


//The doubly-linked list
template<typename T>
class DoublyLinkedList : public IContainer
{
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList()
    {
        clear();
    }

    // Adding an element to the list end
    void add(const void* data) override
    {
        Node<T>* newNode = new Node<T>(*(T*)data);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    //  Deleting the first element
    void remove() override
    {
        if (!isEmpty())
        {
            Node<T>* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            delete temp;
            size--;

            if (size == 0)
            {
                tail = nullptr;
            }
        }
    }

    // Checking for emptiness
    bool isEmpty() const override
    {
        return size == 0;
    }

    // Clearing the list
    void clear()
    {
        while (!isEmpty())
        {
            remove();
        }
    }

    // List size
    size_t getSize() const
    {
        return size;
    }

    // Copying the list
    DoublyLinkedList(const DoublyLinkedList& other)
    {
        *this = other;
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& other)
    {
        if (this != &other)
        {
            clear();
            Node<T>* current = other.head;
            while (current)
            {
                add(&current->data);
                current = current->next;
            }
        }
        return *this;
    }

    //Methods for accessing data
    T getFirstData() const
    {
        if (!isEmpty()) {
            return head->data;
        }
        throw std::runtime_error("The list is empty");
    }

    T getLastData() const
    {
        if (!isEmpty()) {
            return tail->data;
        }
        throw std::runtime_error("The list is empty");
    }
};

#endif