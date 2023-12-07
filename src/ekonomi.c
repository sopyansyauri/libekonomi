#include "ekonomi.h"
#include <math.h>

double inflation_value(double money_value_now, double money_value_past)
{
    double result = (money_value_now - money_value_past) / money_value_past * 100;
    return result;
}

double interest_simple(double money_value, double interest_value, double years)
{
    double result = money_value * interest_value * years;
    return result + money_value;
}

double compound_interest(double money_value, double interest_value, double years)
{
    double money_value_new = money_value;

    for (int i = 0; i < years; i++)
    {
        money_value_new += money_value_new * interest_value;
    }
    return money_value_new;
}

double present_value(double money_value, double interest_value, double years)
{
    double present_value = money_value / (pow(1 + interest_value, years));

    return present_value;
}

double compound_periods(double money_value, double interest_value, double years)
{
    double money_value_new = money_value;

    for (int i = 0; i < years; i++)
    {
        money_value_new += money_value_new * (interest_value / years);
    }
    return money_value_new;
}

double interest_rate(double future_value, double present_value, double years)
{
    double value = 1.0 / years;
    double rate = pow((future_value / present_value), value) - 1.0;
    return rate * 100;
}

double many_periods(double future_value, double present_value, double interest_value)
{
    double result = log(future_value / present_value) / log(1 + interest_value);
    return result;
}