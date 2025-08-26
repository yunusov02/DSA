#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

int main() {
    SinglyLinkedList<int> list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);

    cout << "Initial list: ";
    list.printList();
    cout << endl;

    cout << "Deleting 20..." << endl;
    list.deleteValue(20);
    list.printList();
    cout << endl;

    list.deleteBack();
    list.printList();

    list.deleteFront();
    list.printList();

    cout << "Clearing list..." << endl;
    list.clear();
    list.printList();
    cout << endl;


    return 0;
}
