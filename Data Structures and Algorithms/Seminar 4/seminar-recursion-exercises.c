#include <stdio.h>
#include <math.h>
#include "seminar-recursion-exercises.h"

// Exercise 11
int vector_sum_subs_rec(int* v1, int* v2, int idx, int size) {
    if (idx >= MAX_NUMBERS){
        return size;
    }else{
        int mod = idx % 2;
        int sign = 1;
        if( mod != 0 ){
            sign = -1;
        }
        size = size + (sign * (v1[idx] + v2[idx]));
        return vector_sum_subs_rec(v1, v2, idx +1, size);
    }
}

int vector_sum_subs_iter(int* v1, int* v2, int size) {
    return FALSE;
}

int vector_sum_subs(int* v1, int* v2, int size) {
    return vector_sum_subs_rec(v1, v2, 0, 0);
}

// Exercise 12
/**int sum_digits(int number, int acum) {
   int div = number / 10;
   int digit = number % 10;
   acum = acum + digit;
   if (div == 0) {
       return acum;
   } else {
       return sum_digits(div, acum);
       /** while (div != 0){
        * mod = n% 10
        * acum += mod
        * div = div % 10}


    }
}*/

// Exercise 13
int reverse_digits_simple(int number, int acum) {
    int div =  number % 10;
    int mod = number % 10;
    if (div == 0){
        return mod +(10* acum);
    } else{
        return reverse_digits_simple(div, mod + (10*acum));

    }

    return FALSE;
}

int reverse_digits_hard(int number) {
    return FALSE;
}

int reverse_digits(int number) {
    return reverse_digits_simple(number, 0);
}

// Exercise 14
int norm_rec_rec(int* vector, int size, int acum) {
    return FALSE;
}

int norm(int* vector, int size) {
    return FALSE;
}

// Exercise 15
int mystery (int n, int result) {
    if (n<=0) {
        return result;
    } else {
        return mystery(n-1, result + n*n);
    }
    /**estàs fent el sumatori
     * while i<n
     * resultat = resultat + n * n
         */
}
/** un número és quadrat perfecte si és pot expressar com un altre número al quadrat
 * aquí hem de retornar 0 si no és perfect square i el número que genera el perfect square
 * Tenim dos casos base
 * -si
         */
// Exercise 16
int is_perfect_square_rec(int number, int step) {
    if ((step * step) == number){
        return step;
    }else {
        if((step * step) > number){
            return 0;
        }else{
            return is_perfect_square_rec(number, step +1);
        }
    }

    return FALSE;
}

int is_perfect_square(int number) {
    is_perfect_square_rec(number, 0);

}
/** cas base 1 Me he pasado return 1
     * sino
     * Mirar si step és divisor de n
     *      si lo es
     *      sino
     *          recursivo
         */
// Exercise 17
/**
 *
 * Pre: This function needs. Two inputs, first and step, both positive numbers.
 * Post: This function checks if one number is free of squares
 */
int free_of_squares_rec(int number, int step) {
    int flag_divisor;
    int divisor;
    if((step*step) > number){
        return TRUE;
    }else{
        if (number % step == 0){
            divisor = step;
            flag_divisor = is_perfect_square(divisor);
            if ( flag_divisor != 0){
                return FALSE;
            } else{
                return free_of_squares_rec(number, step+1);

            }
        } else{
            return free_of_squares_rec(number, step+1);
        }
    }


}
/**
 * Pre: This function needs one positive number
 * Post: This function checks if one number is free of squares
 */
int free_of_squares(int number) {
    return free_of_squares_rec(number, 2);
}

// Exercise 18
int reverse_and_sum_rec(int number, int depth) {
    return FALSE;
}

int reverse_and_sum(int number) {
    return FALSE;
}

// Exercise 19
/**
 * Pre: This function needs four inputs, one array of integers and three integers, left, right and number.
 * Post: This function does a recursive search by dividing a vector sorted in ascending order
in smaller splits until the number is found (or not).
 */
int binary_search_rec(int* A, int left, int right, int number) {
    int mid;
    if(right >= left){
        mid = (left + right) / 2;
        if (A[mid] == number){
            return TRUE;
        } else if ( number > A[mid]){
            return binary_search_rec(A, mid +1 , right, number);
        } else {
            return binary_search_rec(A, left, mid -1, number);
        }
        } else return FALSE;

}

int binary_search(int* vector, int size, int number) {
    return binary_search_rec(vector, 0,  size -1, number);

}
