# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Muhammad Randy Prasetya</p>

## Dasar Teori

Array merupakan kumpulan dari nilai-nilai data yang bertipe sama dalam urutan tertentu yang menggunakan nama yang sama. Letak atau posisi dari elemen array ditunjukkan oleh suatu index. Dalam bahasa C indeks dimulai dari 0[1].Itu berarti dengan menggunakan array jika kita ingin menyimpan lima nilai bertipe data int kita tidak perlu mendeklarasikan lima variabel yang berbeda dengan tipe data int, kita cukup mendeklarasikan satu variabel array dengan tipe data int. 
Array sendiri terdiri dari beberapa jenis sebagai berikut:

### 1. Array Satu Dimensi

Array satu dimensi adalah jenis array dasar yang terdiri dari beberapa kolom elemen. Dalam satu baris tersusun dari beberapa elemen-elemen yang sama. Keunggulan dari array satu dimensi mudah untuk digunakan dan dibaca sehingga paling umum digunakan. Elemen pertama ditandai dengan indeks 0, elemen keempat di indeks 3, dan seterusnya[2].

#### Contoh:

```C++
#include <iostream>

int main() {
    int angka[5];

    angka[0] = 10;
    angka[1] = 20;
    angka[2] = 30;
    angka[3] = 40;
    angka[4] = 50;

    std::cout << "Nilai array:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Angka[" << i << "] = " << angka[i] << std::endl;
    }

    return 0;
}
```

### 2. Array Dua Dimensi

Array dua dimensi atau sering dikenal sebagai matriks merupakan pengembangan dari array satu dimensi, jika pada array satu dimensi hanya terdiri dari satu baris dan beberapa kolom saja, maka untuk array dua dimensi ini terdiri lebih dari satu (beberapa) baris dan kolom. Dengan demikian array dua dimensi tersusun dalam bentuk kolom serta baris, yang mana indeks pertamanya dinyatakan sebagai baris dan untuk indeks keduanya dinyatakan sebagai kolom[3].

#### Contoh:

```C++
#include <iostream>

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Nilai array:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

### 3. Array Multi Dimensi

Array Multidimensi adalah suatu array yang mempunyai lebih dari satu subskrip. Kata lainnya array yang memiliki lebih dari satu dimensi. Atau kita sebut pula, array di dalam array. Array multidimensi dideklarasikan dengan menambahkan jumlah tanda kurung setelah nama array[4].

#### Contoh

```C++
#include <iostream>

