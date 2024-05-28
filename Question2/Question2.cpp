#include "header.h"

Node* insertNode()
{
    Node* pHead = nullptr;
    Node* curr = pHead;
    int x;
    cin >> x;
    while (x)
    {
        if (pHead == nullptr)
        {
            pHead = new Node();
            curr = pHead;
        }
        else
        {
            curr->next = new Node();
            curr = curr->next;
        }
        curr->data = x;
        curr->next = nullptr;
        cin >> x;
    }
    return pHead;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    while (1) {
        system("cls");
        cout << "Enter 1 for splitEvenOdd, 2 for merge: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter list of integers continuously, stop by entering 0: ";
            Node* head = insertNode();
            Node* odd = nullptr;
            splitEvenOdd(head, odd);
            cout << "Splited into: " << endl;
            print(head);
            print(odd);
            return 0;
        }
        else if (choice == 2) {
            cout << "Enter even list of integers continuously, stop by entering 0: ";
            Node* head = insertNode();
            cout << "Enter odd list of integers continuously, stop by entering 0: ";
            Node* odd = insertNode();
            merge(head, odd);
            cout << "Merged into: " << endl;
            print(head);
            return 0;
        }
        else {
            cout << "Invalid!" << endl;
            system("pause");
        }
    }
}