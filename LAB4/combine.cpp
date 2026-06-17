#include <iostream>
#include <string>

using namespace std;

//Exercise1
struct Node{
    int data;
    Node* next;
};

//Exercise2

struct Student{
    string id;
    string name;
    int year;
    string program;
};

struct Element{
    Student data;
    Element* next;
};

struct ListStudent{
    Element* head;
    Element* tail;
    int size;
};

//Exercise3

ListStudent* createEmptyList(){
    ListStudent* ls = new ListStudent;
    ls-> head = nullptr;
    ls-> tail = nullptr;
    return ls;
}

void addStudent(ListStudent* ls, Student s){
    Element* newElement = new Element;
    newElement-> data = s;
    newElement-> next = nullptr;

    if(ls-> head == nullptr){
        ls-> head = newElement;
        ls-> tail = newElement;
    } else{
        ls-> tail-> next = newElement;
        ls-> tail = newElement;
    }
}

//Exercise4

void displayStudents(ListStudent* ls){
    Element* temp = ls-> head;
    cout<< "\n--- Current Student List ---"<<endl;
    while (temp != nullptr){
        cout<< "ID: "<< temp-> data.id
            <<" | Name: "<< temp->data.year
            <<" | Yaer: "<<temp->data.program<<endl;

            temp = temp->next;
    }
}

//Exercise5

void numberStorageProgram(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int num, zeroCount = 0;

    cout << "\n*** A program to store number as many as possible: ***" << endl;

    while (zeroCount < 2) {
        cout << "Enter a number: ";
        cin >> num;

        if (num == 0) {
            zeroCount++;
            if (zeroCount == 1) {
                cout << "You have entered the number 0 once. Only 1 more left. We will quit the program." << endl;
            } else {
                cout << "You have entered the number 0 twice so far. The program is going to stop now." << endl;
            }
        } else {
            Node* newNode = new Node{num, nullptr};
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    int sum = 0;
    cout << "\nAll data in the list are: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        sum += temp->data;
        temp = temp->next;
    }
    cout << "\nSummation of all numbers is: " << sum << endl;
}

// Main 
int main() {
    ListStudent* myClass = createEmptyList();

    addStudent(myClass, {"e2026001", "a", 2, "AI & Cybersecurity"});
    addStudent(myClass, {"e2026002", "b", 2, "GIC"});
    addStudent(myClass, {"e2026003", "c", 2, "Cybersecurity"});
    addStudent(myClass, {"e2026004", "d", 2, "AI"});
    addStudent(myClass, {"e2026005", "e", 2, "GIC"});

    displayStudents(myClass);

    addStudent(myClass, {"e2026006", "f", 2, "AI"});
    addStudent(myClass, {"e2026007", "g", 2, "Cybersecurity"});

    cout << "\n(After adding 2 more students):";
    displayStudents(myClass);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    numberStorageProgram();

    return 0;
}