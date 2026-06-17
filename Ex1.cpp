#include <iostream>
using namespace std;

#define MAX 100

class ArrayStack{
    private:
        int top;
        int arr[MAX];
    public:
        ArrayStack(){
            top=-1;
        }
        bool push(int x){
            if(isFull()){
                cout<<"Stack Overflow! Cannot push"<< x <<endl;
                return false;
            }
            arr[++top] =x;
            return true;
        }

        int pop(){
            if (isEmpty()){
                cout<<"Stack Underflow! Cannot pop."<<endl;
                return -1;
            }
            return arr[top--];
        }

        int peek(){
            if(isEmpty()){
                cout<<"Stack is empty."<<endl;
                return -1;
            }
            return arr[top];
        }

        bool isEmpty(){
            return (top<0);
        }

};
