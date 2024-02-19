#include <iostream>
using namespace std;

struct link {
    link* next;
    int data;
    link(int a_data, link* a_next = 0) : next(a_next), data(a_data) {}
};

// Function to print the linked list
void printList(link* head) {
    link* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to add element at the end of the list
void addElement(link*& head, int value) {
    link* newNode = new link(value);
    if (head == NULL) {
        head = newNode;
    } else {
        link* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    // Initialize the linked list with small prime numbers
    link* small_primes = new link(2, new link(3, new link(5, new link(7))));
    
    // Print the initial list
    cout << "Initial list of small primes: ";
    printList(small_primes);
    
    // Add a new prime to the list
    addElement(small_primes, 11);
    cout << "List after adding 11: ";
    printList(small_primes);
    
    // Clean up (delete) the list
    link* current = small_primes;
    while (current != NULL) {
        link* next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}
