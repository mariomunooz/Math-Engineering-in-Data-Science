//
// Created by rcarlini on 25/11/19.
//

#ifndef EDA1_SEMINARS_SEMINAR_FILES_EXERCISES_H
#define EDA1_SEMINARS_SEMINAR_FILES_EXERCISES_H
#define MAX_LOADING_BUFFER 50
#define MAX_NAME_LENGTH 50
#define MAX_COURSES 10
#define MAX_STUDENTS 80


#define MAX_LINE_LENGTH 100
typedef struct {
    char name[MAX_NAME_LENGTH];
    int nia;
    double grade;
    int course;
} Student;

typedef struct  {
    int course_id;
    Student students[MAX_STUDENTS];
} Courses;


void merge(FILE* fa, FILE* fb, FILE* fc);
int count_primes(FILE* fa);
int write_bars(FILE *fa, FILE *fout);
int print_mean_best_simple(FILE* f);
int print_mean_best_student(FILE* f);
int print_mean_best_course(FILE* f);
int print_mean_courses(FILE* f);
int course_exists(int course, Courses courses[MAX_COURSES]);
void course_element_init(Courses courses[MAX_COURSES]);
int ex17();

#endif //EDA1_SEMINARS_SEMINAR_FILES_EXERCISES_H

