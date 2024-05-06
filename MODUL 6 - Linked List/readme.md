# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

### A. Single Linked List

Single Linked list adalah Daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya.
Pembentukan linked list tunggal memerlukan:
1. deklarasi tipe simpul
2. deklarasi variabel pointer penunjuk awal Linked list
3. pembentukan simpul baru
4. pengaitan simpul baru ke Linked list yang telah terbentuk
Ada beberapa operasi yang dapat dibuat pada senarai tersebut, yaitu seperti tambah, hapus dan edit[1].

Single linked list atau biasa disebut linked list terdiri dari elemen-elemen individu, dimana masing-masing dihubungkan dengan pointer tunggal. Masing-masing elemen terdiri dari dua bagian, yaitu sebuah data dan sebuah pointer yang disebut dengan pointernext. Dengan menggunakan struktur two-member seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. Elemen pada awal suatu list disebut head, dan elemen terakhir dari suatu list disebut tail[2]. Single linked list adalah linked list unidirectional. Jadi, kita hanya dapat melintasinya dalam satu arah, yaitu dari simpul kepala ke simpul ekor.

### B. Double Linked List

Double linked list merupakan rangkaian dari node/simpul yang saling terhubungan dengan menggunakan dua pointer dalam satu elemen dan list dapat melintas baik di depan atau belakang[3]. Double linked list adalah linked list bidirectional. Jadi, kita bisa melintasinya secara dua arah. Tidak seperti singly linked list, simpul doubly linked list berisi satu pointer tambahan yang disebut previous pointer. Pointer ini menunjuk ke simpul sebelumnya[4]. Setiap node dalam DLL terdiri dari tiga field: dua field link (referensi ke node sebelumnya dan ke node berikutnya dalam urutan) dan satu field data. Node pertama dan terakhir dalam DLL untuk semua tujuan aplikasi yang praktis dapat diakses langsung (i.e., dapat diakses tanpa traversal) dan biasanya disebut sebagai "head" dan "tail" masing-masing. DLL memungkinkan traversal dalam arah mana pun, termasuk perubahan arah traversal beberapa kali jika diinginkan. DLL memerlukan pointer pada node pertama dan terakhir untuk diupdate setelah penambahan atau penghapusan node pertama atau terakhir. DLL memerlukan pointer pada node sekitar untuk diupdate setelah penghapusan node dari tengah list. DLL memerlukan pointer pada node sebelum dan setelah node yang akan dihapus untuk diupdate setelah penghapusan node[5].

### C. Non-Circular Linked List

Non Circular Linked List adalah jenis linked list yang node terakhirnya tidak menunjuk ke node pertama, berbeda dengan circular linked list yang node terakhirnya menunjuk kembali ke node pertama[6].

### D. Circular Linked List

Circular Linked List (CLL) adalah jenis daftar tertaut yang semua nodenya terhubung membentuk lingkaran. Dalam CLL, node pertama dan node terakhir dihubungkan satu sama lain, membentuk lingkaran. Tidak ada NULL di akhir. Struktur ini memungkinkan penyisipan dan penghapusan node secara efisien di posisi mana pun dalam daftar. Ada dua jenis CLL: Circular Singly Linked List (CSLL) dan Circular Double Linked List (CDLL). Dalam CSLL, simpul terakhir dari daftar berisi penunjuk ke simpul pertama dari daftar. Dalam CDLL, dua elemen yang berurutan dihubungkan atau dihubungkan oleh penunjuk sebelumnya dan berikutnya, dan simpul terakhir menunjuk ke simpul pertama dengan penunjuk berikutnya dan juga simpul pertama menunjuk ke simpul terakhir dengan penunjuk sebelumnya[7].

## Guided 

### 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Kode ini adalah implementasi dari sebuah linked list tunggal (single linked list) non-circular. Program utama di main() melakukan serangkaian operasi pada linked list, seperti menambahkan, menghapus, dan mengubah nilai node, serta menampilkan isi linked list setelah setiap operasi dilakukan.

