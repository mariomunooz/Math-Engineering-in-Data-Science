#include <stdio.h>
#include "common.h"
#include "seminar-files-exercises.h"

int ex1() {

    printf("Executing exercise %d...\n", 1);

    int status = SUCCESS;

    // Do the exercise here

    return status;
}

int ex2() {

    printf("Executing exercise %d...\n", 2);

    int status = SUCCESS;

    // Do the exercise here

    return status;
}

int ex3() {
    printf("Executing exercise %d...\n", 3);
    int code_error = SUCCESS;
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("diagram.txt", "w");

    if (input == NULL || output == NULL) {
        code_error = ERROR;
        return code_error;
    }

    write_bars(input, output);

    int file_a, file_b;
    file_a = fclose(input);
    file_b = fclose(output);
    if (file_a == -1 || file_b == -1) {
        code_error = ERROR;
        return code_error;
    }
}



int ex4a() {

    printf("Executing exercise %s...\n", "4a");
    int code_error = SUCCESS;
    FILE *students = fopen("students.txt", "r");
    if (students == NULL) {
        code_error = ERROR;
        return code_error;
    }
    print_mean_best_simple(students);

    // Do the exercise here

    return code_error;
}

int ex4b() {
    printf("Executing exercise %s...\n", "4b");

    int status = SUCCESS;

    // Do the exercise here

    return status;
}

int ex4c() {

    printf("Executing exercise %s...\n", "4c");

    int status = SUCCESS;

    // Do the exercise here

    return status;
}


int ex5() {
    printf("Executing exercise %s...\n", "5");

    int code_error = SUCCESS;

    FILE *fp = fopen("courses.txt", "r");
    if (fp == NULL){
        code_error = ERROR;
    }

    print_mean_courses(fp);
    int a;
    a = fclose(fp);
    if (a == ERROR){
        code_error = ERROR;
    }
    return code_error;
}

int main() {

    ex1();
    ex2();
    ex3();
    ex4a();
    ex4b();
    ex4c();
    ex5();

    return 0;
}