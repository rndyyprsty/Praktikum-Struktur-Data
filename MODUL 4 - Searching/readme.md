# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

Algoritma Pencarian dalam C++ adalah serangkaian langkah atau prosedur yang dirancang untuk mencari keberadaan data tertentu dalam struktur data, seperti array, vektor, atau struktur data lainnya. Algoritma ini akan menerima sebuah argumen kunci dan langkah-langkah tertentu untuk mencari data yang disimpan dengan kunci tersebut. Proses pencarian dilakukan dengan langkah-langkah tertentu yang dapat bervariasi tergantung pada jenis algoritma yang digunakan, misalnya pencarian linear atau pencarian biner. Selama proses pencarian berlangsung, algoritma akan memeriksa setiap elemen dalam struktur data untuk menentukan apakah nilai yang dicari (kunci) ditemukan atau tidak. Setelah proses dilaksanakan, kemungkinannya adalah data ditemukan atau tidak ditemukan[1].

## Jenis-Jenis Algoritma Searching

### 1. Sequential Search

Sequential Search adalah proses membandingkan setiap elemen array satu persatu secara beruntun dimulai dari elemen pertama hingga elemen yang dicari ditemukan atau hingga elemen terakhir dari array[2]. Metode Sequential Search atau disebut pencarian beruntun dapat digunakan untuk melakukan pencarian data baik pada array yang sudah terurut maupun yang belum terurut. Proses pencarian data dilakukan dengan mencocokkan data yang dilakukan secara berurut satu demi satu dimulai dari data ke-1 hingga data pada urutan terakhir.
Jika data yang dicari mempunyai nilai yang sama dengan data yang ada dalam kelompok data, berarti data telah ditemukan. Jika data yang dicari tidak ada yang cocok dengan data dalam sekelompok data, data tersebut tidak ada dalam sekelompok data[3].

#### Contoh:

```C++ 
#include<iostream.h>
#include<conio.h>
main()
{
int arr1[5];
int req;
int location=-5;
cout<<"Enter 5 numbers to store in array: "<<endl;
for(int i=0; i<5; i++)
{
cin>>arr1[i];
}
cout<<endl;
cout<<"Enter the number you want to find :";
cin>>req;
cout<<endl;
 
for(int w=0;w<5;w++)
{
if(arr1[w] == req)
location=w;
}
if(location !=-5)
{
cout<<"Required number is found out at the location:"<<location+1;
cout<<endl;
}
else
cout<<"Number is not found ";
getch();
}
```

### 2. Binary Search

Algoritma binary search merupakan sebuah teknik pencarian data dengan cara berulang kali membagi separuh dari jumlah data yang dicari sehingga memperkecil lokasi pencarian sampai menjadi satu data[4]. Dengan  teknik  ini  data  akan  dibuang  setengah  dari jumlah   data.   Apabila   ditemukan   kecocokan   data maka   program   akan   mengembalikan   output,   jika tidak  pencarian  akan  terus  berlanjut  hingga  akhir dari  pembagian  jumlah  data  tersebut[5]. Dua  kemungkinan  yang  akan terjadi  yaitu  data  yang  dicari  ditemukan  atau  data tersebut   tidak   ditemukan[6].

#### Contoh:

