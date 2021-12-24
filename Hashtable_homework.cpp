// 20110573_NguyenPhucTien_Homework8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <list>
#include <string>
#include <conio.h>


#define MAXHASH 1000
#define INDEX 100003
using namespace std;
struct DATE {
    int ngay;
    int thang;
    int nam;
};

typedef struct CCCD {
    int id;
    string ten;
    DATE NgSinh;
    char nSinh[20];
	string dcThuongTru;
    string dcTamTru;
    string nNghiep;
    string trinhDo;
};

struct Node {
	CCCD data;
	struct Node* next;
};

bool isEmpty(Node*& head) {
	return head == NULL;
}
void addLast(Node*& head, CCCD x) {
	Node* p = new Node();
	p->data = x;
	p->next = NULL;
	if (head == NULL) {//Nếu rỗng=>khởi tạo danh sách
		head = p;
	}
	else {
		Node* q = head;
		while (q->next != NULL) q = q->next;
		q->next = p;
	}
}
void addFirst(Node*& head, CCCD x) {
	Node* p = new Node();
	p->data = x;
	p->next = head;
	head = p;
}

class Hash
{
	int BUCKET; // No. of buckets
	Node** table; // Pointer to an array containing buckets
public:
	Hash(int V); // Constructor
	void insertItem(CCCD x);
	void deleteItem(int key);
	int hashFunction(int x) {
		return (x % BUCKET);
	}
	void displayHash();
	void checkItem(int key);
	int numberOfItemsInIndex(int index);
	void updateHash(int key);
};
Hash::Hash(int b)
{
	this->BUCKET = b/MAXHASH;
	table = new Node*[BUCKET];
	for (int i = 0; i < BUCKET; ++i) {
		table[i] = NULL;
	}
}
void Hash::deleteItem(int key)
{
	int index = hashFunction(key);
	int found = 0;
	Node*t=NULL,* i = table[index];
	while (i != NULL) {
		if (i->data.id == key) {
			if (i == table[index]) {
				table[index] = table[index]->next;
			}
			else {
				t->next = i->next;
			}
			delete i;
			cout << "\nDa xoa id :" << key;
			found = 1;
			break;
		}
		t = i;
		i = i->next;
	}
	if (found != 1) {
		cout << "\nKhong ton tai id :" << key;
	}
	//for (i = table[index].begin();
	//	i != table[index].end(); i++) {
	//	if (i->id == key.id)
	//		break;
	//}
	//if (i != table[index].end())
	//	table[index].erase(i);
}
void Hash::insertItem(CCCD key)
{
	int index = hashFunction(key.id);
	addFirst(table[index], key);
	cout << "\nDa them CMND/CCCD moi vao Hashtable";
}

