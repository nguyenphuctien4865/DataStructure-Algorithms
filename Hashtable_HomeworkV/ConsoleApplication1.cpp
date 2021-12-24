#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "MyLinkedList.h"
#include <stdio.h>
#include <iomanip>
#include <string>
#include <conio.h>

#define DEAULT_LOAD_FACTOR 0.8
using namespace std;


struct HashTable {
	NodePtr* bucket;
	int size; //kich thuoc bang bam (so luong bucket)
	int n; //so luong phan tu tren bang bam
};

void initHT(HashTable& ht, int capacity)
{
	ht.size = capacity;
	ht.n = 0;
	ht.bucket = new NodePtr[capacity];
	for (int i = 0; i < ht.size; i++)
	{
		initList(ht.bucket[i]);
	}
}
void removeAllHT(HashTable& ht)
{
	for (int i = 0; i < ht.size; i++)
	{
		removeAllList(ht.bucket[i]);
	}
	ht.n = 0;
	//thu hoi lai vung nho
	delete[] ht.bucket;
	ht.size = 0;
}

int Hash(int key, int M)
{
	return key % M;
}

//void insertHT(HashTable& ht, int key, int value);
void rehashing(HashTable& ht, int capacity_new)
{
	//tao ban bam moi voi kich thuoc moi
	HashTable ht_new;
	initHT(ht_new, capacity_new);
	//chuyen du lieu tu ht cu sang ht moi
	for (int i = 0; i < ht.size; i++)
	{
		for (Node* p = ht.bucket[i]; p != NULL; p = p->next)
		{
			//lay key va value tu ht cu
			int key = p->key;
			int value = p->value;
			//truyen key-value tu ht cu vao ht moi
			//insertHT(ht_new, key, value);

			int h = Hash(key, ht.size);
			addHead(ht_new.bucket[h], key, value);
			//tang kich thuoc n
			ht_new.n++;
		}
	}

	//giai phong ht cu
	HashTable ht_old = ht;
	ht = ht_new;
	removeAllHT(ht_old);
}
//them phan tu
void insertHT(HashTable& ht, int key, int value)
{
	//bam khoa de xac dinh bucket
	int h = Hash(key, ht.size);
	//chen khoa tai bucket da xac dinh
	//kiem tra khoa co ton tai hay khong
	Node* p = searchList(ht.bucket[h], key);
	if (p != NULL)
	{
		printf("Da ton tai khoa %d!\n", key);
	}
	else
	{
		//gia su chon theo cach them dau
		addHead(ht.bucket[h], key, value);
		//tang kich thuoc n
		ht.n++;
	}

	//kiem tra chi so tai tren bang bam
	double loadFactor = ht.n * 1.0 / ht.size;
	if (loadFactor > DEAULT_LOAD_FACTOR)
	{
		//THUC HIEN BAM LAI VOI KICH THUOC MOI
		rehashing(ht, ht.size * 2);
	}
}
void traverseHT(HashTable ht)
{
	for (int i = 0; i < ht.size; i++)
	{
		printf("bucket[%d]: ", i);
		traverseList(ht.bucket[i]);
	}
}

struct Node* searchHT(HashTable ht, int key)
{
	int h = Hash(key, ht.size);
	return searchList(ht.bucket[h], key);
}
void removeHT(HashTable& ht, int key)
{
	int h = Hash(key, ht.size);
	removeNode(ht.bucket[h], key);
	ht.n--; //gia su xoa thanh cong
}
void pressAnyKey() {
	cout << "\n\nBam phim bat ky de tiep tuc...";
	_getch();
	system("cls");
}

void themmotphantu(HashTable ht) {
	int n;
	cout << "Nhap mot phan tu x moi de them vao: ";
	cin >> n;
	insertHT(ht, n, n);

}




int main()
{
	int key;
	HashTable ht;
	initHT(ht, 17);
	while (true) {
		cout << "CHUONG TRINH QUAN LY CMND/CCCD C/C++\n";
		cout << "*************************MENU**************************\n";
		cout << "**  1. Xuat cac gia tri trong Hash                   **\n";
		cout << "**  2. Them mot phan tu                              **\n";
		cout << "**  3. Kiem tra phan tu.                             **\n";
		cout << "**  4. Tang kich thuoc bang                          **\n";
		cout << "**  5. Xoa phan tu so chan                           **\n";
		cout << "**  0. Thoat                                         **\n";
		cout << "*******************************************************\n";
		cout << "Nhap tuy chon: ";
		cin >> key;
		switch (key) {
		case 1:
			cout << "\nXuat cac gia tri trong Hash: ";
			traverseHT(ht);
			pressAnyKey();
			break;
		case 2:
			cout << "\nThem mot phan tu x .";
			themmotphantu(ht);
			pressAnyKey();
			break;
		case 3:
			int x;
			cout << "\n Nhap vao phan tu x de kiem tra: ";
			cin >> x;
			if (searchHT(ht, x) != NULL) {
				cout << "Phan tu co ton tai trong bang !";
			}
			else {
				cout << "Phan tu khong ton tai trong bang !";
			}


			pressAnyKey();
			break;
		case 4:
			cout << "\n Tang kich thuoc cua bang bam len 3 hien tai: ";
			rehashing(ht, ht.size * 3);
			cout << "Da tang kich thuoc mang ";
			pressAnyKey();
			break;
		case 5:
			cout << "\nXoa tat cac cac phan tu la so chan trong bang: ";
			for (int i = 0; i < ht.size; i++)
			{
				printf("bucket[%d]: ", i);
				Node* p = ht.bucket[i];
				while (p != NULL)
				{
					if (p->key % 2 == 0) {
						printf("\n<%d: %d> ", p->key, p->value);
						removeHT(ht, p->key);
						cout << "Da xoa du lieu ! " << endl;
					}
					p = p->next;
				}
				printf("\n");
			}
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
	system("pause");
}