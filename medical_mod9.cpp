#include <iostream>
using namespace std;

class Hash {
    int table[9];

public:
    Hash() {
        for (int i = 0; i < 9; i++)
            table[i] = -1;
    }

    // Insert
    void insert(int key) {
        if (key < 0) {
            cout << "Enter non-negative key\n";
            return;
        }

        int index = key % 9;
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % 9;

            if (index == start) {
                cout << "Hash table is full\n";
                return;
            }
        }

        table[index] = key;
        cout << key << " inserted at index " << index << endl;
    }


    // Display
    void display() {
        cout << "\nIndex\tKey\n";

        for (int i = 0; i < 9; i++) {
            cout << i << "\t";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main() {
    Hash h;
    int choice, key;

    do {
        cout << "\n----- MEDICAL STOCK MENU -----\n";
        cout << "1. Insert Key\n";
        cout << "2. Display Hash Table\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter key: ";
            cin >> key;
            h.insert(key);
            break;


        case 2:
            h.display();
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 3);

  
}