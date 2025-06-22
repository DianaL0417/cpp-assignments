#include <iostream>
using namespace std;

void showMenu() {
    cout << "1. Add Item\n2. View Items\n3. Exit\n";
}

void addItem() {
    cout << "Item added!\n";
}

void viewItems() {
    cout << "Showing all items...\n";
}

int main() {
    int option;

    do {
        showMenu();
        cin >> option;

        if (option == 1) {
            addItem();
        } else if (option == 2) {
            viewItems();
        } else if (option == 3) {
            cout << "Goodbye!\n";
        } else {
            cout << "Not a valid choice.\n";
        }

    } while (option != 3);

    return 0;
}