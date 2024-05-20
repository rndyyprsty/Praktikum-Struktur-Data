# <h1 align="center">Laporan Praktikum Modul Priority Queue & Heaps</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

### Queue

Priority Queue adalah kelas turunan di STL (Standard Template Library) yang hanya memproses elemen dengan prioritas tertinggi. Artinya elemen antrian pertama adalah yang terbesar dari elemen antrian lainnya. Nanti semua elemen disusun dalam urutan tidak bertambah, yang berarti kita dapat melihat setiap elemen queue yang memiliki prioritas tetap[1]. Struktur data queue mengikuti strategi FIFO yaitu first in, first out, sedangkan priority queue hanya memeriksa prioritas elemen untuk pengambilan elemen. Antrian prioritas diimplementasikan sebagai adaptor kontainer. Ini adalah kelas yang menggunakan objek yang dienkapsulasi dari kelas kontainer tertentu dan memberikan serangkaian fungsi anggota tertentu untuk mengakses elemen antrian[2].  

Ada beberapa metode priority queue, seperti:
a. push()
b. pop()
c. empty()
d. size()
e. top()
f. emplace()
g. swap()

Priority queue dapat diimplementasikan menggunakan array, binary search tree, linked list, dan struktur data heap. Namun, pilihan terbaik yang ada adalah struktur data heap karena heap dapat membantu implementasi priority queue yang relatif lebih cepat dan efisien[3].

### Heaps

Heaps adalah struktur data dasar yang dapat diimplementasikan menggunakan Standard Template Library (STL). Heap adalah struktur data berbentuk complete binary tree yang memenuhi heap property. Properti ini menyatakan bahwa untuk setiap node tertentu, semua node turunannya memiliki nilai yang kurang dari atau sama dengan node tersebut[4]. Complete binary tree sendiri dapat didefinisikan sebagai binary tree di mana semua level terisi penuh, kecuali level terakhir. Semua kunci atau nilai pada level terakhir harus rata kiri apabila tidak terisi penuh[5].

Ada beberapa properti yang ada pada heaps, seperti:
1. Max Heap Property
    Parent selalu lebih besar atau sama dengan node Child dan key dari root node adalah yang terbesar di antara semua node lainnya.
2. Min Heap Property
    Parent selalu lebih kecil dari node Child dan key dari root node adalah yang terkecil di antara semua node lainnya[6].

Beberapa operasi yang umumnya terlibat dengan heaps, yaitu:
1. Heapify: Proses untuk mengatur ulang heap untuk mempertahankan properti heap.
2. Find-max (atau Find-min): Menemukan item maksimum dari max-heap, atau item minimum dari min-heap.
3. Insertion: Menambahkan item baru di heap.
4. Deletion: Menghapus item dari heap.
5. Extract Min-Max: Mengembalikan dan menghapus elemen maksimum atau minimum masing-masing di max-heap dan min-heap[7].

## Guided

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    
    return 0;
}
```

## Penjelasan Program

Program ini mengimplementasi struktur data max-heap menggunakan array H dan variabel heapSize untuk melacak ukuran heap. Fungsi utamanya yaitu insert untuk menambahkan elemen, extractMax untuk menghapus elemen terbesar, changePriority untuk mengubah nilai elemen tertentu, dan remove untuk menghapus elemen dari heap. Fungsi tambahan seperti parent, leftChild, dan rightChild digunakan untuk navigasi dalam heap, sementara shiftUp dan shiftDown digunakan untuk menjaga properti max-heap setelah penyisipan atau penghapusan.

Dalam fungsi main, beberapa elemen dimasukkan ke heap dan operasi heap dilakukan, seperti menghapus elemen terbesar dan mengubah prioritas elemen. Setelah setiap operasi, keadaan heap di print untuk menunjukkan perubahan yang terjadi.

### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/96993d12-659d-4dc3-b58f-790057840581)

## Unguided

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

void printHeap() {
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int n, element;
    std::cout << "Enter the number of elements to insert into heap: ";
    std::cin >> n;

    std::cout << "Enter the elements of the heap: \n";
    for (int i = 0; i < n; ++i) {
        std::cin >> element;
        insert(element);
    }

    std::cout << "Priority Queue: ";
    printHeap();

    std::cout << "Node with maximum priority: " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum: ";
    printHeap();

    std::cout << "Enter the index and the new priority value: ";
    int index, priority;
    std::cin >> index >> priority;
    changePriority(index, priority);

    std::cout << "Priority queue after priority change: ";
    printHeap();

    std::cout << "Enter the index of the element to remove: ";
    std::cin >> index;
    remove(index);

    std::cout << "Priority queue after removing the element: ";
    printHeap();
    
    return 0;
}
```

