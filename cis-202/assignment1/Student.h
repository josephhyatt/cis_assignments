/*
  File: Student.h
  Description:
    'get_name' constructs a student object with a name
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/
#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>

class Student
{
    // variable to store students name
    std::string name;
public:
    // A constructor with a single non-default parameter (until C++11) that is declared without the function specifier explicit is called a converting constructor.
    explicit Student(std::string n);
    std::string get_name();
};
#endif //_STUDENT_H
