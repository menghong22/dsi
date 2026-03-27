#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book{
    int id;
    string isbn;
    string title;
    int year;
    vector<string> authors;
    double price;
};

void displayAllBooks(Book books[], int size){
    cout<< "\n--- All Books Information---";
    for(int i=0; i<size; i++){
        cout<<"ID: "<<books[i].id<<" | Title: "<<books[i].title
        <<" | ISBN: "<<books[i].isbn<< " | Price: $"<<books[i].price<<endl;
    }
}

void displayBookbyISBN(Book books[], int size, string isbn){
    bool found = false;

    for(int i=0; i<size; i++){
            if(books[i].isbn ==isbn){
                cout<<"\n--- Book Found ---"<<endl;
                cout<<"Title: "<<books[i].title<<endl;
                cout<<"Year: "<<books[i].year<<endl;
                cout<<"Price: $"<<books[i].price<<endl;
                cout<<"Authors: ";
                for(const string& author : books[i].authors){
                    cout<<author<<" ";
                }
                cout<<endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout<<"\nBook with ISBN "<<isbn<<"not found."<<endl;
        }
    }

int main(){
    Book library[5];

    library[0].id = 101;
    library[0].isbn = "978-3-16";
    library[0].title = "C++ Systems Programming";
    library[0].year = 2024;
    library[0].price = 45.99;
    library[0].authors.push_back("Menghong");
    library[0].authors.push_back("Dr. Smith");

    for(int i=1; i<5; i++){
        library[i].id = 100+i+1;
        library[i].isbn = "ISBN-00"+ to_string(i);
        library[i].title = "Basic Engineering Vol " + to_string(i);
        library[i].price = 20.0 + i;
        library[i].authors.push_back("Author Name");
    }

    displayAllBooks(library, 5);

    string searchIsbn;
    cout<<"\nEnter ISBN to search: ";
    cin>> searchIsbn;
    displayBookbyISBN(library, 5, searchIsbn);

    return 0;
}