#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>
#include "Node.h"


using namespace std;

template <typename T>
class SinglyLinkedList {
    private:
        Node<T>* head;
        void check_head() {
            if (head == nullptr) {
                throw range_error("List is Empty");
            }
        }


    public:
        SinglyLinkedList() {};
        SinglyLinkedList(Node<T> *obj) {
            head = obj;
        }

    void insertFront(T value) {
        //  Insert at the beginning
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->set_next(head);
        head = newNode;
    }
    
    void insertBack(T value) {
        // Insert at the end

        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node<T>* temp_node = head;
        while (temp_node->get_next() != nullptr) {
            temp_node = temp_node->get_next();
        }

        temp_node->set_next(newNode);
    }

    void printList() {
        // Display list contents

        Node<T> *temp_node = head;

        while (temp_node != nullptr) {
            cout << " " << temp_node->get_data(); 
            temp_node = temp_node->get_next();
        }
        cout << endl;
    }

    
    void insertAt(int position, T value) {
        // Insert at a given position
        Node<T> *newNode = new Node<T>(value);

        if (position == 0 || head == nullptr) {
            head = newNode;
        }

        check_head();
        
        Node<T>*temp_node = head;
        
        int i = 0;
        while (i < position - 1 && temp_node->get_next() != nullptr) {
            temp_node = temp_node->get_next();
            i += 1;
        }
        newNode->set_next(temp_node->get_next());
        temp_node->set_next(newNode);    
    }

    void deleteFront() {
        // Remove from beginning
        check_head();

        Node<T>* temp_node = head;
        head = head->get_next();
        delete temp_node;
    }

    void deleteBack() {
        // Remove from end
        check_head();

        if (head->get_next() == nullptr) {
            delete head;
            head = nullptr;
            return; 
        }

        Node<T> *temp_node = head;

        while (temp_node->get_next()->get_next() != nullptr) {
            temp_node = temp_node->get_next();
        }

        Node<T> *deletionNode = temp_node->get_next();
        delete deletionNode;
        temp_node->set_next(nullptr);
    }

    void deleteAt(int position) {
        // Remove at a given position
        check_head();

        if (position == 0) {
            Node<T> *deletionNode = head;
            head = head->get_next();
            delete deletionNode;
            return;
        }

        Node<T> *temp_node = head;
        int i = 0;

        while (i < position - 1 && temp_node->get_next() != nullptr) {
            temp_node = temp_node->get_next();
            i += 1;
        }

        if (temp_node->get_next() == nullptr) {
            throw out_of_range("Invalid Position");
        }



        Node<T> *deletionNode = temp_node->get_next();
        temp_node->set_next(temp_node->get_next());
        delete deletionNode;

    }

    void deleteValue(T value) {
        // If list is empty
        if (!head) return;

        // If head contains the value
        if (head->get_data() == value) {
            Node<T>* deletionNode = head;
            head = head->get_next();
            delete deletionNode;
            return;
        }

        Node<T> *temp_node = head;

        // Traverse while next exists
        while (temp_node->get_next() != nullptr) {
            if (temp_node->get_next()->get_data() == value) {
                Node<T> *deletionNode = temp_node->get_next();
                temp_node->set_next(deletionNode->get_next());
                delete deletionNode;
                return;  // stop after deleting first occurrence
            }
            temp_node = temp_node->get_next();
        }
    }


    void clear() {
        Node<T>* temp_node = head;

        while (temp_node != nullptr) {
            Node<T>* deletionNode = temp_node;
            temp_node = temp_node->get_next();
            delete deletionNode;
        }

        head = nullptr;  // list is now empty
    }

};


#endif