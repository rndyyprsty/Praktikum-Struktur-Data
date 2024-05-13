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