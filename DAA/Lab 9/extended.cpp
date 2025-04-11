#include <iostream>

using namespace std;

// Function to compute the GCD and the coefficients x and y
int extendedGCD(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    
    x = y1;
    y = x1 - (a / b) * y1;
    
    return gcd;
}

int main() {
    int a, b, x, y;
    
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    int gcd = extendedGCD(a, b, x, y);
    
    cout << "The GCD of " << a << " and " << b << " is: " << gcd << endl;
    cout << "Bezout coefficients: x = " << x << ", y = " << y << endl;
    
    return 0;
}

