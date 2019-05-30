/*=============================================================================
#  Author:          Joseph Hyatt - https://github.com/josephhyatt/
#  Email:           hyattj@student.vvc.edu
#  FileName:        SafeStack.h
#  Description:     Header file declaring functions being used. SafeStack class gives the
                    implementation of stack with exception when abnormal condition occurs.
=============================================================================*/
#ifndef __SAFESTACK_H
#define __SAFESTACK_H

#include <string>
#include <stack>
#include <iostream>

class SafeStack
{
public:
  SafeStack();
  int size();
  std::string top();
  void push(std::string str);
  void pop();
  bool empty();

private:
  std::stack<std::string> s;
};

#endif // __SAFESTACK_H