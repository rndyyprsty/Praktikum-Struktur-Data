# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Muhammad Randy Prasetya</p>

## Dasar Teori

Tipe data adalah jenis data yang dapat diolah oleh
komputer untuk memenuhi kebutuhan dalam
pemrograman komputer. Ketepatan pemilihan tipe data pada variabel atau konstanta akan sangat menentukan pemakaian
sumberdaya komputer. Tipe data juga dibutuhkan agar kompiler dapat mengetahui bagaimana sebuah
data akan digunakan. Adapun tipe data yang akan dipelajari, adalah sebagai berikut :
1. Tipe data Primitif
2. Tipe data Abstrak
3. Tipe data Koleksi

### Tipe Data Primitif

Tipe data primitif adalah tipe data bawaan bahasa pemrograman dan bisa langsung digunakan programmer untuk mendeklarasikan variabel. Dalam C++, terdapat 7 tipe data yang termasuk tipe data primitif, yaitu: int, float, double, boolean, char, void dan wide_character.[1]
1. Int : bisa disebut integer adalah tipe data yang nilainya terdiri dari angka bulat. Tipe data ini hanya bisa menyimpan angka bulat saja tanpa pecahan (desimal). Nilainya bisa positif maupun negatif. Contohnya seperti 12, 7 dan 20.
2. Float : Float atau disebut juga floating point atau real number adalah tipe data angka yang memiliki bagian desimal di akhir angka, atau mem). Jika ingin menyimpan angka berkoma, kita bisa menggunakan tipe data ini. Contohnya seperti 3.14 , 19.6 dan 2.1.
3. Boolean : Boolean adalah tipe data yang hanya memiliki 2 pilihan nilai, yaitu true dan false. Contohnya seperti tidur = true.
4. Char : Char adalah tipe data yang digunakan untuk menyimpan satu karakter saja. Dan penulisannya harus diapit oleh tanda petik tunggal. Biasanya digunakan untuk simbol A, B, C dan lainnya.

### Tipe Data Abstrak

Tipe data abstrak (TDA) atau lebih dikenal dalam bahasa Inggris sebagai Abstract data type (ADT) merupakan model matematika yang merujuk pada sejumlah bentuk struktur data yang memiliki kegunaan atau perilaku yang serupa; atau suatu tipe data dari suatu bahasa pemrograman yang memiliki sematik yang serupa. Tipe data abstrak umumnya didefinisikan tidak secara langsung, melainkan hanya melalui operasi matematis tertentu sehingga membutuhkan penggunaan tipe data tersebut meski dengan risiko kompleksitas yang lebih tinggi atas operasi tersebut.[2]

### Tipe Data Koleksi

