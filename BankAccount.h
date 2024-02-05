#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

using namespace std;

class BankAccount {
public:
    //constructor
    BankAccount();

    // mutators
    void SetMonths(const int& t_months);
    double SetOpeningBalance(double t_openingBalance) const;
    double SetDepositedAmount(double t_depositedAmount) const;
    double SetDepositedSum(double t_opening, double t_deposited) const;
    double SetInterestEarned(double t_interestRate) const;
    double SetEndingBalance(double t_totalAmount, double t_interestAmount) const;

    // accessors
    int GetMonths() const;
    double GetOpeningBalance() const;
    double GetDepositedAmount() const;
    double GetDepositedSum() const;
    double GetInterestEarned() const;
    double GetEndingBalance() const;

private:
    //fields
    int numMonths = 0; //NOTE: is a result of years, so will be a mult. of 12!
    double openingBalance=0.0;
    double depositedAmount=0.0;
    double depositedSum=0.0; //sum of opening/deposited amounts
    double interestEarned=0.0;
    double endingBalance=0.0;
};


#endif