////Practice
#include <iostream>
#include <queue> 
#include <fstream>
#include <string>
#include "classIContainer.h"
#include "classDoublyLinkedList.h"
#include "classQueue.h"

void MyQueue()
{
    Queue<int> queue;

    // Checking for emptiness
    if (queue.isEmpty())
    {
        std::cout << "The queue is empty" << std::endl;
    }

    // Adding an elements
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // displaying the elements
    try
    {
        while (!queue.isEmpty())
        {
            std::cout << queue.dequeue() << " "; // Removing an elements from the queue
        }
    }

    catch (const std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
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
void printCharsFromFile()
{
    std::ifstream file("chars.txt"); // opening the file for reading

    if (!file.is_open())
    {
        std::cerr << "Opening error" << std::endl;
    }

    // creating two queues: for numbers and for other characters.
    std::queue<char> digits, others;

    //checking queues for emptiness
    if (digits.empty())
    {
        std::cout << "The 'digits' queue is empty" << std::endl;
    }
    if (others.empty())
    {
        std::cout << "The 'others' queue is empty" << std::endl;
    }

    // Reading the file character by character
    char ch;
    while (file.get(ch))
    {
        if (isdigit(ch)) { // if the character is a number
            digits.push(ch);
        }
        else { // if the character is not a number
            others.push(ch);
        }
    }

    // Outputting characters other than numbers
    while (!others.empty())
    {
        std::cout << others.front();
        others.pop();
    }
    // Outputting the numbers
    while (!digits.empty())
    {
        std::cout << digits.front();
        digits.pop();
    }

    file.close(); // closing the file
}

int main()
{
    MyQueue();
    printCharsFromFile();

    return 0;
}