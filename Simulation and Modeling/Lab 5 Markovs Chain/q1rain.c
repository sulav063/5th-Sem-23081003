#include <stdio.h>
int main() {
    float P_notRain_today = 1.0;  // Given that today is not rainy
    float P_notRain_tomorrow = 0.8;
    float P_rain_tomorrow = 0.2;
    float P_notRain_given_notRain = 0.8;
    float P_notRain_given_rain = 0.6;
    // Calculate probability
    float P_notRain_day_after = (P_notRain_tomorrow * P_notRain_given_notRain) +
                                (P_rain_tomorrow * P_notRain_given_rain);
    printf("Probability of not raining the day after tomorrow: %.2f\n", P_notRain_day_after);
    return 0;
}

