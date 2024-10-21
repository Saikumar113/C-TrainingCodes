#include <iostream>
using namespace std;

// Define ABS macro
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int num1 = -10;
    int x = 10, y = 20;

    // Using ABS macro to find the absolute values
    cout << "Absolute value of " << num1 << " is " << ABS(num1) << endl;
    cout << "Greater of " << x << " and " << y << " is " << MAX(x, y) << endl;
    return 0;
}
