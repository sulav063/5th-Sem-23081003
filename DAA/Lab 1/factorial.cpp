#include <iostream>
using namespace std;

// Recursive factorial function with step counter
int fact(int x, int &steps) {
    steps++; // Increment step counter for each call
    if (x == 1) {
        return 1;
    } else {
        return x * fact(x - 1, steps);
    }
}

int main() {
    int n, steps = 0;

    cout << "Enter a number: ";
    cin >> n;

    // Handle invalid input
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    // Calculate factorial and count steps
    int result = fact(n, steps);

    cout << "Factorial of " << n << " is " << result << endl;
    cout << "Number of steps taken: " << steps << endl;

    return 0;
}

