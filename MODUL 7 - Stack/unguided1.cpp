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