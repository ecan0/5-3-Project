#include <iostream>
#include <math.h>

#include "BankAccount.h"
using namespace std;

//Constructor with fields.
BankAccount::BankAccount()
{
    m_numYears = 0;
    m_openingBalance = 0.0;
    m_depositedAmount = 0.0;
    m_sumBalances = 0.0; // sum of opening+deposited amounts
    m_interestEarned = 0.0;
    m_endingBalance = 0.0;
}

//Mutators for number of years, balances, and interest rate.
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

void BankAccount::setEarnedInterest(double t_openingBalance, double t_interestRate)
{
    // Annual interest
    m_interestEarned = t_openingBalance * t_interestRate;
}

void BankAccount::setEndingBalance(double t_totalAmount, double t_interestAmount)
{
    m_endingBalance = t_totalAmount + t_interestAmount;
}

//Accessors for number of years, balances, and interest rate.
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

//Reads user input from terminal for opening amount, deposit amount, interest rate, and years.
void BankAccount::readUserInput()
{
    //create input var and print welcome message
    double input;
    cout << "Welcome to the Airgead Banking App!\n"
         << endl;
    cout << "*************************************" << endl;
    cout << "**************DATA INPUT*************\n"
         << endl;
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
        //error for non number and reprompt
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
        //error for non number and reprompt
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
            //error for non number and reprompt
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
            //error for non number and reprompt
            cout << endl
                 << "That seems to be incorrect, enter a positive real number." << endl;
            continue;
        }
    }

    // Clear input buffer for next input.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //combine opening and deposited balances to get sum
    setSumOfBalances(getOpeningBalance(), getDepositedAmount());
    // Press any key to continue prompt (On Windows)
    system("pause");
    cout << "\n"
         << endl;
    ;
}

void BankAccount::balanceWithoutAdditions()
{
    // initialize variables within function
    double openingBalance = getOpeningBalance();
    double interestRate = getInterestRate() / 100 / 12 ;
    int numYears = getNumberYears();

    // calculate / print end balance and interest earned for each year
    for (int year = 1; year <= numYears; ++year)
    {
        // monthly interest rate
        double monthlyInterestRate = pow(1 + interestRate, 12) - 1;

        // interest earned for the year
        double interestEarned = openingBalance * monthlyInterestRate;

        // year-end balance
        double endingBalance = openingBalance + interestEarned;

        // Print results for year
        cout << fixed << setprecision(2) << year << "                 $" << setw(4) << endingBalance << "                    $" << interestEarned << endl;

        // Update opening balance for the next iteration
        openingBalance = endingBalance;
    }
}

void BankAccount::balanceWithAdditions()
{
    // Constants
    const int monthsPerYear = 12;
    double monthlyInterest = 0.0;

    // Initializations
    double openingBalance = getOpeningBalance();
    double monthlyDeposit = getDepositedAmount();
    double interestRate = (getInterestRate() / 100) / 12;
    int numYears = getNumberYears();

    // Reset sumBalances for the new calculation
    setSumOfBalances(0.0, 0.0);

    // Calculate and update the end of year balance for each year
    for (int year = 1; year <= numYears; ++year)
    {
        // Calculate year-end balance, total accumulated interest, and closing balance
        double endingBalance = openingBalance;
        double totalAccumulatedInterest = 0.0;

        // Add monthly deposits and interest for each month
        for (int month = 1; month <= monthsPerYear; ++month)
        {
            endingBalance += monthlyDeposit;
            monthlyInterest = endingBalance * interestRate;
            totalAccumulatedInterest += monthlyInterest;
            endingBalance += monthlyInterest; // Compounded interest for the month
        }

        // Closing balance is the sum of the total and interest amounts
        double closingBalance = endingBalance + totalAccumulatedInterest;

        // Update sumBalances for the current year
        setSumOfBalances(getSumOfBalances() + closingBalance, 0.0);

        // Print the results for the current year
        cout << fixed << setprecision(2) << year << "                 $" << setw(4) << endingBalance << "                    $" << totalAccumulatedInterest << endl;

        // Update opening balance for the next iteration
        openingBalance = endingBalance;
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