# <h1 align="center">Laporan Praktikum Modul Graph & Tree</h1>
<p align="center">Muhammad Randy Prasetya</p>
<p align="center">2311110015</p>

## Dasar Teori

### Graph

Graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi). Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Representasi visual dari graph adalah dengan menyatakan objek sebagai noktah, bulatan atau titik (Vertex), sedangkan hubungan antara objek dinyatakan dengan garis (Edge)[1].

Graf merupakan suatu cabang ilmu yang memiliki banyak terapan. Banyak sekali struktur yang bisa direpresentasikan dengan graf, dan banyak masalah yang bisa diselesaikan dengan bantuan graf. Seringkali graf digunakan untuk merepresentasikan suaru jaringan. Misalkan jaringan jalan raya dimodelkan graf dengan kota sebagai simpul (vertex/node) dan jalan yang menghubungkan setiap kotanya sebagai sisi (edge) yang bobotnya (weight) adalah panjang dari jalan tersebut[2].

#### Jenis-Jenis Graph
1. Undirected Graph :
Urutan simpul dalam sebuah busur tidak dipentingkan. Misal busur e1
dapat disebut busur AB atau BA
2. Directed Graph
Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan
busur BA adalah e8.
3. Weighted Graph :
- Jika setiap busur mempunyai nilai yang menyatakan hubungan
antara 2 buah simpul, maka busur tersebut dinyatakan memiliki
bobot.
- Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari 2
buah titik, jumlah rata-rata kendaraan perhari yang melalui sebuah
jalan atau hal lainnya[3].

#### Representasi Graph

##### 1. Representasi dengan Matriks (Adjacency Matrix)
Adjacency Matrix merupakan representasi matriks nxn yang menyatakan hubungan antar simpul dalam suatu graf. Kolom dan baris dari matriks ini merepresentasikan simpul-simpul, dan nilai entri dalam matriks ini menyatakan hubungan antar simpul, apakah terdapat sisi yang menghubungkan kedua simpul tersebut. Pada sebuah matriks nxn, entri non-diagonal aij merepresentasikan sisi dari simpul i dan simpul j. Sedangkan entri diagonal aii menyatakan sisi kalang(loop) pada simpul i[4].

Kelebihan dari adjacency matrix ini adalah elemen matriksnya dapat diakses langsung melalui indeks, dengan begitu hubungan ketetanggan antara kedua simpul dapat ditentukan dengan langsung. Sedangkan kekurangan pada representasi ini adalah bila graf memiliki jumlah sisi atau busur yang relative sedikit, karena matriksnya bersifat jarang yaitu hanya mengandung elemen bukan nol yang sedikit. Kasus seperti ini merugikan, karena kebutuhan ruang memori untuk matriks menjadi boros dan tidak efisien karena komputer menyimpan elemen 0 yang tidak perlu[5].

##### 2. Representasi dengan Linked List (Adjacency List)
Adjacency list merupakan bentuk representasi dari seluruh sisi atau busur dalam suatu graf sebagai suatu senarai. Simpul-simpul yang dihubungkan sisi atau busur tersebut dinyatakan sebagai simpul yang saling terkait. Dalam implementasinya, hash table digunakan untuk menghubungkan sebuah simpul dengan senarai berisi simpul-simpul yang saling terkait tersebut[6].

Salah satu kekurangan dari teknik representasi ini adalah tidak adanya tempat untuk menyimpan nilai yang melekat pada sisi. Contoh nilai ini antara lain berupa jarak simpul, atau beban simpul.

### Tree

Kumpulan node yang saling terhubung satu sama lain dalam suatu kesatuan yang membentuk layakya struktur sebuah pohon. Struktur pohon adalah suatu cara merepresentasikan suatu struktur hirarki (one-to-many) secara grafis yang mirip sebuah pohon, walaupun pohon tersebut hanya tampak sebagai kumpulan node-node dari atas ke bawah[7]. Pohon (tree) tidak mengandung sirkuit. Pohon (tree) juga merupakan struktur data yang tidak linier yang digambarkan dengan hubungan yang bersifat hirarkis antar satu elemen[8].

