#include <iostream>

using namespace std;

int main() {
    int principle;
    double interestRate;
    int time = 0;

    cout << "\nEnter initial Balance: ";
    cin >> principle;

    cout << "Enter interest rate (Annual): ";
    cin >> interestRate;

    double finalAmount = 1000000;
    double currentTotal = principle;

    while(currentTotal < finalAmount) {
        currentTotal = currentTotal + (currentTotal * interestRate) / 100.0;
        time++;
    }
    cout << "It would take " << time << " years for $" << principle << " with a " << interestRate << "% interest rate to reach $1,000,000\n";

    return 0;
}