#pragma once
#include <iostream>
#include<conio.h>
//#include <bits/stdc++.h>
using namespace std;

// Structure of Node.
struct qNode
{
	string cname;
		qNode* link;

};

qNode* front = NULL;
qNode* rear = NULL;

//Function to check if queue is empty or not
bool isempty()
{
	if (front == NULL && rear == NULL)
		return true;
	else
		return false;
}

//function to enter elements in queue
void enqueue(string name)
{
	qNode* ptr = new qNode();

	ptr->cname = name;
	ptr->link = NULL;

	//If inserting the first element/node
	if (front == NULL)
	{
		front = rear = ptr;

	}
	else
	{
		rear->link = ptr;
		rear = ptr;
	}
}

//function to delete/remove element from queue
void dequeue()
{
	if (isempty())
		cout << "Queue is empty\n";
	else
		//only one element/node in queue.
		if (front == rear)
		{
			free(front);
			front = rear = NULL;
		}
		else
		{
			qNode* ptr = front;
			front = front->link;
			free(ptr);
		}
}

//function to show the element at front
void showfront()
{
	if (isempty())
		cout << "Queue is empty\n";
	else
		cout << "element at front is:" << front->cname << "\n";
}

//function to display queue
void displayQueue()
{
	if (isempty())
		cout << "Queue is empty\n";
	else
	{
		int n = 1;
		qNode* ptr = front;
		cout << "No\t" << "Name" << endl;
		while (ptr != NULL)
		{
			cout << n<<"\t" << ptr->cname << "\t  " << endl;
			ptr = ptr->link;
			n++;
		}
	}
}

