#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedListStack{
    private:
        Node* top;
    public:
        LinkedListStack(){
            top = nullptr;
        }

        void push (int x){
            Node* temp = new Node();
            temp-> data= x;
            temp-> next = top;
            top = temp;
        }

        int pop(){
            if(isEmpty()){
                cout<< "Stack is underflow! Cannot pop."<<endl;
                return -1;
            }
            Node
        }
};