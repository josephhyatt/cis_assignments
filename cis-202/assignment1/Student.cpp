/*
  File: Student.cpp
  Description:
    'get_name' stores the Student name.
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/
#include "Student.h"
#include <iostream>

// returns the name of a student
std::string Student::get_name()
{
  return name;
}

Student::Student(std::string n)
{
  name = n;
}