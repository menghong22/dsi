#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));

    int userChoice;
    int computerChoice = (rand()%3)+1;
    
    cout<<"--- Rock Paper Scissors ---"<<endl;
    cout<<"1. Rock"<<endl;
    cout<<"2. Paper"<<endl;
    cout<<"3. Scissors"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>userChoice;

    cout<<"Computer chose: ";
    if(computerChoice ==1) cout<<"Rock"<<endl;
    else if(computerChoice ==2) cout<<"Paper"<<endl;
    else cout<<"Scissors"<<endl;

    if(userChoice == computerChoice){
        cout<<"It's a tie!"<<endl;
    }else if((userChoice ==1 && userChoice == 3) || (userChoice==2 && userChoice ==1)
                || userChoice ==3 && userChoice==2){
            cout<<"You win! Congratulations."<<endl;
    }else if(userChoice<1 || userChoice>3){
        cout<<"Invaild Choice! Please run again and pick 1, 2, or 3."<<endl;
    }else{
        cout<<"Computer wins! Better luck next time."<<endl;
    }


    return 0;
}