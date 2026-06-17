#include <iostream>
using namespace std;

int main(){
    int n1=7, n2=3, n3=15;

    int *p1 = &n1;
    int *p2 = &n2;
    int *p3 = &n3;

    cout<<"n1: Value = "<<*p1<< ", Address = "<<p1<<endl;
    cout<<"n2: Value ="<< *p2 << ", Address = "<<p2<<endl;
    cout<<"n3 Value = "<< *p3 << ", Address = "<<p3<<endl;

    *p3 = *p1 + *p2;
    
    cout<< "\nAfter update:"<<endl;
    cout<<"New value of n3: "<<n3<<endl;

    return 0;
}