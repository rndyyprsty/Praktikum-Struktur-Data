# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

Algoritma sorting adalah suatu metode atau teknik untuk mengurutkan data atau elemen-elemen dalam suatu struktur data secara teratur. Algoritma sorting merupakan salah satu konsep penting dalam pemrograman, tujuannya untuk mengubah data yang tidak teratur menjadi urutan yang teratur, misalnya dari data yang tidak terurut menjadi data yang terurut menaik atau menurun[1].

## Jenis-Jenis Algoritma Sorting

### 1. Insertion Sort

Insertion Sort adalah adalah sebuah algoritma pengurutan yang membandingkan dua elemen data pertama, mengurutkannya, kemudian mengecek elemen data berikutnya satu persatu dan membandingkannya dengan elemen data elemen, menemukan yang terkecil atau yang terbesar sesuai yang telah diurutkan. Algoritma pengurutan data insertion sort akan memeriksa setiap kebutuhan jenis pengurutan, dan menyisipkan dalam tempat yang tepa[2].

#### Contoh:

```C++ 
#include <bits/stdc++.h>
using namespace std;
 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, N);
    printArray(arr, N);
 
    return 0;
}
```

### 2. Bubble Sort

Bubble sort merupakan sebuah teknik pengurutan data dengan cara menukar dua data yang bersebelahan jika urutan dari data tersebut salah. Algorithma ini dapat mengurutkan data dari besar ke kecil (Ascending) dan kecil ke besar (Descending). Algoritma ini tidak cocok untuk set data dengan jumlah besar karena kompleksitas dari algorithma ini adalah Ο() di mana n adalah jumlah item.[3].

#### Contoh:

```C++
#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {

  for (int step = 0; step < size; ++step) {
      
    for (int i = 0; i < size - step; ++i) {

      if (array[i] > array[i + 1]) {

        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};

  int size = sizeof(data) / sizeof(data[0]);
  
  bubbleSort(data, size);
  
  cout << "Sorted Array in Ascending Order:\n";  
  printArray(data, size);
}
```

### 3. Selection Sort

Selection sort adalah suatu metode pengurutan data dengan cara memilih suatu data pada urutan tertentu, kemudian membandingkannya dengan data-data lainnya mulai dari posisi [posisi data+1] sampai dgn data pada posisi ke-n, untuk mencari data terkecil pada rentang posisi tersebut. Jika data terkecil ditemukan, maka pindahkan data terkecil tersebut ke posisi [posisi data], dan data yang semula berada di posisi[posisi data] dipindahkan ke posisi dimana data terkecil tadi ditemukan. Demikian seterusnya hingga data terakhir[4].

#### Contoh

```C++
#include<iostream>  
using namespace std;  
int findSmallest (int[],int);  
int main ()  
{  
    int myarray[10] = {11,5,2,20,42,53,23,34,101,22};  
    int pos,temp,pass=0;  
    cout<<"\n Input list of elements to be Sorted\n";  
    for(int i=0;i<10;i++)  
    {  
        cout<<myarray[i]<<"\t";  
    } 
    for(int i=0;i<10;i++)  
    {  
        pos = findSmallest (myarray,i);  
        temp = myarray[i];  
        myarray[i]=myarray[pos];  
        myarray[pos] = temp; 
        pass++;
    }  
    cout<<"\n Sorted list of elements is\n";  
    for(int i=0;i<10;i++)  
    {  
        cout<<myarray[i]<<"\t";  
    } 
    cout<<"\nNumber of passes required to sort the array: "<<pass;
    return 0;  
}  
int findSmallest(int myarray[],int i)  
{  
    int ele_small,position,j;  
    ele_small = myarray[i];  
    position = i;  
    for(j=i+1;j<10;j++)  
    {  
        if(myarray[j]<ele_small)  
        {  
            ele_small = myarray[j];  
            position=j;  
        }  
    }  
    return position;  
}
```

## Guided 

### Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length){
    
    for (int i=0; i<length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){

    int length = 5;
    double a[] = {22,1,15,3,8,2,33,21,99,99};

    cout << "urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Program ini bertugas mengurutkan array dari nilai terkecil ke terbesar. Pertama, program mencetak array sebelum diurutkan. Kemudian, algoritma bubble sort dijalankan untuk mengurutkan array tersebut. Setelah itu, program mencetak array setelah diurutkan.

### Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length){
    int i,j;
    char tmp;

    for (i = 1; i < length; i++){
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]){
            tmp = arr[j];
            arr[j] = arr [j - 1];
            arr[j - 1] = tmp;
            j--;
        }//end of while loop
    }//end of for loop
}

