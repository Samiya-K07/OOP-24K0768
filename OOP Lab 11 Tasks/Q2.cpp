// Samiya Khan
// 24K-0768

#include <iostream>
#include <exception>

using namespace std;

class QueueOverflowException : public exception
{
};

class QueueUnderflowException : public exception
{
};

template <typename T>
class Queue
{
private:
    int frontIndex;
    int rearIndex;
    int currentSize;
    int capacity;
    T *queueArray;

public:
    Queue(int maxCapacity)
    {
        capacity = maxCapacity;
        queueArray = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    ~Queue()
    {
        delete[] queueArray;
    }

    void enqueue(T value)
    {
        if (currentSize == capacity)
        {
            throw QueueOverflowException();
        }

        rearIndex = (rearIndex + 1) % capacity;
        queueArray[rearIndex] = value;
        currentSize++;
    }

    T dequeue()
    {
        if (currentSize == 0)
        {
            throw QueueUnderflowException();
        }

        T value = queueArray[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        return value;
    }

    bool isEmpty() const
    {
        return currentSize == 0;
    }

    bool isFull() const
    {
        return currentSize == capacity;
    }
};

int main()
{
    Queue<int> q1(3);

    try
    {
        cout << "Attempting to enqueue to a full queue..." << endl;
        q1.enqueue(10);
        q1.enqueue(20);
        q1.enqueue(30);
        q1.enqueue(40); 
    }
    
    catch (const QueueOverflowException &ex)
    {
        cout << "Caught QueueOverflowException\n";
        cout << "what(): " << ex.what() << endl;
    }

    Queue<int> q2(2);

    try
    {
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q2.dequeue(); 
    }
    catch (const QueueUnderflowException &ex)
    {
        cout << "Caught QueueUnderflowException" << endl;
        cout << "what(): " << ex.what() << endl;
    }

    return 0;
}
