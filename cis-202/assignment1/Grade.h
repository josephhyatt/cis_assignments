/*
  File: Grade.h
  Description:
    'add_quiz' stores the number of quizzes given.
    'get_total_score' stores the total quiz score.
    'get_average_score' calculates and returns average score.
    'get_grade' stores the average of grades.
  Author: Joseph Hyatt
  Email: hyattj@student.vvc.edu
*/
#ifndef _GRADE_H
#define _GRADE_H

#include <iostream>
#include <string>

class Grade
{
    int total_quiz_score;
    int number_of_quizzes;
  public:
    Grade()
    {
      total_quiz_score = 0;
      number_of_quizzes = 0;
    }
    // constructs a grade % with a letter grade
    std::string get_grade(int grade_percentage)
    {
      if(grade_percentage >= 95)
        return "A+";
      if(grade_percentage >= 90)
        return "A";
      if(grade_percentage >= 85)
        return "B+";
      if(grade_percentage >= 80)
        return "B";
      if(grade_percentage >= 75)
        return "C+";
      if(grade_percentage >= 70)
        return "C";
      if(grade_percentage >= 65)
        return "D+";
      if(grade_percentage >= 60)
        return "D";
      return "F";
    }
    // adds a quiz score to the total quiz score of the student
    void add_quiz(int score);
    // returns the total quiz score of all the quizzes combined of the student
    int get_total_score();
    // divides all quizzes by number of quizzes
    // returns the average score
    int get_average_score();
    std::string get_grade();
};

#endif //_GRADE_H