#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/eac50f91-b404-4456-b7f7-7c64b4458111)

#### Penjelasan Program

Setelah program guided di modifikasi, program ini akan meminta input jumlah elemen yang ingin dimasukkan ke dalam heap dan kemudian memasukkan elemen-elemen tersebut satu per satu menggunakan std::cin. Kemudian Fungsi printHeap ditambahkan untuk mencetak isi heap secara rapi. Terakhir, bagian main diatur agar meminta input dan menggunakan fungsi printHeap untuk mencetak isi heap setelah setiap operasi insert, extractMax, changePriority & remove selesai.

Secara keseluruhan, program ini adalah implementasi Max-Heap menggunakan array. Program ini berisi fungsi untuk mendapatkan parent, left child, dan right child dari sebuah node, serta fungsi untuk menjaga properti heap melalui operasi shiftUp dan shiftDown. Operasi utama dalam heap seperti insert (menambah elemen), extractMax (mengeluarkan elemen maksimum), changePriority (mengubah prioritas elemen), dan remove (menghapus elemen) juga diimplementasi.

Dalam fungsi main, program meminta input dari pengguna untuk memasukkan jumlah elemen dan elemen-elemen itu sendiri ke dalam heap. Setelah itu, program mencetak isi heap, mengeluarkan elemen maksimum, dan mencetak heap setelah operasi tersebut. Program juga meminta input untuk mengubah prioritas elemen tertentu dan menghapus elemen pada indeks tertentu, lalu mencetak heap setelah setiap perubahan. 

## Kesimpulan

Priority Queue memungkinkan kita mengolah elemen berdasarkan prioritasnya. Hal ini diimplementasikan secara efisien dengan menggunakan struktur data heap, khususnya max-heap. Operasi dasar pada heap seperti insert, extractMax, changePriority, dan remove menjaga properti heap melalui fungsi shiftUp dan shiftDown. Implementasi ini juga menunjukkan bagaimana heap dapat dibangun dan dimanipulasi secara dinamis berdasarkan inputan. Praktikum kali ini menekankan pentingnya heap dalam membangun priority queue yang efisien. Heap menyediakan waktu yang relatif cepat untuk operasi insert dan extractMax, yaitu O(log n). Selain itu, pemahaman tentang properti max-heap dan min-heap dapat mempermudah pemahaman bagaimana elemen-elemen diatur dan diakses.

## Referensi
[1] Bhadaniya, S. (2021). "Priority Queue - Insertion, Deletion and Implementation in C++". Diakses pada 18 Mei 2024, dari https://favtutor.com/blogs/priority-queue-cpp

[2] Romford, L. (2024). "How to Work with C++ Priority Queue". Diakses pada 18 Mei 2024, dari https://academichelp.net/coding/cpp/priority-queue.html

[3] Barata, G.S.H., Pangestu, B.B, Lay, E.W. & Alghifari, M. (2022). "Priority Queue". Diakses pada 19 Mei 2024, dari https://www.scribd.com/document/657230171/Makalah-Priority-Queue-revisi

[4] Josuttis, N.M. (2012). C++ Standard Library: A Tutorial and Reference. Boston: Addison-Wesley Professional.

[5] Stroustrup, B. (2013). The C++ Programming Language. Boston: Addison-Wesley Professional.

[6] Boccara, J. (2018). "Heaps and Priority Queues in C++ – Part 1: Heaps Basics", diakses pada 20 Mei 2024, dari https://www.fluentcpp.com/2018/03/13/heaps-priority-queues-stl-part-1/

[7] Santoso, J.T. (2021). STRUKTUR DATA DAN ALGORITMA (BAGIAN 1). Semarang: Yayasan Prima Agus Teknik.