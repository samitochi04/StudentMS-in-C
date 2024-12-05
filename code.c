#include<stdio.h>
#include<stdbool.h>

int main(){

    // Fellow Bro
    /*SUper Bro */
    int x = 25;
    int y = x/5;
    float z = x/5.0;
    double w = z*2.0;
    char grade = 'A';
    char name[] = "Fellow Bro"; // array of charracters
    bool isMale = true;

    char f = 47;
    unsigned char g = 47;

    printf("%c\n\n", f);

    printf("You are %d years old\n", y);
    printf("This is a float %f\n", z);
    printf("Your grade is %c\n", grade);
    printf("Hello, %s\n", name);
    printf("Your weight is %lf\n", w);

    return 0;
}