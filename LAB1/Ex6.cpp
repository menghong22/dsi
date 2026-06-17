#include <iostream>
using namespace std;

int main(){
    int n;
    long long sum =0;

    cout<<"Enter a number (n>50)";
    cin>>n;

    while(n<=50){
        cout<<"Error: Number must be greater than 50. Please try again: ";
        cin>> n;
    }

    for(int i=1; i<=n; i++){
        if(i==10 | i==30){
            continue;
        }
        sum+=i;
    }
    cout<<"The summation from 1 to "<<n<<" (excluding 10 and 30) is: "<<sum<<endl;

    return 0;
}