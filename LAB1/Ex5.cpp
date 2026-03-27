#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double totalMin;
    int hours, remainMin, seconds;

    cout<< "Enter the number of minutes: ";
    cin>> totalMin;

    hours = (int)totalMin/60;
    remainMin = (int)totalMin%60;
    seconds = (totalMin - (int)totalMin)*60;

    cout<<"Time format(h:m:s)"<<hours<<":"<<remainMin<<":"<<seconds<<endl;
    return 0;
}