```C++
#include<iostream.h>
#include<conio.h>
main()
{
 
int abb[4];
int r;
int initial=0;
int final=4;
int mid;
int location=-5;
cout<<"Enter 5 numbers to store in array: "<<endl;
 
for(int i=0; i<5; i++)
{
cin>>abb[i];
}
cout<<endl;
cout<<"Enter the number you want to found :";
cin>>r;
cout<<endl;
 
while(initial<=final)
{
mid= (initial+final)/2;
 
if(abb[mid]==r)
{
location=mid;
break;
}
if(r<abb[mid])
final=mid-1;
 
if(r>abb[mid])
initial=mid+1;
}
if(location==-5)
cout<<" Required number not found "<<endl;
else
cout<<" Required number is found at index "<<location<<endl;
 
getch();
}
```

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>
using namespace std;
int main(){
 int n = 10;
 int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
 int cari = 10;
 bool ketemu = false;
 int i;
 // algoritma Sequential Search
 for (i = 0; i < n; i++){
 if(data[i] == cari){
 ketemu = true;
 break;
 }
 }
 cout << "\t Program Sequential Search Sederhana\n" << endl;
 cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}"<< endl;
 if (ketemu){
 cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
 } else {
 cout << cari << " tidak dapat ditemukan pada data." << endl;
 }
 return 0;
}
```

Program ini adalah sebuah contoh sederhana dari algoritma pencarian berurutan (sequential search). Tujuan program ini adalah untuk mencari sebuah angka tertentu dalam sebuah array data. Array tersebut diinisialisasi dengan nilai-nilai tertentu, dan kemudian dilakukan pencarian terhadap angka yang ditentukan. Algoritma pencarian yang digunakan adalah sequential search, yang artinya program akan menelusuri setiap elemen dalam array data satu per satu, mulai dari awal hingga akhir, untuk mencari angka yang dicari. Jika angka tersebut ditemukan, program akan memberitahu pengguna indeks dimana angka tersebut ditemukan. Jika tidak ditemukan, program akan memberitahu bahwa angka tersebut tidak ada dalam data. Setelah pencarian selesai, program mencetak hasil pencarian ke layar.

berikut output daripada program diatas:
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/e4726a07-9ad2-46de-a7a0-896810dfb43b)

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
#include <iostream>
using namespace std;
#include <conio.h>
#include <iomanip>

int data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort()
{
    int temp, min, i, j;
    for(i=0; i<7;i++)
    {
        min = i;
        for(j = i+1; j<7; j++)
        {
            if(data[j]<data[min])
            {
                min=j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch()
{
    //searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal<=akhir)
    {
        tengah = (awal + akhir)/2;
        if(data[tengah] == cari)
        {
            b_flag = 1;
            break;
        }
        else if(data[tengah]<cari)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah -1;
        }
    }
    if(b_flag == 1)
    {
        cout<<"\n Data ditemukan pada index ke- "<<tengah<<endl;
    }
    else
    {
        cout<<"\n Data tidak ditemukan\n";
    }
}

int main()
{
    cout<<"\t BINARY SEARCH "<<endl;
    cout<<"\n Data : ";
    //tampilkan data awal
    for(int x = 0; x<7; x++)
    {
        cout<<setw(3)<<data[x];
    }
    cout<<endl;
    cout<<"\n Masukkan data yang ingin Anda cari : ";
    cin>>cari;
    cout<<"\n Data diurutkan : ";
    //urutkan data dengan selection sort
    selection_sort();
    //tampilkan data setelah diurutkan
    for(int x = 0; x<7;x++)
    {
        cout<<setw(3)<<data[x];
    }
    cout<<endl;
    binarysearch();
    _getche();
    return EXIT_SUCCESS;
}
```
Program ini adalah contoh implementasi algoritma pencarian binary search. Tujuan dari program ini adalah untuk mencari sebuah angka tertentu dalam array data menggunakan binary search. Pertama, program meminta pengguna untuk memasukkan angka yang ingin dicari. Kemudian, program mengurutkan array data menggunakan algoritma selection sort. Setelah itu, program melakukan pencarian menggunakan algoritma binary search.
Algoritma binary search bekerja dengan membagi array menjadi dua bagian dan memeriksa apakah nilai yang dicari berada di bagian kiri atau kanan. Proses ini terus berlanjut hingga nilai yang dicari ditemukan atau hanya ada satu elemen yang tersisa.
Setelah pencarian selesai, program mencetak hasil pencarian ke layar.

Berikut outputnya :
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/e76bfd2c-6958-4ffc-8f8a-402e1edd2f75)


## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// melakukan binary search pada string
bool binarySearch(const string &str, char target) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (str[mid] == target)
            return true;
        else if (str[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return false;
}

int main() {
    string sentence = "ayam geprek enak.";
    cout << "Kalimatnya: " << sentence << endl;
    char searchChar;
    
    // Mengurutkan kalimat
    sort(sentence.begin(), sentence.end());
    
    // Mencari huruf
    cout << "Cari huruf: ";
    cin >> searchChar;
    
    bool found = binarySearch(sentence, searchChar);
    
    if (found)
        cout << "Huruf ada." << endl;
    else
        cout << "Huruf tidak ada." << endl;
    
    return 0;
}
```
#### Output
![Screenshot 2024-04-28 153117](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/7aa3b21b-6dd3-4888-be52-9700939e206b)

#### Penjelasan program:
Program ini menyatakan kalimat dan ditaruh dalam var sentence. Fungsi sort akan mengurutkan huruf-huruf di kalimat kemudian binary search akan dilakukan sesuai dengan inputan user. Jika huruf yang dicari ditemukan maupun tidak ditemukan, hasilnya akan ditampilkan pada output sesuai perbandingan tadi.

Karena program ini memakai algoritma binary search maka kompleksitas waktunya adalah 0(log n). n adalah jumlah elemen dalam data yang diurutkan.

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream>
#include <string>

using namespace std;

int hitungVokal(const string &kalimat) {
    int jumlahVokal = 0;
    for (char ch : kalimat) {
        // Atur huruf jadi lowercase
        char lowercaseCh = tolower(ch);
        // Mengecek huruf vokal
        if (lowercaseCh == 'a' || lowercaseCh == 'e' || lowercaseCh == 'i' || lowercaseCh == 'o' || lowercaseCh == 'u') {
            jumlahVokal++;
        }
    }
    return jumlahVokal;
}

int main() {
    string kalimat = "ayo main star rail.";
    cout << "Kalimatnya: " << kalimat << endl;
    
    int jumlahVokal = hitungVokal(kalimat);
    
    cout << "jumlah huruf vocal ada: " << jumlahVokal << endl;
    
    return 0;
}
```
#### Output
![Screenshot 2024-04-28 152950](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/91482178-fa57-4470-9df9-5b8743ba2a7d)

#### Penjelasan Program
Program ini menyatakan kalimat dan menaruhnya dalam var kalimat. Kemudian hitungVokal akan menghitung jumlah huruf vokalnya dengan mengiterasi setiap huruf pada kalimat. Sebelum itu, setiap huruf diubah menjadi lowercase agar mengurangi kemungkinan salah hitung. Jika huruf teruji sebagai huruf vokal maka var jumlahVokal akan mencatat jumlahnya. Ketika iterasi selesai, program akan mengembalikan jumlah huruf vokal ke jumlahVokal dan hasilnya akan ditampilkan pada output.

Karena program hanya melakukan satu iterasi untuk menghitung jumlah huruf vokal, maka kompleksitas waktunya adalah 0(n). n adalah jumlah huruf dalam kalimat.

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>
#include <vector>

using namespace std;

int hitungEmpat(const vector<int> &data) {
    int hitung = 0;
    for (int num : data) {
        if (num == 4) {
            hitung++;
        }
    }
    return hitung;
}

int main() {
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    
    int jumlahEmpat = hitungEmpat(data);
    
    cout << "Jumlah angka 4 ada: " << jumlahEmpat << endl;
    
    return 0;
}
```
### Output
![Screenshot 2024-04-28 153446](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/a708795b-6735-4862-b2ca-33408d2ef7d9)

### Penjelasan Program:

Program ini membuat vector yang berisi data dari soal. Kemudian fungsi hitungEmpat akan mengiterasi setiap elemen vektor untuk menemukan angka 4, jika ditemukan maka var hitung akan bertambah satu sebanyak 4 yang ditemukan. Setelah itu jumlah total kemunculan akan dikembalikan pada var hitung dan hasilnya akan di tampilkan pada output

Karena program ini menggunakan sequential search maka kompleksitas waktunya adalah 0(n). n adalah jumlah elemen dalam vektor.
 
## Kesimpulan
Algoritma searching memiliki tujuan mencari letak keberadaan elemen tertentu dalam dataset. Algoritma pencarian digunakan secara luas dalam berbagai bidang dan memiliki keunggulan dalam mencari informasi di dataset yang besar. Namun dibalik keunggulannya, ada keterbatasan dimana kinerjanya mungkin menurun jika dataset tidak terurut dengan baik sehingga akan sulit untuk menemukan informasi yang diinginkan terutama pada dataset yang rumit.

## Referensi
[1] Purnamasari, K. Kinanti. (2011). "Algoritma Pencarian (Searching Algorithm)". Diakses pada 5 April 2024, dari https://repository.unikom.ac.id/37438/1/10.%20Pencarian.pdf

[2] Sitorus, L. (2015). “Algoritma dan Pemrograman”. Andi, Yogyakarta

[3] Sonita, A. & Sari, M. (2018). Implementasi Algoritma Sequential Searching untuk Pencarian Nomor Surat Pada Sistem Arsip Elektronik. Jurnal Pseudocode, 05(01), 1-9.

[4] Darmawantoro, R. Y., Utami, Y. R. W., & Kustanto, K. (2022). Implementasi Binary Search Untuk Data Obat di Apotek. Jurnal Teknologi Informasi Dan Komunikasi (TIKomSiN), 10(1).

[5] Tobing, F. A. T., & Nainggolan, R. (2021). Analisis Perbandingan   Penggunaan   Metode   Binary Search  Dengan  Regular  Search  Expression. METHOMIKA Jurnal Manajemen Informatika   Dan   Komputerisasi   Akuntansi, 4(2), 168–172.

[6] Wijaya,  A.,  Maulana,  M.  F.,  &  Danil,  M.  (2021). Aplikasi   Pencarian   Resep   Masakan   Khas Bengkulu   Menggunakan   Algoritma   Binary Search  BerbasisAndroid. JURNAL  MEDIAINFOTAMA, 17(1).