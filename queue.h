/*
 File: hw12.cpp
 Name: Joshua Yang
 Date: 4/15/2019
 CL: CS1C 
 */


#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Queue;

template <class T>
ostream& operator<<(ostream& os, const Queue<T>& queue);

template <class T>
class Queue
{
    public:
        Queue(int capacity = 100);
        Queue(const Queue& other); // Copy constructor
        ~Queue();
        void enqueue(const T& object); // inserts an element at the end of the queue
        T dequeue(); // removes and returns the element at the front of the queue
        T front(); // returns the element at the front without removing it
        int size(); // returns the number of elements stored
        bool isEmpty(); // indicates whether no elements are stored
        bool isFull(); // indicates whether queue is full
        Queue& operator =(const Queue &other); // Copy assignment
        friend ostream& operator<<<>(ostream& stream, const Queue& queue);
    private:
        int _capacity; // Capacity of queue
        int _size; // Keep size of queue
        int _head; // Keep head index
        int _tail; // Keep tail index
        T *_data; // Data keeper
};

template <class T>
Queue<T>::Queue(int capacity)
{
    _capacity = capacity;
    _size = 0;
    _head = 0;
    _tail = 0;
    _data = new T[_capacity];
}

template <class T>
Queue<T>::Queue(const Queue& other)
{
    _capacity = other._capacity;
    _size = other._size;
    _head = other._head;
    _tail = other._tail;
    _data = new T[_capacity];
    for (int i = 0; i < _capacity; i++)
    {
        _data[i] = other._data[i];
    }
}

template <class T>
Queue<T>::~Queue()
{
    delete[] _data;
}

template <class T>
void Queue<T>::enqueue(const T& object)
{
    if (!isFull())
    {
        _data[_tail] = object;
        _tail = (_tail + 1) % _capacity;
        _size++;
    }
    else
    {
        throw std::runtime_error("The cappacity is exceeded. Can not enqueue more");
    }
}

template <class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw std::runtime_error("Can not dequeue from empty queue!");
    }
    T result = _data[_head];
    // Update index keep head
    _head = (_head + 1) % _capacity;
    _size--;
    return result;

}

template <class T>
T Queue<T>::front()
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty.");
    }
    return _data[_head];
}

template <class T>
int Queue<T>::size()
{
    return _size;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return (_size == 0);
}

template <class T>
bool Queue<T>::isFull()
{
    return (_size == _capacity - 1);
}

template <class T>
Queue<T>& Queue<T>::operator =(const Queue &other)
{
    if (this != &other)
    {
        // delete old data
        delete[] _data;

        // copy
        _capacity = other._capacity;
        _size = other._size;
        _head = other._head;
        _tail = other._tail;
        _data = new T[_capacity];
        for (int i = 0; i < _capacity; i++)
        {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

template <class T>
ostream& operator<<(ostream& os, const Queue<T>& queue)
{
    os << "[ ";
    if (queue._size != 0)
    {
        for (int i = queue._head; i < queue._head + queue._size; i++)
        {
            os << queue._data[i % queue._capacity] << " ";
        }
    }
    os << "]";
    return os;
}

#endif /* QUEUE_H_ */
