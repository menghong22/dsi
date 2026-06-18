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

        bool isFull(){
            return (top>= MAX-1);
        }

        void displayStack(){
            if (isEmpty()){
                cout<<"Stack is empty."<<endl;
                return;
            }
            cout<<"Stack elements (top to bottom)";
            for(int i=top; i>=0; i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    ArrayStack stack;

    cout <<"--- Testing Array-Vased Stack ---"<<endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.displayStack();

    cout<<"Peek top element: "<<stack.peek()<<endl;
    cout<<"Popped: " <<stack.pop()<<endl;
    stack.displayStack();

    return 0;
}