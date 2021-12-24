// 20110573_NguyenPhucTien_BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#define SIZE 100
using namespace std;

struct BinaryTree {
    int data;
    struct BinaryTree* left;
    struct BinaryTree* right;
};
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    _getch();
    system("cls");
}

BinaryTree* NewNode(int x) {
    BinaryTree* temp = new BinaryTree();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct BinaryTree* insertNode(struct BinaryTree* node, int val) {
    if (node == NULL) return NewNode(val);
    if (val < node->data)
        node->left = insertNode(node->left, val);
    else if (val > node->data)
        node->right = insertNode(node->right, val);
    return node;
}

void printPostorder(struct BinaryTree* node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printInorder(struct BinaryTree* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int docFile(int a[], char fileName[]) {
    FILE* fp;
    int i = 0;
    fp=fopen(fileName, "rt");
     if (fp == NULL) {
         cout << "Ko mo duoc tap tin!\n";
         return -1;
     }
    cout << "Chuan bi doc file: "; puts(fileName);
    while (fscanf_s(fp, "%d",&a[i] ) != EOF) {
        i++;
    }
    cout << endl;
    fclose(fp);
    return i;
}

void printPreorder(struct BinaryTree* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}


int main()
{
    int arr[SIZE];
    char fileName[] = "E:\\test1.txt";
    int index;
    index = docFile(arr, fileName);
    BinaryTree* root = NewNode(arr[0]);
    for (int i = 1; i < index; i++) {
        insertNode(root, arr[i]);
    }
    cout << "\nPreorder: ";
    printPreorder(root);
    cout << "\nInorder: ";
    printInorder(root);
    cout << "\nPostorder: ";
    printPostorder(root);

   
    
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
