
// Problem 5: Railway reservation system using circular linked list
#include <iostream>
using namespace std;
 
class node {
public:
    int tck;
    string name;
    int age;
    node* next;
};
 
class railway {
    node* head;
 
public:
    railway() {
        head = NULL;
    }
 
    void book();
    void cancel();
    void display();
    void search();
};
 
void railway::book() {
    node* p = new node;
    cout << "Enter ticket Number : ";
    cin >> p->tck;
    cout << "Enter Passenger name : ";
    cin >> p->name;
    cout << "Enter Your age : ";
    cin >> p->age;
 
    if (head == NULL) {
        head = p;
        p->next = head;
    }
    else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = p;
        p->next = head;
    }
}
 
void railway::cancel() {
    if (head == NULL) {                         // fix 1: empty check
        cout << "List is empty\n";
        return;
    }
 
    int val;
    cout << "Enter ticket number to cancel the ticket : ";
    cin >> val;
 
    // Case 1: ticket is at head
    if (head->tck == val) {
        if (head->next == head) {               // only one node
            delete head;
            head = NULL;
        }
        else {
            node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            node* temp = head;
            head = head->next;
            last->next = head;                  // fix 2: last node must point to new head
            delete temp;
        }
        cout << "Ticket cancelled\n";
        return;                                 // fix 3: stop here
    }
 
    // Case 2: ticket is after head
    node* prev = head;
    node* curr = head->next;
    while (curr != head && curr->tck != val) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == head) {
        cout << "Ticket not found\n";
    }
    else {
        prev->next = curr->next;
        delete curr;
        cout << "Ticket cancelled\n";
    }
}
 
void railway::display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    node* temp = head;
    do {
        cout << "=== Ticket ===\n";
        cout << "Ticket Number : " << temp->tck << endl;
        cout << "Name : " << temp->name << endl;
        cout << "Age : " << temp->age << endl;
        temp = temp->next;
    } while (temp != head);
}
 
void railway::search() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    int value;
    cout << "Enter ticket number to search : ";
    cin >> value;
 
    node* temp = head;
    int pos = 1;
    bool found = false;
    do {
        if (temp->tck == value) {
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
 
    if (found)
        cout << "Ticket number found at position " << pos << endl;
    else
        cout << "Ticket number not found" << endl;
}
 
int main() {
    railway r;
    int choice;
 
    do {
        cout << "\n======  Menu  ======\n";
        cout << "1. Insert details\n";
        cout << "2. Display tickets\n";
        cout << "3. Search ticket\n";
        cout << "4. Cancel ticket\n";
        cout << "5. Exit\n";
        cout << "Enter choice : ";
        cin >> choice;
 
        switch (choice) {
        case 1: r.book(); break;
        case 2: r.display(); break;
        case 3: r.search(); break;
        case 4: r.cancel(); break;
        case 5: cout << "Exiting\n"; break;
        default: cout << "Invalid Choice\n";
        }
    } while (choice != 5);
 
    return 0;
}
 