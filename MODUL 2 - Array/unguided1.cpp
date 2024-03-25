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