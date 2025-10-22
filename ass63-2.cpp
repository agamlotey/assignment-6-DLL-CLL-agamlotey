#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *head = NULL, *temp = NULL, *n;
    int val, count = 0;
    cout << "Enter 5 values: ";
    for (int i = 0; i < 5; i++) {
        cin >> val;
        n = new Node{val, NULL};
        if (!head) head = n;
        else temp->next = n;
        temp = n;
    }
    temp->next = head; // make circular
    temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    cout << "Size of Circular Linked List: " << count << endl;
}
