/*
   File: mammal.h
   Description: 
   Author: Joseph Hyatt
   Email: hyattj@student.vvc.edu
*/
#pragma once
#include "animal.h"
#include <iostream>

//Derived class 2
class Mammal : public Animal
{
public:
  //virtual member is a member function that can be redefined in a derived class, while preserving its calling properties through references.
  virtual void eat();
};

void eat();