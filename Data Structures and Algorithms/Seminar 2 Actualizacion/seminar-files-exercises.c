#include <stdio.h>
#include <string.h>

#include "common.h"
#include "seminar-files-exercises.h"

// Exercise 1
void merge(FILE* fa, FILE* fb, FILE* fc) {

}

// Exercise 2

int is_prime(int n) {
    return FALSE;
}

int count_primes(FILE* fa) {
    return 0;
}

// Exercise 3

void print_bar(int size, FILE *f){
    int element;
    for (element=0; element < size; element++){
        printf("*");
        fprintf(f, "*");

    }
    printf("\n");
    fprintf(f, "\n");
}

int write_bars(FILE *fa, FILE *fout) {
    int number;
    while (!feof(fa)) {
        fscanf(fa, "%d", &number);
        print_bar(number, fout);
    }
    return SUCCESS;
}
// Exercise 4a

    int print_mean_best_simple(FILE *f) {
        char top_name[MAX_NAME_LENGTH] = "";
        int top_nia = 0;
        double top_grade = 0;
        double acum = 0;
        int code_error = SUCCESS;
        char buffer[MAX_LOADING_BUFFER];
        int idx = 0;
        double grade = -5;
        char name[MAX_NAME_LENGTH] = "";
        int nia = -5;
        while (!feof(f) && code_error == SUCCESS) {
            fgets(buffer, MAX_LOADING_BUFFER, f);
            int count = sscanf(buffer, "%s %d %lf", name, &nia, &grade);
            if (count == EXPECTED_MATCHES_EX_4A) {
                if (grade > top_grade) {
                    strcpy(top_name, name);
                    top_grade = grade;
                    top_nia = nia;
                }
                acum = acum + grade;
                idx++;
            } else
                code_error = ERROR;
        }
            if (code_error == SUCCESS) {
                if (idx > 0) {
                    double mean = acum / idx;
                    printf("The average grade is: %.2lf\n", mean);
                    printf("The best student is %s, with nia %d and grade %.2lf\n", top_name, top_nia, grade);
                }
            } return code_error;

    }

// Exercise 4b

    int print_mean_best_student(FILE *f) {
    return ERROR;
}



// Exercise 4c

    int print_mean_best_course(FILE *f) {
        return ERROR;
    }

// Exercise 5
void course_element_init(Courses courses_array[MAX_COURSES]){
    int element;
    for (element = 0; element < MAX_COURSES; element++){
        courses_array[element].course_id = -5;
    }
}
int print_mean_courses(FILE *f) {
    char name[MAX_NAME_LENGTH]= "";
    int code_error = SUCCESS;
    int nia = -5;
    double grade = -5;
    int course = -5;
    double total_grade = 0;
    char buffer[MAX_LOADING_BUFFER];
    Student students[MAX_STUDENTS];
    Courses courses_array[MAX_COURSES];
    int total_counter = 0;
    int course_idx = 0;
    int i;
    int j;
    int students_course[MAX_COURSES];
    course_element_init(courses_array);
        while (!feof(f)) {
            fgets(buffer, MAX_LOADING_BUFFER, f);
            int count = sscanf(buffer, "%s %d %lf %d", name, &nia, &grade, &course);
            if (count == EXPECTED_MATCHES_EX_5) {
                students[total_counter].course = course;
                strcpy(students[total_counter].name, name);
                students[total_counter].nia = nia;
                students[total_counter].grade = grade;
                total_grade += grade;
                total_counter++;
                if (course_exists(course, courses_array) == FALSE) {
                    courses_array[course_idx].course_id = course;
                    course_idx++;
                }
                i = 0;
                while (course != courses_array[i].course_id) {
                    i++;
                }
                strcpy(courses_array[i].students[students_course[i]].name, name);
                courses_array[i].students[students_course[i]].grade = grade;
                courses_array[i].students[students_course[i]].nia = nia;
                students_course[i]++;
            } else{
                code_error = ERROR;
            }
        }
    double grade_sum = 0, contador_tot = 0;
    for (i = 0; i < course_idx; i++){
        double sum = 0, count = 0;
        for (j = 0; j < students_course[i]; j++){
            sum += courses_array[i].students[j].grade;
            count++;
            contador_tot++;
        }grade_sum += sum;
        printf("The mean grade of the course is '%d' es %.2f\n", courses_array[i].course_id, sum/count);
    }
    printf("The mean grade of all students is %.2f\n", grade_sum/contador_tot);

    return code_error;
        }


int course_exists(int course, Courses courses_array[MAX_COURSES]) {
    int element; int course_exists = FALSE;
    for (element = 0; element < MAX_COURSES; element++) {
        if (courses_array[element].course_id == course) {
            course_exists = TRUE; }
    }
    return course_exists;
}
// Exercise 5

    int cat() {
        return ERROR;

    }
