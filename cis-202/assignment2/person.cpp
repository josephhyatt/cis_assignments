/*
  File: person.cpp
  Description: defining the functions that get called by the person.h file.
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/

#include "person.h"

// 'this' pointer retrieves the person object's name
void Person::setName(const std::string& name)
{
    this->name = name;
}
// returning name
std::string Person::getName() const
{
    return name;
}
// 'this' pointer retrieves the person object's age
void Person::setAge(int age)
{
    this->age = age;
}
// returning age
int Person::getAge() const
{
    return age;
}