Koleksi adalah tipe data yang berupa rangkaian atau kumpulan data ataupun objek yang berindeks[3]. terdapat tiga tipe dasar koleksi yaitu:
1. Array; koleksi statis dengan ukuran tetap dan hanya bisa mengelompokkan tipe data yang sama.
2. Vector; Tipe data vector adalah tipe data koleksi yang dapat menyimpan objek atau nilai dengan panjang yang berubah-ubah.
3. Map; koleksi dinamis dengan ukuran adaptif dan bisa mengelompokkan tipe data yang sama ataupun berbeda dengan menggunakan pasangan <key,value>

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
// Main program
int main()
{
char op;
float num1, num2;
// It allows user to enter operator i.e. +, -, *, /
cin >> op;
// It allow user to enter the operands
cin >> num1 >> num2;
// Switch statement begins
switch (op)
{
// If user enter +
case '+':
cout << num1 + num2;
break;
// If user enter -
case '-':
cout << num1 - num2;
break;
// If user enter *
case '*':
cout << num1 * num2;
break;
// If user enter /
case '/':
cout << num1 / num2;
break;
// If the operator is other than +, -, * or /,
// error message will display
default:
cout << "Error! operator is not correct";
} // switch statement ends
return 0;
}
```
### 2. Tipe Data Abstrak

```C++
#include <stdio.h>
//Struct
struct Mahasiswa
{
const char *name;
const char *address;
int age;
};
int main()
{
// menggunakan struct
struct Mahasiswa mhs1, mhs2;
// mengisi nilai ke struct
mhs1.name = "Dian";
mhs1.address = "Mataram";
mhs1.age = 22;
mhs2.name = "Bambang";
mhs2.address = "Surabaya";
mhs2.age = 23;
// mencetak isi struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}
```
### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
//deklarasi dan inisialisasi array
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;
//mencetak array
cout << "Isi array pertama :" << nilai[0] << endl;
cout << "Isi array kedua :" << nilai[1] << endl;
cout << "Isi array ketiga :" << nilai[2] << endl;
cout << "Isi array keempat :" << nilai[3] << endl;
cout << "Isi array kelima :" << nilai[4] << endl;
return 0;
}
```

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>

using namespace std;

int hitungLuasPersegiPanjang(int panjang, int lebar) {
    return panjang * lebar;
}

int hitungKelilingLingkaran(int jariJari) {
    return 2 * 3.14 * jariJari;
}

int main() {
    int panjang = 5;
    int lebar = 3;
    cout << "Luas persegi panjang dengan panjang " << panjang << " dan lebar " << lebar << " adalah: " << hitungLuasPersegiPanjang(panjang, lebar) << endl;

    int jariJari = 7;
    cout << "Keliling lingkaran dengan jari-jari " << jariJari << " adalah: " << hitungKelilingLingkaran(jariJari) << endl;

    return 0;
}
```
#### Penjelasan program:

Program ini menggunakan tipe data primitif int untuk menyimpan nilai panjang, lebar, dan jari-jari.
Fungsi hitungLuasPersegiPanjang menerima dua parameter berupa panjang dan lebar, lalu akan mengembalikan hasil perkalian keduanya.
Fungsi hitungKelilingLingkaran menerima satu parameter berupa jari-jari, lalu ia akan mengembalikan hasil perhitungan keliling lingkaran menggunakan rumus 2 * π * jari-jari (π diaproksimasi sebagai 3.14).
Di dalam main(), program menampilkan hasil perhitungan luas persegi panjang dengan panjang dan lebar, dan hasil perhitungan keliling lingkaran dengan jari-jari.
Kesimpulan:

Tipe data primitif seperti int bisa berguna untuk menyimpan nilai bilangan bulat.
Dengan tipe data ini, kita dapat melakukan berbagai operasi matematika dan perhitungan sederhana.
Program tersebut menunjukkan bahwa, kita dapat membuat program yang bisa melakukan perhitungan matematika dasar dapat dibuat tanpa bergantung pada tipe data yang lebih kompleks.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

- Class:

  Class bersifat Private dan tidak bisa diakses di luarnya kecuali melalui fungsi member publik.
  Kepemilikannya juga private pada umumnya, kecuali jika dinyatakan secara eksplisit.
  Untuk penggunaannya, pada umumnya dipakai untuk menyembunyikan implementasi internal dan menerapkan konsep enkapsulasi.
  Contoh:

```C++
class Mahasiswa {
private:
    std::string nama;
    int umur;
public:
    void setNama(std::string n) {
        nama = n;
    }
    void setUmur(int u) {
        umur = u;
    }
    void display() {
        std::cout << "Nama: " << nama << ", Umur: " << umur << std::endl;
    }
};
```
- Struct:

  Struct bersifat Public, sehingga ia dapat diakses langsung dari luar struktur.
  Kepemilikannya pada umumnya adalah public.
  Untuk penggunaan, biasanya dipakai untuk membuat tipe data yang mengelompokkan beberapa item data dengan struktur yang sederhana.
  Contoh:

```C++
struct Person {
    std::string name;
    int age;
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
```
#### Contoh Program

```C++
#include <iostream>
#include <string>

// Contoh penggunaan class
class Mahasiswa {
private:
    std::string nama;
    int umur;
public:
    void setNama(std::string n) {
        nama = n;
    }
    void setUmur(int u) {
        umur = u;
    }
    void display() {
        std::cout << "Nama: " << nama << ", Umur: " << umur << std::endl;
    }
};

// Contoh penggunaan struct
struct Person {
    std::string name;
    int age;
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Mahasiswa mhs;
    mhs.setNama("Sherlock");
    mhs.setUmur(20);
    mhs.display();

    Person person;
    person.name = "Watson";
    person.age = 25;
    person.display();

    return 0;
}
```
Program tersebut mendefinisikan class Mahasiswa dan struct Person. Objek Mahasiswa memiliki data anggota yaitu nama dan umur serta fungsi anggota untuk mengatur dan menampilkan data tersebut. Sedangkan objek Person hanya memiliki dua data yaitu name dan age yang secara default dapat diakses dari luar struct dan memiliki fungsi display untuk menampilkannya.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> umur;

    umur["Birdway"] = 25;
    umur["Misaka"] = 30;
    umur["Othinus"] = 20;

    std::cout << "Umur Birdway: " << umur["Birdway"] << std::endl;

    std::cout << "Semua Umur:" << std::endl;
    for (const auto& pair : umur) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```
### Penjelasan Program:

Program ini menggunakan fungsi map dari STL untuk membuat tipe data yang memiliki pasangan <key, value>.
Di program ini, map digunakan untuk menyimpan nama sebagai key dan umur sebagai value.
Elemen-elemen yang ada, ditambahkan ke map dengan cara menggunakan operator [].
Lalu kemudian program akan mencetak umur dengan menggunakan nama sebagai key.
Terakhir, program akan mengiterasi melalui semua pasangan <key, value> dalam map dan mencetaknya hasilnya.

#### Perbedaan Array dengan Map

Array
- Menyimpan data dalam urutan terindeks dengan indeks integer.
- Akses ke data dilakukan dengan menggunakan indeks integer.
- Ukuran array harus didefinisikan sebelum digunakan, dan tidak dapat diubah setelah itu.
- Memiliki akses konstan ke elemen dengan kompleksitas waktu O(1).

Map
- Menyimpan data dalam pasangan <key, value>, di mana key dapat berupa tipe data apa pun, tidak hanya integer
- Akses ke data dilakukan dengan menggunakan key yang bisa berupa tipe data apa pun.
- Dinamis dan dapat diubah saat runtime, entah itu menambah, menghapus ataupun memodifikasi pasangan <key, value>.
- Umumnya memiliki kompleksitas waktu O(log n) untuk akses, yang mana n adalah jumlah elemen dalam map.

#### Output:
![Screenshot 2024-03-11 161001](https://github.com/rndyyprsty/Praktikum-Struktur-Data-Assignment/assets/162487464/3d10b6ac-b604-4369-928e-a78194e873b2)

![Screenshot 2024-03-11 172749](https://github.com/rndyyprsty/Praktikum-Struktur-Data-Assignment/assets/162487464/0036dc53-fc38-4b51-a3cb-e9f3bcbe5818)

![Screenshot 2024-03-11 172809](https://github.com/rndyyprsty/Praktikum-Struktur-Data-Assignment/assets/162487464/587d7c2d-0037-4ab8-9138-f71384c6488e)

## Kesimpulan
Praktikum ini mendalami konsep dasar tipe-tipe data dalam bahasa C++ yang terdiri dari data primitif, abstrak dan koleksi. Dari cara pemilihan data yang tepat hingga cara menyimpan dan mengelola data.
Dengan demikian, praktikum ini telah memberikan pemahaman mengenai konsep-konsep tipe data dan cara pemanfaatannya dengan baik.

## Referensi
[1] Martin M. Syahidin, Mengenal Jenis-jenis Tipe Data dalam Bahasa C++, Jurnal MMS, 2019.

[2] Barbara Liskov, Programming with Abstract Data Types, in Proceedings of the ACM SIGPLAN Symposium on Very High Level Languages, pp. 50--59, 1974.

[3] Dwitha F. Ramadhani, Ika Damayanti, Tipe Data Primitif, Abstrak dan Koleksi, Academia.edu, 2017.