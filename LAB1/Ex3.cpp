#include <iostream>
#include <string>


using namespace std;

int main(){
    string name;
    char gender;
    double salary, tax;
    
    cout<< "Enter your name: ";
    getline(cin, name);
    cout<<"Enter gender: ";
    cin>> gender;
    cout<<"Enter salary: ";
    cin>>salary;

    if(gender=='m' || gender=='M'){
        if(salary> 1000){
            tax = salary*(9.5/100);
        }else if (salary > 500 || salary <=1000){
            tax = salary*(7/100);
        }else if (salary>=300 || salary <=500){
            tax = salary*(5/100);
        }else if(salary<300){
            tax =0;
        }
        cout<<"Name: "<<name<< ", Gender: "<<gender<< ", Salary: "<< salary<< ", Tax: "<<tax<<endl;
    }else if (gender =='f' || gender =='F'){
        if(salary> 1000){
            tax = salary*(8/100);
        }else if (salary > 500 || salary <=1000){
            tax = salary*(6.5/100);
        }else if (salary>=300 || salary <=500){
            tax = salary*(3.5/100);
        }else if (salary<300){
            tax =0;
        }
        cout<<"Name: "<<name<< ", Gender: "<<gender<< ", Salary: "<< salary<< ", Tax: "<<tax<<endl;
    }else{
        cout<<"Invaild input.";
    }

    return 0;
}