#include <istream>
#include "Stack.h"

using namespace std;


int main() {

    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout << stack.size() << endl;

    stack.printStack();

    stack.pop();

    stack.printStack();




    return 0;
}