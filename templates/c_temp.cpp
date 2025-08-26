#include <iostream>

using namespace std;

template<typename T1, typename T2, typename T3>
class Geek {
    public:
    T1 x;
    T2 y;
    T3 z;

    Geek(T1 val1, T2 val2, T3 val3) {
        x = val1;
        y = val2;
        z = val3;
    }

    void getValues() {
        cout << x << " " << y << " " << z << endl;
    }
};


int main() {
    Geek<int, float, double> g1(1.1, 1.1, 1.1);

    g1.getValues();

    return 0;
}
