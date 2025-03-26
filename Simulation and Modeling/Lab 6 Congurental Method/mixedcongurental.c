#include <stdio.h>

int main() {
    int X0 = 11, a = 5, c = 13, m = 100;
    int Xn = X0;
    int i; // Declare variables outside loops

    printf("Generated 50 random numbers using Mixed Congruential Method:\n");

    for (i = 0; i < 50; i++) {
        Xn = (a * Xn + c) % m;
        printf("%d ", Xn);

        if ((i + 1) % 10 == 0)  // Print 10 numbers per line
            printf("\n");
    }

    return 0;
}

