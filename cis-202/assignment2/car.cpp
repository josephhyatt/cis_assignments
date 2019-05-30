/*
  File: car.cpp
  Description: defining the functions that get called by the car.h file.
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/

#include "car.h"

// 'this' pointer retrieves the car object's model
void Car::setModel(const std::string& model)
{
    this->model = model;
}
// returning model
std::string Car::getModel() const
{
    return model;
}
// 'this' pointer retrieves the car object's owner
void Car::setOwner(Person *owner)
{
    this->owner = owner;
}
// returning owner
Person* Car::getOwner() const
{
    return owner;
}
// 'this' pointer retrieves the car object's driver
void Car::setDriver(Person *driver)
{
    this->driver = driver;
}
// returning driver
Person* Car::getDriver() const
{
    return driver;
}
