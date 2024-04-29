# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

### A. Variabel

Variabel adalah sebuah kotak atau kontainer yang berfungsi untuk menyimpan nilai. Dalam C++, ada berbagai jenis variabel (didefinisikan dengan kata kunci yang berbeda) seperti int, double, char, string dan bool[1]. Tiap jenis variabel memiliki fungsi yang berbeda-beda, berikut beberapa fungsinya:
- int = Variabel ini digunakan untuk menyimpan bilangan bulat.
- double = Variabel ini digunakan untuk menyimpan angka desimal.
- char = Variabel ini digunakan untuk menyimpan karakter tunggal.
- string = Variabel ini digunakan untuk menyimpan kumpulan karakter.
- bool = Variabel ini digunakan untuk menyimpan nilai true or false.

Dalam suatu program C++, setiap variabel yang akan digunakan terlebih dahulu dideklarasikan, dimana setiap variabel harus mempunyai tipe. Deklarasi variabel berguna untuk memberi informasi kepada compiler serta membantu programmer untuk berpikir secara jelas dan terencana[2].

### B. Struct

Struct (struktur) adalah pengelompokkan dari variabel-variabel yang berada dalam satu nama yang sama. Suatu struktur dapat terdiri dari kumpulan variabel-variabel yang berbeda tipenya dalam satu nama tetapi berkaitan. Variabel-variabel yang membentuk suatu struktur ini selanjutnya disebut dengan elemen atau anggota struktur. Dengan demikian suatu struktur dimungkinkan dapat berisi dengan elemen-elemen data bertipe int, float, char dan lainnya. Dengan menggunakan struktur maka data ini dapat diolah per elemen (field) atau secara keseluruhan (per struktur, per-record)[3].

Deklarasi struct sama sekali tidak memakan memori, struct bisa dikatakan hanyalah sebuah rancangan, deklarasi struct dibuat untuk membuat tipe data yang dibuat oleh programmer. Yang memakan memori adalah Object yang didirikan menggunakan data structure sebagai tipe datanya. Jumlah memori dari object akan memiliki besar dari total besar memori member yang ada pada struct tersebut[4].

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>
#include <string>
using namespace std;

// Deklarasi struct
struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    float harga_buku;
};

int main() {
    // Membuat objek
    Buku buku1;

    // Isi nilai ke objek
    buku1.judul_buku = "A Study in Scarlet";
    buku1.pengarang = "Sir Arthur Conan Doyle";
    buku1.penerbit = "Ward, Lock & Co";
    buku1.tebal_halaman = 192;
    buku1.harga_buku = 2.99$;

    // Menampilkan informasi
    cout << "Judul Buku: " << buku1.judul_buku << endl;
    cout << "Pengarang: " << buku1.pengarang << endl;
    cout << "Penerbit: " << buku1.penerbit << endl;
    cout << "Tebal Halaman: " << buku1.tebal_halaman << endl;
    cout << "Harga Buku: $" << buku1.harga_buku << endl;

    return 0;
}
```
Kode di atas adalah contoh implementasi struktur dalam C++. Struktur yang didefinisikan disebut Buku dan memiliki lima atribut: judul_buku, pengarang, penerbit, tebal_halaman, dan harga_buku. Selanjutnya, dalam fungsi main(), kita membuat sebuah objek dari struktur Buku dengan nama buku1. Kemudian, nilai-nilai untuk setiap atribut dalam objek tersebut diatur. Setelah mengatur nilai, kita menggunakan perintah cout untuk mencetak informasi buku ke layar, termasuk judul, pengarang, penerbit, tebal halaman, dan harga.

berikut output daripada program diatas:

![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/2d1077d5-a40b-4931-b157-f2033ed7685d)

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.

![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/5d0f9b59-c151-417a-9b4a-14a05697f8f1)

```C++
#include <iostream>
#include <string>
using namespace std;

struct HewanDarat {
    int Jumlah_Kaki;
    bool Apakah_menyusui;
    string Suara;
};

struct HewanLaut {
    string Bentuk_sirip;
    string Bentuk_pertahanan_diri;
};

struct Hewan {
    string Nama_hewan;
    string Jenis_kelamin;
    string Cara_berkembangbiak;
    string Alat_pernafasan;
    string Tempat_hidup;
    bool Apakah_Karnivora;
    HewanDarat darat_detail;
    HewanLaut laut_detail;
};

