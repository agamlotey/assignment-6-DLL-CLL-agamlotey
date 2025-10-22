#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyList {
    Node* head;
public:
    DoublyList() { head = NULL; }

    void insertFront(int val) {
        Node* n = new Node{val, NULL, head};
        if (head) head->prev = n;
        head = n;
        cout << "Inserted at beginning\n";
    }

    void insertLast(int val) {
        Node* n = new Node{val, NULL, NULL};
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
        cout << "Inserted at end\n";
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Key not found!\n";
            return;
        }
        Node* n = new Node{val, temp, temp->next};
        if (temp->next)
            temp->next->prev = n;
        temp->next = n;
        cout << "Inserted after " << key << endl;
    }

    void deleteNode(int val) {
        Node* temp = head;
        while (temp && temp->data != val)
            temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Node deleted.\n";
    }

    void search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) {
                cout << "Found " << val << " in list.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not found.\n";
    }

    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList d;
    int ch, val, key;

    do {
        cout << "\n1.Insert Front\n2.Insert Last\n3.Insert After\n4.Delete Node\n5.Search\n6.Display\n0.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; d.insertFront(val); break;
            case 2: cout << "Enter value: "; cin >> val; d.insertLast(val); break;
            case 3: cout << "After which value? "; cin >> key; cout << "Enter value: "; cin >> val; d.insertAfter(key, val); break;
            case 4: cout << "Enter value to delete: "; cin >> val; d.deleteNode(val); break;
            case 5: cout << "Enter value to search: "; cin >> val; d.search(val); break;
            case 6: d.display(); break;
        }
    } while (ch != 0);
}
