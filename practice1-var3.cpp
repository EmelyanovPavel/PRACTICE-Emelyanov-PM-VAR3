////Practice
#include <iostream>
#include <queue> 
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>	

//1. Create a template for the "doubly linked list" class.The class must run on
//dynamic memory, manage it correctly(including when copying objects),
//and prevent memory leaks.
//Classes must be implemented independently(
//    it is forbidden to use STL library tools to implement a class).
//
//    2. Implement the container interface(as an abstract class containing only
//        purely virtual functions).The container interface must contain methods for:
//a.adding an element
//b.removing an element
//c.checking the container for emptiness
//The interface is used to implement the class described below, which
//inherits from the interface and overrides all the specified methods.
//
//3. Using the developed list class, it is required to implement one of
//the classes : stack, queue, priority queue.You choose the class yourself
//based on the assignment.
//
//4. Complete the task according to the option.

// Интерфейс контейнера Container interface
class IContainer 
{
public:
    virtual void add(const void* data) = 0;
    virtual void remove() = 0;
    virtual bool isEmpty() const = 0;
    virtual ~IContainer() {} // Виртуальный деструктор Virtual destructor
};

// Узел двусвязного списка A node of a doubly linked list
template<typename T>
struct Node 
{
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    ~Node() {}
};

// Двусвязный список The doubly-linked list
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

    // Добавление элемента в конец списка Adding an element to the list end
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

    // Удаление первого элемента Deleting the first element
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

    // Проверка на пустоту Checking for emptiness
    bool isEmpty() const override 
    {
        return size == 0;
    }

    // Очистка списка Clearing the list
    void clear() 
    {
        while (!isEmpty()) 
        {
            remove();
        }
    }

    // Размер списка List size
    size_t getSize() const 
    {
        return size;
    }

    // Копирование списка Copying the list
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

    // Методы для доступа к данным Methods for accessing data
    Node<T>* getHead() const 
    {
        return head;
    }
    Node<T>* getTail() const 
    {
        return tail;
    }
};

// Класс Очередь на основе двусвязного списка Queue class based on a doubly linked list
template<typename T>

class Queue 
{
private:
    DoublyLinkedList<T> list;

public:
    Queue() {}

    ~Queue() {}

    // Добавление элемента в очередь Adding an element to the queue
    void enqueue(const T& data) 
    {
        list.add(&data);
    }

    // Извлечение элемента из очереди Removing an element from the queue
    T dequeue() 
    {

        if (list.isEmpty()) 
        {
            throw std::runtime_error("The queue is empty");
        }

        T data = list.getHead()->data;
        list.remove();
        return data;
    }

    // Проверка на пустоту Checking for emptiness
    bool isEmpty() const 
    {
        return list.isEmpty();
    }

    // Размер очереди List size
    size_t size() const 
    {
        return list.getSize();
    }
};

// Пример использования Usage example
void task1() 
{
    Queue<int> queue;

    //проверка очереди на пустоту Checking for emptiness
    if (queue.isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
    }

    //добавление элементов Adding an elements
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    //выводим элементы displaying the elements
    try 
    {
        while (!queue.isEmpty()) 
        {
            std::cout << queue.dequeue() << " "; // Removing an elements from the queue
        }
    }

    catch (const std::runtime_error& e) 
    {
        std::cerr << "runtime error" << std::endl;
    }
    std::cout << std::endl;

    //Checking for emptiness
    if (queue.isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
    }
    std::cout << std::endl;
}

//Tasks.
//Option 3.
//A text file is given.In one file view, print the file elements in
//the following order : first, all characters other than digits, and then all digits,
//maintaining the original order in each character group.

void task2()
{
    std::ifstream file("chars.txt"); // открываем файл для чтения

    if (!file.is_open()) {
        std::cerr << "Opening error" << std::endl;
    }

    // Создаем две очереди: для цифр и для остальных символов
    std::queue<char> digits;
    std::queue<char> others;

    //проверка очередей на пустоту
    if (digits.empty())
    {
        std::cout << "The 'digits' queue is empty" << std::endl;
    }

    if (others.empty())
    {
        std::cout << "The 'others' queue is empty" << std::endl;
    }

    // Читаем файл символ за символом
    char ch;
    while (file.get(ch)) 
    {
        if (isdigit(ch)) { // если символ цифра
            digits.push(ch);
        }
        else { // если символ не цифра
            others.push(ch);
        }
    }

    // Выводим символы, отличные от цифр
    while (!others.empty()) 
    {
        std::cout << others.front();
        others.pop();
    }

    // Выводим цифры
    while (!digits.empty()) 
    {
        std::cout << digits.front();
        digits.pop();
    }

    file.close(); // закрываем файл
}

int main()
{
    task1();
    task2();

    return 0;
}