int main() {
    // Objek hewan darat
    Hewan hewan_darat;
    hewan_darat.Nama_hewan = "Lynx";
    hewan_darat.Jenis_kelamin = "Betina";
    hewan_darat.Cara_berkembangbiak = "Melahirkan";
    hewan_darat.Alat_pernafasan = "Paru-paru";
    hewan_darat.Tempat_hidup = "Hutan";
    hewan_darat.Apakah_Karnivora = true;
    hewan_darat.darat_detail.Jumlah_Kaki = 4;
    hewan_darat.darat_detail.Apakah_menyusui = true;
    hewan_darat.darat_detail.Suara = "Roar";

    // Objek hewan laut
    Hewan hewan_laut;
    hewan_laut.Nama_hewan = "Hiu BaNtEnG";
    hewan_laut.Jenis_kelamin = "Jantan";
    hewan_laut.Cara_berkembangbiak = "Bertelur";
    hewan_laut.Alat_pernafasan = "Insang";
    hewan_laut.Tempat_hidup = "Laut";
    hewan_laut.Apakah_Karnivora = true;
    hewan_laut.laut_detail.Bentuk_sirip = "Berkurang";
    hewan_laut.laut_detail.Bentuk_pertahanan_diri = "Sirip ekor panjang";

    // Tampil hasil
    cout << "Informasi Hewan Darat:" << endl;
    cout << "Nama: " << hewan_darat.Nama_hewan << endl;
    cout << "Jenis Kelamin: " << hewan_darat.Jenis_kelamin << endl;
    cout << "Cara Berkembangbiak: " << hewan_darat.Cara_berkembangbiak << endl;
    cout << "Alat Pernafasan: " << hewan_darat.Alat_pernafasan << endl;
    cout << "Tempat Hidup: " << hewan_darat.Tempat_hidup << endl;
    cout << "Apakah Karnivora: " << (hewan_darat.Apakah_Karnivora ? "Ya" : "Tidak") << endl;
    cout << "Jumlah Kaki: " << hewan_darat.darat_detail.Jumlah_Kaki << endl;
    cout << "Apakah Menyusui: " << (hewan_darat.darat_detail.Apakah_menyusui ? "Ya" : "Tidak") << endl;
    cout << "Suara: " << hewan_darat.darat_detail.Suara << endl;

    cout << "\nInformasi Hewan Laut:" << endl;
    cout << "Nama: " << hewan_laut.Nama_hewan << endl;
    cout << "Jenis Kelamin: " << hewan_laut.Jenis_kelamin << endl;
    cout << "Cara Berkembangbiak: " << hewan_laut.Cara_berkembangbiak << endl;
    cout << "Alat Pernafasan: " << hewan_laut.Alat_pernafasan << endl;
    cout << "Tempat Hidup: " << hewan_laut.Tempat_hidup << endl;
    cout << "Apakah Karnivora: " << (hewan_laut.Apakah_Karnivora ? "Ya" : "Tidak") << endl;
    cout << "Bentuk Sirip: " << hewan_laut.laut_detail.Bentuk_sirip << endl;
    cout << "Bentuk Pertahanan Diri: " << hewan_laut.laut_detail.Bentuk_pertahanan_diri << endl;

    return 0;
}
```
Program ini menyimpan informasi hewan darat dan hewan laut. Untuk setiap jenis hewan ada atribut-atribut seperti nama hewan, jenis kelamin, cara berkembangbiak, alat pernafasan, tempat hidup, karnivora atau tidak, dan beberapa detail khusus. Dua struct HewanDarat dan HewanLaut dibuat terpisah. Kemudian struktur Hewan dengan sub darat_detail dan laut_detail, menyimpan detail khusus dari hewan darat dan laut. Dua objek Hewan dibuat untuk masing-masing jenisnya. Setiap objek diisi dengan informasi spesifik sesuai jenis hewannya. Lalu hasilnya ditampilkan dengan perintah cout.

Berikut outputnya :

![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/ace0894d-e7f2-4029-ab60-e26520590ca9)

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan

```C++
#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    float harga_buku[5];
};

