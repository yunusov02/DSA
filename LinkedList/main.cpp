#include <iostream>
#include "SinglyLinkedList.h"
#include "CircularLinkedList.h"

using namespace std;

int main() {

    CircularLinkedList<int> cList;

    cList.insertFront(1);
    cList.insertFront(2);
    cList.insertFront(3);
    cList.insertFront(4);

    cList.printList();

    cList.insertBack(5);
    cList.insertBack(6);
    cList.insertBack(7);
    cList.insertBack(8);

    cList.insertAt(4, 100);

    cList.deleteFront();
    cList.deleteFront();

    cList.deleteBack();
    cList.deleteBack();

    cList.printList();

    cList.clear();

    cList.printList();

    // SinglyLinkedList<int> list;

    // list.insertFront(10);
    // list.insertFront(20);
    // list.insertFront(30);
    // list.insertFront(40);

    // cout << "Initial list: ";
    // list.printList();
    // cout << endl;

    // cout << "Deleting 20..." << endl;
    // list.deleteValue(20);
    // list.printList();
    // cout << endl;

    // list.deleteBack();
    // list.printList();

    // list.deleteFront();
    // list.printList();

    // cout << "Clearing list..." << endl;
    // list.clear();
    // list.printList();
    // cout << endl << endl;

    return 0;
}