### 2. Latihan Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Kode ini adalah implementasi dari Doubly Linked List (daftar berantai berganda) dalam C++. Ini memiliki dua kelas, yaitu Node untuk merepresentasikan simpul dalam linked list dan DoublyLinkedList untuk merepresentasikan linked list itu sendiri.
Program utama memiliki loop yang meminta pengguna untuk memilih operasi apa yang ingin mereka lakukan pada linked list: menambahkan data, menghapus data, memperbarui data, menghapus seluruh data, atau menampilkan seluruh isi linked list. Program akan terus berjalan hingga pengguna memilih untuk keluar.

### 3. Linked List Non Circular

```C++
#include <iostream>

// Definisi simpul (node) dalam linked list
struct ListNode {
    int val; // Nilai dari simpul
    ListNode *next; // Pointer ke simpul selanjutnya
    ListNode(int x) : val(x), next(nullptr) {} // Konstruktor untuk inisialisasi nilai dan pointer
};

// Kelas untuk merepresentasikan linked list
class LinkedList {
private:
    ListNode *head; // Pointer ke simpul pertama (head)

public:
    // Konstruktor untuk inisialisasi linked list
    LinkedList() : head(nullptr) {}

    // Fungsi untuk menambahkan simpul baru ke akhir linked list
    void append(int value) {
        // Buat simpul baru dengan nilai yang diberikan
        ListNode *newNode = new ListNode(value);

        // Jika linked list masih kosong, atur simpul baru sebagai head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Temukan simpul terakhir dalam linked list
        ListNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        // Tambahkan simpul baru setelah simpul terakhir
        current->next = newNode;
    }

    // Fungsi untuk mencetak seluruh isi linked list
    void printList() {
        ListNode *current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destruktor untuk menghapus semua simpul dalam linked list
    ~LinkedList() {
        ListNode *current = head;
        while (current != nullptr) {
            ListNode *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    // Membuat objek dari kelas LinkedList
    LinkedList myList;

    // Menambahkan beberapa elemen ke linked list
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);

    // Mencetak isi linked list
    std::cout << "Linked List: ";
    myList.printList();

    return 0;
}
```
Program ini adalah implementasi dari linked list yang membuat sebuah kelas `LinkedList` yang memiliki struktur simpul `ListNode`. Metode `append` digunakan untuk menambahkan elemen baru ke linked list. Metode `printList` mencetak seluruh isi linked list. Program kemudian menciptakan sebuah objek `myList` dari kelas `LinkedList`, menambahkan beberapa elemen, dan mencetak isi linked list. Saat program selesai dijalankan, destruktor dari kelas `LinkedList` akan dipanggil untuk menghapus semua simpul dalam linked list dan mencegah kebocoran memori.

### 4. Linked List Circular

```C++
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};

// Fungsi untuk mencetak linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Membuat linked list sebagai contoh
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    std::cout << "Linked List awal: ";
    printList(head);

    // Memanggil fungsi deleteDuplicates
    Solution solution;
    ListNode* newHead = solution.deleteDuplicates(head);

    std::cout << "Linked List setelah menghapus duplikat: ";
    printList(newHead);

    // Menghapus linked list untuk mencegah kebocoran memori
    ListNode* current = newHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
```
Kode ini adalah program yang menghapus duplikat dari linked list. Membuat linked list, kemudian menggunakan metode `deleteDuplicates` di kelas `Solution` untuk menghapus duplikat. Algoritma yang digunakan adalah mengunjungi setiap node dan menghapus node-node yang memiliki nilai yang sama dengan node berikutnya. Sesudah itu, hasilnya dicetak dan memori yang dialokasikan untuk linked list dihapus untuk mencegah kebocoran memori.

## Unguided 

### Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa

```C++
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
```
#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/b3d65abd-06f3-46b7-a865-b3ec28d76aa5)

