#include <iostream>

#include "array.h"

using namespace std;


int main() {
    FixedArray arr(3);
    arr.fill(2);

    arr[1] = 10;
    arr.back() = 99;

    for (int* it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << arr.at(3) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    cout << endl << endl;
    
    DynamicArray darr(4);

    darr[1] = 1;
    darr.back() = 100;
    darr.push_back(20);

    for (int* it = darr.begin(); it != darr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    darr.pop_back();

    for (int* it = darr.begin(); it != darr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    DynamicArray D(0);

    cout << D.empty() << endl;

    return 0;
}