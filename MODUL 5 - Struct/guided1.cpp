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
    buku1.harga_buku = 2.99;

    // Menampilkan informasi
    cout << "Judul Buku: " << buku1.judul_buku << endl;
    cout << "Pengarang: " << buku1.pengarang << endl;
    cout << "Penerbit: " << buku1.penerbit << endl;
    cout << "Tebal Halaman: " << buku1.tebal_halaman << endl;
    cout << "Harga Buku: $" << buku1.harga_buku << endl;

    return 0;
}