#ifndef EKONOMI_H

#define EKONOMI_H

extern double inflation_rate(double money_value_now, double money_value_past);
extern double interest_simple(double money_value, double interest_value, double years);
extern double compound_interest(double money_value, double interest_value, double years);
extern double present_value(double money_value, double interest_value, double years);
extern double compound_periods(double money_value, double interest_value, double years);
extern double interest_rate(double future_value, double present_value, double years);
extern double many_periods(double future_value, double present_value, double interest_value);

#endif