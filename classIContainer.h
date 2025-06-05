#ifndef CLASSICONTAINER_H_
#define CLASSICONTAINER_H_

//// Container interface 
class IContainer {
public:
    virtual void add(const void* data) = 0;
    virtual void remove() = 0;
    virtual bool isEmpty() const = 0;
    virtual ~IContainer() {} // Virtual destructor
};
#endif //CLASSICONTAINER_H_
