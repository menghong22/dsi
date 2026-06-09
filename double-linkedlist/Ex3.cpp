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

void displayList(DoublyLinkedList* list) {
    Node* current = list->head;
    std::cout << "Current List: ";
    if (current == nullptr) {
        std::cout << "EMPTY\n";
        return;
    }
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) std::cout << " <=> ";
        current = current->next;
    }
    std::cout << " -> NULL\n";
}

void deleteFromBegin(DoublyLinkedList* list) {
    if (list->head == nullptr) return;

    Node* temp = list->head;
    list->head = list->head->next;

    if (list->head != nullptr) {
        list->head->prev = nullptr;
    } else {
        list->tail = nullptr; 
    }
    delete temp;
    std::cout << "Deleted from beginning.\n";
}

void deleteFromEnd(DoublyLinkedList* list) {
    if (list->tail == nullptr) return;

    Node* temp = list->tail;
    list->tail = list->tail->prev;

    if (list->tail != nullptr) {
        list->tail->next = nullptr;
    } else {
        list->head = nullptr; 
    }
    delete temp;
    std::cout << "Deleted from end.\n";
}

void deleteAtPosition(DoublyLinkedList* list, int position) {
    if (list->head == nullptr) return;
    
    if (position == 0) {
        deleteFromBegin(list);
        return;
    }

    Node* current = list->head;
    int index = 0;

    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }

    if (current == nullptr) {
        std::cout << "Position " << position << " out of bounds. Deletion ignored.\n";
        return;
    }

    if (current == list->tail) {
        deleteFromEnd(list);
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
    std::cout << "Deleted from position " << position << ".\n";
}

int main() {
    DoublyLinkedList* list = createEmptyList();

    addToEnd(list, 10);
    addToEnd(list, 20);
    addToEnd(list, 30);
    addToEnd(list, 40);
    addToEnd(list, 50);
    
    std::cout << "--- Initial State ---\n";
    displayList(list);
    std::cout << "\n";

    // Perform deletions
    deleteFromBegin(list);
    displayList(list);

    deleteFromEnd(list);
    displayList(list);

    deleteAtPosition(list, 1); 
    displayList(list);

    return 0;
}