#### Operasi-Operasi Pada Tree
1. Create : Membentuk binary tree baru yang masih kosong
2. Clear : Mengosongkan binary tree yang sudah ada
3. Empty Function : untuk memeriksa apakah binary tree masih kosong
4. Insert : Memasukkan sebuah node ke dalam tree. Ada tiga pilihan insert : sebagai root, left child, atau right child. Khusus insert sebagai root, tree harus dalam keadaan kosong
5. Find : Mencari root, parent, left child, atau right child dari suatu node. (tree tidak boleh kosong).
6. Update : Mengubah isi dari node yang ditunjuk oleh pointer curret (Tree tidak boleh kosong)
7. Retrieve : Mengetahui isi dari node yang ditunjuk oleh pointer current (Tree tidak boleh kosong)
8. DeleteSub : Menghapus sebuah subtree (node beserta seluruh descendantnya) yang ditunjuk current. Tree tidak boleh kosong. Setelah itu, pointer current dakan berpindah ke parent dari node yang dihapus.
9. Characteristic : Mengetahui karakteristik dari suatu tree, yakni: size, height, serta average length. Tree tidak boleh kosong.
10. Traverse : Mengunjungi seluruh node-node pada tree, masing-masing sekali. Hasilnya adalah urutan informasi secara linear yang tersimpan dalam tree. Ada tiga cara traverse,yaitu PreOrder, InOrder, dan PostOrder[9]. 
- Preorder : cetak isi node yang dikunjungi, kunjungi Left Child, kunjungi Right Child 
- Inorder : kunjungi Left Child, cetak isi node yang dikunjungi, kunjungi Right Child 
- Postorder : kunjungi Left Child, kunjungi Right Child cetak isi node yang dikunjungi[10].

## Guided

### 1. Guided I

```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {"Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogjakarta"};
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++) {
        for (int kolom = 0; kolom < 7; kolom++) {
            cout << setw(3) << busur[baris][kolom];
        }
        cout << endl;
    }
}

int main()
{
    tampilGraph();
    return 0;
}
```

## Penjelasan Program

Program di atas mengelola dan menampilkan representasi graf menggunakan matriks untuk beberapa kota. Disini array `simpul` menyimpan nama-nama kota. Matriks `busur` berisi nilai jarak antar kota. Nilai 0 dalam matriks menunjukkan tidak adanya jalur langsung antara dua kota, sedangkan nilai selain 0 menunjukkan adanya jalur. Fungsi `tampilGraph` menampilkan matriks, menggunakan `setw` untuk memastikan setiap nilai ditampilkan dengan lebar yang sama. Dalam fungsi `main`, `tampilGraph` dipanggil untuk menampilkan hubungan antar kota beserta jalur yang menghubungkan mereka.

### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/e3dbeda3-be7d-4c2e-bd01-a3229cc823d3)

### 2. Guided II

```C++
#include <iostream>
using namespace std;

/// PROGRAM BINARY TREE

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
int isEmpty() {
    if (root == NULL)
        return 1;
    else
        return 0;
}

// Buat Node Baru
void buatNode(char data) {
    if (isEmpty() == 1) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL) {
            // kalau ada
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node) {
    if (root == NULL) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL) {
            // kalau ada
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Ubah Data Tree
void update(char data, Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node: " << node->data << endl;
        }
    }
}

// Cari Data Tree
void find(Pohon *node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root) {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root) {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root) {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    cout << "\nSize Tree: " << size() << endl;
    cout << "Height Tree: " << height() << endl;
    cout << "Average Node of Tree: " << size() / height() << endl;
}

int main() {
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);

    cout << "\nPreOrder:" << endl;
    preOrder(root);
    cout << "\n" << endl;

    cout << "InOrder:" << endl;
    inOrder(root);
    cout << "\n" << endl;

    cout << "PostOrder:" << endl;
    postOrder(root);
    cout << "\n" << endl;

    return 0;
}
```

## Penjelasan Program

Program di atas mengelola pohon biner yang dimulai dari deklarasi struktur pohon. Struktur pohon itu memiliki elemen data serta pointer ke child kiri kanan, dan parent. Inisialisasi pohon dilakukan dengan menyatakan root sebagai NULL. Fungsi yang ada meliputi pembuatan node baru, penambahan child kiri dan kanan, dan juga update data node. Program juga bisa ngecek keberadaan node, pengambilan data dari node, dan pencarian node. Traversal pohon menggunakan metode pre-order, in-order, dan post-order. Lalu program bisa menghapus node, subtree, seluruh pohon, dan juga menghitung ukuran dan tinggi pohon. Di fungsi main(), program mendemonstrasikan pembuatan node, pembentukan struktur pohon, pembaruan dan pengambilan data, serta penelusuran dan penghapusan node.

### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/5da0390a-ceb1-45a2-9111-5dfd8f4061b7)

## Unguided

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.


