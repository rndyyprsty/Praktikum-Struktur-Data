#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class linkedlist {
public:
    linkedlist(): head(nullptr) {}

    void append(int dataBaru) {
        Node* nodeBaru = new Node();
        nodeBaru->data = dataBaru
        nodeBaru->next = nullptr;
        if (head == nullptr) {
            head = nodeBaru;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

void printLinked() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}   cout << endl;     
    }
}
