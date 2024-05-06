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