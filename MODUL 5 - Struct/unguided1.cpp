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