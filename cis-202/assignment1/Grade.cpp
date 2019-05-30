/*
  File: Grade.cpp
  Description:
    'add_quiz' stores the number of quizzes given.
    'get_total_score' stores the total quiz score.
    'get_average_score' calculates and returns average score.
    'get_grade' stores the average of grades.
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/
#include "Grade.h"
#include <iostream>

// adds a quiz score to the total quiz score of the student
void Grade::add_quiz(int score) {
  total_quiz_score += score;
  number_of_quizzes += 1;
}
// returns the total quiz score of all the quizzes combined of the student
int Grade::get_total_score() {
  return total_quiz_score;
}
// divides all quizzes by number of quizzes
// returns the average score
int Grade::get_average_score() {
  int avg = (total_quiz_score / number_of_quizzes);
  return avg;
}

std::string Grade::get_grade() {
  Grade grade;
  return grade.get_grade(total_quiz_score / number_of_quizzes);
}
