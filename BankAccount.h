#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <limits> // Include for numeric_limits.

using namespace std;

class BankAccount
{
public:
    // constructor
    BankAccount();

    void getUserInput();

    // mutators
    void setNumberYears(int t_numYears);
    void setOpeningBalance(double t_openingBalance);
    void setDepositedAmount(double t_depositedAmount);
    void setDepositedSum(double t_opening, double t_deposited);
    void setInterestEarned(double t_interestRate);
    void setEndingBalance(double t_totalAmount, double t_interestAmount);

    // accessors
    int getNumberYears(int t_numYears);
    double getOpeningBalance() const;
    double getDepositedAmount() const;
    double getDepositedSum() const;
    double getInterestEarned() const;
    double getEndingBalance() const;

private:
    // fields
    int m_numYears = 0;
    double m_openingBalance = 0.0;
    double m_depositedAmount = 0.0;
    double m_depositedSum = 0.0; // sum of opening/deposited amounts
    double m_interestEarned = 0.0;
    double m_endingBalance = 0.0;
};

#endif