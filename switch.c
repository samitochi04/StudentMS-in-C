#include <stdio.h>


// 1:10:28 C Programming Full Course for free - Bro Code
int main() {
    char grade;
    
    printf("Enter your grade (A, B, C, D, or F): ");
    scanf(" %c", &grade);
    
    // Convert lowercase input to uppercase for consistency
    if (grade >= 'a' && grade <= 'f') {
        grade = grade - 32;  // Convert to uppercase
    }
    
    switch(grade) {
        case 'A':
            printf("Excellent! Outstanding performance!\n");
            break;
        case 'B':
            printf("Very good! Above average performance.\n");
            break;
        case 'C':
            printf("Satisfactory. Average performance.\n");
            break;
        case 'D':
            printf("Pass, but needs improvement.\n");
            break;
        case 'F':
            printf("Failed. Significant improvement needed.\n");
            break;
        default:
            printf("Invalid grade entered! Please enter A, B, C, D, or F.\n");
    }
    
    return 0;
}