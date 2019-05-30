#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define MAX 10000

class BigInteger 
{
public:
  BigInteger(); // empty constructor initializes zero
  BigInteger(std::string s); // "string" constructor
  BigInteger(std::string s, bool sign); // "string" constructor
  BigInteger(int n); // "int" constructor
  void setInt(std::string s);
  const std::string& getNumber(); // retrieves the number
  void setSign(bool s);
  const bool& getSign();
  BigInteger absolute(); // returns the absolute value
  void operator = (BigInteger b);
  bool operator == (BigInteger b);
  bool operator != (BigInteger b);
  bool operator > (BigInteger b);
  bool operator < (BigInteger b);
  bool operator >= (BigInteger b);
  bool operator <= (BigInteger b);
  BigInteger operator + (BigInteger b);
  BigInteger operator - (BigInteger b);
  BigInteger operator * (BigInteger b);
  BigInteger& operator += (BigInteger b);
  BigInteger& operator -= (BigInteger b);
  BigInteger& operator *= (BigInteger b);
  BigInteger operator -();
  operator std::string();
  friend std::ostream& operator << (std::ostream& os, const BigInteger& b);  

private:
  std::string number;
  bool sign;
  bool equals(BigInteger n1, BigInteger n2);
  bool less(BigInteger n1, BigInteger n2);
  bool greater(BigInteger n1, BigInteger n2);
  std::string add(std::string number1, std::string number2);
  std::string subtract(std::string number1, std::string number2);
  std::string multiply(std::string n1, std::string n2);
};

void BigInteger();

BigInteger::BigInteger(std::string s) 
{
  if(isdigit(s[0])) {
    setInt(s);
    sign = false;
  } else {
    setInt(s.substr(1));
    sign = (s[0] == '-');
  }
}

BigInteger::BigInteger(std::string s, bool sign) 
{
  setInt(s);
  setSign(sign);
}

BigInteger::BigInteger(int n) 
{
  std::stringstream ss;
  std::string s;
  ss << n;
  ss >> s;

  if(isdigit(s[0])) 
  {
    setInt(s);
    setSign(false); // +ve
  } else {
    setInt(s.substr(1));
    setSign(s[0] == '-');
  }
}

void BigInteger::setInt(std::string s) 
{
  number = s;
}

const std::string& getNumber() 
{ 
  return number;
}

void BigInteger::setSign(bool s) 
{
  sign = s;
}

const bool& BigInteger::getSign() 
{
  return sign;
}

void absolute() 
{
  return BigInteger(getNumber());
}

void BigInteger::operator = (BigInteger b) 
{
  setInt(b.getNumber());
  setSign(b.getSign());
}

bool BigInteger::operator == (BigInteger b) 
{
  return equals((*this) , b);
}

bool BigInteger::operator != (BigInteger b) 
{
  return !equals((*this) , b);
}

bool BigInteger::operator > (BigInteger b) 
{
  return greater((*this) , b);
}

bool BigInteger::operator < (BigInteger b) 
{
  return less((*this) , b);
}

bool BigInteger::operator >= (BigInteger b) 
{
  return equals((*this) , b) || greater((*this), b);
}

bool BigInteger::operator <= (BigInteger b) 
{
  return equals((*this) , b) || less((*this) , b);
}

BigInteger BigInteger::operator + (BigInteger b) 
{
  BigInteger addition;
  if(getSign() == b.getSign()) 
  {
    addition.setInt(add(getNumber(), b.getNumber()));
    addition.setSign(getSign());
  } else {
  if(absolute() > b.absolute()) {
    addition.setInt(subtract(getNumber(), b.getNumber()));
    addition.setSign(getSign());
  } else {
    addition.setInt(subtract(b.getNumber(), getNumber()));
    addition.setSign(b.getSign());
  }
  }
  if(addition.getNumber() == "0")
    addition.setSign(false);
  return addition;
}

BigInteger BigInteger::operator - (BigInteger b) 
{
  b.setSign(!b.getSign());
  return (*this) + b;
}

BigInteger BigInteger::operator * (BigInteger b) 
{
  BigInteger product;
  product.setInt( multiply(getNumber(), b.getNumber() ) );
  product.setSign( getSign() != b.getSign() );
  if(product.getNumber() == "0")
    product.setSign(false);
    (*this) = product;
  return product;
}

