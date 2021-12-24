// 20110573_NguyenPhucTien_C4_B1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include <string>
#include <conio.h>


using namespace std;
#define MAX 100

// stack <int>
class Stack {
	int top = -1;
public:
	int data[MAX];
	Stack() { top = -1; }
	~Stack() { top = -1; }
	bool push(int x);
	int pop();
	int getTop();
	bool isEmpty()
	{
		return (top < 0);
	};
	bool isFull()
	{
		return (top >= MAX - 1);
	};
};
bool Stack::push(int x) {
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		data[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}
int Stack::pop() // loại bỏ phần tử ở cuối Stack
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = data[top--];
		return x;
	}
}
int  Stack::getTop() {
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = data[top];
		return x;
	}
}

// stack <char>
class Stackc {
	int top = -1;
public:
	char data[MAX];
	Stackc() { top = -1; }
	~Stackc() { top = -1; }
	bool push(char x);
	char pop();
	char getTop();
	bool isEmpty()
	{
		return (top < 0);
	};
	bool isFull()
	{
		return (top >= MAX - 1);
	};
};
bool Stackc::push(char x) {
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		data[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}
char Stackc::pop() // loại bỏ phần tử ở cuối Stack
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		char x = data[top--];
		return x;
	}
}
char  Stackc::getTop() {
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		char x = data[top];
		return x;
	}
}

int toanTu(char ch)
{

	switch (ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	}
	return -1;
}

int applyOp(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}

int tinhBieuThuc(string tokens) {
	int i;

	Stack val;

	Stackc ops;

	for (i = 0; i < tokens.length(); i++) {

		if (tokens[i] == ' ')
			continue;

		else if (tokens[i] == '(') {
			ops.push(tokens[i]);
		}

		else if (isdigit(tokens[i])) {
			int values = 0;

			while (i < tokens.length() && isdigit(tokens[i])) {
				values = (values * 10) + (tokens[i] - '0');
				i++;
			}
			i--;
			val.push(values);
		}

		else if (tokens[i] == ')') {

			while (!ops.isEmpty() && ops.getTop() != '(') {
				int val2 = val.pop();

				int val1 = val.pop();

				char op = ops.pop();

				val.push(applyOp(val1, val2, op));
			}

			if (!ops.isEmpty())
				ops.pop();
		}

		else if (toanTu(tokens[i])!=-1){
			while (!ops.isEmpty() && (toanTu(ops.getTop()) >= toanTu(tokens[i]))) {
				int val2 = val.pop();

				int val1 = val.pop();

				char op = ops.pop();

				val.push(applyOp(val1, val2, op));
			}

			ops.push(tokens[i]);
		}
		else {
			return NULL;
				
		}
	}

	while (!ops.isEmpty()) {
		int val2 = val.pop();

		int val1 = val.pop();

		char op = ops.pop();

		val.push(applyOp(val1, val2, op));
	}

	return val.getTop();
}



int main()
{
	string ch;
	cout << "Nhap bieu thuc:";
	getline(cin, ch);
	if (tinhBieuThuc(ch) != NULL)
		cout << "Ket qua bieu thuc: " << tinhBieuThuc(ch);
	else cout << "Bieu thuc loi !";

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
