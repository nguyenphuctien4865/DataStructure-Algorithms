
/// Ten : Nguyen Phuc Tien - MSSV : 20110573
/// Cap nhat : 25/11/2021
/// Chuc nang : Chuong trinh quan ly quan Caffee - Su dung cau truc du lieu LinkedList, Stack, Queue, 
/// Sort cho cac chuc nang chuong trinh


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include "queue.h"
#include "animation.h"
#include "stack.h"
#include <fstream>


using namespace std;

int search(int);
int display();
string check(int);       


struct cafe {
	int ID;
	string proName;
	double prePrice;
	int quantity;
};
////////////////////////////////////////////////////////////////////
struct node
{
	cafe data;
	struct node* next;
	node(int id, string proname, double preprice, int quant) {
		this->data.ID = id;
		this->data.proName = proname;
		this->data.prePrice = preprice;
		this->data.quantity = quant;
	}
	node() {};
};

struct node* head = NULL;

void addLast(node* t) {
	t->next = NULL;
	if (head == NULL) {//Nếu rỗng=>khởi tạo danh sách
		head = t;
	}
	else {
		node* q = head;
		while (q->next != NULL)
		{ q = q->next; }
		q->next = t;
	}
}
////////////////////////////////////////////////////////////////////
void insert()
{
	int count = display();    
	int pos = 0;
	
	cout << "\t\t\t|============INSERT PRODUCT==============|" << endl;
	int id, quant;           //  quant  for quantity
	string name;
	double pre;            //  pre for price
	struct node* t = new node();
	struct node* p = head;
	
	cout << "\t\t\tEnter product ID:-";
	do {
		cin >> id;
		pos = search(id);
		if (pos <= count) {
			cout << "\n\t\t\tID da ton tai, vui long nhap lai: ";
			
		}
		else {
			t->data.ID = id;
			break;
		}
	} while (true);
	
	
	cout << "\t\t\tEnter product Name:-";
	cin.ignore(32767, '\n');
	getline(cin, name);
	t->data.proName = name;
	cout << "\t\t\tEnter product price:-";
	cin >> pre;
	t->data.prePrice = pre;
	cout << "\t\t\tEnter product quantity:-";
	cin >> quant;
	t->data.quantity = quant;
	
	addLast(t);
	system("cls");
	cout << "\n\n\t\t\t\tThis product is Inserted!\n\n\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
int search(int id)                     //    for search item in list
{
	int count = 1;
	struct node* p = head;
	while (p != NULL)
	{
		if (p->data.ID == id)
			break;
		else
			count++;
		p = p->next;
	}
	return count;
}
///////////////////////////////////////////////////////////////////////

void ghiFile(sNode* head, char fileName[]) {
	int i = 1;
	cusOrder P;
	ofstream file1;
	int t = 0 ;
	file1.open(fileName);
	file1 << "========ALL BILL TODAY========" << endl;
	while (!isEmpty()) {
		P = bpop();
		file1 << "=============" << i << "===============" << endl;
		file1 << "Ten khach hang: " << P.cusName << endl;
		for (int j = 0; j < P.no; j++) {
			file1 << "Ten mon: " << P.proName[j] << "\tSo luong: " << P.quantity[j] << endl;
		}
		file1 << "Total: " << P.pay << endl;
		t += P.pay;
		i++;
	}
	file1 << "Tong doanh thu ca ngay: " << t;
	file1.close();
}


////////////////////////////////////////////////////////////////////////
void delPro()
{
	system("cls");
	display();
	int id;
	struct node* cur = head;
	struct node* pre = head;
	cout << "\n\nEnter ID to delete that product:\n\n";
	cin >> id;
	if (head == NULL)
	{
		system("cls");
		cout << "List is empty" << endl;
	}
	int pos = 0;
	int count = display();               
	if (pos <= count) {

		while (cur->data.ID != id) {               
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		system("cls");
		cout << "\n<<item is deleted>>\n";
	}
	else {
		cout << "\n<<<Not found>>\n\n";
	}
}

//////////////////////////////////////////////////////////////////////////////////
void modify()
{
	int id;
	double pre;        //    pre for price
	string pName;
	int nid; int nq;     //   pName for new name
	if (head == NULL)
	{
		system("cls");
		cout << "List is empty" << endl;
	}
	else
	{
		display();
		cout << "\n\nEnter ID to modify product Name and its price:\n";
		cin >> id;
		struct node* cur = head;
		int pos = 0;
		int count = display();               //   for load no of nodes
		pos = search(id);
		
		if (pos <= count)
		{
			while (cur->data.ID != id)
			{
				cur = cur->next;
			}
			cout << "\nOld ID : " << cur->data.ID << endl;
			cout << "\nOld Name : " << cur->data.proName << endl;
			cout << "\nOld Price : " << cur->data.prePrice << endl;
			cout << "\nOld Quantity : " << cur->data.quantity << endl;

			cout << endl << endl;
			cout << "Enter new ID:";
			cin >> nid;
			cur->data.ID = nid;
			cout << "Enter new Name:";
			cin.ignore(32767, '\n');
			getline(cin, pName);
			cur->data.proName = pName;
			cout << "Enter new Price:";
			cin >> pre;
			cur->data.prePrice = pre;
			cout << "Enter new Quantity:";
			cin >> nq;
			cur->data.quantity = nq;
		}

		else
		{
			cout << id << " is <<<Not found>>\n\n";
			system("pause");
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////

int display()
{
	system("cls");
	int c = 0;             //   c for count products
	struct node* p = head;
	cout << "List of products:\n";
	cout << "ID\t\tProduct Name\t\t\tPrice\t\t\tQuantity\n";
	cout << "|==============================================================================|\n";
	while (p != NULL)
	{
		cout << p->data.ID << "\t\t" << p->data.proName << "\t\t\t" << p->data.prePrice << "\t\t\t     " << check(p->data.quantity) << "\n"; //    call   check func and pass quantity
		p = p->next;
		c = c + 1;
	}
	cout << "\nTotal products in our store is : " << c << "\n\n\n";
	return c;
}
////////////////////////////////////////////////////////////////////////////////////////
string check(int quant)

{              //        check function
	int a = quant;
	stringstream ss;
	ss << a;
	string quantity = ss.str();

	if (quant <= 0)
		return "out of stock!";
	else
		return quantity;
}


///////////////////////////////////////////////////////////////////////
void buy()
{
	system("cls");
	display();
	string products[20];
	int quantnum[20];
	//   Hien thong tin nhap can mua
	int pay = 0, no, c = 0, price, id, i = 1;

	if (head == NULL)
	{
		cout << "\n<<<<Khong co san pham nao de mua>>>>\n";
	}
	else
	{
		cout << "\nSo luong san pham ban muon mua: ";
		cin >> no;
		int count = display();           //   for store no of nodes  in c
		while (i <= no)
		{
			
			struct node* cur = head;
			int quant, cho;   a:           //   quant   for quantity  and cho for choice
			cout << "Nhap ID san pham ban muon mua: ";
			int id, pos = 0;
			cin >> id;
			if (id == -1) { system("cls"); return; }
			pos = search(id);
			if (pos <= count)
			{
				//     
				while (cur->data.ID != id)
				{
					cur = cur->next;
				}
				cout << "So luong ban muon:";
				cin >> quant;
				if (cur->data.quantity < quant)
				{
					cout << "\n\n\t\t\t----So luong ban nhap hien khong phu hop---" << endl;
					cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
					goto a;

				}
				quantnum[c] = quant;
				products[c] = cur->data.proName;   // Mang de chua thong tin san pham mua
				c++;

				pay = pay + (cur->data.prePrice * quant);         //     Tinh bill
				cur->data.quantity = cur->data.quantity - quant;           //    thay doi so luong san pham con lai
				i++;
				
			}
			else
			{

				cout << "\n<<<<<<<<<San pham nay khong phu hop voi cua hang hien tai>>>>\n\n";

			}
		}
		cusOrder infoCus;
		string customer;
		cout << "\n\t\t Nhap Ten cua ban :"; cin.ignore(32767, '\n'); getline(cin, customer);
		enqueue(customer);
		system("cls");
		cout << "\n\n=================Ban da mua :==================== " << endl;
		cout << "Product Name\t\t\tQuantity\n";

		for (int j = 0; j < no; j++)
		{              //    Hien thi san pham da mua
			cout << products[j] <<"\t\t\t "<< quantnum[j] << endl;
		}
		price = pay ;           
		cout << "\n\nTong gia : " << pay;
		cout << "\nThank you! for the shopping\n\n";
		infoCus.cusName = customer;
		infoCus.pay = price;
		infoCus.no = no;
		for (int j = 0; j < no; j++) {
			infoCus.proName[j] = products[j];
			infoCus.quantity[j] = quantnum[j];
		}
		push(infoCus);
		system("pause");
		

	}
}

/// Bubble Sort by price Cafe
void SortbyPrice() {
	cafe tmp;
	node* p, * q, * min;
	p = head;
	cout << "|============SORT BY PRICE==============|";
	while (p != NULL) {
		min = p;
		q = p->next;
		while (q != NULL) {
			if (min->data.prePrice > q->data.prePrice) {
				min = q;
				tmp = p->data;
				p->data = min->data;
				min->data = tmp;
			}
			q = q->next;
		}
		p = p->next;
	}
}

/// Hien thi bill moi nhat duoc order

void customerBill() {
	system("cls");
	cusOrder temp = getTop();
	cout << "|============CUSTOMER BILL==============|";
	cout << "\nCustomer Name: " << temp.cusName;
	for (int i = 0; i < temp.no; i++) {
		cout << "\n\t" << temp.proName[i] << "\t" << temp.quantity[i];
	}
	cout << "\nTotal: " << temp.pay;
	cout << "\n";

}


/////////////////////////////////////////////////////////////////////////////////////////
void administator()
{

	system("cls");
	int ch;
	char fileName2[] = "D:\BillFile.txt";

	do {

	

		cout << "\t\t============================================" << endl;
		cout << "\t\t|          Administator Portal              |" << endl;
		cout << "\t\t============================================" << endl;

		cout << "\t\t     Enter 1 for ADD a new product    " << endl;
		cout << "\t\t     Enter 2 for Display all products   " << endl;
		cout << "\t\t     Enter 3 for MODIFY Existing product" << endl;
		cout << "\t\t     Enter 4 for Delete a particular product item" << endl;
		cout << "\t\t     Enter 5 for Sort by price" << endl;
		cout << "\t\t     Enter 6 for Customers List " << endl;
		cout << "\t\t     Enter 7 for Customer bill" << endl;
		cout << "\t\t     Enter 8 for Dequeue customer" << endl;
		cout << "\t\t     Enter 9 for Write Bill list to file" << endl;
		cout << "\t\t     Enter 0 for Main Menu" << endl;


		cout << "\nEnter Your choice >>>";   cin >> ch;
		switch (ch) {
		case 1:
			insert();
			system("cls");
			break;
		case 2:
			system("cls");
			display();
			break;
		case 3:
			modify();
			system("cls");
			break;
		case 4:
			delPro();
			cout << "\n-------Product is Deleted-------\n";
			break;
		case 5:
			system("cls");
			SortbyPrice();
			display();
			break;
		case 6:
			system("cls");
			cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
			displayQueue();
			break;
		case 7:
			system("cls");
			customerBill();
			break;
		case 8:
			system("cls");
			cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
			dequeue();
			displayQueue();
			break;
		case 9:
			system("cls");
			if (!isEmpty()) {
				cout << "\nGhi danh sach Bill vao file.";
				ghiFile(top, fileName2);
			}
			else {
				cout << "\nDanh sach Bill empty!";
			}
			printf("\nGhi danh sach Bill vao file %s thanh cong!\n", fileName2);
			break;
		
		

		default: system("cls");

		}
	} while (ch != 0);
}

int keyPress(int Clear) {
	if (Clear == 0) {
		cout << "\n\nPress a key to continue....";
		_getch();
		system("cls");
		return 0;
	}
	else {
		cout << "\n\nEnter Your choice :";
		int keyp;
		cin >> keyp;
		return keyp;
	}
}

void docFile(ifstream& file, char fileName[]) {
	file.open(fileName);
	while (file.eof() == false) {
		node* pro = new node();
		file >> pro->data.ID;
		file.ignore(1);
		getline(file, pro->data.proName, ';');
		file >> pro->data.prePrice;
		file.ignore(1); 
		file >> pro->data.quantity;
		addLast(pro);		
	}
	file.close();
}



//        Main function
int main()
{
	ifstream file;
	char	fileName1[] = "D:\input.txt";
	docFile(file, fileName1);

	
	sNode cusList;


	system("color F1");     
	gotoxy(17, 5);
	cout << "--------------------------------------------------" << endl;
	gotoxy(17, 7);
	cout << "||            COFFEE SHOP MANAGEMENT SYSTEM              ||" << endl;
	gotoxy(17, 9);
	cout << "--------------------------------------------------" << endl;
	gotoxy(17, 11);
	cout << "           |Giang vien ->> Hoang Van Dung <<--|\n" << endl;
	gotoxy(17, 13);
	cout << "              >>>-----Nguoi thuc hien-----<<<            " << endl;
	gotoxy(22, 15);
	cout << "          Nguyen Phuc Tien - 20110573               " << endl;
	system("pause");
	system("cls");
	system("color Fc");

	int key;
	do {

		//            choice for below message

		cout << "\n\t\t|--------<Main Menu>-----------|";
		cout << "\n\n";
		cout << "\t\t 1)Administator\n";
		cout << "\t\t 2)Customer               \n";
		cout << "\t\t 0)Exit                    \n";



		cout << "\nEnter Your choice >>>";   cin >> key;
		switch (key) {
		case 1:
			administator();
			break;

		case 2:
			picture();
			system("pause");
			buy();
			system("cls");
			break;
		case 0:
			cout << "\n Da thoat chuong trinh!";
			break;
		
		default: system("cls");
		}
	} while (key != 0);
	return 0;
}






