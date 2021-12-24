// BinaryTree_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <array>

using namespace std;
#define SIZE 99

void  insertBTN(int key, int tree[],int parent) {
    if (parent > SIZE)
        cout << "\nSpace not available";
    else
        if (tree[parent] == -1)
            tree[parent] = key;
        else
            if (key < tree[parent])
                insertBTN(key, tree, parent * 2);
            else
                insertBTN(key, tree, (parent * 2) + 1);
}

//int set_left(char key, int parent) {
//    if (tree[parent] == '\0')
//        cout << "\nCan't set child at"
//        << (parent * 2) 
//        << " , no parent found";
//    else
//        tree[(parent * 2)] = key;
//    return 0;
//}
//
//int set_right(char key, int parent) {
//    if (tree[parent] == '\0')
//        cout << "\nCan't set child at"
//        << (parent * 2) + 1
//        << " , no parent found";
//    else
//        tree[(parent * 2) + 1] = key;
//    return 0;
//}

void printPostorder(int tree[],int parent)
{
    
        printPostorder(tree,parent*2);
        printPostorder(tree,parent*2+1);
        if (tree[parent] != -1) {
        cout << tree[parent] << " ";
    }
}

void printInorder(int tree[], int parent)
{

        printInorder(tree, parent * 2);
        if (tree[parent] != -1) {
            cout << tree[parent] << " ";
        }
        printInorder(tree, parent * 2 + 1);

    
}

void printPreorder(int tree[],int parent)
{
    if (tree[parent] != -1) {
        cout << tree[parent] << " ";
    }
        printPreorder(tree, parent * 2);
        printPreorder(tree, parent * 2 + 1);
    
}
int docFile(int a[], char fileName[]) {
    FILE* fp;
    int i = 0;
    fp = fopen(fileName, "rt");
    if (fp == NULL) {
        cout << "Ko mo duoc tap tin!\n";
        return -1;
    }
    cout << "Chuan bi doc file: "; puts(fileName);
    while (fscanf_s(fp, "%d", &a[i]) != EOF) {
        i++;
    }
    cout << endl;
    fclose(fp);
    return i;
}


int main()
{
    int arr[SIZE];
    char fileName[] = "E:\\test1.txt";
    int index;
    index = docFile(arr, fileName);
    cout << index;
    int tree[SIZE];
    int key;
    for (int i = 1; i < SIZE; i++) {
        tree[i] = -1;
    }
   
    for (int i = 0; i < index; i++) {
        insertBTN(arr[i], tree, 1);
   }

    cout << "\n Preorder :";
    printPreorder(tree,1);
    cout << "\n Inorder :";
    printInorder(tree,1);
    cout << "\n Postorder :";
    printPostorder(tree,1);

    
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
