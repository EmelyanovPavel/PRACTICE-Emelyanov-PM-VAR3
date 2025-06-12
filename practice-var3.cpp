////Practice
#include "classQueue.h"

void output()
{
    Queue<int> queue;

    std::cout << "I'm queue" << std::endl;

    std::cout << "Adding elements..." << std::endl;
    queue.add(1);
    queue.add(2);
    queue.add(3);

    try {
        std::cout << "Removing elements..." << std::endl;
        while (!queue.isEmpty()) {
            std::cout << queue.front() << " ";
            queue.remove();
        }
    }
    
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

//Tasks.
//Option 3.
//A text file is given.In one file view, print the file elements in
//the following order : first, all characters other than digits, and then all digits,
//maintaining the original order in each character group.

#include <queue> 
#include <fstream>
#include <string>

void print()
{
    std::ifstream file("chars.txt"); // opening the file for reading

    if (!file.is_open())
    {
        std::cerr << "Opening error" << std::endl;
    }

    // creating two queues: for numbers and for other characters.
    std::queue<char> digits, others;

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
    output();
    print();

    return 0;
}
