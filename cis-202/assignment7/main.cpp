/*=============================================================================
#  Author:          Joseph Hyatt - https://github.com/josephhyatt/
#  Email:           hyattj@student.vvc.edu
#  FileName:        main.cpp
#  Description:     Write a telephone lookup program. Read a data set of 1,000 names
                    and telephone numbers from a file that contains the numbers in random order.
                    Handle lookups by name and also reverse lookups by phone number.
                    Use a binary search for both lookups.Use the following class with
                    the split function to aid in splitting a csv string
=============================================================================*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

class Contact
{
private:
  std::string name;
  std::string contact_number;

public:
  void set_name(std::string name) { this->name = name; }
  std::string get_name() { return this->name; }
  void set_contact_number(std::string contact_number) { this->contact_number = contact_number; }
  std::string get_contact_number() { return this->contact_number; }

  Contact(std::string fname, std::string lname, std::string num)
  {
    name = fname + " " + lname;
    contact_number = num;
  }
};

class splitstring : public std::string
{
  std::vector<std::string> flds;

public:
  splitstring(const char *s)
      : std::string(s){};
  std::vector<std::string> &split(char delim, int rep = 0);
};

// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
std::vector<std::string> &splitstring::split(char delim, int rep)
{
  if (!flds.empty())
    flds.clear(); // empty vector if necessary
  std::string work = data();
  std::string buf = "";
  int i = 0;
  while (i < work.length())
  {
    if (work[i] != delim)
      buf += work[i];
    else if (rep == 1)
    {
      flds.push_back(buf);
      buf = "";
    }
    else if (buf.length() > 0)
    {
      flds.push_back(buf);
      buf = "";
    }
    i++;
  }
  if (!buf.empty())
    flds.push_back(buf);
  return flds;
}

bool compareByName(Contact c1, Contact c2)
{
  return c2.get_name() > c1.get_name();
}
bool compareByPhoneNumber(Contact c1, Contact c2)
{
  return c2.get_contact_number() > c1.get_contact_number();
}

int findByName(std::vector<Contact> sortedByName, int l, int r, std::string x)
{

  if (r >= l)
  {
    int mid = l + (r - l) / 2;

    if (sortedByName[mid].get_name() == x)
      return mid;

    if (sortedByName[mid].get_name() > x)
      return findByName(sortedByName, l, mid - 1, x);

    return findByName(sortedByName, mid + 1, r, x);
  }

  return -1;
}

int findByNumber(std::vector<Contact> sortedByNumber, int l, int r, std::string x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;
    if (sortedByNumber[mid].get_contact_number() == x)
      return mid;

    if (sortedByNumber[mid].get_contact_number() > x)
      return findByNumber(sortedByNumber, l, mid - 1, x);

    return findByNumber(sortedByNumber, mid + 1, r, x);
  }

  return -1;
}
int main()
{
  // we define a string
  /*  splitstring s("1,John,Doe,4");
    cout << s << endl;

    // splits and displays the vector of strings
    vector<string> flds = s.split(',');
    for (int i = 0; i < flds.size(); i++)
        cout << i << " => " << flds[i] << endl; */

  std::ifstream infile("MOCK_DATA.csv");
  std::string line;
  int choice;
  std::string key;

  std::vector<Contact> contacts;
  while (getline(infile, line))
  {
    splitstring s(line.c_str());
    //cout << s << endl;

    // splits and displays the vector of strings
    std::vector<std::string> flds = s.split(',');
    Contact contact(flds[1], flds[2], flds[3]);
    contacts.push_back(contact);
  }
  std::vector<Contact> sortedByName;
  sortedByName = contacts;
  sort(sortedByName.begin(), sortedByName.end(), compareByName);
  std::vector<Contact> sortedByNumber;
  sortedByNumber = contacts;
  sort(sortedByNumber.begin(), sortedByNumber.end(), compareByPhoneNumber);

  std::cout << "Welcome to Phonebook Directory!" << std::endl;
  std::cout << "===============================" << std::endl;
  bool done = false;
  while (!done)
  {

    std::cout << "1. Search by Name" << std::endl;
    std::cout << "2. Search by Number" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter Your Choice: ";

    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore();
    switch (choice)
    {
    case 1:
    {
      std::cout << "Enter Full Name (Example: Tim Short): ";
      std::getline(std::cin, key);
      int loc = findByName(sortedByName, 0, sortedByName.size() - 1, key);
      if (loc == -1)
      {
        std::cout << "Not found! Please Try Again!" << std::endl;
      }
      else
      {
        std::cout << "Contact Details: " << std::endl;
        std::cout << sortedByName[loc].get_name() << " : " << sortedByName[loc].get_contact_number() << std::endl;
      }
      break;
    }
    case 2:
    {
      std::cout << "Enter Contact Number (Example: 409-578-0807):  ";
      std::getline(std::cin, key);
      int loc = findByNumber(sortedByNumber, 0, sortedByNumber.size() - 1, key);
      if (loc == -1)
      {
        std::cout << "Not found! Please Try Again!" << std::endl;
      }
      else
      {
        std::cout << "Contact Details: " << std::endl;
        std::cout << sortedByNumber[loc].get_name() << " : " << sortedByNumber[loc].get_contact_number() << std::endl;
      }
      break;
    }
    case 3:
    {
      done = true;
      break;
    }
    default:
      std::cout << "Invalid Choice! Please Try Again!" << std::endl;
    }
  }
}