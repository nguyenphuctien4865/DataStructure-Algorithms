// Queue_LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <fstream>


using namespace std;
struct DATE {
    int ngay;
    int thang;
    int nam;
};

struct HSSV {
    
    string hoten;
    DATE NgSinh;
    string noisinh;
    float gpa;
};


struct Node {
    HSSV data;
    struct Node* next;
    Node(HSSV x)
    {
        data = x;
        next = NULL;
    }
};

class Queue {
    Node* front, * rear, * temp;
public:
    void Init()
    {
        front = rear = NULL;
    }
    bool isEmpty();
    void enqueue(HSSV val);
    void dequeue();
    void getFront();
    void displayQueue();
};
bool Queue::isEmpty()
{
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

void Queue::enqueue(HSSV val) {
    temp = new Node(val);
    
  
    if (rear == NULL) {
        front = temp;
        rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}


//void Queue::getFront()
//{
//    if (isEmpty())
//        cout << "Queue is empty\n";
//    else
//        cout << "element at front is:" << front->data;
//}

void Queue::displayQueue()
{
    if (isEmpty())
        cout << "Queue is empty\n";
    else
    {
        Node* ptr = front;
        cout << "Ten\t\t\tGPA\t\t\tNgaysinh\t\tNoisinh" << endl;
        while (ptr != NULL)
        {
            cout << ptr->data.hoten << "\t\t" << ptr->data.gpa << "\t\t\t" << ptr->data.NgSinh.ngay << "/" << ptr->data.NgSinh.thang << "/" << ptr->data.NgSinh.nam << "\t\t" << ptr->data.noisinh;
            ptr = ptr->next;
        }
    }
}

void Queue::dequeue() {
    temp = front;
    if (isEmpty())
        cout << "Queue is empty\n";
    else
        if (front == rear)
        {
            front = rear = NULL;
            delete(temp);
        }
        else
        {
            front = front->next;
            temp = NULL;
            delete(temp);
        }
}

int keyPress(int Clear) {
    if (Clear == 0) {
        cout << "\n\nPress a key to continue....";
        _getch();
        system("cls");
        return 0;
    }
    else {
        cout << "\n\nPress a key to do a function:";
        int keyp;
        cin >> keyp;
        return keyp;
    }
}
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    _getch();
    system("cls");
}

void nhapthongtin(Queue& queue1) {
    HSSV hs1;
    cout << "\nNhap ten: "; cin.ignore(); getline(cin, hs1.hoten);
    cout << "\nGPA: "; cin >> hs1.gpa;
    cout << "\nNgay sinh: "; cin >> hs1.NgSinh.ngay >> hs1.NgSinh.thang >> hs1.NgSinh.nam;
    cout << "\nNoi sinh: "; cin.ignore(); getline(cin, hs1.noisinh);
    queue1.enqueue(hs1);
    cout << "Da them sinh vien " << endl;

}
void docFile(ifstream& file, Queue &queue1,char fileName[]) {
    file.open(fileName);
    while (file.eof() == false) {
        HSSV sv;
        getline(file, sv.hoten, ';');
        file >> sv.NgSinh.ngay;
        file.ignore(1);
        file >> sv.NgSinh.thang;    
        file.ignore(1);
        file >> sv.NgSinh.nam;
        file.ignore(1); 
        getline(file, sv.noisinh, ';');
        file >> sv.gpa;
        queue1.enqueue(sv);
    }
    file.close();
}





int main()
{
    ifstream file;
    Queue queue1;
    queue1.Init();
    char fileName[] = "D:\queuefile.txt";
    docFile(file, queue1, fileName);
    int key;

    while (true) {
        cout << "\nCHUONG TRINH QUAN LY SINH VIEN C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Nhap them sinh vien.                          **\n";
        cout << "**  2. Lay sinh vien ra.                             **\n";
        cout << "**  3. In thong tin sinh vien.                       **\n";
         cout <<"**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1: {
            nhapthongtin(queue1);
            pressAnyKey();
            break;
        }
        case 2: {
            system("cls");
            queue1.dequeue();
            cout << "\nDa xoa HSSV";
            pressAnyKey();
            break;
        }
        case 3: {
            system("cls");
            queue1.displayQueue();
            break;
        }
        case 0:
            cout << "\nBan da chon thoat chuong trinh!";
            _getch();
            return 0;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nHay chon chuc nang trong hop menu.";
            pressAnyKey();
            break;
        }
    }

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
