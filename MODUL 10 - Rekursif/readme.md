# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

### Rekursif

Rekursi adalah suatu proses dari fungsi yang memanggil dirinya sendiri. Fungsi yang seperti ini disebut fungsi rekursif (recursive function). Dalam sebuah fungsi rekursif pemanggilan dapat terjadi berulang kali. Karena ada proses yang berulang-ulang maka harus ada suatu kondisi yang mengakhiri prosesnya. Jika tidak, maka proses tidak akan pernah berhenti sampai memori yang digunakan tidak dapat menampung lagi. Pemecahan masalah dengan pendekatan rekursif dapat dilakukan jika masalah tersebut dapat didefinisikan secara rekursif, yaitu masalah dapat diuraikan menjadi masalah sejenis yang lebih sederhana[1].  

Jenis Rekursif
Ada beberapa jenis rekursif yaitu:
1. Rekursi Langsung (Direct Recursion)
Rekursi langsung adalah jenis rekursif di mana fungsi memanggil dirinya sendiri secara langsung. Contoh: fungsi fun(n) memanggil dirinya sendiri dengan parameter n-1.
2. Rekursi Tidak Langsung (Indirect Recursion)
Rekursi tidak langsung adalah jenis rekursif di mana fungsi memanggil fungsi lain yang kemudian memanggil fungsi asli. Contoh: fungsi fun1() memanggil fungsi fun2() yang kemudian memanggil fungsi fun1().
3. Rekursi Akhir (Tail Recursion)
Rekursi akhir adalah jenis rekursif di mana fungsi memanggil dirinya sendiri dan recursive call adalah statement terakhir dalam fungsi. Contoh: fungsi fun(n) memanggil dirinya sendiri dengan parameter n-1 dan tidak melakukan operasi lain.
4. Rekursi Pohon (Tree Recursion)
Rekursi pohon adalah jenis rekursif di mana fungsi memanggil dirinya sendiri lebih dari satu kali. Contoh: fungsi fun(n) memanggil dirinya sendiri dengan parameter n-1 dan n-2[2].

Fungsi rekursif adalah salah satu teknik pemrograman yang cukup penting, dimana dalam beberapa kasus menggunakan fungsi rekursif akan jauh lebih mudah. Selain itu proses yang berjalan akan jauh lebih cepat dan efisien, hanya saja akan membutuhkan space memori yang cukup banyak karena proses iterasi dari bagian fungsi tersebut akan dipanggil secara terus menerus sehingga memerlukan ruang penyimpanan yang cukup besar jika dibandingkan dengan proses lainnya[3].

Kelebihan & Kekurangan Rekursif
Kelebihan:
- Rekursi membantu mengurangi panjang kode
- Memberikan cara yang bersih dan mudah untuk menulis kode.
- Meminimalkan pemanggilan ke fungsi berulang kali.
- Rekursi lebih disukai dalam permasalahan seperti penjelajahan pohon dan menara Hanoi.

Kekurangan:
- Fungsi rekursif sedikit lebih lambat dibandingkan fungsi non-rekursif.
- Memiliki kebutuhan ruang yang lebih signifikan dibandingkan program berulang.
- Ini memakan waktu yang lebih signifikan karena pemanggilan fungsi.
- Agak sulit untuk dipahami[4]

## Guided

### 1. Rekursif Langsung (Direct Recursion)

```C++
#include <iostream>
using namespace std;

//Code ini berfungsi untuk melakukan hitung mundur
//dari angka yang diinputkan

void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursi Langsung: ";
    countdown(5); //5 merupakan input nya
    cout << endl;
    return 0;
}
```

## Penjelasan Program

Program ini menggunakan rekursi untuk melakukan hitung mundur dari angka yang diinputkan. Fungsi countdown berulang kali memanggil dirinya sendiri dengan nilai argumen yang berkurang hingga mencapai 0, menghasilkan urutan hitung mundur yang dicetak ke konsol.

### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/9a3ed879-a64e-428e-b3fa-dfb531c31078)

### 2. Rekursif Tidak Langsung (Indirect Recursion)

```C++
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```

## Penjelasan Program

Program ini menampilkan gabungan hitung mundur dan pembagian menggunakan rekursi tidak langsung. Fungsi functionA memulai hitung mundur dari n dan pada setiap iterasi memanggil functionB dengan nilai n - 1 untuk membagi n dengan 2. functionB kemudian memanggil functionA dengan hasil bagi untuk melanjutkan hitung mundur. Proses ini berulang hingga mencapai 0, menghasilkan urutan hitung mundur dan pembagian bilangan yang saling terkait dicetak ke konsol.

### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/0a6455ff-f6a1-4a28-91b9-e2fcdcb96fd4)

