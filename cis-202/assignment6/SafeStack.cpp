/*=============================================================================
#  Author:          Joseph Hyatt - https://github.com/josephhyatt/
#  Email:           hyattj@student.vvc.edu
#  FileName:        SafeStack.cpp
#  Description:     Implementation file for SafeStack.h declared functions.
=============================================================================*/
#include "SafeStack.h"

SafeStack::SafeStack(){
}

int SafeStack::size(){
  return s.size();
}
// Throws exception if stack is empty
std::string SafeStack::top(){
  if (s.empty())
    return "Nothing in Stack!";
  else
    return s.top();
}
// Pushes string element in SafeStack
void SafeStack::push(std::string str){
  s.push(str);
}
// Remove element from stack
void SafeStack::pop(){
  if (!s.empty())
    s.pop();
}
// Checks whether stack is empty
bool SafeStack::empty(){
  return s.empty();
}