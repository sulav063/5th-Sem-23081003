#include <stdio.h>

int main() {
    int X0 = 13, a = 15, m = 1000;
    int Xn = X0;
    int i; // Declare loop variable outside (for old compilers)

    printf("Generated 50 random numbers using Multiplicative Congruential Method:\n");

    for (i = 0; i < 50; i++) {
        Xn = (a * Xn) % m; // Multiplicative congruential formula
        printf("%d ", Xn);

        if ((i + 1) % 10 == 0) // Print 10 numbers per line
            printf("\n");
    }

    return 0;
}