```C++
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
```

#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/ca44b473-c1cb-4fb7-9fc1-75a559720307)

#### Penjelasan Program

Program ini menerima input untuk menentukan jarak antar kota dan menampilkan matriks jaraknya. Kita diminta untuk memasukkan jumlah, nama, dan jarak setiap pasangan kota. Nama kota disimpan di vektor kota, dan jarak kota disimpan di matriks matriks_jarak. Setiap elemen matriks diisi dengan jarak yang menunjukkan jarak dari satu kota ke kota lainnya.

Setelah data diinput, program menampilkan matriks jarak. Program mengprint nama-nama kota sebagai header baris dan kolom. Kemudian, untuk setiap kota, program mengprint jarak ke setiap kota lainnya. Hasilnya adalah tabel yang menunjukkan jarak dari setiap kota ke kota lainnya.


### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```
#include <iostream>
#include <queue>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right;
};

Pohon *root = NULL;

void buatNode(char data) {
    if (root == NULL) {
        root = new Pohon();
        root->data = data;
        root->left = root->right = NULL;
        cout << "\nNode " << data << " root dibuat." << endl;
    } else {
        cout << "\nPohon sudah punya root." << endl;
    }
}

void insertLeft(char data, char parentData) {
    queue<Pohon*> q;
    q.push(root);
    while (!q.empty()) {
        Pohon* node = q.front();
        q.pop();
        if (node->data == parentData) {
            if (node->left == NULL) {
                node->left = new Pohon();
                node->left->data = data;
                node->left->left = node->left->right = NULL;
                cout << "\nNode " << data << " berhasil ditambah ke child kiri " << parentData << endl;
                return;
            } else {
                cout << "\nNode " << parentData << " sudah ada child kiri." << endl;
                return;
            }
        }
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
    cout << "\nNode " << parentData << " ga ada." << endl;
}

void insertRight(char data, char parentData) {
    queue<Pohon*> q;
    q.push(root);
    while (!q.empty()) {
        Pohon* node = q.front();
        q.pop();
        if (node->data == parentData) {
            if (node->right == NULL) {
                node->right = new Pohon();
                node->right->data = data;
                node->right->left = node->right->right = NULL;
                cout << "\nNode " << data << " berhasil ditambah ke child kanan " << parentData << endl;
                return;
            } else {
                cout << "\nNode " << parentData << " suda ada child kanan." << endl;
                return;
            }
        }
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
    cout << "\nNode " << parentData << " ga ada." << endl;
}

void displayChild(char data) {
    queue<Pohon*> q;
    q.push(root);
    while (!q.empty()) {
        Pohon* node = q.front();
        q.pop();
        if (node->data == data) {
            cout << "\nNode " << data << " punya child: ";
            if (node->left != NULL) cout << "Left: " << node->left->data << " ";
            if (node->right != NULL) cout << "Right: " << node->right->data << " ";
            if (node->left == NULL && node->right == NULL) cout << "ga ada";
            cout << endl;
            return;
        }
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
    cout << "\nNode " << data << " ga ada." << endl;
}

void displayDescendants(char data) {
    queue<Pohon*> q;
    q.push(root);
    while (!q.empty()) {
        Pohon* node = q.front();
        q.pop();
        if (node->data == data) {
            cout << "\nNode " << data << " punya descendant: ";
            queue<Pohon*> descendants;
            descendants.push(node);
            bool hasDescendants = false;
            while (!descendants.empty()) {
                Pohon* current = descendants.front();
                descendants.pop();
                if (current != node) {
                    cout << current->data << " ";
                    hasDescendants = true;
                }
                if (current->left != NULL) descendants.push(current->left);
                if (current->right != NULL) descendants.push(current->right);
            }
            if (!hasDescendants) cout << "ga ada";
            cout << endl;
            return;
        }
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
    cout << "\nNode " << data << " ga ada." << endl;
}

void menu() {
    int pilihan;
    char data;
    char parentData;

    do {
        cout << "\nMenu:";
        cout << "\n1. Buat Node Root";
        cout << "\n2. Buat Child Kiri";
        cout << "\n3. Buat Child Kanan";
        cout << "\n4. Tampil Child";
        cout << "\n5. Tampil Descendant";
        cout << "\n0. Keluar";
        cout << "\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nInput data root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "\nInput data parent: ";
                cin >> parentData;
                cout << "\nInput data child kiri: ";
                cin >> data;
                insertLeft(data, parentData);
                break;
            case 3:
                cout << "\nInput data parent: ";
                cin >> parentData;
                cout << "\nInput data child kanan: ";
                cin >> data;
                insertRight(data, parentData);
                break;
            case 4:
                cout << "\nInput node: ";
                cin >> data;
                displayChild(data);
                break;
            case 5:
                cout << "\nInput node: ";
                cin >> data;
                displayDescendants(data);
                break;
            case 0:
                cout << "\nKeluar." << endl;
                break;
            default:
                cout << "\nga valid!" << endl;
        }
    } while (pilihan != 0);
}

int main() {
    menu();
    return 0;
}
```

#### Output
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/445e3808-c027-4da1-9310-a4f8e951b4db)
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/4d281c4e-4573-4c8f-8c41-f180e028cfeb)
![image](https://github.com/rndyyprsty/Praktikum-Struktur-Data/assets/162487464/089450c3-5dfc-4a2a-9a39-1b1809df7a19)

#### Penjelasan Program

Program di atas bisa membuat root pohon, menambahkan node child kiri dan kanan ke node, dan juga menampilkan child dan semua turunan dari node. Struktur data `Pohon` mendefinisikan setiap node dalam pohon, dengan setiap node memiliki atribut `data` dan pointer ke child kiri kanan. Fungsi-fungsi seperti `buatNode`, `insertLeft`, dan `insertRight` digunakan untuk membuat pohon, sedangkan fungsi `displayChild` dan `displayDescendants` menampilkan informasi soal node yang diinput.

Program ini memakai queue untuk melakukan traversal pohon secara breadth-first di fungsi `insertLeft`, `insertRight`, `displayChild`, dan `displayDescendants`. Metode traversal memungkinkan pencarian node dilakukan secara level-by-level dari root hingga ke daun, sehingga memudahkan jika ingin menambah node baru atau mencari informasi node. Menu yang ada dari fungsi `menu` memberikan opsi pada user untuk memasukkan data ataupun melihat hasilnya.

## Kesimpulan

Graf adalah struktur data non-linear yang terdiri dari kumpulan simpul (vertex) yang dihubungkan oleh garis (edge). Graf dapat berupa graf tak berarah (undirected graph) atau graf berarah (directed graph). Graf juga dapat memiliki bobot (weight) yang menunjukkan hubungan antara dua simpul. Sedangkan Tree adalah struktur data non-linear yang digunakan untuk merepresentasikan hubungan data yang bersifat hierarkis antara elemen-elemen. Tree terdiri dari root (akar) dan simpul (node/vertex) yang terpecah menjadi sejumlah himpunan yang tidak saling berhubungan satu sama lain, yang disebut subtree (cabang).

## Referensi
[1] Triase. (2020). Struktur Data. Medan: Fakultas Saintek UIN SU.

[2] Hadari, A. (2019). "Graf (Graph) dan Pohon (Tree)". Diakses pada 8 Juni 2024, dari https://ahmadhadari77.blogspot.com/2019/05/graph-graf-dan-tree-pohon-algoritma.html

[3] Fariza, A. (2013). Graph. Surabaya: PENS.

[4] Putra, Z. E. (2014). "Pengertian dan Representasi Graph". Diakses pada 9 Juni 2024, dari https://www.slideshare.net/slideshow/makalah-graph-i/42413476

[5] Fosalgo. (2020, 5 Mei). ADT Graph | Adjacency Matrix dan Adjacency List. [Video]. Youtube. https://www.youtube.com/watch?v=VBBj-WcBipI

[6] Dinho, D. (2013). "Pengertian dan Konsep Graph dalam Struktur Data". Diakses pada 9 Juni 2024, dari https://dinda-dinho.blogspot.com/2013/11/pengertian-dan-konsep-graph-dalam.html?m=1

[7] Santoso, R. (2014). "Tree pada C++ (Tree Awal)". Diakses pada 9 Juni 2024, dari https://www.nblognlife.com/2014/12/tree-pada-c-tree-awal.html

[8] Latifah, F. (2016). Penerapan Algorithma Pohon untuk Operasi Pengolahan dan Penyimpanan Data dalam Teknik Pemrograman (kajian algorithma pohon pada teknik pemrograman). Jurnal Techno Nusa Mandiri, 13(2), 23-32.

[9] Fachrurrozi, M. (2006). Modul Praktikum “Struktur Data”. Palembang: PIK-Unsri.

[10] Kadir, A. (2013). Teori dan Aplikasi Struktur Data Menggunakan C++. Yogyakarta: Andi.