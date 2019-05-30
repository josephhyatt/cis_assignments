/*
  File: main.cpp
  Description: running a loop that prompts the user to specify a car model, owners name, and age, and the drivers name and age.  The input gets stored in a Person and Car vector. The user then gets the option of adding more cars/owners/drivers, and when/if the user is done entering input the Person/Car objects get transversed which increases their ages by one year and gets printed to the console.
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/

#include "person.h"
#include "car.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
    Person *car_owner;
    Person *driver;
    std::vector<Person *> person_vector;
    std::vector<Person *>::iterator person_iterator;

    Car *car;
    std::vector<Car *> car_vector;
    std::vector<Car *>::iterator car_iterator;
    char input;
    std::string str;

    do
    {

        car = new Car();
        car_owner = new Person();
        driver = new Person();

        // ask for car information
        std::cout << "Car Model: "; std::cin >> str;
        car->setModel(str);

        // ask for owner information
        std::cout << "Owner's Name: "; std::cin >> str;
        car_owner->setName(str);
        std::cout << "Owner's Age: "; std::cin >> str;
        car_owner->setAge(stoi(str));

        person_vector.push_back(car_owner);
        car->setOwner(car_owner);

        // ask for driver information
        std::cout << "Drivers Name: "; std::cin >> str;
        driver->setName(str);
        std::cout << "Drivers Age: "; std::cin >> str;
        driver->setAge(stoi(str));

        person_vector.push_back(driver);
        car->setDriver(driver);
        car_vector.push_back(car);

        std::cout << "-------------------------------------" << std::endl;
        std::cout << "|   Want to input another driver?   |" << std::endl;
        std::cout << "|  Type 'y' for yes and 'n' for no  |" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cin >> input;

    } while (input == 'y');

    // change person ages
    person_iterator = person_vector.begin();
    while (person_iterator != person_vector.end())
    {
        (*person_iterator)->setAge((*person_iterator)->getAge()+1);
        person_iterator++;
    }

    // print car information
    car_iterator = car_vector.begin();
    while (car_iterator != car_vector.end())
    {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Car Model: " << (*car_iterator)->getModel() << std::endl;
        std::cout << "Owner's Name: " << ((*car_iterator)->getOwner())->getName() << "\nOwner's Age: " << ((*car_iterator)->getOwner())->getAge() << std::endl;
        std::cout << "Driver's Name: " << ((*car_iterator)->getDriver())->getName() << "\nDriver's Age: " << ((*car_iterator)->getDriver())->getAge() << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        car_iterator++;
    }

    // delete cars
    car_iterator = car_vector.begin();
    while (car_iterator != car_vector.end())
    {
        delete *car_iterator;
        car_iterator++;
    }

    // delete persons
    person_iterator = person_vector.begin();
    while (person_iterator != person_vector.end())
    {
        delete *person_iterator;
        person_iterator++;
    }

    return 0;
}
