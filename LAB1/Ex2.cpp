#include <iostream>

using namespace std;

int main(){
    char ch;

    cout<<"Enter a character: ";
    cin>> ch;

    int asciiValue = (int)ch;

    if(asciiValue >= 65 && asciiValue<=90){
        asciiValue +=32;
    }

    if(asciiValue >= 97 && asciiValue<=122){
        if(asciiValue == 97 || asciiValue == 101 || asciiValue == 105
        || asciiValue == 111 || asciiValue == 117){
            cout<< ch << " is a vowel."<< endl;
        }else{
            cout<< ch << " is a consanant."<<endl;
        }
    }else{
        cout<< "Invaild input. Please enter an alphabetic character,"<<endl;
    }

    return 0;
}