#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./my_c_lib/my_c_lib_header.h"

#define DAYS_IN_YEAR 365
#define DAYS_IN_WEEK 7

enum days
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

void printArray(void *array, size_t length, size_t elemSize, void (*printElem)(void *))
{
    for (size_t i = 0; i < length; ++i)
    {
        // Calculate the address of the i-th element and print it
        void *elemPtr = (char *)array + i * elemSize;
        printElem(elemPtr);
    }
    printf("\n");
}

// Helper functions to print specific types
void printInt(void *elem)
{
    printf("%d ", *(int *)elem);
}

void printDouble(void *elem)
{
    printf("%.2f ", *(double *)elem);
}

void printChar(void *elem)
{
    printf("%c ", *(char *)elem);
}

int main(int argc, char **argv)
{

    // printf: https://cplusplus.com/reference/cstdio/printf/

    // char
    printf("char type size: %lu\n", sizeof(char));
    char x_char = 9;
    char y_char = 'y';
    // note: 9 doesn't print an ascii char, why?
    printf("char: %d size: %zu\n", x_char, sizeof(x_char));
    printf("char: %c size: %zu\n", y_char, sizeof(y_char));

    // ints and shorts and longs
    printf("int type size: %zu\n", sizeof(int));
    int x_int = 0;
    printf("int: %d: size: %zu\n", x_int, sizeof(x_int));

    short x_short = 0;
    printf("short: %d: size: %zu\n", x_short, sizeof(x_short));
    unsigned short ux_short = 0;
    printf("unsigned short: %.d: size: %zu\n", ux_short, sizeof(ux_short));

    long x_long = 0;
    printf("long: %lu: size: %zu\n", x_long, sizeof(x_long));
    unsigned long ux_long = 0;
    printf("unsigned long: %lu: size: %zu\n", ux_long, sizeof(ux_long));

    // floating point types
    float x_float = 0.0f;
    printf("float: %.6f: size: %zu\n", x_float, sizeof(x_float));
    double x_double = 0.0;
    printf("double: %.6f: size: %zu\n", x_double, sizeof(x_double));

    // size type
    int a = 1;
    size_t size = sizeof(a++);
    printf("size of int: %zu: size: %zu\n", size, sizeof(size));

    // arrays
    char my_char_array[20]; // 1 * 20 = 20 bytes
    int my_int_array[20];   // 4 * 20  = 80 bytes

    // init array to all 0
    // int my_array[20] = {0}; // {0} is the initializer: [0,0,0,0,0]
    int my_array[5] = {1, 2}; // [1,2,0,0,0]

    // compute the size of an array
    // always compute size before passing to a fn because gets converted to a ptr
    size_t my_array_size = sizeof(my_array) / sizeof(my_array[0]);
    printf("dynamic array length: %zu\n", my_array_size);
    printf("sizeof array = %zu\n", sizeof my_array);

    // printf("Enter the array size: ");
    // int array_size;
    // fscanf(stdin, "%d", &array_size);
    // int var_length_array[array_size];
    // printf("sizeof array = %zu\n", sizeof var_length_array);

    char a_string[20] = "This is a string"; // c inserts a \0 at the end for us.
    printf("%s\n", a_string);
    printf("%d\n", a_string[15]); // => 103
    printf("%d\n", a_string[16]); // => 0

    // multidimensional arrays
    int multi_array[2][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}};
    // access elements
    int array_int = multi_array[1][2];
    printf("%d\n", array_int);

    // floating point numbers cannot perfectly store exact values
    int ans = (0.1 + 0.1 + 0.1) == 0.3;
    printf("((0.1 + 0.1 + 0.1) == 0.3) => %s\n", ans ? "true" : "false");

    // END BASIC TYPES

    // this notation is scientific notations for numbers: 1e123 = 1*10^123

    // floating point math it is NOT associative due to reasons mentioned above.
    1 + (1e123 - 1e123) != (1 + 1e123) - 1e123; // => 1 (true)
    // therefore: when doing floating point comparisons, a little bit of error (epsilon)
    // needs to be considered.

    // Comparison operators are probably familiar, but
    // there is no Boolean type in C. We use ints instead.
    // (C99 introduced the _Bool type provided in stdbool.h)
    // 0 is false, anything else is true. (The comparison
    // operators always yield 0 or 1.)
    3 == 2; // => 0 (false)
    3 != 2; // => 1 (true)
    3 > 2;  // => 1
    3 < 2;  // => 0
    2 <= 2; // => 1
    2 >= 2; // => 1

    // bitwise operators

    // each shift left is like multiplying by 2
    int bs = 0x01 << 1; // => 2
    printf("%d\n", bs);

    // each shift right is like dividing by 2
    bs = 0x02 >> 1; // => 1
    printf("%d\n", bs);

    ///////////////////////////////////////
    // Control Structures
    ///////////////////////////////////////

    if (0)
    {
        printf("I am never run\n");
    }
    else if (0)
    {
        printf("I am also never run\n");
    }
    else
    {
        printf("I print\n");
    }

    ///////////////////////////////////////
    // Pointers
    ///////////////////////////////////////

    // A pointer is a variable declared to store a memory address. Its declaration will
    // also tell you the type of data it points to. You can retrieve the memory address
    // of your variables, then mess with them.

    int x = 0;
    printf("print the address of a variable, e.g. x is at: %p\n", (void *)&x);
    // Use & to retrieve the address of a variable
    // (%p formats an object pointer of type void *)
    // => Prints some address in memory;

    // Pointers start with * in their declaration
    int *px, not_a_pointer;     // px is a pointer to an int
    px = &x;                    // Stores the address of x in px
    printf("%p\n", (void *)px); // => Prints some address in memory
    printf("%zu, %zu\n", sizeof(px), sizeof(not_a_pointer));
    // => Prints "8, 4" on a typical 64-bit system

    // To retrieve the value at the address a pointer is pointing to,
    // put * in front to dereference it.
    // Note: yes, it may be confusing that '*' is used for _both_ declaring a
    // pointer and dereferencing it.
    printf("%d\n", *px); // => Prints 0, the value of x

    // You can also change the value the pointer is pointing to.
    // We'll have to wrap the dereference in parenthesis because
    // ++ has a higher precedence than *.
    (*px)++;             // Increment the value px is pointing to by 1
    printf("%d\n", *px); // => Prints 1
    printf("%d\n", x);   // => Prints 1

    // Arrays are a good way to allocate a contiguous block of memory
    int x_array[20]; // declares array of size 20 (cannot change size)
    int xx;
    for (xx = 0; xx < 20; xx++)
    {
        x_array[xx] = 20 - xx;
    } // Initialize x_array to 20, 19, 18,... 2, 1

    // print the array out with our helper
    printArray(x_array, 20, sizeof(int), printInt);

    // arrays are pointers that point by default to their first element
    // Declare a pointer of type int and initialize it to point to x_array
    int *x_ptr = x_array;
    printf("the first element of x_array: %d \n", *x_ptr);
    printf("the first element of x_array: %d \n", (int)*x_array); // peek into any array like this

    // Pointers are incremented and decremented based on their type
    // (this is called pointer arithmetic)
    printf("%d\n", *(x_ptr + 1)); // => Prints 19
    printf("%d\n", x_array[1]);   // => Prints 19

    // You can also dynamically allocate contiguous blocks of memory with the
    // standard library function malloc, which takes one argument of type size_t
    // representing the number of bytes to allocate (usually from the heap, although this
    // may not be true on e.g. embedded systems - the C standard says nothing about it).
    int *my_ptr = malloc(sizeof(*my_ptr) * 20);
    for (xx = 0; xx < 20; xx++)
    {
        *(my_ptr + xx) = 20 - xx; // my_ptr[xx] = 20-xx
    } // Initialize memory to 20, 19, 18, 17... 2, 1 (as ints)

    // Be careful passing user-provided values to malloc! If you want
    // to be safe, you can use calloc instead (which, unlike malloc, also zeros out the memory)
    int *my_other_ptr = calloc(20, sizeof(int));

    // Note that there is no standard way to get the length of a
    // dynamically allocated array in C. Because of this, if your arrays are
    // going to be passed around your program a lot, you need another variable
    // to keep track of the number of elements (size) of an array. See the
    // functions section for more info.
    size = 10;
    int *my_arr = calloc(size, sizeof(int));
    // Add an element to the array
    size++;
    my_arr = realloc(my_arr, sizeof(int) * size);
    if (my_arr == NULL)
    {
        // Remember to check for realloc failure!
        printf("failed to realloc \n");
        return 1;
    }
    my_arr[10] = 5;

    // Dereferencing memory that you haven't allocated gives
    // "unpredictable results" - the program is said to invoke "undefined behavior"
    printf("%d\n", *(my_ptr + 21)); // => Prints who-knows-what? It may even crash.

    // When you're done with a malloc'd block of memory, you need to free it,
    // or else no one else can use it until your program terminates
    // (this is called a "memory leak"):
    free(my_ptr);
    free(my_arr);

    // This is not the case if the string is an array
    // (potentially initialized with a string literal)
    // that resides in writable memory, as in:
    char foo[] = "foo";
    foo[0] = 'a'; // this is legal, foo now contains "aoo"

    ///////////////////////////////////////
    // User-defined types and structs
    ///////////////////////////////////////

    // Typedefs can be used to create type aliases
    typedef int my_type;
    my_type my_type_var = 0;

    // Structs are just collections of data, the members are allocated sequentially,
    // in the order they are written:
    struct rectangle
    {
        int width;
        int height;
    };
}
