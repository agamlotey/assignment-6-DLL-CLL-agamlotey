#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node *left = head, *right = head;
    while (right->next)
        right = right->next;
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node *head = NULL, *temp = NULL, *n;
    string s;
    cout << "Enter string: ";
    cin >> s;
    for (char ch : s) {
        n = new Node{ch, NULL, temp};
        if (!head) head = n;
        else temp->next = n;
        temp = n;
    }
    cout << (isPalindrome(head) ? "True\n" : "False\n");
}
