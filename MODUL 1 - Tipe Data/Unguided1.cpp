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