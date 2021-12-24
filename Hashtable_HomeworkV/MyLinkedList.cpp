#include "MyLinkedList.h"
#include <stdio.h>

void initList(Node*& head)
{
	head = NULL;
}
bool isEmptyList(Node* head)
{
	return head == NULL;
}
struct Node* createNode(int key, int value)
{
	Node* p = new Node;
	p->key = key;
	p->value = value;
	p->next = NULL;
	return p;
}

void addHead(Node*& head, int key, int value)
{
	Node* p = createNode(key, value);
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}
void removeHead(Node*& head)
{
	if (head != NULL)
	{
		Node* tmp = head;
		head = tmp->next;
		delete tmp;
	}
}
void removeAfter(Node*& q)
{
	Node* p = q->next;
	q->next = p->next;
	delete p;
}
void removeNode(Node*& head, int key)
{
	Node* p = head;
	Node* q = NULL;//q la nut truoc p
	while (p != NULL && p->key != key)
	{
		q = p;
		p = p->next;
	}
	if (p == NULL)
	{
		printf("Khong tim thay phan tu can xoa\n ");
		return;
	}
	//tim thay
	else
	{
		if (q == NULL)
			removeHead(head);
		else
			removeAfter(q);
	}
}

void removeAllList(Node*& head)
{
	while (!isEmptyList(head))
		removeHead(head);
}

void traverseList(Node* head)
{
	Node* p = head;
	while (p != NULL)
	{
		printf("\t<%d>  ", p->key);
		p = p->next;
	}
	printf("\n");
}
struct Node* searchList(Node* head, int key)
{
	Node* p = head;
	while (p != NULL)
	{
		if (p->key == key)
			return p;
		p = p->next;
	}
	return NULL;
}