

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define MAX 10000
#include "bigInteger.cpp"
 

int main()
{
  BigInteger a("123456789");
  BigInteger b("987654321");
  BigInteger c = a * b;
  std::cout << c << std::endl;
  return 0;
}