/*
  File: main.cpp
  Description: Implement a class Student. Supply an appropriate constructor and functions get_name(), add_quiz(int score), get_total_score(), and get_average_score().
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/
#include "Student.h"
#include "Grade.h"
#include <iostream>

int main()
{
  // create student objects
  Student st("Bill Lumbergh");
  // create grade objects
  Grade gd;
  // add quiz score
  gd.add_quiz(44);
  gd.add_quiz(97);
  gd.add_quiz(78);
  gd.add_quiz(66);
  // display student/grade objects
  std::cout << "Hello Professor Tonning, what's happening? Listen, are you gonna have those TPS reports for us this afternoon?" << std::endl;
  std::cout << "Student Name: " << st.get_name() << std::endl;
  std::cout << "Total Score: " << gd.get_total_score() << std::endl;
  std::cout << "Average Score: " << gd.get_average_score() << std::endl;
  std::cout << "Grade: " << gd.get_grade() << std::endl;
  return 0;
}