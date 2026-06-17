#include <iostream>
#include <string>

using namespace std;

int main(){

    string name, major;
    char gender;
    int age;

    cout<< "Enter student name: ":
    getline(cin, name);
    
    cout<< "Enter gender (M/F): ";
    cin>>gender;

    cout<< "Enter age: ";
    cin>> age;

    cout<< "\n--- Result ---";

    if(gender == 'M' || gender == 'm'){
        cout<<"Hi, Mr. "<< name<< "!, you age is "<<age<<
         " year old and you learn "<< major << "!" <<endl;
    }else if{
        cout<<"Hi, Mrs. "<< name<< "!, you are "<<age<<
         " year old and you are majoring in "<< major << "!" <<endl;
    }else{
        cout<< "Hi, "<<name << "!"<<endl;
    }

    if(age>=18){
        cout<<"You can vote."<<endl;
    }else{
        cout<< "You can not vote."<<endl;
    }

    return 0;
}