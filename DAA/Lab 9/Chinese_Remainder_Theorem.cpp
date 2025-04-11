#include <iostream>
using namespace std;

// Function to compute gcd of two numbers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to compute modular inverse of a under modulo m
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;  // In case inverse doesn't exist
}

// Function to solve the system of congruences using the Chinese Remainder Theorem
int chineseRemainderTheorem(int a[], int m[], int n) {
    int M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];  // Compute the product of all moduli
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int Mi = M / m[i];  // Partial product
        int yi = modInverse(Mi, m[i]);  // Modular inverse of Mi modulo mi
        if (yi == -1) {
            cout << "Modular inverse doesn't exist for modulus " << m[i] << endl;
            return -1;
        }
        result += a[i] * Mi * yi;  // Add to the solution
    }

    return result % M;  // Return the result modulo M
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    int a[n], m[n];
    cout << "Enter the remainders (a_i): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter the moduli (m_i): ";
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    int result = chineseRemainderTheorem(a, m, n);
    if (result != -1) {
        cout << "The solution to the system of congruences is: " << result << endl;
    }

    return 0;
}

