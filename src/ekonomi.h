#ifndef EKONOMI_H

#define EKONOMI_H

extern double inflation_value(double price_year_now, double price_year_past);
extern double interest_simple(double price_money, double price_interest, double years);
extern double compound_interest(double price_money, double price_interest, double years);
extern double present_value(double price_money, double price_interest, double years);
extern double compound_periods(double price_money, double price_interest, double years);
extern double interest_rate(double future_value, double present_value, double years);
extern double many_periods(double future_value, double present_value, double interest_value);

#endif