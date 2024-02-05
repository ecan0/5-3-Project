#include <iostream>
#include "BankAccount.h"

using namespace std;

int main()
{
    BankAccount test;
    test.readUserInput();
    test.printNoDeposits();
    test.printAdditionalDeposits();
}