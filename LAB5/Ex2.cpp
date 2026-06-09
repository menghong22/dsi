#include <iostream>
#include <string>

struct PersonNode {
    std::string name;
    PersonNode* next;
};

struct PersonList {
    PersonNode* head;
};

PersonList* createList() {
    PersonList* list = new PersonList();
    list->head = nullptr;
    return list;
}

void addPerson(PersonList* list, std::string name) {
    PersonNode* newNode = new PersonNode();
    newNode->name = name;
    
    newNode->next = list->head;
    list->head = newNode;
}

void displayList(PersonList* list) {
    std::cout << "--- List of Persons (Newest First) ---\n";
    PersonNode* current = list->head;
    int count = 1;
    while (current != nullptr) {
        std::cout << count << ". " << current->name << "\n";
        current = current->next;
        count++;
    }
    if (list->head == nullptr) {
        std::cout << "The list is empty.\n";
    }
}

int main() {
    PersonList* list = createList();

    addPerson(list, "Sok");
    addPerson(list, "Sao");
    addPerson(list, "Dara");
    addPerson(list, "Jane");
    addPerson(list, "Bona");
    addPerson(list, "Sophea");
    addPerson(list, "Vichea");
    addPerson(list, "Rith");
    addPerson(list, "Nita");
    addPerson(list, "Seyha");
    displayList(list);

    return 0;
}