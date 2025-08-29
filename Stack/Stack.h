#ifndef STACK
#define STACK

#include <iostream>
#include "StackNode.h"

using namespace std;

/*


push(T Value)
pop
top() Top element without removing it
isEmpty
size
clear
contains


*/


template <typename T>
class Stack {
    private:
        StackNode<T> *head;
    
    public:
        Stack() {
            head = nullptr;
        }

        Stack(StackNode<T>* obj) {
            head = obj;
        }
        
        void push(T value) {
            StackNode<T> *newNode = new StackNode(value);

            if (head == nullptr) {
                head = newNode;
                return;
            }

            newNode->set_next(head);
            head = newNode;
        }

        void pop() {

            if (head == nullptr)
                throw range_error("Stack is empty");

            StackNode<T> *deletionNode = head;
            head = head->get_next();

            delete deletionNode;
        }


        int size() const {
            int counter = 0;

            if (head == nullptr) return 0;
            
            StackNode<T> *tempNode = head;
            while (tempNode != nullptr) {
                counter += 1;
                tempNode = tempNode->get_next();
            }

            return counter;
        }

        bool isEmpty() const {
            return size() == 0;
        }

        void printStack() const {

            if (head == nullptr) cout << "List is empty" << endl;

            StackNode<T> *temp = head;
            
            bool fisrtTime = true;

            while (temp != nullptr) {
                if (fisrtTime) {
                    cout << temp->get_data();
                    fisrtTime = false;
                } else {
                    cout << " --> " << temp->get_data();
                } 
                
                temp = temp->get_next();
            }

            cout << endl;

        }

};

#endif