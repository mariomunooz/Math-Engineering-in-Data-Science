#include <stdio.h>
#include <string.h>


#include "seminar-refstruct-exercises.h"

void ex6() {
    int grade = 3;

//    printf("Give me the initial grade:\n");
//    scanf("%d", &grade);

    printf("\nInitial grade: %d\n", grade);

    int result = increase_grade_value(grade, 2);
    printf("\nNOT updated grade: %d\n", grade);
    printf("\nbut result should be: %d\n", result);

    increase_grade_ref(&grade, 2);
    printf("\nUpdated grade: %d\n", grade);

    int grades[MAX_STUDENTS] = {1, 2, 3};

    printf("\nInitial grades:\n");
    print_grades(grades);

    update_grades(grades, 2);
    printf("\nUpdated grades:\n");
    print_grades(grades);
    printf("\n");
}

void ex7() {
    Student a = {"Neno",
                 "Dimitrijevic",
                 9
    };
    Student b = {"Shawn",
                 "dawson",
                 10};
    Student c = {"Tony",
                 "Wroten",
                 8
                 };
    Student d = {"Joel",
                "Parra",
                7};


Student array[MAX_STUDENTS];
array[0] = a;
array[1] = b;
array[2] = c;
array[3] = d;
    print_students_grades(array);

    update_student_grades(array, 100);
}

int main() {
    
    ex6();
    ex7();

    return 0;
}