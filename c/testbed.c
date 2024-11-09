#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./my_c_lib/my_c_lib_header.h"

#define DAYS_IN_YEAR 365
#define DAYS_IN_WEEK 7

enum days {SUN, MON, TUE, WED, THU, FRI, SAT};

int main(void) {

    
    // char
    printf("%lu\n", sizeof(char));
    char x_char = 9;
    char y_char = 'y';
    printf("%lu\n", sizeof(char));
    // note: 9 doesn't print an ascii char, why?
    printf("char: %d size: %lu\n", x_char, sizeof(x_char));
    printf("char: %c size: %lu\n", y_char, sizeof(y_char));

    // ints and shorts and longs
    int x_int = 0;
    printf("%lu\n", sizeof(x_int));
    printf("%lu\n", sizeof(int));
    short x_short = 0;
    printf("%ld\n", sizeof(x_short));
    long x_long = 0;
    printf("long: %lu: size: %lu\n", x_long, sizeof(x_long));

    // floats
    float x_float = 0.0f;
    printf("float: %.6f: size: %lu\n", x_float, sizeof(x_float));



}


// // take input from the keyboard
// int main(int argc, char** argv) {
//     // printf("Typed in a number and hit enter: ");
//     // int input;
//     // scanf("%d", &input);
//     // printf("%d\n", input);
// }