BigInteger& BigInteger::operator += (BigInteger b) 
{
  (*this) = (*this) + b;
  return (*this);
}

BigInteger& BigInteger::operator -= (BigInteger b) 
{
  (*this) = (*this) - b;
  return (*this);
}

BigInteger& BigInteger::operator *= (BigInteger b) 
{
  (*this) = (*this) * b;
  return (*this);
}

BigInteger BigInteger::operator -() 
{
  return (*this) * -1;
}

BigInteger::operator std::string() 
{
  std::string signedString = ( getSign() ) ? "-" : "";
    signedString += number;
  return signedString;
}

bool BigInteger::equals(BigInteger n1, BigInteger n2) 
{
  return n1.getNumber() == n2.getNumber() && n1.getSign() == n2.getSign();
}

bool BigInteger::less(BigInteger n1, BigInteger n2) 
{
  bool sign1 = n1.getSign();
  bool sign2 = n2.getSign();
  if(sign1 && ! sign2)
    return true;
  else if(! sign1 && sign2)
    return false;
  else if(! sign1) 
  {
    if(n1.getNumber().length() < n2.getNumber().length() )
      return true;
    if(n1.getNumber().length() > n2.getNumber().length() )
      return false;
    return n1.getNumber() < n2.getNumber();
  } else {
    if(n1.getNumber().length() > n2.getNumber().length())
      return true;
    if(n1.getNumber().length() < n2.getNumber().length())
      return false;
    return n1.getNumber().compare( n2.getNumber() ) > 0;
  }
}

bool BigInteger::greater(BigInteger n1, BigInteger n2) 
{
  return !equals(n1, n2) && !less(n1, n2);
}

std::string BigInteger::add(std::string number1, std::string number2) 
{
  std::string add = (number1.length() > number2.length()) ? number1 : number2;
  char carry = '0';
  int differenceInLength = abs( (int) (number1.size() - number2.size()) );
  if(number1.size() > number2.size())
    number2.insert(0, differenceInLength, '0');
  else
    number1.insert(0, differenceInLength, '0');
  for(int i=number1.size()-1; i>=0; --i) 
  {
    add[i] = ((carry-'0')+(number1[i]-'0')+(number2[i]-'0')) + '0';
    if(i != 0) 
    {
      if(add[i] > '9') 
      {
        add[i] -= 10;
        carry = '1';
      } else
        carry = '0';
    }
  }
  if(add[0] > '9') 
  {
    add[0]-= 10;
    add.insert(0,1,'1');
  }
  return add;
}

std::string BigInteger::subtract(std::string number1, std::string number2) 
{
  std::string sub = (number1.length()>number2.length())? number1 : number2;
  int differenceInLength = abs( (int)(number1.size() - number2.size()) );
  if(number1.size() > number2.size())
    number2.insert(0, differenceInLength, '0');
  else
    number1.insert(0, differenceInLength, '0');
  for(int i=number1.length()-1; i>=0; --i) 
  {
    if(number1[i] < number2[i]) 
    {
      number1[i] += 10;
      number1[i-1]--;
    }
    sub[i] = ((number1[i]-'0')-(number2[i]-'0')) + '0';
  }
  while(sub[0]=='0' && sub.length()!=1) // erase leading zeros
    sub.erase(0,1);
  return sub;
}

std::string BigInteger::multiply(std::string n1, std::string n2)
{
  if(n1.length() > n2.length())
    n1.swap(n2);
    std::string res = "0";
  for(int i=n1.length()-1; i>=0; --i) 
  {
    std::string temp = n2;
    int currentDigit = n1[i]-'0';
    int carry = 0;
    for(int j=temp.length()-1; j>=0; --j) 
    {
      temp[j] = ((temp[j]-'0') * currentDigit) + carry;
      if(temp[j] > 9) 
      {
      carry = (temp[j]/10);
      temp[j] -= (carry*10);
      } else
      carry = 0;
      temp[j] += '0';
    }
    if(carry > 0)
    temp.insert(0, 1, (carry + '0'));
    temp.append((n1.length()-i-1), '0');
    res = add(res, temp);
  }
  while(res[0] == '0' && res.length()!=1)
    res.erase(0,1);
  return res;
}

std::ostream& operator<<(std::ostream& os, BigInteger& b)  
{  
  os << std::string(b);  
  return os;  
} 