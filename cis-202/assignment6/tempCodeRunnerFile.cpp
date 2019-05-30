/*=============================================================================
#  Author:          Joseph Hyatt - https://github.com/josephhyatt/
#  Email:           hyattj@student.vvc.edu
#  FileName:        main.cpp
#  Description:     One argument used to justify the fact that the stack data structure in
                    the standard library does not throw exceptions is that it is easy to add these facilities.
                    Create a class SafeStack that implements a stack of strings. Use an instance of stack<string>
                    to hold the underlying values, and implement the same interface as that data type. However,
                    your class should throw an exception if an attempt is made to remove a value from an empty stack.
=============================================================================*/
#include "SafeStack.cpp"

int main()
{
  SafeStack s;
  // code display menus of operation to be performed on stack
  std::cout << "\nElements in stack: " << s.size() << std::endl;
  std::cout << "Top element in stack: " << s.top() << std::endl;

  s.push("Jeff");
  s.push("Lebowski");
  s.push("The Dude");

  std::cout << "\nElements in stack: " << s.size() << std::endl;
  std::cout << "Top element in the stack: " << s.top() << std::endl;

  std::cout << "\nElements in stack: " << s.size() << std::endl;
  std::cout << "Removing one element from the stack." << std::endl;
  s.pop();
  std::cout << "Top element in the stack: " << s.top() << std::endl;

  std::cout << "\nElements in stack: " << s.size() << std::endl;
  std::cout << "Removing another element from the stack." << std::endl;
  s.pop();
  std::cout << "Top element in the stack: " << s.top() << std::endl;

  std::cout << "\nElements in stack: " << s.size() << std::endl;
  std::cout << "Removing another element from the stack." << std::endl;
  s.pop();
  std::cout << "Top element in the stack: " << s.top() << std::endl;
  return 0;
}