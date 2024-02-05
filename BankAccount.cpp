#include <iostream>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount()
{
    m_numYears = 0;
    m_openingBalance = 0.0;
    m_depositedAmount = 0.0;
    m_depositedSum = 0.0; // sum of opening/deposited amounts
    m_interestEarned = 0.0;
    m_endingBalance = 0.0;
}

void BankAccount::setOpeningBalance(double t_openingBalance)
{
    m_openingBalance = t_openingBalance;
}

void BankAccount::getUserInput()
{
    double input;
    cout << "Welcome to the Airgead Banking App!" << endl;
    cout << "*************************************!" << endl;
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

    cout << endl
         << "Monthly deposit amount: ";
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
    cout << endl
         << "Annual Interest: ";
    while (cin >> input)
    {
        // Needs to be positive real number
        if (input > 0)
        {
            setInterestEarned(input);
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

    //Number of years user input
    cout << endl
         << "Number of years: ";
    while (cin >> input)
    {
        // Needs to be positive real number
        if (input > 0)
        {
            setNumberYears(input);
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
}