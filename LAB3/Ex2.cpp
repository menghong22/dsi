#include <iostream>
using namespace std;

int main(){
    int n;
    int *ptr = &n;

    cout<<"Enter a number: ";
    cin >> n;

    *ptr = *ptr +7;

    cout<<"Modified value of n: "<<n<<endl;

    return 0;
}