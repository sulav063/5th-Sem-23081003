#include <iostream>
using namespace std;

// Recursive Fibonacci function with step counter
int fib(int x, int &steps)
{
    steps++; // Increment step counter for each function call
    if ((x == 1) || (x == 0))
    {
        return x;
    }
    else
    {
        return fib(x - 1, steps) + fib(x - 2, steps);
    }
}

int main()
{
    int x, i = 0, steps = 0;

    cout << "Enter the number of terms of series: ";
    cin >> x;

    cout << "\nFibonacci Series: ";
    while (i < x)
    {
        int stepsForTerm = 0; // Track steps for each term
        cout << " " << fib(i, stepsForTerm);
        steps += stepsForTerm; // Accumulate total steps
        i++;
    }

    cout << "\n\nTotal steps taken: " << steps << endl;

    return 0;
}

