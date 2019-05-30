/*=============================================================================
#  Author:          josephhyatt - https://github.com/josephhyatt/
#  Email:           hyattj@student.vvc.edu
#  FileName:        main.cpp
#  Description:     Program that's given a number n, that will print all primes <= to n. 
                    It does so by finding numbers in the table that are multiples of a number and therefore composite, 
                    to discard them as prime. The numbers that are left will be prime numbers.
=============================================================================*/
#include <iostream>
#include <set>

void Sieve(int n)
{
  // create a boolean array
  bool prime[n + 1];
  // initialize all entries it as true. If i is prime then prime[i] is true else false.
  for (int i = 0; i < n + 1; i++)
    prime[i] = true;
    prime[0] = false; //0 and 1 are not prime
    prime[1] = false;
    // create a set and insert all numbers from 0 to n into it.
    std::set<int> s;
  for (int i = 0; i < n + 1; i++){
    s.insert(i);
  }

  for (int j = 2; j * j <= n; j++){
    // if prime[j] stays the same, then it's a prime
    if (prime[j] == true){
      // update j multiples which are >= it and < than j^2
      for (int i = j * j; i <= n; i += j)
        prime[i] = false;
    }
  }

  // output prime numbers
  for (int j = 1; j <= n; j++)
    if (prime[j]){
      // iterator that points to the beginning of the set
      std::set<int>::iterator traverse = s.begin(); 
      std::advance(traverse, j);
      std::cout << *traverse << " ";
    }
}

int main()
{
  int n;
  std::cout << "Enter value for n: ";
  std::cin >> n;
  std::cout << "Prime numbers <= to " << n << ":" << std::endl;
  Sieve(n);
}