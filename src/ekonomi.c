#include "ekonomi.h"
#include <math.h>

double inflation_value(double price_year_now, double price_year_past)
{
    double result = (price_year_now - price_year_past) / price_year_past * 100;
    return result;
}

double interest_simple(double price_money, double price_interest, double years)
{
    double result = price_money * price_interest * years;
    return result + price_money;
}

double compound_interest(double price_money, double price_interest, double years)
{
    double price_money_new = price_money;

    for (int i = 0; i < years; i++)
    {
        price_money_new += price_money_new * price_interest;
    }
    return price_money_new;
}

double present_value(double price_money, double price_interest, double years)
{
    double present_value = price_money / (pow(1 + price_interest, years));

    return present_value;
}

double compound_periods(double price_money, double price_interest, double years)
{
    double price_money_new = price_money;

    for (int i = 0; i < years; i++)
    {
        price_money_new += price_money_new * (price_interest / years);
    }
    return price_money_new;
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