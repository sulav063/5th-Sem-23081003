#include <stdio.h>
int main() {
    float P_C_given_C = 0.9;  // P(Coke | Coke)
    float P_C_given_P = 0.2;  // P(Coke | Pepsi)
    float P_P_given_C = 0.1;  // P(Pepsi | Coke)
    float P_P_given_P = 0.8;  // P(Pepsi | Pepsi)
    // Initial condition: person starts with Pepsi
    float P_C_2_given_P_0 = (P_C_given_P * P_C_given_C) + (P_P_given_P * P_C_given_P);
    printf("Probability of purchasing Coke after two purchases: %.2f\n", P_C_2_given_P_0);
    return 0;
}

