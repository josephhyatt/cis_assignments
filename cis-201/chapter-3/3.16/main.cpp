#include <iostream>
using namespace std;
int main()
{
    double checking;
    double savings;
    double amount;
    int transaction_select;
    int account_select;

    cout<<"Checking: ";
    cin>>checking;
    cout<<"Saving: ";
    cin>>savings;

    if (checking >= 0 && savings >= 0)
    {
        cout<<"\nDeposit - 1\nWithdraw - 2\nTransfer to - 3\n";
        cin>>transaction_select;
        cout<<"Checking - 1\nSavings - 2\n";
        cin>>account_select;
        cout<<"Amount: ";
        cin>>amount;

        if (transaction_select == 1 && account_select == 1 && amount > 0)
            checking = checking + amount;
        if (transaction_select == 2 && account_select == 1 && amount <= checking && amount > 0)
            checking = checking - amount;
        if (transaction_select == 3 && account_select == 1 && amount <= checking && amount > 0)
        {
            checking = checking + amount;
            savings = savings - amount;
        }
        if (transaction_select == 1 && account_select == 2 && amount > 0)
            savings = savings + amount;
        if (transaction_select == 2 && account_select == 2 && amount <= savings && amount > 0)
            savings = savings - amount;
        if (transaction_select == 3 && account_select == 2 && amount <= savings && amount > 0)
        {
            savings = savings + amount;
            checking = checking - amount;
        }
        cout<<"\nChecking: "<<checking<<"\nSavings: "<<savings;
    }
    else
        cout<<"You can't enter negative numbers!";
}