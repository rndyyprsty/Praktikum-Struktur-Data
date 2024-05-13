# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

### Queue

Queue atau bisa disebut antrian adalah sebuah struktur data yang mengikuti prinsip "First-In-First-Out" (FIFO), di mana elemen pertama yang ditambahkan ke dalam antrian adalah elemen pertama yang dihapus dari antrian. Queue digunakan untuk mengatur dan mengelola data dalam urutan tertentu, dengan cara elemen yang pertama ditambahkan ke dalam antrian adalah elemen yang pertama dihapus[1].  

Queue dalam C++ dapat didefinisikan sebagai struktur data yang memungkinkan operasi tambah (enqueue) dan hapus (dequeue) elemen di ujung belakang (rear) dan ujung depan (front) antrian, secara berurutan[2]

Dalam implementasinya, queue biasanya menggunakan dua pointer, yaitu FRONT dan REAR, untuk mengindikasikan posisi elemen pertama dan terakhir di dalam antrian. Operasi tambah elemen dilakukan dengan menambahkan elemen baru di ujung belakang antrian dan meningkatkan nilai REAR, sedangkan operasi hapus elemen dilakukan dengan menghapus elemen di ujung depan antrian dan meningkatkan nilai FRONT[3].

Operasi pada FIFO (First-In-First-Out) queue dalam C++ meliputi operasi tambah (enqueue) dan hapus (dequeue) elemen di ujung belakang (rear) dan ujung depan (front) antrian, secara berurutan. Operasi tambah elemen dilakukan dengan menambahkan elemen baru di ujung belakang antrian dan meningkatkan nilai REAR, sedangkan operasi hapus elemen dilakukan dengan menghapus elemen di ujung depan antrian dan meningkatkan nilai FRONT[4].

## Guided

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
```

## Penjelasan Program

Di program ini queue direpresentasikan menggunakan array queueTeller dengan ukuran maksimum yang telah ditentukan sebelumnya. Ada dua penanda, yaitu front dan back, yang menunjukkan elemen pertama dan terakhir dalam queue. Fungsi isFull() dan isEmpty() digunakan untuk memeriksa apakah queue sudah penuh atau kosong. Fungsi enqueueAntrian(string data) digunakan untuk menambahkan elemen baru ke dalam queue, sementara dequeueAntrian() menghapus elemen pertama dari queue.

Fungsi lainnya termasuk countQueue() untuk menghitung jumlah elemen dalam queue, clearQueue() untuk menghapus semua elemen dalam queue, dan viewQueue() untuk menampilkan semua elemen dalam queue beserta nomor urutannya. Di fungsi main(), program melakukan serangkaian operasi pada queue seperti penambahan elemen, penghapusan elemen, dan penghapusan semua elemen. Setiap operasi yang dilakukan akan diikuti dengan penampilan jumlah elemen dalam queue serta tampilan semua elemen dalam queue. 

### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/c229fec5-990f-48ef-9927-11f2a4a776a6)

## Unguided

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list!

```C++
#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    
    Node(string d) : data(d), next(nullptr) {}
};

class Queue {
private:
    Node* front; 
    Node* rear;  
    int size;    
    
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        clearQueue();
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(string data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    string peek() {
        if (isEmpty()) {
            return "Antrian kosong";
        } else {
            return front->data;
        }
    }

    int count() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* current = front;
            cout << "Data antrian teller:" << endl;
            while (current != nullptr) {
                cout << current->data << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue("Andi");
    queue.enqueue("Maya");
    queue.displayQueue();
    cout << "Jumlah antrian = " << queue.count() << endl;

    queue.dequeue();
    queue.displayQueue();
    cout << "Jumlah antrian = " << queue.count() << endl;

    queue.clearQueue();
    queue.displayQueue();
    cout << "Jumlah antrian = " << queue.count() << endl;

    return 0;
}
```

#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/2bdad21f-7ac7-46cb-920d-e5ed414a11a3)

#### Penjelasan Program

Program ini menggunakan dua kelas utama: Node dan Queue. Node merepresentasikan elemen-elemen individu dalam queue dengan menyimpan informasi dari setiap elemen dan alamat elemen selanjutnya dalam queue. Sementara itu, kelas Queue mengelola logika manipulasi queue, termasuk penambahan (enqueue) dan penghapusan (dequeue) elemen, pemeriksaan apakah queue kosong (isEmpty), dan operasi seperti melihat elemen pertama (peek), menghitung jumlah elemen (count), membersihkan queue (clearQueue), dan menampilkan semua elemen dalam queue (displayQueue). Di fungsi main() program membuat objek Queue dan melakukan operasi pada queue itu seperti penambahan dan penghapusan elemen, dan menampilkan jumlah elemen setiap kali operasi dilakukan.

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa!

```C++
#include <iostream>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
    
    Node(string n, string id) : nama(n), nim(id), next(nullptr) {}
};

class Queue {
private:
    Node* front; 
    Node* rear;  
    int size;    
    
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        clearQueue();
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(string nama, string nim) {
        Node* newNode = new Node(nama, nim);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Nama: " << front->nama << ", NIM: " << front->nim << endl;
        }
    }