void Hash::checkItem(int key) {
	int index = hashFunction(key);
	Node* i = table[index];
	int found = 0;
	while (i!=NULL) {
		if (i->data.id == key) {
			cout << "\n =================================";
			cout << "\n So CMND/CCCD: " << i->data.id << endl;
			cout << "\n Ho Ten: " << i->data.ten << endl;
			cout << "\n Ngay sinh: " << i->data.NgSinh.ngay << "/" << i->data.NgSinh.thang << "/" << i->data.NgSinh.nam << endl;
			cout << "\n Noi sinh: " << i->data.nSinh << endl;
			cout << "\n Dia chi tam tru " << i->data.dcTamTru << endl;
			cout << "\n Dia chi thuong tru " << i->data.dcThuongTru << endl;
			cout << "\n Nghe nghiep: " << i->data.nNghiep << endl;
			cout << "\n Trinh do chuyen mon " << i->data.trinhDo << endl;
			found = 1;
			break;
		}
		i = i->next;
	}
	if (found != 1) {
			cout << "\n===============================";
			cout << "\nKhong co du lieu";
	}
}
int Hash::numberOfItemsInIndex(int index) {
	int count = 0;
	if (table[index] == NULL) {
		return count;
	}
	else {
		count++;
		Node* Ptr = table[index];
		while (Ptr->next != NULL) {
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

void Hash::displayHash() {
	int number;
	for (int i = 0; i < BUCKET; i++) {
		number = numberOfItemsInIndex(i);
		Node* t = table[i];
		while (t != NULL) {
			cout << i << ". ================================= " << endl;
			cout << " So CMND/CCCD: " << t->data.id << endl;
			cout << " Ho Ten: " << t->data.ten << endl;
			cout << " Ngay sinh: " << t->data.NgSinh.ngay << "/" << t->data.NgSinh.thang << "/" << t->data.NgSinh.nam << endl;
			cout << " Noi sinh: " << t->data.nSinh << endl;
			cout << " Dia chi tam tru " << t->data.dcTamTru << endl;
			cout << " Dia chi thuong tru " << t->data.dcThuongTru << endl;
			cout << " Nghe nghiep: " << t->data.nNghiep << endl;
			cout << " Trinh do chuyen mon " << t->data.trinhDo << endl;
			t = t->next;
		}
		/*for (int j = 0; j < number;j++) {
			cout << i<<". =================================";
			cout << " So CMND/CCCD: " << x.d << endl;
			cout << " Ho Ten: " << x.ten << endl;
			cout << " Ngay sinh: " << x.NgSinh.ngay<<"/"<<x.NgSinh.thang<<"/"<<x.NgSinh.nam << endl;
			cout << " Noi sinh: " << x.nSinh << endl;
			cout << " Dia chi tam tru " << x.dcTamTru << endl;
			cout << " Dia chi thuong tru " << x.dcThuongTru << endl;
			cout << " Nghe nghiep: " << x.nNghiep << endl;
			cout << " Trinh do chuyen mon " << x.trinhDo << endl;

		}
		cout << endl;*/
	}
}
void Hash::updateHash(int key) {
	int index = hashFunction(key);
	int found = 0;
	Node* i = table[index];
	while (i != NULL) {
		if (i->data.id == key) {
			cout << "\n =================================";
			cout << "\n So CMND/CCCD: " << i->data.id << endl;
			cout << "\n Ho Ten: " << i->data.ten << endl;
			cout << "\n Ngay sinh: " << i->data.NgSinh.ngay << "/" << i->data.NgSinh.thang << "/" << i->data.NgSinh.nam << endl;
			cout << "\n Noi sinh: " << i->data.nSinh << endl;
			cout << "\n Dia chi tam tru " << i->data.dcTamTru << endl;
			cout << "\n Dia chi thuong tru " << i->data.dcThuongTru << endl;
			cout << "\n Nghe nghiep: " << i->data.nNghiep << endl;
			cout << "\n Trinh do chuyen mon " << i->data.trinhDo << endl;
			
			cout << "\n ===================================";
			cout << "\n Nhap thong tin moi cho CMND/CCCD";
			CCCD cccd1;
			cout << "\nNhap ten: "; cin.ignore(); getline(cin, cccd1.ten);
			cout << "\nso CCCD: "; cin >> cccd1.id;
			cout << "\nNgay sinh: "; cin >> cccd1.NgSinh.ngay >> cccd1.NgSinh.thang >> cccd1.NgSinh.nam;
			cout << "\nNoi sinh: "; cin >> cccd1.nSinh;
			cout << "\nDia chi tam tru: "; cin.ignore(); getline(cin, cccd1.dcTamTru);
			cout << "\nDia chi thuong tru: "; cin.ignore(); getline(cin, cccd1.dcThuongTru);
			cout << "\nNghe nghiep: "; cin.ignore(); getline(cin, cccd1.nNghiep);
			cout << "\nTrinh do: "; cin.ignore(); getline(cin, cccd1.trinhDo);
			
			
			insertItem(cccd1);
			deleteItem(i->data.id);
			cout << "Da  chinh sua";
			found = 1;
			break;
		}
		i = i->next;
	}
	if (found != 1) {
		cout << "\n===============================";
		cout << "\nKhong co du lieu";
	}
}

void nhapthongtin(Hash &Hashtable) {
	CCCD cccd1;
	cout << "\nNhap ten: "; cin.ignore(); getline(cin, cccd1.ten);
	cout << "\nso CCCD: "; cin >> cccd1.id;
	cout << "\nNgay sinh: "; cin >> cccd1.NgSinh.ngay >> cccd1.NgSinh.thang >> cccd1.NgSinh.nam;
	cout << "\nNoi sinh: "; cin >> cccd1.nSinh;
	cout << "\nDia chi tam tru: "; cin.ignore(); getline(cin, cccd1.dcTamTru);
	cout << "\nDia chi thuong tru: "; cin.ignore(); getline(cin, cccd1.dcThuongTru);
	cout << "\nNghe nghiep: "; cin.ignore(); getline(cin, cccd1.nNghiep);
	cout << "\nTrinh do: "; cin.ignore(); getline(cin, cccd1.trinhDo);
	Hashtable.insertItem(cccd1);
}
void pressAnyKey() {
	cout << "\n\nBam phim bat ky de tiep tuc...";
	_getch();
	system("cls");
}


int main()
{
	int key;

	Hash Hashtable(INDEX);
	while (true) {
		cout << "CHUONG TRINH QUAN LY CMND/CCCD C/C++\n";
		cout << "*************************MENU**************************\n";
		cout << "**  1. Tim kiem CMND/CCCD.                           **\n";
		cout << "**  2. Them CMND/CCCD.                               **\n";
		cout << "**  3. Xoa sinh vien boi ID.                         **\n";
		cout << "**  4. Chinh sua CMND/CCCD                           **\n";
		cout << "**  5. Hien thi danh sach CMND/CCCD                  **\n";
		cout << "**  0. Thoat                                         **\n";
		cout << "*******************************************************\n";
		cout << "Nhap tuy chon: ";
		cin >> key;
		switch (key) {
		case 1:
			int id;
			cout << "\n1. Tim kiem CMND/CCCD.";
			cout << "\nNhap so CMND/CCCD ban muon tim: ";
			cin >> id;
			Hashtable.checkItem(id);
			pressAnyKey();
			break;
		case 2:
			cout << "\nThem CMND/CCCD moi.";
			nhapthongtin(Hashtable);
			pressAnyKey();
			break;
		case 3:
			int cmnd3;
			cout << "\n Xoa mot CMND/CCCD.";
			cout << "\n Nhap so CMND/CCCD ban muon xoa: ";
			cin >> cmnd3;
			Hashtable.deleteItem(cmnd3);
			pressAnyKey();
			break;
		case 4:
			int cmnd4;
			cout << "\n Chinh sua CMND/CCCD";
			cout << "\n Nhap CMND/CCCd ban muon chinh sua: ";
			cin >> cmnd4;
			Hashtable.updateHash(cmnd4);
			pressAnyKey();
			break;
		case 5:
			cout << "\nDanh sach CMND/CCCD ";
			Hashtable.displayHash();
			pressAnyKey();
			break;
		
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
