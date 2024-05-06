# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

### Stack

Stack adalah sebuah kumpulan data dimana data yang diletakkan di atas data  yang lain. Dengan demikian stack adalah struktur data yang menggunakan konsep LIFO(Last In First Out). Dengan demikian, elemen terakhir yang disimpan dalam stack menjadi elemen pertama yang diambil. Dalam proses komputasi, untuk meletakkan sebuah elemen pada bagian atas dari stack, maka dilakukan operasi push. Dan untuk memindahkan dari tempat yang atas tersebut, maka dilakukan operasi pop[1].  

Di C++, ada dua cara penerapan prinsip stack, yakni dengan array dan linked list. Setidaknya stack haruslah memiliki operasi-operasi sebagai berikut. 
1. Push Untuk menambahkan item pada tumpukan paling atas
2. Pop Untuk mengambil item teratas
3. Clear Untuk mengosongkan stack
4. IsEmpty Untuk memeriksa apakah stack kosong
5. IsFull Untuk memeriksa apakah stack sudah penuh[2].

Manipulasi data pada Stack hanya ada 3, pop, push dan stack top. Namun yang benar-benar mengubah keadaan stack itu sendiri hanyalah operasi pop dan push. Push akan menambahkan object ke dalam stack, atau menginisialisasi stack jika dalam keadaan kosong. Pop akan mengambil data yang terakhir masuk dari stack, sekaligus mengurangi isi dari stack. Sedangkan stack top hanya mirip dengan Pop, mengambil data dari posisi terakhir, hanya saja tidak menghapus object yang diambil tersebut[3].

