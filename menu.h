#pragma once

#include <iostream>
#include "sequence.h"

using namespace std;

void printArrayMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  0. Create name of the array\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Insert element at index\n";
    cout << "  5. Erase element at index\n";
    cout << "  6. Concatenation\n";
    cout << "  7. Map\n";
    cout << "  8. Where\n";
    cout << "  9. Sort array\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 0-9 to choose the action:\n";
}

void printLinkedListMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  0. Create name of the list\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Insert element at index\n";
    cout << "  5. Erase element at index\n";
    cout << "  6. Concatenation\n";
    cout << "  7. Map\n";
    cout << "  8. Where\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 0-8 to choose the action:\n";
}

void ArrayMenu() {
    //Sequence<int> *sequence = new Array<int>();

    string input;
    while (true) {
        printArrayMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 0: { // Create name of the array

            }
            case 1: { // Show elements

            }
            case 2: { // Add element

            }
            case 3: { // Remove element

            }
            case 4: { // Insert element at index

            }
            case 5: { // Erase element at index

            }
            case 6: { // Concatenation

            }
            case 7: { // Map

            }
            case 8: { // Where

            }
            case 9: { // Sort

            }
            default: {
                cout << "\nUnknown command, try again.\n";
                break;
            }
        }
    }

}

void LinkedListMenu() {
    //LinkedList<int> sequence;

    string input;
    while (true) {
        printLinkedListMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 0: { // Create name of the list

            }
            case 1: { // Show elements

            }
            case 2: { // Add element

            }
            case 3: { // Remove element

            }
            case 4: { // Insert element at index

            }
            case 5: { // Erase element at index

            }
            case 6: { // Concatenation

            }
            case 7: { // Map

            }
            case 8: { // Where

            }
            default: {
                cout << "\nUnknown command, try again.\n";
                break;
            }
        }
    }
}