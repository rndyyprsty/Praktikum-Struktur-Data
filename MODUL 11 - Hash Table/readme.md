# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

### Hash Table

Hash table adalah sebuah cara untuk menyimpan suatu data pada memori ke dalam baris-baris dan kolom-kolom sehingga membentuk tabel yang dapat diakses dengan cepat [1]. Setiap sel yang merupakan pertemuan antara baris dan kolom di dalam tabel hash dimana data diarsipkan disebut dengan slot [2]. Sebuah tabel hash dapat dibuat dari dua bagian, yaitu sebuah larik atau array dan sebuah fungsi untuk memetakan, yang disebut dengan fungsi hash atau hash function. Fungsi hash adalah pemetaan ke dalam larik sesuai dengan kunci-kunci yang diberikan, dengan kata lain fungsi hash mendistribusikan data yang dimasukkan oleh pengguna ke dalam tabel atau larik yang telah disediakan[3].  

#### Fungsi Hash Table
Fungsi yang menerjemahkan kunci ke indeks array dikenal sebagai fungsi hash. Kunci harus didistribusikan secara merata ke seluruh array melalui fungsi hash yang layak untuk mengurangi tabrakan dan memastikan kecepatan pencarian yang cepat[4].

#### Operasi Hash Table

1. Search (Pencarian): Operasi ini digunakan untuk mencari data dalam hash table dengan menggunakan kunci unik. Operasi ini meliputi:
- Mencari indeks hash menggunakan fungsi hash.
- Mencari data di indeks hash yang ditemukan.
- Mengembalikan data jika ditemukan, atau mengembalikan nilai null jika tidak ditemukan.
2. Insert (Penghapusan): Operasi ini digunakan untuk menambahkan data baru ke dalam hash table. Operasi ini meliputi:
- Mencari indeks hash menggunakan fungsi hash.
- Mencari data di indeks hash yang ditemukan.
- Menggantikan data yang ditemukan dengan data baru jika ditemukan, atau menggantikan data yang tidak ditemukan dengan data baru jika tidak ditemukan.
3. Delete (Penghapusan): Operasi ini digunakan untuk menghapus data dari hash table. Operasi ini meliputi:
- Mencari indeks hash menggunakan fungsi hash.
- Mencari data di indeks hash yang ditemukan.
- Menghapus data yang ditemukan jika ditemukan, atau mengembalikan nilai null jika tidak ditemukan[5].

#### Collision Resolution

Collision resolution adalah aspek penting dari hash table, ini agar memastikan data dapat disimpan dan diambil secara efisien bahkan ketika terjadi kolisi. Ini dapat terjadi ketika satu atau lebih nilai hash bersaing dengan satu slot tabel hash. Untuk mengatasi hal ini, slot kosong berikutnya yang tersedia ditetapkan ke nilai hash saat ini[6]. Ada beberapa teknik yang digunakan untuk menyelesaikan hal tersebut:

1. Separate Chaining (Open Hashing): Metode ini melibatkan pembuatan daftar tertaut di setiap slot dalam tabel hash. Ketika tabrakan terjadi, kunci baru ditambahkan ke daftar tertaut di slot yang sesuai. Teknik ini mudah diterapkan dan memungkinkan operasi penyisipan dan penghapusan yang efisien. Namun, hal ini dapat menyebabkan kinerja cache yang buruk dan pemborosan memori karena daftar tertaut.

2. Open Addressing (Closed Hashing): Metode ini melibatkan penyelidikan tabel hash untuk menemukan slot terbuka ketika terjadi tabrakan. Ada beberapa variasi pengalamatan terbuka, antara lain:
- Linear Probing: Teknik ini melibatkan pemeriksaan tabel hash dalam urutan linier hingga slot terbuka ditemukan. Hal ini sederhana untuk diterapkan namun dapat menyebabkan pengelompokan, dimana item menjadi terkonsentrasi di area tertentu dari tabel hash.
- Penyelidikan Kuadrat: Teknik ini melibatkan penggunaan fungsi kuadrat untuk menghitung urutan penyelidikan, yang membantu mendistribusikan item secara lebih merata di seluruh tabel hash.
- Hashing Ganda: Teknik ini melibatkan penggunaan fungsi hash kedua untuk menghitung urutan probe, yang membantu mengurangi pengelompokan[7].

## Guided

### 1. Guided I

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
        }
    }
    delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
   
    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```

## Penjelasan Program

Program di atas adalah implementasi sederhana dari tabel hash menggunakan linked list untuk mengatasi tabrakan. Fungsi hash (hash_func) mengembalikan indeks berdasarkan operasi modulo (key % MAX_SIZE). Tabel hash menggunakan array pointer ke node (Node), di mana setiap node menyimpan pasangan kunci-nilai dan pointer ke node berikutnya jika terjadi tabrakan.

Class HashTable menyediakan metode untuk memasukkan (insert), mencari (get), menghapus (remove), dan menelusuri elemen (traverse). Penyisipan memperbarui nilai jika kunci sudah ada atau menambahkan node baru. Pencarian dan penghapusan dilakukan dengan menemukan indeks melalui fungsi hash dan menelusuri linked list pada indeks tersebut. Program utama menunjukkan contoh penggunaan tabel hash dengan menyisipkan, mencari, menghapus, dan menampilkan elemen.

### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/60a3d173-e483-4a96-8015-5c6f6fda3e71)

### 2. Guided II

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
    return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
       
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name) {
    int hash_val = hashFunc(name);
    for (auto node : table[hash_val]) {
        if (node->name == name) {
            return node->phone_number;
        }
    }
    return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
                for (auto pair : table[i]) {
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
                }
            cout << endl;
        }
    }
};

int main() {
HashMap employee_map;

employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");

cout << "Nomer Hp Mistah : " <<employee_map.searchByName("Mistah") << endl;
cout << "Phone Hp Pastah : " <<employee_map.searchByName("Pastah") << endl;

employee_map.remove("Mistah");

cout << "Nomer Hp Mistah setelah dihapus : " <<employee_map.searchByName("Mistah") << endl << endl;

cout << "Hash Table : " << endl;

employee_map.print();

return 0;
}
```

