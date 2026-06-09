#include <iostream>

struct AlphabetNode {
    char letter;
    AlphabetNode* next;
};

struct AlphabetList {
    AlphabetNode* head;
    AlphabetNode* tail;
};

AlphabetList* createList() {
    AlphabetList* list = new AlphabetList();
    list->head = nullptr;
    list->tail = nullptr;
    return list;
}

void addAlphabet(AlphabetList* list, char letter) {
    AlphabetNode* newNode = new AlphabetNode();
    newNode->letter = letter;
    newNode->next = nullptr;

    if (list->head == nullptr) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void displayList(AlphabetList* list, const std::string& listName) {
    std::cout << listName << ": ";
    AlphabetNode* current = list->head;
    while (current != nullptr) {
        std::cout << current->letter << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}

int main() {
    AlphabetList* capitalList = createList();
    AlphabetList* smallList = createList();

    for (char c = 'A'; c <= 'Z'; ++c) {
        addAlphabet(capitalList, c);
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        addAlphabet(smallList, c);
    }

    displayList(capitalList, "Capital Letters List");
    displayList(smallList, "Small Letters List");

    return 0;
}