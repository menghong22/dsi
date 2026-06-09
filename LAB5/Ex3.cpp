#include <iostream>
#include <string>

// Define structural representation for products [cite: 61, 67]
struct Product {
    int productId;
    std::string name;
    double price;
    Product* next; 
};

// Define list wrapper structure tracking boundary endpoints [cite: 68]
struct ListProduct {
    Product* head;
    Product* tail;
};

// a. Create an empty list structure [cite: 62, 69]
ListProduct* createEmptyList() {
    ListProduct* list = new ListProduct();
    list->head = nullptr;
    list->tail = nullptr;
    return list;
}

// b. Add product to the BEGINNING of the list (when price < 50) [cite: 63, 74]
void addProductToBegin(ListProduct* list, int id, std::string name, double price) {
    Product* newProduct = new Product{id, name, price, nullptr};
    
    if (list->head == nullptr) {
        list->head = newProduct;
        list->tail = newProduct;
    } else {
        newProduct->next = list->head;
        list->head = newProduct;
    }
    std::cout << "Successfully added '" << name << "' to the BEGINNING (< $50)\n";
}

// c. Add product to the END of the list (when price >= 50) [cite: 64, 75]
void addProductToEnd(ListProduct* list, int id, std::string name, double price) {
    Product* newProduct = new Product{id, name, price, nullptr};
    
    if (list->head == nullptr) {
        list->head = newProduct;
        list->tail = newProduct;
    } else {
        list->tail->next = newProduct;
        list->tail = newProduct;
    }
    std::cout << "Successfully added '" << name << "' to the END (>= $50)\n";
}

// Router helper function to distribute elements using conditional pricing rules [cite: 63, 64]
void insertProduct(ListProduct* list, int id, std::string name, double price) {
    if (price < 50.0) {
        addProductToBegin(list, id, name, price);
    } else {
        addProductToEnd(list, id, name, price);
    }
}

// d. Display product implementations within list chain layout [cite: 65, 70]
void display(ListProduct* list) {
    std::cout << "\n================ PRODUCT INVENTORY ================\n";
    Product* current = list->head;
    if (current == nullptr) {
        std::cout << "The warehouse registry database is currently empty.\n";
        return;
    }
    while (current != nullptr) {
        std::cout << "Product ID: " << current->productId 
                  << " | Name: " << current->name 
                  << " | Price: $" << current->price << "\n";
        current = current->next;
    }
    std::cout << "===================================================\n";
}

// Test program execution profile [cite: 66]
int main() {
    ListProduct* inventory = createEmptyList();

    std::cout << "--- Populating Inventory Record Base ---\n";
    insertProduct(inventory, 201, "Wireless Mouse", 24.99); // Goes to begin (< 50) [cite: 63]
    insertProduct(inventory, 202, "Mechanical Keyboard", 89.99); // Goes to end (>= 50) [cite: 64]
    insertProduct(inventory, 203, "USB-C Adapter Cables", 12.50); // Goes to begin (< 50) [cite: 63]
    insertProduct(inventory, 204, "UltraWide Gaming Monitor", 349.99); // Goes to end (>= 50) [cite: 64]

    // Render global structure elements map
    display(inventory);

    return 0;
}