void print_array(char a[], int length){
    for(int i=0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int length = 6;
    char a[length] = {'c','f','a','z','d','p'};
    
    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas menggunakan algoritma insertion sort untuk mengurutkan array karakter dari besar ke kecil. Pertama, program mencetak array sebelum diurutkan. Kemudian, algoritma insertion sort dijalankan untuk mengurutkan array tersebut. Setelah itu, program mencetak array setelah diurutkan.

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerimalembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! 

```C++
#include <iostream>

void selectionSort(double arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        double temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    double IPS[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    int n = sizeof(IPS) / sizeof(IPS[0]);

    selectionSort(IPS, n);

    std::cout << "\nNilai setelah diurutkan:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Mahasiswa " << i + 1 << ": " << IPS[i] << std::endl;
    }

    return 0;
}
```
#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/39dba41e-1852-4898-90b4-4ec0a149b6e7)

#### Penjelasan program:

Program ini terdiri dari dua fungsi utama, yaitu selectionSort untuk melakukan pengurutan dan main sebagai awal program.Nilai-nilai IPS mahasiswa disimpan dalam array, kemudian nilai-nilai yang ada itu akan ditampilkan sebelum diurutkan. Kemudian program akan mengurutkan nilai-nilai itu dari yang tertinggi ke yang terendah menggunakan algoritma selection dan hasilnya akan ditampilkan.

Kompleksitas waktu algoritma itu adalah O(n^2), di mana "n" adalah jumlah mahasiswa. Ini karena ada dua perulangan bersarang dalam algoritma tersebut. Perulangan pertama digunakan untuk memilih elemen terbesar pada setiap iterasi, sementara perulangan kedua digunakan untuk melakukan pertukaran nilai. Seiring dengan peningkatan jumlah mahasiswa, waktu eksekusi algoritma Selection Sort akan meningkat secara kuadratik, yang berarti semakin banyak mahasiswa akan memperpanjang waktu eksekusi program secara signifikan.

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama-nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    string names[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    int n = sizeof(names) / sizeof(names[0]);

    bubbleSort(names, n);

    cout << "Nama setelah diurutkan:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << names[i] << " ";
    }
    cout << endl;

    return 0;
}
```
#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/8b6a5af1-f53a-4673-a4fd-037ec4ef94b3)

#### Penjelasan Program
Program pertama-tama mendefinisikan fungsi bubbleSort yang menggunakan nested loop untuk membandingkan nama-nama dalam array dan menukar posisi jika diperlukan agar sesuai dengan alfabet. Selanjutnya, di dalam fungsi main, array names yang berisi nama-nama dimasukkan ke dalam algoritma Bubble Sort. Setelah diurutkan, program akan menampilkan hasilnya dengan nama yang telah terurut.

Kompleksitas waktu algoritma itu adalah O(n^2), di mana 'n' adalah jumlah elemen dalam array. Hal ini disebabkan oleh adanya dua loop bersarang yang digunakan untuk membandingkan dan menukar setiap elemen dalam array. Pada setiap iterasi dari loop luar, loop dalam harus melintasi array secara penuh. Jadi, jika terdapat 'n' elemen dalam array, akan ada sekitar 'n^2/2' operasi perbandingan dan penukaran yang dilakukan oleh algoritma ini.

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/14514520-9ca8-4cef-93c0-35172d649a95)

```C++
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter: ";
    cin >> n;
    
    char karakter[n];
    
    cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; ++i) {
        cin >> karakter[i];
    }
    
    sort(karakter, karakter + n);
    
    cout << "Sorting Ascending: ";
    for (int i = 0; i < n; ++i) {
        cout << karakter[i] << " ";
    }
    cout << endl;
    
    sort(karakter, karakter + n, greater<char>());
    
    cout << "Sorting Descending: ";
    for (int i = 0; i < n; ++i) {
        cout << karakter[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```
### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/18679e51-f17b-4a60-9cc8-c0111537b08f)

### Penjelasan Program:

Program ini meminta pengguna untuk memasukkan jumlah karakter yang diinginkan, lalu meminta karakter-karakter itu dimasukkan. Setelah itu, program akan melakukan sorting secara naik dan turun menggunakan fungsi `sort()`, dan menampilkan hasilnya.

Kompleksitas waktu dari program adalah O(n log n) atau logaritmik, di mana 'n' adalah jumlah karakter yang dimasukkan pengguna. Hal ini disebabkan oleh kompleksitas waktu pengurutan menggunakan `std::sort`, yang dominan dalam penentuan kompleksitas keseluruhan.

## Kesimpulan
Algoritma sorting adalah metode yang digunakan untuk menyusun data dalam urutan tertentu, seperti dari yang terkecil ke yang terbesar atau sebaliknya. Ada berbagai jenis algoritma sorting, seperti Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, dan Merge Sort. Setiap algoritma memiliki cara kerja yang berbeda-beda serta kelebihan dan kekurangan masing-masing. Pemilihan algoritma sorting yang sesuai harus mempertimbangkan karakteristik data yang akan diurutkan dan kebutuhan aplikasi yang bersangkutan. Misalnya, Quick Sort dan Merge Sort sering diutamakan untuk jumlah data yang besar karena efisiensinya yang tinggi, sementara Bubble Sort dan Selection Sort lebih cocok untuk jumlah data yang kecil atau digunakan sebagai algoritma dasar dalam pembelajaran.

## Referensi
[1] Annisa. (2023, 9 September). Pengertian Algoritma Sorting (Pengurutan) Dalam Pemrograman. Diakses pada 30 Maret 2024, dari https://fikti.umsu.ac.id/pengertian-algoritma-sorting-pengurutan-dalam-pemrograman/ 

[2] Sari, Y.P., Ali, R., & Rajasa, A. (2022). Perbandingan Efisiensi dengan Algoritma Sorting dalam Penentuan Jarak (Studi Kasus: Pet Shop di Bandar Lampung). Jurnal Teknika, 16(01), 149-159.

[3] Tanzil, F. (2019, 26 Desember). Bubble Sort. Diakses pada 30 Maret 2024, dari https://socs.binus.ac.id/2019/12/26/bubble-sort/

[4] Sunandar, E. (2019). Perbandingan Metode Selection Sort dan Insertion Sort dalam Pengurutan Data Menggunakan Bahasa Program Java PETIR: Jurnal Pengkajian dan Penerapan Teknik Informatika, 12(02), 172-178.