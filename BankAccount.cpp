#include <iostream>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount()
{
    m_numYears = 0;
    m_openingBalance = 0.0;
    m_depositedAmount = 0.0;
    m_sumBalances = 0.0; // sum of opening/deposited amounts
    m_interestEarned = 0.0;
    m_endingBalance = 0.0;
}

void BankAccount::setNumberYears(int t_numYears)
{
    m_numYears = t_numYears;
}

void BankAccount::setOpeningBalance(double t_openingBalance)
{
    m_openingBalance = t_openingBalance;
}

void BankAccount::setDepositedAmount(double t_depositedAmount)
{
    m_depositedAmount = t_depositedAmount;
}

void BankAccount::setInterestRate(double t_interestRate)
{
    m_interestRate = t_interestRate;
}

void BankAccount::setSumOfBalances(double t_opening, double t_deposited)
{
    m_sumBalances = t_opening + t_deposited;
}

void BankAccount::setEarnedInterest(double t_openingBalance, double t_sumOfBalances, double t_interestRate, int t_years)
{
    // Annual interest
    m_interestEarned = (t_openingBalance + t_sumOfBalances) * (t_interestRate / 100) * t_years;
}

void BankAccount::setEndingBalance(double t_totalAmount, double t_interestAmount)
{
    m_endingBalance = t_totalAmount + t_interestAmount;
}

int BankAccount::getNumberYears()
{
    return m_numYears;
}

double BankAccount::getOpeningBalance() const
{
    return m_openingBalance;
}

double BankAccount::getDepositedAmount() const
{
    return m_depositedAmount;
}

double BankAccount::getInterestRate() const
{
    return m_interestRate;
}

double BankAccount::getSumOfBalances() const
{
    return m_sumBalances;
}

double BankAccount::getEarnedInterest() const
{
    return m_interestEarned;
}

double BankAccount::getEndingBalance() const
{
    return m_endingBalance;
}

void BankAccount::readUserInput()
{
    double input;
    cout << "Welcome to the Airgead Banking App!" << endl;
    cout << "*************************************" << endl;
    cout << "**************DATA INPUT*************" << endl;
    cout << "Initial investment amount: ";

    // Opening Investment user input check
    while (cin >> input)
    {
        // Needs to be positive real number
        if (input > 0)
        {
            setOpeningBalance(input);
            break;
        }
        else
        {
            cout << endl
                 << "That seems to be incorrect, enter a positive real number." << endl;
            continue;
        }
    }

    // Clear input buffer for next input.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Monthly deposit amount: ";
    // Monthly deposit amount user input check
    while (cin >> input)
    {
        // Needs to be positive real number
        if (input > 0)
        {
            setDepositedAmount(input);
            break;
        }
        else
        {
            cout << endl
                 << "That seems to be incorrect, enter a positive real number." << endl;
            continue;
        }
    }

    // Clear input buffer for next input.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Annual accured interest  user input check
    cout << "Annual Interest: ";
    while (cin >> input)
    {
        // Needs to be positive real number
        if (input > 0)
        {
            setInterestRate(input);
            break;
        }
        else
        {
            cout << endl
                 << "That seems to be incorrect, enter a positive real number." << endl;
            continue;
        }
    }

    // Clear input buffer for next input.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Number of years user input
    cout << "Number of years: ";
    while (cin >> input)
    {
        // Needs to be positive real number
        if (input > 0)
        {
            setNumberYears(static_cast<int>(input));
            break;
        }
        else
        {
            cout << endl
                 << "That seems to be incorrect, enter a positive real number." << endl;
            continue;
        }
    }

    // Clear input buffer for next input.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    setSumOfBalances(getOpeningBalance(), getDepositedAmount());
    // Press any key to continue prompt (On Windows)
    system("pause");
}

void BankAccount::balanceWithoutAdditions()
{
    for (int year = 1; year <= getNumberYears(); ++year)
    {
        setEarnedInterest(getOpeningBalance(), getSumOfBalances(), getInterestRate(), getNumberYears());
        setEndingBalance(getSumOfBalances(), getEarnedInterest());
        cout << endl << year << "                 " << getEndingBalance() << "                     " << getEarnedInterest() <<  endl;
    }
}

void BankAccount::balanceWithAdditions()
{
    for (int year = 1; year <= getNumberYears(); ++year)
    {
        setEndingBalance(getSumOfBalances(), getEarnedInterest());
        cout << endl << year << "                 " << getEndingBalance() << "                     " << getEarnedInterest() <<  endl;
    }
}

void BankAccount::printNoDeposits()
{
    cout << "     Balance And Interest Without Additional Monthly Deposits    " << endl;
    cout << "=================================================================" << endl;
    cout << "Year              Year End Balance           Year Earned Interest" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    balanceWithoutAdditions();
    cout << "-----------------------------------------------------------------" << endl;
}

void BankAccount::printAdditionalDeposits()
{
    cout << "     Balance And Interest With Additional Monthly Deposits    " << endl;
    cout << "=================================================================" << endl;
    cout << "Year              Year End Balance           Year Earned Interest" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    balanceWithAdditions();
    cout << "-----------------------------------------------------------------" << endl;
}