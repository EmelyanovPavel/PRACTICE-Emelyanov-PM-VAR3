#ifndef CLASSDOUBLYLINKEDLIST_H_
#define CLASSDOUBLYLINKEDLIST_H_

#include <iostream>
#include <stdexcept>

//The doubly-linked list
template<typename T>
class DoublyLinkedList
{
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
            : data(data), prev(prev), next(next) {
        }
    };

    Node* head;
    Node* tail;
    size_t size;

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {
        std::cout << "Default Constructor!" << std::endl;
    }

    ~DoublyLinkedList() {
        std::cout << "Destructor!" << std::endl;
        clear(); 
    }

    void push_back(const T& data) {
        Node* newNode = new Node(data, tail, nullptr);
        if (tail != nullptr) {
            tail->next = newNode;
        }
        if (head == nullptr) {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    void push_front(const T& data) {
        Node* newNode = new Node(data, nullptr, head);
        if (head != nullptr) {
            head->prev = newNode;
        }
        if (tail == nullptr) {
            tail = newNode;
        }
        head = newNode;
        size++;
    }

    void pop_back() {
        if (tail != nullptr) {
            Node* temp = tail;
            if (tail->prev != nullptr) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else {
                head = nullptr;
                tail = nullptr;
            }
            delete temp;
            size--;
        }
    }

    void pop_front() {
        if (head != nullptr) {
            Node* temp = head;
            if (head->next != nullptr) {
                head = head->next;
                head->prev = nullptr;
            }
            else {
                head = nullptr;
                tail = nullptr;
            }
            delete temp;
            size--;
        }
    }

    bool empty() const { 
        return size == 0; 
    }

    size_t getSize() const { 
        return size; 
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // Copying constructor
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        std::cout << "Copying Constructor!" << std::endl;
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    // The assignment operator
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        std::cout << "The assignment operator!" << std::endl;
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current != nullptr) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    //The equality comparison operator
    bool operator==(const DoublyLinkedList& other) const {
        if (size != other.size) {
            return false;
        }
        Node* current1 = head;
        Node* current2 = other.head;
        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return true;
    }

    //The inequality operator
    bool operator!=(const DoublyLinkedList& other) const {
        return !(*this == other);
    }
    //Methods for accessing data
    T getFront() const {
        if (!empty()) {
            return head->data;
        }
        throw std::runtime_error("The list is size");
    }

    T getBack() const {
        if (!empty()) {
            return tail->data;
        }
        throw std::runtime_error("The list is size");
    }
};
#endif //CLASSDOUBLYLINKEDLIST_H_
