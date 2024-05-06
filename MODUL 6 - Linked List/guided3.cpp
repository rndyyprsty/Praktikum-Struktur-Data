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