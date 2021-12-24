// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
using namespace std;
#define SIZE 50

class Queue {
	int front, rear, capacity;
	int* queue;
public:
    Queue(int size);
    ~Queue() { front = rear = -1; delete[] queue; }
	bool enqueue(int x);
	int dequeue();
	void getFront();
    void displayQueue();
    bool isEmpty()
	{
        return (front ==-1 && rear==-1);
	};
	bool isFull()
	{
        return ((rear + 1) %( capacity)  == front);
	};
};
Queue::Queue(int size) {
    queue = new int[size];
    capacity = size;
    front = -1;
    rear = -1;
}

int Queue::dequeue()
{
    int x = 0;
    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return false;
    }
     x = queue[front];
  /*  if (front == rear)
    {
        front = rear = -1;
    }
    else {
        front++;
    }*/
    cout << "Removing " << queue[front] << endl;
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % capacity;
    return x;
}


bool Queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\n";
        return false;
    }
    else if (front == -1)
    {
        front = 0; 
    }
    /*if (front == -1) { front = 0; }
    if ((rear == capacity - 1) && (front > 0))
    {
        for (int i = 0; i < rear - front + 1; i++)
            queue[i] = queue[front + i];
        rear = rear - front;
        front = 0;
    }
    queue[++rear] = item;*/
    cout << "Inserting " << item << endl;
    rear = (rear + 1) % capacity;
    queue[rear] = item;
    return true;
}

void Queue::displayQueue()
{
    if (isEmpty()) {
        printf("\nQueue is Empty\n");
        return;
    }
    // traverse front to rear and print elements
    printf("Front= %d , rear=%d<-- \n", front, rear);
    for (int i = front; i <= rear; i++) {
        printf(" %d <-- ", queue[i]);
    }
    cout << endl;
    return;
}

void Queue::getFront()
{
    if (isEmpty() ){
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nFront Element is: %d", queue[front]);
    return;
}
int main()
{
    Queue q(20);
    for (int i = 0; i < 10; i++) {
        q.enqueue(i);
    }
    for (int i = 0; i < 15; i++) {
        q.dequeue();
    }
    
    

    q.displayQueue();
    
   
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
