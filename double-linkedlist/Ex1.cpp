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

void addToBegin(DoublyLinkedList* list, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (list->head == nullptr) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    std::cout << "Added " << value << " to the beginning.\n";
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
    std::cout << "Added " << value << " to the end.\n";
}

void addToPosition(DoublyLinkedList* list, int value, int position) {
    if (position <= 0 || list->head == nullptr) {
        addToBegin(list, value);
        return;
    }

    Node* current = list->head;
    int index = 0;

    while (current != nullptr && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == nullptr || current->next == nullptr) {
        addToEnd(list, value);
        return;
    }

    Node* newNode = new Node{value, current, current->next};
    current->next->prev = newNode;
    current->next = newNode;
    std::cout << "Added " << value << " at position " << position << ".\n";
}

void displayList(DoublyLinkedList* list) {
    Node* current = list->head;
    std::cout << "List Contents: ";
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

int main() {
    DoublyLinkedList* list = createEmptyList();

    std::cout << "--- Testing Exercise 1 Insertions ---\n";
    addToBegin(list, 10);          
    addToEnd(list, 30);            
    addToPosition(list, 20, 1);   
    addToPosition(list, 5, 0);     
    
    std::cout << "\n";
    displayList(list);

    return 0;
}