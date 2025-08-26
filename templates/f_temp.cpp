#include <iostream>
using namespace std;

template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}




template <typename T1, typename T2>
T1 myfunc(T1 x, T2 y) {
    return x + y;
}


int main() {

    cout << myMax<int>(7, 3) << endl;

    cout << myMax<double>(2.3, 54.2) << endl;

    cout << myMax<char>('g', 'e') << endl;


    cout << myfunc<int, double>(23.34, 40.56) << endl;

    return 0;
}