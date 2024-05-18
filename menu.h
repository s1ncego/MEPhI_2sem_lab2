#pragma once

#include <iostream>
#include "sequence.h"
#include "Array&&List.h"

using namespace std;

void printArrayMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Insert element at index\n";
    cout << "  5. Erase element at index\n";
    cout << "  6. Map\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-6 to choose the action:\n";
}

void printLinkedListMenu() {
    cout << "\n---=== Menu ===---\n";
    cout << "-------------------------------\n";
    cout << "  1. Show elements\n";
    cout << "  2. Add element\n";
    cout << "  3. Remove element\n";
    cout << "  4. Insert element at index\n";
    cout << "  5. Erase element at index\n";
    cout << "  6. Map\n";
    cout << "Enter 'STOP' to finish.\n";
    cout << "Press 1-6 to choose the action:\n";
}

void ArrayMenu() {
    Sequence<int> *sequence = new Array<int>();

    string input;
    while (true) {
        printArrayMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 1: { // Show elements
                if (sequence->Size() == 0) {
                    cout << "Array is empty.\n";
                    break;
                }
                cout << "Elements:\n";
                auto dynarr = (DynamicArray<int> *) sequence;
                auto iterator = dynarr->begin();
                while (iterator.hasNext()) {
                    cout << iterator.next() << " ";
                }
                cout << "\n";

                break;
            }
            case 2: { // Add element
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                sequence->PushBack(value);

                break;
            }
            case 3: { // Remove element
                if (sequence->Size() == 0) {
                    cout << "Array is empty.\n";
                    break;
                }
                Array<int> *array = dynamic_cast<Array<int> *>(sequence);
                array->PopBack();

                break;
            }
            case 4: { // Insert element at index
                size_t index;
                int value;
                cout << "Enter index to insert: ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                sequence->Insert(index, value);

                break;
            }
            case 5: { // Erase element at index
                size_t index;
                cout << "Enter index to erase: ";
                cin >> index;
                sequence->Erase(index);

                break;
            }
            case 6:{
                auto dynarr = (DynamicArray<int> *) sequence;
                dynarr->Map();

                break;
            }
            default: {
                cout << "\nUnknown command, try again.\n";
                break;
            }
        }
    }

}

void LinkedListMenu() {
    List<int> sequence;

    string input;
    while (true) {
        printLinkedListMenu();
        cin >> input;

        int action = stoi(input);
        if (input == "STOP") {
            break;
        }

        switch (action) {
            case 1: { // Show elements
                if (sequence.Size() == 0) {
                    cout << "List is empty.\n";
                    break;
                }
                cout << "Elements:\n";
                for (size_t i = 0; i < sequence.Size(); ++i) {
                    cout << sequence[i] << " ";
                }
                cout << "\n";

                break;
            }
            case 2: { // Add element
                int value;
                cout << "Enter the element to add: ";
                cin >> value;
                sequence.PushBack(value);

                break;
            }
            case 3: { // Remove element
                if (sequence.Size() == 0) {
                    cout << "List is empty.\n";
                    break;
                }
                sequence.PopBack();

                break;
            }
            case 4: { // Insert element at index
                size_t index;
                int value;
                cout << "Enter the index to insert: ";
                cin >> index;
                cout << "Enter the value to insert: ";
                cin >> value;
                sequence.Insert(index, value);

                break;
            }
            case 5: { // Erase element at index
                size_t index;
                cout << "Enter the index to erase: ";
                cin >> index;
                if (index >= sequence.Size()) {
                    cout << "Invalid index.\n";
                } else {
                    sequence.Erase(index);
                }

                break;
            }
            case 6: {
                sequence.Map(sequence);

                break;
            }
            default: {
                cout << "\nUnknown command, try again.\n";
                break;
            }
        }
    }
}