/*
   File: animal.h
   Description: 
   Author: Joseph Hyatt
   Email: hyattj@student.vvc.edu
*/
#pragma once
#include <iostream>

// Base classes
class Animal
{
public:
  //virtual member is a member function that can be redefined in a derived class, while preserving its calling properties through references.
  virtual void eat();
};

void eat();