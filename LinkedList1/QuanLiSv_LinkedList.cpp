// QuanLiSv_LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct SingleList 
{
    Node* pHead;
};

void Initialize(SingleList& list) {
    list.pHead = NULL;
}

Node *CreateNode (int d)
{
    Node* pNode = new Node;
    if (pNode != NULL) {
        pNode->data = d;
        pNode->pNext = NULL;
    }
    else
    {
        cout << "Cap phat bo nho that bai !";
    }
    return pNode;
}

void PrintList(SingleList list) 
{
    Node* pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The List is empty!";
        return;
    }
    while (pTmp != NULL)
    {
        cout << pTmp->data << " ";
        pTmp = pTmp->pNext;
    }
}

int SizeOfList(SingleList list)
{
    Node* pTmp = list.pHead;
    int nSize = 0;
    while (pTmp != NULL)
    {
        pTmp = pTmp->pNext;
        nSize++;
    }
    return nSize;
}

void InsertFirst(SingleList& list, int d)
{
    Node* pNode = CreateNode(d);
    if (list.pHead == NULL) {
        list.pHead = pNode;
    }
    else
    {
        pNode->pNext = list.pHead;
        list.pHead = pNode;
    }
}

void InsertLast(SingleList& list, int d)
{
    Node* pNode = CreateNode(d);
    if (list.pHead == NULL) {
        list.pHead = pNode;
    }
    else
    {
        Node* pTmp = list.pHead;
        while (pTmp->pNext != NULL)
        {
            pTmp = pTmp->pNext;
        }
        pTmp->pNext = pNode;
    }
}

void InsertMid(SingleList& list, int pos, int d)
{
    if (pos < 0 || pos > SizeOfList(list))
    {
        cout << "Not valid position do insert";
        return;
    }
    if (pos == 0)
    {
        InsertFirst(list, d);
    }
    else if (pos == (SizeOfList(list)) - 1)
    {
        InsertLast(list, d);
    }
    else
    {
        Node* pNode = CreateNode(d);
        Node* pIns = list.pHead;
        Node* pPre = NULL;
        int i = 0;
        while (pIns != NULL)
        {
            if (i == pos)
                break;
            pPre = pIns;
            pIns = pIns->pNext;
            i++;
        }
        pPre->pNext = pNode;
        pNode->pNext = pIns;
    }
}

int main()
{
    std::cout << "Hello World!\n";
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
