#include <stdio.h>
#include <string.h>
#include "seminar-refstruct-exercises.h"

// Exercise 6.1
/**
 * Pre: The grade is an integer between 0 and 10
 * Post: The function returns the grade plus increase
 */
int increase_grade_value(int grade, int increase) {
    int result = grade + increase;
    return result;
}

// Exercise 6.2
/**
 * Pre: Grade_ptr is a memory adress
 * Post: The function change the value of grade outside the scope of the function
 */
void increase_grade_ref(int* grade_ptr, int increase) {
    *grade_ptr += increase;
}

// Exercise 6.3
/**
 * Pre: The array has at least one element
 * Post: The function prints all grades separated by a comma and a space
 */
void print_grades(int grade_array[MAX_STUDENTS]) {
    for (int element = 0; element < MAX_STUDENTS; element ++){
        printf("%d, ", grade_array[element]);
    }
}

// Exercise 6.4
/**
 * Pre: The array has at least one element
 * Post: The function update_student_grades modifies each student grade, adding the increment to the grade and prints the result.
 */
void update_grades(int grade_array[MAX_STUDENTS], int increase) {
    for (int element = 0; element < MAX_STUDENTS; element++){
        grade_array[element] += increase;
    }
}


// Exercise 7.2
/**
 * Pre: The strcture has at least one student and every student has defined their grade
 * Post: The function modifies the grade of student, adding the increase to the grade
 */
void increase_student_grade(Student* student, int increase) {
    student->grade += increase;
}

// Exercise 7.3
/**
 * Pre: The array has at least one element and we have one structure with the same students in the array and we have all the grades for all students
 * Post: The function print the name of the student with their related grade
 */
void print_students_grades(Student students[MAX_STUDENTS]) {
    for (int element = 0; element < MAX_STUDENTS; element++){
            printf("The student %s\n ", students[element].name);
            printf("Has the following grade %d\n ", students[element].grade);
        printf("___________________________________________\n");
        }
}

// Exercise 7.4
/**
 * Pre: Pre: The array has at least one element and we have one structure with the same students in the array and we have all the grades for all students
 * Post:  The function update_student_grades that given an array of MAX_STUDENTS students and an increment, modifies each student grade, adding the increment to the grade and prints the result.
 */
void update_student_grades(Student grade_array[MAX_STUDENTS], int increase) {
    for (int element = 0; element < MAX_STUDENTS; element++){
        printf("Initial grade of student %s is %d\n", grade_array[element].name, grade_array[element].grade);
        grade_array[element].grade = increase_grade_value(grade_array[element].grade, increase);
        printf("The student %s\n ", grade_array[element].name);
        printf("Have this updated grade %d\n ", grade_array[element].grade);
        printf("___________________________________________\n");
            
        }
}

