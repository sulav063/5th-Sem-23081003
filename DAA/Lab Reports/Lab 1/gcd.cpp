#include <iostream>
using namespace std;

// Function to calculate GCD and count steps
int gcd(int a, int b, int &steps) {
    steps = 0; // Initialize step counter
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        steps++; // Increment step counter
    }
    return a;
}

int main() {
    int num1, num2, steps;

    // Input two numbers
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Calculate GCD and steps
    int result = gcd(num1, num2, steps);

    // Display the result
    cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    cout << "Number of steps taken: " << steps << endl;

    return 0;
}

