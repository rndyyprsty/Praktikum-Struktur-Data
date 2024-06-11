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