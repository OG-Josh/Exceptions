/*
 File: hw12.cpp
 Name: Joshua Yang
 Date: 4/15/2019
 CL: CS1C 
 */


#include <iostream>
#include <string>
#include <assert.h>
#include <exception>
#include "queue.h"
using namespace std;

int main(int argc, char* argv[])
{
    Queue<int> intQueue;
    cout << "============TEST ASSERT MACRO===================" << endl;
    cout << "Test assert macro. Create Queue integer." << endl;
    cout << "\t-Queue should be empty. assert(intQueue.isEmpty() == true)" << endl;
    assert(intQueue.isEmpty() == true);
    cout << "\t-Test passed!!!!!!" << endl;

    cout << "\t-Queue should not be full. assert(intQueue.isFull() == false)" << endl;
    assert(intQueue.isFull() == false);
    cout << "\t-Test passed!!!!!!" << endl;
    cout << "============TEST EXCEPTION===================" << endl;
    cout << "Create double Queue with capacity 5." << endl;
    Queue<double> doubleQueue(5);
    cout << "Try to dequeue from queue empty" << endl;
    try
    {
        doubleQueue.dequeue();
    }
    catch (const std::runtime_error& e)
    {
        cout << "\t-DEQUEUE ERROR with message: " << e.what() << endl;
        cout << "Queue: " << doubleQueue << endl;
    }
    cout << "Enqueue to full!" << endl;
    double element = 1.5;
    while (!doubleQueue.isFull())
    {
        doubleQueue.enqueue(element);
        element += 1.9;
    }
    cout << "Queue: " << doubleQueue << endl;
    cout << "Try to enqueue more when queue is full. doubleQueue.enqueue(16.5)" << endl;
    try
    {
        doubleQueue.enqueue(16.5);
    }
    catch (const std::runtime_error& e)
    {
        cout << "\t-ENQUEUE ERROR with message: " << e.what() << endl;
        cout << "Queue: " << doubleQueue << endl;
    }

}
