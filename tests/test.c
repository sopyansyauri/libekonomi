#include <stdio.h>
#include <ekonomi.h>
#include <math.h>

int main(void)
{
    printf("Persentage of inflasion: %.2f%% \n", inflation_value(2000000000, 1000000000));
    printf("Interest Value: %.2f \n", interest_simple(3000.0, 0.05, 4.0));
    printf("Compound Interest: %.2f \n", compound_interest(1000, 0.1, 15));
    printf("Present Value: %.2f \n", present_value(4177.25, 0.1, 15));
    printf("Present Value: %.2f \n", present_value(1100, 0.1, 1));
    printf("Interest Rate: %.2f%% \n", interest_rate(2000, 1000, 5));
    printf("Many Periods: %.2f years \n", many_periods(10000, 1000, 0.05));

    return 0;
}