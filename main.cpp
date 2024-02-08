#include <iostream>
#include "BankAccount.h"

using namespace std;

int main()
{
    BankAccount Account;
    Account.readUserInput();
    Account.printNoDeposits();
    Account.printAdditionalDeposits();
}