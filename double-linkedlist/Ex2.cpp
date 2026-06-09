#include <iostream>
#include <cstdlib> 
#include <ctime>   

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
    std::cout << "List Elements: ";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) std::cout << " <=> ";
        current = current->next;
    }
    std::cout << " -> NULL\n";
}

void computeSumAndAverage(DoublyLinkedList* list) {
    Node* current = list->head;
    if (current == nullptr) {
        std::cout << "The list is empty.\n";
        return;
    }

    int sum = 0;
    int count = 0;
    while (current != nullptr) {
        sum += current->data;
        count++;
        current = current->next;
    }

    double average = static_cast<double>(sum) / count;
    std::cout << "\n--- Statistical Calculations ---\n";
    std::cout << "Summation: " << sum << "\n";
    std::cout << "Average:   " << average << "\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    DoublyLinkedList* list = createEmptyList();
    int n;

    std::cout << "Enter the amount of random numbers (n) to generate: ";
    std::cin >> n;

    // Generate n random numbers (between 1 and 100) and store them
    for (int i = 0; i < n; ++i) {
        int randomNum = rand() % 100 + 1;
        addToEnd(list, randomNum);
    }

    std::cout << "\n";
    displayList(list);
    computeSumAndAverage(list);

    return 0;
}