    int count() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* current = front;
            cout << "Data antrian mahasiswa:" << endl;
            while (current != nullptr) {
                cout << "Nama: " << current->nama << ", NIM: " << current->nim << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    Queue antrian;

    antrian.enqueue("Andi", "123456");
    antrian.enqueue("Maya", "654321");
    antrian.displayQueue();
    cout << "Jumlah antrian = " << antrian.count() << endl;

    antrian.dequeue();
    antrian.displayQueue();
    cout << "Jumlah antrian = " << antrian.count() << endl;

    antrian.enqueue("Budi", "987654");
    antrian.displayQueue();
    cout << "Jumlah antrian = " << antrian.count() << endl;

    cout << "Elemen di depan antrian: ";
    antrian.peek();

    antrian.clearQueue();
    antrian.displayQueue();
    cout << "Jumlah antrian = " << antrian.count() << endl;

    return 0;
}
```
#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/5ba7d492-1dd8-44fb-9d47-0a5a7cb99141)

#### Penjelasan Program

Di program ini ada dua kelas utama yaitu Node dan Queue. Node merepresentasikan elemen-elemen individu dalam queue dengan menyimpan informasi nama dan NIM dari setiap mahasiswa, dan juga alamat elemen selanjutnya dalam queue. Lalu kelas Queue mengelola logika manipulasi queue, termasuk penambahan elemen baru (enqueue), penghapusan elemen (dequeue), pemeriksaan apakah queue kosong (isEmpty), melihat elemen pertama tanpa menghapusnya (peek), menghitung jumlah elemen (count), membersihkan queue (clearQueue), dan menampilkan semua elemen dalam queue (displayQueue).

Di fungsi main(), program membuat objek Queue bernama queue dan melakukan serangkaian operasi pada queue tersebut. Operasi yang dilakukan antara lain: menambahkan elemen mahasiswa dengan nama dan NIM tertentu, menampilkan semua elemen dalam queue beserta jumlah elemennya, menghapus elemen pertama dari queue, menambahkan elemen baru, menampilkan elemen di depan queue tanpa menghapusnya, membersihkan queue, dan menampilkan kembali queue kosong setelah dibersihkan. Setiap kali operasi dilakukan, jumlah elemen dalam queue juga ditampilkan untuk memberikan informasi tentang ukuran queue pada setiap langkahnya.

## Kesimpulan

Konsep FIFO (First In First Out) adalah prinsip dasar yang menjadi landasan struktur data queue. Dalam prinsip FIFO, elemen yang pertama kali dimasukkan ke dalam suatu struktur data akan menjadi elemen yang pertama kali diambil atau diproses. Konsep ini diterapkan dalam berbagai konteks dan aplikasi di dunia nyata serta dalam dunia pemrograman. Dalam dunia pemrograman, struktur data queue digunakan untuk mengimplementasikan prinsip FIFO secara efisien. Queue biasanya digunakan dalam berbagai aplikasi, termasuk sistem penjadwalan dalam sistem operasi, penanganan pesan dalam pemrograman jaringan, simulasi antrian dalam pemodelan sistem, dan banyak lagi.Penerapan konsep FIFO dan queue membantu dalam menyelesaikan banyak masalah dan tugas komputasi. Mereka memungkinkan untuk mengorganisir dan mengelola data dalam urutan yang tepat, serta memastikan bahwa elemen-elemen diproses sesuai dengan urutan kedatangannya. 

## Referensi
[1] Larkin, D.H., Sen, S. & Tarjan, R.E. (2014). "A Back-to-Basics Empirical Study of Priority Queues". Diakses pada 7 Mei 2024, dari https://arxiv.org/abs/1403.0252v1

[2] Sruthy. (2024). "Queue Data Structure In C++ With Illustration". Diakses pada 7 Mei 2024, dari https://www.softwaretestinghelp.com/queue-in-cpp/

[3] Sharma, A. (2022). "Data Structures in C++ – Queue & Heap". Diakses pada 11 Mei 2024, dari https://www.prepbytes.com/blog/queues/data-structures-in-c-queue-heap-2/

[4] Kochar, A. (2022). "Applications of Queue in Data Structure". Diakses pada 12 Mei 2024, dari https://www.prepbytes.com/blog/queues/applications-of-queue-data-structure/