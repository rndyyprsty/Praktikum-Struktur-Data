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