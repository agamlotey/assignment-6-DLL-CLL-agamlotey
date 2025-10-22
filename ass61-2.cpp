#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularList {
    Node* head;
public:
    CircularList() { head = NULL; }

    void insertLast(int val) {
        Node* n = new Node{val, NULL};
        if (!head) {
            head = n;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
        cout << "Inserted.\n";
    }

    void deleteNode(int val) {
        if (!head) return;
        Node *curr = head, *prev = NULL;
        while (curr->data != val) {
            if (curr->next == head) {
                cout << "Node not found!\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        if (curr == head && curr->next == head) {
            head = NULL;
            delete curr;
            return;
        }
        if (curr == head) {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = head->next;
            prev->next = head;
        } else if (curr->next == head)
            prev->next = head;
        else
            prev->next = curr->next;
        delete curr;
        cout << "Deleted.\n";
    }

    void search(int val) {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == val) {
                cout << "Found " << val << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not found\n";
    }

    void display() {
        if (!head) {
            cout << "List empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularList c;
    int ch, val;
    do {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Display\n0.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; c.insertLast(val); break;
            case 2: cout << "Enter value to delete: "; cin >> val; c.deleteNode(val); break;
            case 3: cout << "Enter value to search: "; cin >> val; c.search(val); break;
            case 4: c.display(); break;
        }
    } while (ch != 0);
}
