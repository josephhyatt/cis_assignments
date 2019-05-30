/*
   File: main.cpp
   Description: 
   Author: Joseph Hyatt
   Email: hyattj@student.vvc.edu
*/
#include "animal.h"
#include "insect.h"
#include "mammal.h"
#include "reptile.h"

#include <iostream>
#include <vector>

int main()
{
  std::vector<Animal *> zoo;
  // adds new element to zoo vector increasing the container size. dynamic_cast converts pointers and references to classes along the inheritance hierarchy.
  zoo.push_back(dynamic_cast<Animal *>(new Mammal()));
  zoo.push_back(dynamic_cast<Animal *>(new Insect()));
  zoo.push_back(dynamic_cast<Animal *>(new Reptile()));

  //iterate and eat
  for (Animal *animal : zoo)
  {
    animal->eat();
  }

  //deallocate dynamically allocated objects
  for (Animal *animal : zoo)
  {
    delete animal;
  }
  return 0;
}