## Guided

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty(){
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else{
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku(){
    if(isEmpty()){
        cout << "Tidak ada data yang dihapus" << endl;
    }else{
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku (int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else{
        int index = top; 
        for (int i = 1; i <= posisi; i ++){
            index--;
        }
        cout << "Posisi ke " << posisi << "adalah" << arrayBuku[index] << endl; 
    }
}

int countStack(){
    return top;
}
void changeArrayBuku (int posisi, string data){
    if (posisi > top){
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++){
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku() {
    for (int i = top; i >= 0; i--){
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArraybuku () {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}
int main(){
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArraybuku();
    cout << "\n";

    cout << "Apakah data stack penuh?" << isFull() << endl;
    cout <<"Apakah data stack kosong?" << isEmpty () << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data =" << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArraybuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus:" << top << endl;

    cetakArraybuku();
    return 0;
}
```
Program ini merupakan implementasi dari struktur data stack menggunakan array. Dalam program ini, terdapat beberapa fungsi dasar yang digunakan untuk operasi-operasi pada stack. Fungsi pushArrayBuku(string data) digunakan untuk menambahkan data ke dalam stack. Jika stack sudah penuh, program akan menampilkan pesan "Data telah penuh". Fungsi popArrayBuku() digunakan untuk menghapus data dari stack. Jika stack kosong, program akan menampilkan pesan "Tidak ada data yang dihapus". Fungsi peekArrayBuku(int posisi) digunakan untuk melihat data pada posisi tertentu dalam stack. Jika stack kosong, program akan menampilkan pesan "Tidak ada data yang bisa dilihat". Fungsi countStack() mengembalikan jumlah data dalam stack. Fungsi changeArrayBuku(int posisi, string data) digunakan untuk mengubah data pada posisi tertentu dalam stack. Fungsi destroyArraybuku() digunakan untuk menghapus semua data dalam stack. Fungsi cetakArraybuku() digunakan untuk mencetak semua data dalam stack dari atas ke bawah.

Di dalam fungsi main(), program melakukan beberapa operasi pada stack seperti menambahkan data, mencetak isi stack, memeriksa apakah stack penuh atau kosong, melihat data pada posisi tertentu dalam stack, menghapus data dari stack, mengubah data pada posisi tertentu dalam stack, menghapus semua data dalam stack, dan mencetak isi stack setelah dihapus semua datanya.

### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/6310e4ad-dca0-46de-a448-f9cd5c1e479b)

## Unguided

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <stack>
#include <cstring>
#include <locale>

using namespace std;

string praPemrosesanString(string str) {
    string hasil = "";
    locale loc;

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i], loc)) {
            hasil += tolower(str[i], loc);
        }
    }

    return hasil;
}

bool adalahPalindrom(string str) {
    stack<char> tumpukan;
    int panjang = str.length();
    int tengah = panjang / 2;

    for (int i = 0; i < tengah; i++) {
        tumpukan.push(str[i]);
    }

    for (int i = tengah + (panjang % 2); i < panjang; i++) {
        if (str[i] != tumpukan.top()) {
            return false;
        }
        tumpukan.pop();
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    string kalimatSetelahPemrosesan = praPemrosesanString(kalimat);

    if (adalahPalindrom(kalimatSetelahPemrosesan)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
```

#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/ba3fb907-ca60-4b07-9605-bacca5da70bc)

#### Penjelasan Program

Program meminta pengguna untuk memasukkan sebuah kalimat.Kemudian string itu diproses menggunakan fungsi praPemrosesanString. Proses pemrosesan ini menghapus semua karakter non-alfabet dari string dan mengubah huruf kapital menjadi huruf kecil.
Fungsi adalahPalindrom digunakan untuk mengecek apakah string tersebut adalah palindrom atau tidak. Proses ini dilakukan dengan menggunakan tumpukan (stack). Setengah karakter pertama dimasukkan ke dalam tumpukan. Kemudian, karakter-karakter setengah terakhir dibandingkan dengan karakter-karakter yang diambil dari tumpukan. Jika semua karakter cocok, maka string tersebut adalah palindrom.
Hasilnya akan ditampilkan kepada pengguna.

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string balikKata(string kata) {
    stack<char> tumpukan;

    for (char karakter : kata) {
        tumpukan.push(karakter);
    }

    string hasil = "";

    while (!tumpukan.empty()) {
        hasil += tumpukan.top();
        tumpukan.pop();
    }

    return hasil;
}

string balikKalimat(string kalimat) {
    string kata = "";
    string hasil = "";

    for (char karakter : kalimat) {
        if (karakter == ' ') {
            hasil += balikKata(kata) + " ";
            kata = "";
        } else {
            kata += karakter;
        }
    }

    hasil += balikKata(kata);

    return hasil;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, kalimat);

    string hasil = balikKalimat(kalimat);

    cout << "Hasil pembalikan kalimat: " << hasil << endl;

    return 0;
}
```
#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/bc09b167-9766-4ef2-a861-3eb96c93244c)

#### Penjelasan Program
Program ini bertujuan untuk membalikkan urutan kata dalam sebuah kalimat yang dimasukkan pengguna. Program menggunakan struktur data stack untuk melakukan pembalikan urutan karakter dalam setiap kata.
Fungsi balikKata(string kata) bertanggung jawab untuk membalikkan urutan karakter dalam satu kata. Saat sebuah kata diterima sebagai argumen, setiap karakternya dimasukkan ke dalam stack. Setelah itu, karakter-karakter tersebut dikeluarkan dari stack satu per satu, membentuk kata terbalik. Hasil dari kata terbalik kemudian dikembalikan oleh fungsi ini.
Fungsi balikKalimat(string kalimat) berperan dalam membalikkan urutan kata dalam kalimat yang diterima sebagai argumen. Selama membaca karakter dalam kalimat, setiap karakter ditinjau. Jika sebuah spasi ditemukan, berarti sebuah kata telah selesai, maka kata tersebut dibalikkan urutan karakternya dengan memanggil fungsi balikKata. Setelah semua kata dalam kalimat selesai diproses, hasil dari pembalikan urutan kata dikembalikan oleh fungsi ini.
Di dalam fungsi utama main(), program meminta pengguna untuk memasukkan kalimat. Setelah kalimat dimasukkan, program menggunakan fungsi balikKalimat untuk membalikkan urutan katanya. Hasil pembalikan tersebut kemudian ditampilkan kepada pengguna sebagai output program.

## Kesimpulan
Stack adalah salah satu konsep dasar pemrograman yang memungkinkan untuk menyimpan dan mengambil data secara teratur. Dalam bahasa pemrograman C++, konsep stack dapat digunakan untuk membuat program yang lebih efisien dan terstruktur. Karena Stack adalah sebuah kumpulan data dimana data yang diletakkan di atas data yang lain. Oleh karena itu, stack adalah struktur data yang menggunakan konsep LIFO.

## Referensi
[1] blogger. (2014). "Stack pada C++". Diakses pada 5 Mei 2024, dari https://www.nblognlife.com/2014/04/stack-pada-c.html?m=1

[2] UPJ. (2016). "Modul Praktikum Struktur Data". Diakses pada 5 Mei 2024, dari https://ocw.upj.ac.id/files/Handout-TIF104-Modul-Praltikum-Struktur-Data.pdf

[3] konglie. (2016). "Stack dengan C++". Diakses pada 5 Mei 2024, dari https://www.kurungkurawal.com/2011/05/11/stack-dengan-c/ 