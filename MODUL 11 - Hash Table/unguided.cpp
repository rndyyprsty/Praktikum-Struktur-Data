#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Mahasiswa {
    string NIM;
    float nilai;
};

class HashTable {
private:
    unordered_map<string, Mahasiswa> table;

public:
    void tambahData(const string& NIM, float nilai) {
        Mahasiswa mhs = {NIM, nilai};
        table[NIM] = mhs;
        cout << "Data mahasiswa dengan NIM " << NIM << " berhasil ditambahkan.\n";
    }

    void hapusData(const string& NIM) {
        if (table.erase(NIM)) {
            cout << "Data mahasiswa dengan NIM " << NIM << " berhasil dihapus.\n";
        } else {
            cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
        }
    }

    void cariDataBerdasarkanNIM(const string& NIM) {
        auto it = table.find(NIM);
        if (it != table.end()) {
            Mahasiswa mhs = it->second;
            cout << "Data ditemukan: NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
        } else {
            cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
        }
    }

    void cariDataBerdasarkanNilai(float minNilai, float maxNilai) {
        vector<Mahasiswa> hasil;
        for (const auto& entry : table) {
            if (entry.second.nilai >= minNilai && entry.second.nilai <= maxNilai) {
                hasil.push_back(entry.second);
            }
        }

        if (!hasil.empty()) {
            cout << "Mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << ":\n";
            for (const auto& mhs : hasil) {
                cout << "NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
            }
        } else {
            cout << "Tidak ada mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << ".\n";
        }
    }
};

void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah data\n";
    cout << "2. Hapus data\n";
    cout << "3. Cari data berdasarkan NIM\n";
    cout << "4. Cari data berdasarkan rentang nilai (80 - 90)\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    HashTable ht;
    int pilihan;
    string NIM;
    float nilai;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                ht.tambahData(NIM, nilai);
                break;

            case 2:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                ht.hapusData(NIM);
                break;

            case 3:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                ht.cariDataBerdasarkanNIM(NIM);
                break;

            case 4:
                ht.cariDataBerdasarkanNilai(80.0, 90.0);
                break;

            case 5:
                cout << "keluar program.\n";
                break;

            default:
                cout << "pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}