## Penjelasan Program

Program ini mengimplementasikan tabel hash untuk menyimpan pasangan nama dan nomor telepon menggunakan linked list untuk menangani tabrakan. Kelas HashNode menyimpan pasangan nama-nomor telepon, sementara kelas HashMap mengelola tabel hash dengan ukuran tetap (TABLE_SIZE = 11). Fungsi hash (hashFunc) menghitung indeks dari jumlah nilai ASCII karakter dalam nama. Metode insert menambahkan atau memperbarui pasangan, remove menghapus pasangan berdasarkan nama, dan searchByName mencari nomor telepon berdasarkan nama.

Dalam fungsi main, objek HashMap dibuat dan beberapa pasangan nama-nomor telepon dimasukkan. Program mencari nomor telepon berdasarkan nama, menghapus pasangan tertentu, dan menampilkan hasil pencarian setelah penghapusan. Metode print menampilkan seluruh isi tabel hash, menunjukkan cara penggunaan tabel hash untuk operasi penyimpanan, pencarian, dan penghapusan data.

### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/3cd945f9-313c-4d4b-9187-051839476ab0)

## Unguided

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
a.	Setiap mahasiswa memiliki NIM dan nilai.
b.	Program memiliki tampilan pilihan menu berisi poin C.
c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).


```C++
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
```

#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/1acfb165-9ea2-48d6-9bc5-a8c4d2b0ad99)

#### Penjelasan Program

Program ini menggunakan konsep hash table untuk menyimpan data mahasiswa, di mana setiap mahasiswa memiliki NIM dan nilai. Menggunakan struktur data unordered_map dari C++ Standard Library, program ini menyimpan pasangan kunci-nilai di mana NIM digunakan sebagai keyword untuk setiap entry mahasiswa.

Di dalam kelas HashTable, terdapat empat fungsi utama: tambahData untuk menambahkan data mahasiswa baru, hapusData untuk menghapus data mahasiswa berdasarkan NIM, cariDataBerdasarkanNIM untuk mencari dan menampilkan data mahasiswa berdasarkan NIM, dan cariDataBerdasarkanNilai untuk mencari dan menampilkan mahasiswa dengan nilai dalam rentang tertentu. Fungsi-fungsi ini memanfaatkan kemampuan hash table untuk melakukan operasi pencarian dan manipulasi data dengan kompleksitas waktu yang rendah, biasanya O(1).

Program ini juga memiliki menu yang sederhana. Fungsi main berisi loop yang menampilkan menu pilihan kepada pengguna dan meminta input untuk melakukan operasi yang diinginkan.

## Kesimpulan

Hash table merupakan struktur data yang secara asosiatif menyimpan data. Dalam hal ini, data disimpan dalam format array, di mana setiap nilai data memiliki nilai indeks uniknya sendiri. Akses data akan menjadi sangat cepat jika Anda mengetahui indeks dari data yang diinginkan. Dengan demikian, hash table menjadi struktur data di mana operasi penyisipan dan pencarian data terjadi sangat cepat terlepas dari ukuran data tersebut. Hash table menggunakan array sebagai media penyimpanan dan tekniknya untuk menghasilkan indeks suatu elemen yang dimasukkan atau ditempatkan.

## Referensi
[1] Barnes & Noble. (2018). "What is a Hash Tables?". Diakses pada 1 Juni 2024, dari https://www.sparknotes.com/cs/searching/hashtables/section1/
[2] Morris, J. (1998). "Hash Tables". Diakses pada 2 Juni 2024, dari https://www.cs.auckland.ac.nz/software/AlgAnim/hash_tables.html

[3] Prestiliano, J. (2007). Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data. Jurnal Teknologi Informasi-Aiti, 4(1), 41-56.

[4] Nikhilgarg527. (2020). "Hash Table Data Structure". GeeksforGeeks, Diakses pada 2 Juni 2024, dari https://www.geeksforgeeks.org/hash-table-data-structure/

[5] TutorialsPoint Team. (2023). "Hash Table Data Structure". Diakses pada 2 Juni 2024, dari https://www.tutorialspoint.com/data_structures_algorithms/hash_data_structure.htm

[6] Vibrant Publishers. (2022). "Collision Resolution with Hashing". Diakses pada 3 Juni 2024, dari https://www.vibrantpublishers.com/blogs/blogs-on-programming/collision-resolution-with-hashing

[7] Saylor Academy. (2024). "Searching and Hashing". Diakses pada 4 Juni 2024, dari https://learn.saylor.org/mod/book/view.php?chapterid=12838&id=32990
