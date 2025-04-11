#include <iostream>

using namespace std;

// Function to perform modular exponentiation (base^exp % mod)
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

// Function to perform Miller-Rabin primality test
bool millerRabin(long long n, int k) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    long long d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d = d / 2;
        s++;
    }

    for (int i = 0; i < k; i++) {
        long long a = 2 + i;  // Simple base selection
        long long x = modExp(a, d, n);

        if (x == 1 || x == n - 1) continue;

        bool isComposite = true;
        for (int r = 0; r < s - 1; r++) {
            x = (x * x) % n;
            if (x == n - 1) {
                isComposite = false;
                break;
            }
        }

        if (isComposite) return false;
    }

    return true;
}

int main() {
    long long n;
    int k;

    cout << "Enter a number to test for primality: ";
    cin >> n;
    cout << "Enter number of iterations for Miller-Rabin test: ";
    cin >> k;

    if (millerRabin(n, k)) {
        cout << n << " is probably prime." << endl;
    } else {
        cout << n << " is composite." << endl;
    }

    return 0;
}

