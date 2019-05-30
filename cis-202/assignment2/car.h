/*
  File: car.h
  Description: setModel, setOwner, setDriver are setter methods and are assigned model, owner, and driver data to the car class. model, owner* and driver* are private variables (owner and driver are pointers which point to a specific address) and are accessed within the public member method. getModel, getOwner, and getDriver are getter methods that retrieve the values of the data from the car class, and because of 'const' the method will not change any value within the class.
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/

#ifndef __CAR_H__
#define __CAR_H__

#include <string>

class Person;

class Car
{
public:
    void setModel(const std::string& model);
    std::string getModel() const;

    void setOwner(Person *owner);
    Person* getOwner() const;

    void setDriver(Person *driver);
    Person* getDriver() const;

private:
    std::string model;
    Person *owner;
    Person *driver;
};

#endif