int main() {
    // objek buku
    Buku buku;

    // Mengisi data
    buku.judul_buku[0] = "Tokyo dan Perayaan Kesedihan";
    buku.pengarang[0] = "Ruth Priscilla Angelina";
    buku.penerbit[0] = "Gramedia Pustaka Utama";
    buku.tebal_halaman[0] = 192;
    buku.harga_buku[0] = 4.99;

    buku.judul_buku[1] = "Fantastic Beasts and Where to Find Them";
    buku.pengarang[1] = "J.K. Rowling";
    buku.penerbit[1] = "Bloomsbury.";
    buku.tebal_halaman[1] = 128;
    buku.harga_buku[1] = 11.26;

    buku.judul_buku[2] = "A Certain Magical Index: The Old Testament";
    buku.pengarang[2] = "Kazuma Kamachi";
    buku.penerbit[2] = "Yen On";
    buku.tebal_halaman[2] = 1664;
    buku.harga_buku[2] = 139.30;

    buku.judul_buku[3] = "The Return of the King";
    buku.pengarang[3] = "J.R.R Tolkien";
    buku.penerbit[3] = "George Allen & Unwin";
    buku.tebal_halaman[3] = 416;
    buku.harga_buku[3] = 13.85;

    buku.judul_buku[4] = "A Study in Scarlet";
    buku.pengarang[4] = "Sir Arthur Conan Doyle";
    buku.penerbit[4] = "Ward, Lock & Co";
    buku.tebal_halaman[4] = 192;
    buku.harga_buku[4] = 2.99;

    // Tampil hasil
    cout << "Informasi Buku:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Buku ke-" << i+1 << ":\n";
        cout << "Judul Buku: " << buku.judul_buku[i] << endl;
        cout << "Pengarang: " << buku.pengarang[i] << endl;
        cout << "Penerbit: " << buku.penerbit[i] << endl;
        cout << "Tebal Halaman: " << buku.tebal_halaman[i] << endl;
        cout << "Harga Buku: $" << buku.harga_buku[i] << endl;
        cout << endl;
    }

    return 0;
}
```
#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/777fe7c2-80a7-4c90-9bac-bb5d89130fce)

#### Penjelasan program:

Program itu menyatakan struct Buku yang memiliki lima atribut: judul buku, pengarang, penerbit, tebal halaman, dan harga buku. Setiap atribut dijadikan array yang bisa menyimpan data lima buku. Fungsi main() membuat objek dari struktur Buku. Kemudian, data untuk lima buku diisi ke dalam atribut. Setelah data diisi, loop menampilkan informasi masing-masing buku ke layar.

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

Jika deklarasi variabel struct yang dibuat berjenis Array, maka variabel akan jadi array yang isinya elemen-elemen dari struct itu. Ini berarti objek-objek dari struct semuanya akan disimpan dalam satu array. Misalnya, struct Buku dapat dideklarasikan sebagai array dengan:

```C++
Buku buku[5];
```

Untuk mengisi data dan menampilkannya, bisa dengan indeks array untuk mengakses setiap elemen struct dan atribut-atributnya. Seperti berikut:

```C++
#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    float harga_buku;
};

int main() {
    // objek buku
    Buku buku[5];

    // Mengisi data
    buku.judul_buku[0] = "Tokyo dan Perayaan Kesedihan";
    buku.pengarang[0] = "Ruth Priscilla Angelina";
    buku.penerbit[0] = "Gramedia Pustaka Utama";
    buku.tebal_halaman[0] = 192;
    buku.harga_buku[0] = 4.99;

    buku.judul_buku[1] = "Fantastic Beasts and Where to Find Them";
    buku.pengarang[1] = "J.K. Rowling";
    buku.penerbit[1] = "Bloomsbury.";
    buku.tebal_halaman[1] = 128;
    buku.harga_buku[1] = 11.26;

    buku.judul_buku[2] = "A Certain Magical Index: The Old Testament";
    buku.pengarang[2] = "Kazuma Kamachi";
    buku.penerbit[2] = "Yen On";
    buku.tebal_halaman[2] = 1664;
    buku.harga_buku[2] = 139.30;

    buku.judul_buku[3] = "The Return of the King";
    buku.pengarang[3] = "J.R.R Tolkien";
    buku.penerbit[3] = "George Allen & Unwin";
    buku.tebal_halaman[3] = 416;
    buku.harga_buku[3] = 13.85;

    buku.judul_buku[4] = "A Study in Scarlet";
    buku.pengarang[4] = "Sir Arthur Conan Doyle";
    buku.penerbit[4] = "Ward, Lock & Co";
    buku.tebal_halaman[4] = 192;
    buku.harga_buku[4] = 2.99;

    // Tampil hasil
    cout << "Informasi Buku:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Buku ke-" << i+1 << ":\n";
        cout << "Judul Buku: " << buku.judul_buku[i] << endl;
        cout << "Pengarang: " << buku.pengarang[i] << endl;
        cout << "Penerbit: " << buku.penerbit[i] << endl;
        cout << "Tebal Halaman: " << buku.tebal_halaman[i] << endl;
        cout << "Harga Buku: $" << buku.harga_buku[i] << endl;
        cout << endl;
    }

    return 0;
}
```
#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/03d6587d-5dba-480e-b613-2ff6cfde5e22)

#### Penjelasan Program
Array buku yang berukuran 5 diisi data untuk setiap elemen array menggunakan indeksnya. Kemudian loop menampilkan informasi buku yang ada dalam array.

## Kesimpulan
Struct adalah cara untuk mengelompokkan informasi dalam satu paket yang terorganisir. Dengan menggunakan struct, struktur data dapat dibuat lebih teratur dan mudah dimengerti. Objek bisa dibuat berdasarkan struktur tersebut, sehingga pengaksesan informasi tersebut menjadi lebih mudah dan cepat.

## Referensi
[1] Ma'arif, A. (2020). BUKU AJAR DASAR PEMROGRAMAN C++. Yogyakarta: UAD Press.

[2] Budiman, E. (2015). Belajar Dasar Algoritma & Pemrograman. Samarinda: Kalimantan Timur.

[3] Ta, Uch. (2016). "Pemograman C++ Bab 14 Struct". Diakses pada 25 April 2024, dari https://www.academia.edu/35362131/Pemograman_C_Bab_14_Struct_pdf

[4] Fajar. (2018). "Penjelasan dan Cara Mendirikan Struct". Diakses pada 26 April 2024, dari https://www.belajarcpp.com/tutorial/cpp/struct/