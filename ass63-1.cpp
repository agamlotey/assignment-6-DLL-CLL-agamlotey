#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node *head = NULL, *temp = NULL, *n;
    int val, count = 0;
    cout << "Enter 5 values: ";
    for (int i = 0; i < 5; i++) {
        cin >> val;
        n = new Node{val, NULL, temp};
        if (!head) head = n;
        else temp->next = n;
        temp = n;
    }
    temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    cout << "Size of Doubly Linked List: " << count << endl;
}
