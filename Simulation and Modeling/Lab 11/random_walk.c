#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int position = 0;
    int steps, i;
    printf("Enter number of steps: ");
    scanf("%d", &steps);
    srand(time(0));
    for (i = 0; i < steps; i++) {
        if (rand() % 2 == 0)
            position--;
        else
            position++;
    }
    printf("Final position: %d\n", position);
    return 0;
}

