#include <iostream>

using namespace std;

// Function to compute GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    cout << "The GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    
    return 0;
}

