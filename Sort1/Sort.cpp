// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Họ và tên: Nguyễn Phúc Tiền
MSSV: 20110573
Ngày cập nhật cuối: Sep 09, 2021
Công dụng: Cài đặt SelectionSort, InsertSort, BubbleSort, MergerSort, QuickSort
*/

#include <iostream>
#include <time.h>
#include<string>
#include <cstdlib>

#define MAX 100

using namespace std;

void merge(int data[], int l, int m, int r)
{  
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* Tạo các mảng tạm */
    int *L = new int[n1];
    int *R = new int[n2];

    /* Copy dữ liệu sang các mảng tạm */
    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1 + j];

    /* Gộp hai mảng tạm vừa rồi vào mảng data*/
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy các phần tử còn lại của mảng L vào arr nếu có */
    while (i < n1)
    {
        data[k] = L[i];
        i++;
        k++;
    }

    /* Copy các phần tử còn lại của mảng R vào arr nếu có */
    while (j < n2)
    {
        data[k] = R[j];
        j++;
        k++;
    }
}

/* l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp */
void mergeSort(int data[], int l, int r)
{
    if (l < r)
    {
        // Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
        int m = l + (r - l) / 2;

        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        mergeSort(data, l, m);
        mergeSort(data, m + 1, r);

        merge(data, l, m, r);
    }
}


void showMenu() {
    cout << "=========Meunu========" << endl;
    cout << "a. Tao ngau nhien day so gom n so" << endl;
    cout << "b. In day so" << endl;
    cout << "c. Selection Sort" << endl;
    cout << "d. Insertion Sort" << endl;
    cout << "e. Bubble Sort" << endl;
    cout << "f. Merger Sort" << endl;
    cout << "g. Quick Sort" << endl;
    cout << "h. Exit" << endl;
    cout << "======================" << endl;


}
void QuickSort(int data[], int left, int right) {
    int i = left, j = right;
    int mid = (left + right) / 2;
    int pivot = data[mid];
    
    while (i < j) {
        while (data[i] < pivot) i++;
        while (data[j] > pivot)  j++;
        if (i <= j) {
            swap(data[i], data[j]);
            i++;
            j++;
        }
    }
    if (left < j)   QuickSort(data, left, j);
    if (right > i)   QuickSort(data, i, right);
}
void InsertionSort(int data[], int n) {
    for (int i = 1; i < n; i++) {      
        int j = i;
        while (j > 0 && data[i] < data[j - 1]) --j;

        int tmp = data[i];
        for (int k = i; k > j; k--)
            data[k] = data[k - 1];
        data[j] = tmp;
    }

}
void BubbleSort(int data[], int n) {

    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n - 1; j++) {
            if (data[j] > data[j + 1]) {
                flag = true;
                swap(data[j], data[j + 1]);
            }
        }
        if (!flag)  break;
    }           
    /*for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }*/
}
void SelectionSort(int data[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (data[j] < data[min_idx])
                min_idx = j;
        swap(data[min_idx], data[i]);
    }
}

void createArr(int data[], int n) {
    for (int i = 0; i < n; i++) {
        data[i] = -50 + rand() %(50+1+50);
    }
}



int main()
{   // Tao ma tran ngau nhien
    srand(time(0));
    int numberOfArray = rand() % 10;
    int *arr= new int[numberOfArray];
    for (int i = 0; i < numberOfArray; i++) {
        arr[i] = rand() % 100;

    }
    char option;
    do {
        showMenu();
        cout << "Option: ";
        cin >> option;
        system("cls");
        switch (option)
        {
        case 'a':
            int n; 
            cout << "Nhap so n cho day: ";
            cin >> n;
            numberOfArray = n;
            createArr(arr, numberOfArray);
            break;
        case 'b':
                for (int i = 0; i < numberOfArray; i++) {
                    cout << arr[i] << " ";
                }
            cout << endl;
            break;
        case 'c': 
            SelectionSort(arr, n);
            for (int i = 0; i < numberOfArray; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 'd': 
            InsertionSort(arr, numberOfArray);
            for (int i = 0; i < numberOfArray; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
       
        case 'e': 
            BubbleSort(arr, numberOfArray);
            for (int i = 0; i < numberOfArray; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 'f': 
            mergeSort(arr, 0, numberOfArray);
            for (int i = 0; i < numberOfArray; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 'g':
            mergeSort(arr, 0, numberOfArray);
            for (int i = 0; i < numberOfArray; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
    } while (option != 'h');
    delete[] arr;
    
    system("pause>0");
}
