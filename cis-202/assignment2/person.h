/*
  File: person.h
  Description: setName and setAge are setter methods that assign name and age value data to the person class. getName and getAge are getter methods that retrieve the values of the data from the person class, and because of 'const' the method will not change the value within the class. name and age are private variables and are accessed within the public member function of setName and setAge.
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/

#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

class Person
{
public:
    void setName(const std::string& name);
    std::string getName() const;

    void setAge(int age);
    int getAge() const;


private:
    std::string name;
    int age;
};

#endif
