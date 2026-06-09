#include <iostream>
#include <string>

struct Product {
    int productId;
    std::string name;
    double price;
    Product* next;
};

struct ListProduct {
    Product* head;
    Product* tail;
};

ListProduct* createEmptyList() {
    ListProduct* list = new ListProduct();
    list->head = nullptr;
    list->tail = nullptr;
    return list;
}

void addProductToBegin(ListProduct* list, int id, std::string name, double price) {
    Product* newProduct = new Product{id, name, price, nullptr};
    if (list->head == nullptr) {
        list->head = newProduct;
        list->tail = newProduct;
    } else {
        newProduct->next = list->head;
        list->head = newProduct;
    }
}

void addProductToEnd(ListProduct* list, int id, std::string name, double price) {
    Product* newProduct = new Product{id, name, price, nullptr};
    if (list->head == nullptr) {
        list->head = newProduct;
        list->tail = newProduct;
    } else {
        list->tail->next = newProduct;
        list->tail = newProduct;
    }
}

void insertProduct(ListProduct* list, int id, std::string name, double price) {
    if (price < 50.0) {
        addProductToBegin(list, id, name, price);
    } else {
        addProductToEnd(list, id, name, price);
    }
}

void display(ListProduct* list) {
    Product* current = list->head;
    while (current != nullptr) {
        std::cout << "ID: " << current->productId 
                  << " | Name: " << current->name 
                  << " | Price: $" << current->price << "\n";
        current = current->next;
    }
}

void searchByName(ListProduct* list, std::string searchName) {
    std::cout << "\n--- Search Profile Lookup Match: \"" << searchName << "\" ---\n";
    Product* current = list->head;
    bool found = false;
    
    while (current != nullptr) {
        if (current->name == searchName) {
            std::cout << "[Match Found] ID Location: " << current->productId 
                      << " | Current Standard Value Cost Evaluation: $" << current->price << "\n";
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "Notice: Target entity item name reference not recovered inside nodes.\n";
    }
}


void searchByPrice(ListProduct* list, double p) {
    std::cout << "\n================ SEARCH RESULTS BY PRICE BENCHMARK: $" << p << " ================\n";
    
    std::cout << "1) Section1: All products that have price lower than $" << p << ":\n";
    Product* current = list->head;
    bool foundLower = false;
    while (current != nullptr) {
        if (current->price < p) {
            std::cout << "   -> ID: " << current->productId << " | " << current->name << " ($" << current->price << ")\n";
            foundLower = true;
        }
        current = current->next;
    }
    if (!foundLower) std::cout << "   (No inventory records match lower parameters subset evaluation constraints)\n";

    std::cout << "\n2) Section2: All products that have price more than $" << p << ":\n";
    current = list->head;
    bool foundHigher = false;
    while (current != nullptr) {
        if (current->price > p) {
            std::cout << "   -> ID: " << current->productId << " | " << current->name << " ($" << current->price << ")\n";
            foundHigher = true;
        }
        current = current->next;
    }
    if (!foundHigher) std::cout << "   (No inventory records match higher parameters subset evaluation constraints)\n";
    std::cout << "================================================================================\n";
}

void updateByProductid(ListProduct* list, int id) {
    Product* current = list->head;
    while (current != nullptr) {
        if (current->productId == id) {
            std::cout << "\n[Target Match Identified] Modifying fields for ID " << id << "\n";
            std::cout << "Enter updated product identifier text label descriptor: ";
            std::cin.ignore();
            std::getline(std::cin, current->name);
            std::cout << "Enter new price numerical evaluation index ($): ";
            std::cin >> current->price;
            std::cout << "Update successfully written to active data pointer fields.\n";
            return;
        }
        current = current->next;
    }
    std::cout << "\nExecution terminated: Product tracking code ID " << id << " was not located.\n";
}

int main() {
    ListProduct* storeCatalog = createEmptyList();

    insertProduct(storeCatalog, 501, "Office Desk", 150.00);
    insertProduct(storeCatalog, 502, "Desk Lamp", 35.00);
    insertProduct(storeCatalog, 503, "Coffee Mug", 12.00);
    insertProduct(storeCatalog, 504, "Ergonomic Chair", 210.00);
    insertProduct(storeCatalog, 505, "Desk Lamp", 45.00); 

    std::cout << "--- Base Baseline Setup Configured Inventory ---\n";
    display(storeCatalog);

    searchByName(storeCatalog, "Desk Lamp");

    searchByPrice(storeCatalog, 100.00);

    updateByProductid(storeCatalog, 503);

    std::cout << "\n--- Inventory Audit Map Representation Post Changes Application ---\n";
    display(storeCatalog);

    return 0;
}