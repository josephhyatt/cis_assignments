#include <iostream>

using namespace std;

int main ()
{
    int number;
    cout << "Enter a number to get all prime #'s upto this number: ";
    cin >> number;
    if (number <= 1)
    {
        cout << "Only positive integers greater than 1 allowed.";
        return 0;
    }
    // Iterate over all numbers from 2 to given number
    for (int i = 2; i < number; i++)
    {
        bool isPrime = true;
        // divide the i with all number from 2 to sqrt(i), if i is divisible, means not prime, if not it's a prime
        for (int j = 2; j*j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            cout << i << endl;
        }
    }
    return 0;
}