#### Penjelasan Program:

Program ini adalah implementasi dari menu Linked List Non Circular menggunakan yang memungkinkan pengguna untuk melakukan operasi pada data mahasiswa. Menu yang disediakan mulai dari penambahan data di depan, di belakang, dan di tengah, pengubahan data di depan, di belakang, dan di tengah, penghapusan data di depan, di belakang, dan di tengah, penghapusan seluruh data, serta menampilkan semua data yang telah dimasukkan. Program ini menggunakan struktur data linked list untuk menyimpan nama dan NIM mahasiswa.

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/bba18d1e-cc2b-411d-afe2-77b0567ac03d)

#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/9bc93710-00ed-4f37-a7c4-6d09c83290f8)

### 3. Lakukan Perintah Berikut:

#### A. Tambahkan data berikut diantara farrel dan denis
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/7afe4259-7158-4479-aa03-50a585f5c36f)

#### B. Hapus Data Denis
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/dd9aebf7-01c7-40c0-bba6-38f2e31bd73e)

#### C. Tambahkan Data berikut di awal
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/8faba2ad-1f30-4053-9975-f9ea12bab5c0)

#### D. Tambahkan data berikut di akhir
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/2ce819c2-ba75-4073-bf42-22e8753ca7fe)

#### E. Ubah data udin menjadi data berikut
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/570dea6e-f84e-4be8-905f-7d37ed88f4d3)

#### F. Ubah data terakhir menjadi berikut
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/c79751b0-5f0e-4fa1-b948-0d4278f84686)

#### G. Hapus data awal
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/4073e0a3-1147-48eb-b993-cf0a61d5518f)

#### H. Ubah data awal menjadi berikut
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/e2ad80e0-126a-4ce6-956d-3f071921d8bd)

#### I. Hapus Data Akhir
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/8de52648-324b-4f70-999e-210df5328162)

#### J. Tampilkan Seluruh Data
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/87c00f2f-cf99-4571-9a36-6ae7b9034a69)

## Kesimpulan
Linked List adalah suatu cara untuk menyimpan data dengan struktur sehingga
programmer dapat secara otomatis menciptakan suatu tempat baru untuk menyimpan
data kapan saja diperlukan. Linked list dikenal juga dengan sebutan senarai berantai
adalah stuktur data yang terdiri dari urutan record data dimana setiap record memiliki
field yang menyimpan alamat/referensi dari record selanjutnya (dalam urutan). Elemen
data yang dihubungkan dengan link pada linked list disebut Node. Biasanya dalam
suatu linked list, terdapat istilah head dan tail .

## Referensi
[1] Triase, S.T. (2020). "Diktat Struktur Data". Diakses pada 28 April 2024, dari http://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf

[2] Ibad, I. (2013). "Linked List". Diakses pada 28 April 2024, dari https://www.scribd.com/doc/144549239/Jurnal-Linked-List

[3] Permana, R., Indrajit, R.E., Aryanti, R., & Yanto, A.B.H (2018). Implementasi Model Information Retrieval untuk
Pencarian Konten pada KUHP Berdasarkan Tingkatan Hukuman Terberat di Indonesia. Jurnal PILAR Nusa Mandiri, 14(1), 89-96.

[4] Trivusi. (2022). "Struktur Data Linked List: Pengertian, Karakteristik, dan Jenis-jenisnya". Diakses pada 28 April 2024, dari https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html?m=1

[5] Codeacademy. (2017). "Doubly Linked List". Diakses pada 28 April 2024, dari https://www.codecademy.com/article/doubly-linked-list-conceptual

[6] Rakhman, A.A. (2013). "Double Linked List Non Circular". Diakses pada 28 April 2024, dari https://www.scribd.com/document/122397485/Double-Linked-List-Non-Circular

[7] Programiz. (2013). "Circular Linked List". Diakses pada 28 April 2024, dari https://www.programiz.com/dsa/circular-linked-list