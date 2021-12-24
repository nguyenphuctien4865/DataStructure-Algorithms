// Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Ngay cap nhat: 29/10/2021 
//Ho ten: Nguyen Phuc Tien - MSSV : 20110573.

#include <iostream>
#include <string>
#include<conio.h>

using namespace std;

struct node {
    char data;
    struct node* firstChild;
    struct node* nextSibling;
};
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    _getch();
    system("cls");
}

 node* newNode(char data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return (newNode);
}

node* addSibling(node* n, char data)
{
    if (n == NULL)
        return NULL;

    while (n->nextSibling)
        n = n->nextSibling;

    return (n->nextSibling = newNode(data));
}

node* addChild(node* n, int data)
{
    if (n == NULL)
        return NULL;
    if (n->firstChild)
        return addSibling(n->firstChild, data);
    else
        return (n->firstChild = newNode(data));
}

void traversePreOrder(struct node* temp) {
    if (temp != NULL) {
        node* q = temp->firstChild;
        cout << " " << temp->data;
        traversePreOrder(q);
        if (q != NULL) {
            q = q->nextSibling;
            while (q != NULL) {
                traversePreOrder(q);
                q = q->nextSibling;
            }
        }
    }
}

// Traverse Inorder
void traverseInOrder(node* temp) {
    if (temp != NULL) {
        node* q = temp->firstChild;
        traverseInOrder(q);
        cout << " " << temp->data;
        if (q != NULL) {
            q = q->nextSibling;
            while (q != NULL) {
                traverseInOrder(q);
                q = q->nextSibling;
            }
        }
    }
}

// Traverse Postorder
void traversePostOrder( node* temp) {
    if (temp != NULL) {
        node* q = temp->firstChild;
        traversePostOrder(q);
        if (q != NULL) {
            q = q->nextSibling;
            while (q != NULL) {
                traversePostOrder(q);
                q = q->nextSibling;
            }
        }
        cout << " " << temp->data;
    }
 }

int main()
{
    int key, x;
    cout << "Nhap goc cua cay: ";
    cin >> x;
    node* T = newNode('A');
    node* p, * q;
    do {
        cout << "\n 0. thoat chuong trinh.";
        cout << "\n 1. Duyet cay.";
        cout << "\n 2. Them mot nut con.";
        cout << "\n 3. Them mot em.";
        if
    }
}
/*node* root = newNode('a');
   node* n1 = addChild(root, 'b');
   node* n2 = addChild(root, 'c');
   node* n3 = addChild(root, 'd');
   node* n4 = addChild(n3, 'h');
   node* n5 = addChild(root, 'e');
   node* n6 = addChild(n5,'i') ;
   node* n7 = addChild(n5, 'j');
   node* n8 = addChild(n7, 'p');
   node* n9 = addChild(n7, 'q');
   node* n10 = addChild(root, 'f');
   node* n11 = addChild(n10, 'k');
   node* n12 = addChild(n10, 'l');
   node* n13 = addChild(n10, 'm');
   node* n14 = addChild(root, 'g');
   node* n15 = addChild(n14, 'n');
   cout << "\n===PREORDER==========" << endl;
   traversePreOrder(root);
   cout << "\n===INORDER=========="  << endl;
   traverseInOrder(root);
   cout << "\n===POSTORDER==========" << endl;
   traversePostOrder(root);*/
