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

    void readUserInput();
    void printNoDeposits();
    void printAdditionalDeposits();
    void balanceWithAdditions();
    void balanceWithoutAdditions();

    // mutators
    void setNumberYears(int t_numYears);
    void setOpeningBalance(double t_openingBalance);
    void setDepositedAmount(double t_depositedAmount);
    void setInterestRate(double t_interestRate);
    void setSumOfBalances(double t_opening, double t_deposited);
    void setEarnedInterest(double t_openingBalance, double t_sumOfBalances, double t_interestRate, int t_years);
    void setEndingBalance(double t_totalAmount, double t_interestAmount);

    // accessors
    int getNumberYears();
    double getOpeningBalance() const;
    double getDepositedAmount() const;
    double getInterestRate() const;
    double getSumOfBalances() const;
    double getEarnedInterest() const;
    double getEndingBalance() const;

private:
    // fields
    int m_numYears = 0;
    double m_openingBalance = 0.0;
    double m_depositedAmount = 0.0;
    double m_interestRate = 0.0;
    double m_sumBalances = 0.0; // sum of opening/deposited amounts
    double m_interestEarned = 0.0;
    double m_endingBalance = 0.0;
};

#endif