## Unguided

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } 
    else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int bilangan;

    std::cout << "Masukkan bilangan bulat positif: ";
    std::cin >> bilangan;

    if (bilangan < 0) {
        std::cerr << "Input harus bilangan positif." << std::endl;
        return 1;
    }

    int hasil = faktorial(bilangan);

    std::cout << "Faktorial dari " << bilangan << " adalah: " << hasil << std::endl;

    return 0;
}
```

#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/706bf523-6ff5-40db-86ff-5b565b3046f3)

#### Penjelasan Program

Program ini menghitung nilai faktorial dari sebuah bilangan bulat positif menggunakan rekursi langsung. Fungsi faktorial menerima sebuah bilangan bulat n dan mengembalikan nilai faktorialnya. Basis kasus dalam fungsi ini adalah ketika n bernilai 0 atau 1, yang mana fungsi akan mengembalikan 1. Untuk nilai n yang lebih besar dari 1, fungsi akan memanggil dirinya sendiri dengan n-1 dan mengalikan hasilnya dengan n, mengikuti definisi faktorial.

Di dalam fungsi main, program meminta bilangan bulat positif. Jika bilangan benar-benar positif maka program menghitung nilai faktorial dengan memanggil fungsi faktorial dan kemudian menampilkan hasilnya. Jika input tidak valid (bilangan negatif), program akan menampilkan pesan kesalahan dan berhenti. Hasil akhir ditampilkan dalam format yang menyatakan "Faktorial dari [bilangan] adalah: [hasil]".

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
#include <iostream>

int faktorialA(int n);
int faktorialB(int n);

int faktorialA(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * faktorialB(n - 1);
    }
}

int faktorialB(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return faktorialA(n);
    }
}

int main() {
    int bilangan;

    std::cout << "Masukkan bilangan bulat positif: ";
    std::cin >> bilangan;

    if (bilangan < 0) {
        std::cerr << "Input harus bilangan positif." << std::endl;
        return 1;
    }

    int hasil = faktorialA(bilangan);

    std::cout << "Faktorial dari " << bilangan << " adalah: " << hasil << std::endl;

    return 0;
}
```

#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/276e81d3-023e-415e-9fd0-673fd1574784)

#### Penjelasan Program

Program ini menghitung nilai faktorial dari sebuah bilangan bulat positif menggunakan rekursi tidak langsung (indirect recursion). Rekursi tidak langsung didapat dengan menggunakan dua fungsi, faktorialA dan faktorialB, yang saling memanggil satu sama lain. Pada faktorialA, jika n adalah 0 atau 1, fungsi mengembalikan 1 sebagai basis kasus. Jika tidak, faktorialA memanggil faktorialB dengan n-1, melanjutkan perhitungan rekursif. Sebaliknya, faktorialB juga memiliki basis kasus yang sama dan akan memanggil faktorialA dengan n untuk melanjutkan perhitungan.

Di dalam fungsi main, program meminta bilangan bulat positif, kemudian memanggil faktorialA untuk menghitung faktorial. Hasil perhitungan kemudian ditampilkan kepada pengguna. Jika pengguna memasukkan bilangan negatif, program menampilkan pesan kesalahan dan berhenti. Struktur ini memungkinkan perhitungan faktorial dilakukan melalui dua fungsi yang saling memanggil, menjadikan program ini menggunakan fungsi rekursi tidak langsung.

## Kesimpulan

Rekursif adalah fungsi yang memanggil dirinya sendiri dan digunakan untuk menyelesaikan masalah yang dapat didefinisikan secara rekursif. Fungsi rekursif dapat digunakan untuk menghitung faktorial dan pangkat, serta memecahkan masalah yang memerlukan iterasi berulang. Namun, fungsi rekursif harus didefinisikan dengan jelas dan memiliki kondisi yang menghentikan iterasi agar tidak terjadi infinite loop.

## Referensi
[1] Ta, U. (2015). "Pemograman C++ Bab 11 Fungsi Rekursif.pdf". Diakses pada 27 Mei 2024, dari https://www.academia.edu/35362128/Pemograman_C_Bab_11_Fungsi_Rekursif_pdf

[2] Chauhan, S. (2024). "What is Recursion in C++ | Types of Recursion in C++ ( With Examples )". Diakses pada 27 Mei 2024, dari https://www.scholarhat.com/tutorial/cpp/recursion-in-cpp

[3] Dimas, S. (2020). "Contoh Penerapan Fungsi Rekursif Pada C++". Diakses pada 27 Mei 2024, dari https://kelasprogrammer.com/contoh-fungsi-rekursif/

[4] Bhardwaj, H. (2012). "What is Recursion in C++? Types, its Working and Examples". Diakses pada 27 Mei 2024, dari https://www.simplilearn.com/tutorials/cpp-tutorial/what-is-recursion-in-cpp