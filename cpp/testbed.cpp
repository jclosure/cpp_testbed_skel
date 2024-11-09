#include <iostream>
#include <string>

#define DAYS_IN_YEAR 365
#define DAYS_IN_WEEK 7


void print(char const* myString)
{
    printf("String %s\n", myString);
}

void print(int myInt)
{
    printf("My int is %d\n", myInt);
}

int main() {   
//     const char* msg = "testbed";
//     print(msg); // Resolves to void print(const char*)
//     print(15); // Resolves to void print(int)

    auto weeks_in_year = DAYS_IN_YEAR / DAYS_IN_WEEK;

    std::cout << weeks_in_year << std::endl;


}