int main() {
    int cube[2][3][4] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };

    std::cout << "Nilai array:\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "Layer " << i+1 << ":\n";
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                std::cout << cube[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
```

## Guided 

### 1. Program Input Array 3 Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
// Deklarasi array
int arr[2][3][3];
// Input elemen
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << "Input Array[" << x << "][" << y << "][" << z <<
"] = ";
cin >> arr[x][y][z];
}
}
cout << endl;
}
// Output Array
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << "Data Array[" << x << "][" << y << "][" << z <<
"] = " << arr[x][y][z] << endl;
}
}
}
cout << endl;
// Tampilan array
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << arr[x][y][z] << ends;
}
cout << endl;
}
cout << endl;
}
}
```
### Output
![Screenshot 2024-03-25 111401](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/f28978c9-9a04-4e1d-b363-090d93920b4f)

### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;
int main()
{
int maks, a, i = 1, lokasi;
cout << "Masukkan panjang array: ";
cin >> a;
int array[a];
cout << "Masukkan " << a << " angka\n";
for (i = 0; i < a; i++)
{
cout << "Array ke-" << (i) << ": ";
cin >> array[i];
}
maks = array[0];
for (i = 0; i < a; i++)
{
if (array[i] > maks)
{
maks = array[i];
lokasi = i;
}
}
cout << "Nilai maksimum adalah " << maks << " berada di Array
ke " << lokasi << endl;
}
```
### Output
![Screenshot 2024-03-25 111519](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/ceb7fa4d-7a15-4f55-a107-acada3bcec72)

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/cafe6a94-d662-45c6-ae28-3ff8b044046b)

```C++
#include <iostream>

using namespace std;

int main() {
    int data[10];
    int input;

    // Memasukkan data
    cout << "Masukkan 10 angka: ";
    for (int i = 0; i < 10; ++i) {
        cin >> input;
        data[i] = input;
    }

    // Menampilkan semua data
    cout << "Data Array = ";
    for (int i = 0; i < 10; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Menampilkan angka genap
    cout << "Nomor genap = ";
    for (int i = 0; i < 10; ++i) {
        if (data[i] % 2 == 0) {
            cout << data[i] << " ";
        }
    }
    cout << endl;

    // Menampilkan angka ganjil
    cout << "Nomor Ganjil = ";
    for (int i = 0; i < 10; ++i) {
        if (data[i] % 2 != 0) {
            cout << data[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
```
#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/13193446-ec27-45a2-afd1-3a7b74f0c567)

#### Penjelasan program:

Program ini meminta user memasukkan sepuluh angka, lalu kemudian akan memisahkan angka genap dan ganjil dari data tersebut. Setelah itu, program ini akan menampilkan hasilnya secara terpisah sesuai format yang diminta. Proses pemisahan ini dilakukan dengan cara membagi angka dengan 2. Jika habis dibagi maka dia akan termasuk genap dan jika tidak habis dibagi maka dia akan dinyatakan ganjil.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

int main() {
    int size1, size2, size3;

    // Input ukuran array
    cout << "Masukkan ukuran array: ";
    cin >> size1 >> size2 >> size3;

    int arr[size1][size2][size3];

    // Input elemen array
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    cout << "Data Array:" << endl;
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << "Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    cout << "Tampilan Array:" << endl;
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/f4c5fb21-3625-44f8-92fc-0658c1803d05)

#### Penjelasan Program
Program tersebut meminta user untuk menginput ukuran array tiga dimensi, kemudian mengisi array tersebut dengan nilai yang diinput oleh user, dan akhirnya menampilkan isi dari array-nya. Program ini menggunakan tiga loop bersarang untuk mengisi elemen-elemen array. Loop-loop ini akan berjalan sejumlah kali sesuai dengan ukuran array yang dimasukkan pengguna.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];

    // Input elemen array
    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Elemen " << i+1 << ": ";
        cin >> arr[i];
    }

    // Menghitung nilai maksimum, minimum, rata-rata
    int max = arr[0];
    int min = arr[0];
    int sum = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        sum += arr[i];
    }
    double average = static_cast<double>(sum) / n;

    cout << "\nNilai maksimum: " << max << endl;
    cout << "Nilai minimum: " << min << endl;
    cout << "Nilai rata-rata: " << average << endl;

    return 0;
}
```
### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/ce51e987-69b8-41f2-a126-150480959a63)

### Penjelasan Program:

Program ini meminta user untuk memasukkan jumlah elemen array dan nilai-nilai elemen array tersebut. Setelah memasukkan nilai-nilai, program akan menghitung nilai maksimum, minimum, dan rata-rata dari array yang dimasukkan. Ini dilakukan dengan menggunakan perulangan untuk membandingkan setiap elemen array dengan nilai maksimum dan minimum yang telah ditentukan, serta menghitung jumlah total elemen untuk kemudian dijadikan rata-rata. Hasil perhitungan tersebut kemudian ditampilkan kepada pengguna melalui output konsol.

## Kesimpulan
Array adalah kumpulan-kumpulan variabel yang menyimpan data dengan tipe yang sama atau data-data yang tersusun secara linear dimana di dalamnya terdapat elemen dengan tipe yang sama. Indeks dalam array menyatakan elemen yang disimpan dan panjang atau length menyatakan total elemen yang tersimpan.
Kelebihan dari array adalah kemampuannya menyimpan beragam data serupa dengan satu variabel dan dapat diakses dengan menggunakan indeksnya.


## Referensi
[1] Ta, Uch. "Pemograman C++ Bab 12 Array", Academia, 2018. https://academia.edu

[2] Maulana, Muhammad. "Array Adalah : Pengertian, Kegunaan, dan Jenisnya", 7 Oktober 2022. https://itbox.id/blog/array-adalah/#:~:text=Array%20satu%20dimensi%20adalah%20jenis,dibaca%20sehingga%20paling%20umum%20digunakan.

[3] Efendi, Yasin. "Buku Ajar Pendidikan Algoritma dan Struktur Data." 2022.

[4] Ridwan, Taufik. "Array Multidimensi", 2019.