#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambahDepan(string nama, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
    }

    void tambahBelakang(string nama, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void tambahTengah(string nama, string nim, int posisi) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;

        if (posisi == 1 || head == nullptr) {
            tambahDepan(nama, nim);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < posisi - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void tampilkan() {
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        }
    }

    void hapusList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Semua data berhasil dihapus" << endl;
    }

    void hapusDepan() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Data di depan berhasil dihapus" << endl;
    }

    void hapusBelakang() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Data di belakang berhasil dihapus" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Data di belakang berhasil dihapus" << endl;
    }

    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }

        if (posisi == 1) {
            hapusDepan();
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        for (int i = 1; i < posisi && temp != nullptr; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Data di tengah berhasil dihapus" << endl;
    }

    void ubahDepan(string nama, string nim) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }

        head->nama = nama;
        head->nim = nim;
        cout << "Data di depan berhasil diubah" << endl;
    }

    void ubahBelakang(string nama, string nim) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->nama = nama;
        temp->nim = nim;
        cout << "Data di belakang berhasil diubah" << endl;
    }

    void ubahTengah(string nama, string nim, int posisi) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < posisi && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        temp->nama = nama;
        temp->nim = nim;
        cout << "Data di tengah berhasil diubah" << endl;
    }
};

int main() {
    LinkedList mahasiswa;

    int pilihan, posisi;
    string nama, nim;
    do {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                mahasiswa.tambahDepan(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                mahasiswa.tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                mahasiswa.tambahTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                mahasiswa.ubahDepan(nama, nim);
                break;
            case 5:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                mahasiswa.ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                mahasiswa.ubahTengah(nama, nim, posisi);
                break;
            case 7:
                mahasiswa.hapusDepan();
                break;
            case 8:
                mahasiswa.hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                mahasiswa.hapusTengah(posisi);
                break;
            case 10:
                mahasiswa.hapusList();
                break;
            case 11:
                mahasiswa.tampilkan();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    return 0;
}