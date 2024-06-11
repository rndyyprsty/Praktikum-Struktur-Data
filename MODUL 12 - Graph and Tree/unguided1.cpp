#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int jumlah_kota;
    cout << "input jumlah kota: ";
    cin >> jumlah_kota;

    vector<string> kota(jumlah_kota);
    for (int i = 0; i < jumlah_kota; ++i) {
        cout << "Kota " << i + 1 << ": ";
        cin >> kota[i];
    }

    vector<vector<int>> matriks_jarak(jumlah_kota, vector<int>(jumlah_kota));
    for (int i = 0; i < jumlah_kota; ++i) {
        for (int j = 0; j < jumlah_kota; ++j) {
            cout << kota[i] << "-->" << kota[j] << " = ";
            cin >> matriks_jarak[i][j];
        }
    }

    cout << "\nMatriks Jarak:" << endl;
    cout << "   ";
    for (const auto& k : kota) {
        cout << k << " ";
    }
    cout << endl;

    for (int i = 0; i < jumlah_kota; ++i) {
        cout << kota[i] << " ";
        for (int j = 0; j < jumlah_kota; ++j) {
            cout << matriks_jarak[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}