
#pragma once
#include <iostream>
using namespace std;

struct cusOrder {

	string cusName;
	string proName[20];
	int quantity[20];
	int pay;
	int no;
};
struct sNode
{
	cusOrder data;
	sNode* link;
};

struct sNode* top;

//class Stack {
//public:
//	struct Node* top;
//	Stack() { top = NULL; }
//	~Stack() { top = NULL; }
//	bool push(int x);
//	int pop();
//	int getTop();
//	bool isEmpty() { return (top == NULL); };
//};


void push(cusOrder data)
{
	struct sNode* temp;
	temp = new sNode();

	if (!temp) {
		cout << "\nHeap Overflow";
		exit(1);
	}

	temp->data = data;

	temp->link = top;

	top = temp;
}

int isEmpty()
{
	return top == NULL;
}

cusOrder getTop()
{

	if (!isEmpty())
		return top->data;
	else
		exit(1);
}


cusOrder bpop()
{
	struct sNode* temp;


	if (top == NULL) {
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else {

		temp = top;
		top = top->link;
		temp->link = NULL;
		cusOrder data = temp->data;
		// release memory of top node 
		free(temp);
		return data;

	}
}

void bdisplay()
{
	struct sNode* temp;


	if (top == NULL) {
		cout << "\nStack Underflow";
		exit(1);
	}
	else {
		int i = 0;
		temp = top;
		while (temp != NULL)
		{
			cout << temp->data.cusName << " ";
			cout << temp->data.proName[i] << " ";
			cout << temp->data.quantity[i] << " ";
			i++;
			temp = temp->link;
		}
	}
}






