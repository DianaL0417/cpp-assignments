#include <iostream>
#include <string>
using namespace std;

// Define a struct to represent a flower item
struct Item {
    int id;
    string name;
};

// Function to perform binary search on array of Items
int binarySearch(Item* items, int size, int targetId) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (items[mid].id == targetId) {
            return mid;
        } else if (items[mid].id < targetId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Not found
}

int main() {
    int size = 5;

    // Dynamically allocate an array of Item structs
    Item* items = new Item[size];

    // Initialize the elements of the array (sorted by ID)
    items[0] = {101, "Rose"};
    items[1] = {104, "Lily"};
    items[2] = {107, "Dahlia"};
    items[3] = {110, "Marigold"};
    items[4] = {115, "Orchid"};

    // Ask user for an ID to search
    int searchId;
    cout << "Enter flower ID to search for: ";
    cin >> searchId;

    // Perform binary search
    int result = binarySearch(items, size, searchId);

    // Display the result
    if (result != -1) {
        cout << "Flower found: " << items[result].name
             << " (ID: " << items[result].id << ")" << endl;
    } else {
        cout << "Flower with ID " << searchId << " not found." << endl;
    }

    // Free the memory
    delete[] items;

    return 0;
}
