#include <iostream>
using namespace std;

void exchange(float *a, float *b){
    float temp = *a;
    *a =*b;
    *b =temp;
}

int main(){
    float x=10.5, y=20.5;
    cout<<"Before Exchange: x= "<<x<< ", y= "<<y<<endl;

    exchange(&x, &y);

    cout<<"After Exchange: x= "<<x<< ", y= "<<y;
    return 0;
}