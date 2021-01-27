
#ifndef EDA1_SEMINARS_SEMINAR_REFSTRUCT_EXERCISES_H
#define EDA1_SEMINARS_SEMINAR_REFSTRUCT_EXERCISES_H

#define MAX_NAME_LENGTH 20

// Exercise 6
#define MAX_STUDENTS 4

int increase_grade_value(int grade, int increment);
void increase_grade_ref(int* grade_ptr, int increment);

void update_grades(int grade_array[MAX_STUDENTS], int increment);
void print_grades(int grade_array[MAX_STUDENTS]);

// Exercise 7
typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int grade;
} Student;


void increase_student_grade(Student* grade_ptr, int increment);
void print_students_grades(Student students[MAX_STUDENTS]);
void update_student_grades(Student grade_array[MAX_STUDENTS], int increment);

#endif //EDA1_SEMINARS_SEMINAR_REFSTRUCT_EXERCISES_H
