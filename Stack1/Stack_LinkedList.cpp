#include<iostream>
#define INF 9999999;
using namespace std;
struct Node {
	int data;
	struct Node* link;
};
class Stack {
public:
	struct Node* top;
	Stack() { top = NULL; }
	~Stack() { top = NULL; }
	bool push(int x);
	int pop();
	int getTop();
	bool isEmpty() { return (top == NULL); };
};

bool Stack::push(int data)
{
	struct Node* temp;
	temp = new Node();
	if (!temp) {
		cout << "\nHeap Overflow";
		return false;
	}
	temp->data = data;
	temp->link = top;
	top = temp;
	return true;
}
int Stack::pop()
{
	struct Node* temp;
	if (top == NULL) {
		cout << "\nStack Underflow" << endl;
		return INF;
	}
	else {
		temp = top;
		top = top->link;
		temp->link = NULL;
		int data = temp->data;
		free(temp);
		return data;
	}
}

int main()
{
	class Stack s;
	cout << "\n ===Before push elements====";
	cout << "\n Check empty: " << s.isEmpty();
	for (int i = 1; i <= 100; i++) {
		s.push(i);
	}
	cout << "\n ===After push elements====";
	cout << "\n Check empty: " << s.isEmpty();
	cout << "\n Top element is " << s.getTop();
	cout << "\n === Pop all elements====" << endl;
	for (int i = 1; i <= 100; i++) {
		cout << s.pop() << "->";
	}
	cout << "\n Top element is " << s.getTop();
	cout << "\n ===After pop all elements====";
	cout << "\n Check empty: " << s.isEmpty();
	return 0;
}