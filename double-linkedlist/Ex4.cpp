#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;
};

DoublyLinkedList* createEmptyList() {
    DoublyLinkedList* list = new DoublyLinkedList();
    list->head = nullptr;
    list->tail = nullptr;
    return list;
}

void addToEnd(DoublyLinkedList* list, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (list->tail == nullptr) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void displayMinimum(DoublyLinkedList* list) {
    if (list->head == nullptr) {
        std::cout << "List is empty, cannot identify minimum.\n";
        return;
    }

    Node* current = list->head;
    int min = current->data;

    while (current != nullptr) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    std::cout << "Minimum number in the list: " << min << "\n";
}

void displayMaximum(DoublyLinkedList* list) {
    if (list->head == nullptr) {
        std::cout << "List is empty, cannot identify maximum.\n";
        return;
    }

    Node* current = list->head;
    int max = current->data;

    while (current != nullptr) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    std::cout << "Maximum number in the list: " << max << "\n";
}

int main() {
    DoublyLinkedList* list = createEmptyList();

    addToEnd(list, 44);
    addToEnd(list, 12);
    addToEnd(list, 99);
    addToEnd(list, 3);
    addToEnd(list, 75);

    std::cout << "List configuration loaded.\n";
    
    displayMinimum(list);
    displayMaximum(list);

    return 0;
}