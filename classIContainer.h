#ifndef CLASS_IContainer
#define CLASS_IContainer

// Container interface
class IContainer
{
public:
    virtual void add(const void* data) = 0;
    virtual void remove() = 0;
    virtual bool isEmpty() const = 0;
    virtual ~IContainer() {} // Virtual destructor
};

// A node of a doubly linked list
template<typename T>
struct Node
{
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    ~Node() {}
};
#endif
