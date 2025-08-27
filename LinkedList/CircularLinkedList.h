#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class CircularLinkedList {
    private:
        Node<T>* head;
        void check_head() {
            if (head == nullptr) {
                throw range_error("List is Empty");
            }
        }


    public:
        CircularLinkedList() {};
        CircularLinkedList(Node<T> *obj) {
            head = obj;
        } // done

    void insertFront(T value) {
        //  Insert at the beginning
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            head->set_next(head);
            return;
        }

        newNode->set_next(head);

        Node<T>* temp_node = head;
        while (temp_node->get_next() != head) {
            temp_node = temp_node->get_next();
        }

        temp_node->set_next(newNode);
        head = newNode;
    }
    
    void insertBack(T value) {
        // Insert at the end

        Node<T> *newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            head->set_next(head);
            return;
        }

        Node<T>* temp_node = head;
        while (temp_node->get_next() != head) {
            temp_node = temp_node->get_next();
        }

        temp_node->set_next(newNode);
        newNode->set_next(head);
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node<T>* temp_node = head;
        do {
            cout << " " << temp_node->get_data();
            temp_node = temp_node->get_next();
        } while (temp_node != head);

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
        while (i < position - 1 && temp_node->get_next() != head) {
            temp_node = temp_node->get_next();
            i += 1;
        }
        newNode->set_next(temp_node->get_next());
        temp_node->set_next(newNode);    
    }

    void deleteFront() {
        // Remove from beginning
        check_head();
    
        Node<T>* deletionNode = head;

        if (head->get_next() == head) {
            head = nullptr;
            delete deletionNode;
            return;
        }


        Node<T> *temp_node = head;
        while (temp_node->get_next() != head) {
            temp_node = temp_node->get_next();
        }
        
        head = head->get_next();
        temp_node->set_next(head);

        delete deletionNode;
    }

    void deleteBack() {
        // Remove from end
        check_head();

        Node<T> *deletionNode = head;
        if (head->get_next() == head) {
            head = nullptr;
            delete deletionNode;
            return; 
        }

        Node<T> *temp_node = head;

        while (temp_node->get_next()->get_next() != head) {
            temp_node = temp_node->get_next();
        }

        deletionNode = temp_node->get_next();
        delete deletionNode;

        temp_node->set_next(head);
    }

    void deleteAt(int position) {
        check_head();

        if (head->get_next() == head && position == 0) {
            delete head;
            head = nullptr;
            return;
        }

        if (position == 0) {
            Node<T>* last = head;
            while (last->get_next() != head) {
                last = last->get_next();
            }

            Node<T>* deletionNode = head;
            head = head->get_next();
            last->set_next(head);

            delete deletionNode;
            return;
        }

        Node<T>* temp = head;
        int i = 0;

        while (i < position - 1) {
            temp = temp->get_next();
            if (temp == head) {
                throw out_of_range("Invalid Position");
            }
            i++;
        }

        Node<T>* deletionNode = temp->get_next();
        temp->set_next(deletionNode->get_next());
        delete deletionNode;
    }

    void deleteValue(T value) {
        check_head();

        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        if (head->get_next() == head && head->get_data() == value) {
            delete head;
            head = nullptr;
            return;
        }

        if (head->get_data() == value) {
            Node<T>* last = head;
            while (last->get_next() != head) {
                last = last->get_next();
            }

            Node<T>* deletionNode = head;
            head = head->get_next();
            last->set_next(head);

            delete deletionNode;
            return;
        }

        prev = head;
        temp = head->get_next();
        while (temp != head) {
            if (temp->get_data() == value) {
                prev->set_next(temp->get_next());
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->get_next();
        }

        throw out_of_range("Value not found");
    }



    void clear() {
        Node<T>* temp_node = head;

        while (temp_node->get_next() != head) {
            Node<T>* deletionNode = temp_node;
            temp_node = temp_node->get_next();
            delete deletionNode;
        }

        head = nullptr;  // list is now empty
    }

};
    
#endif