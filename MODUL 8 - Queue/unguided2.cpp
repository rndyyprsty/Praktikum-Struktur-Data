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