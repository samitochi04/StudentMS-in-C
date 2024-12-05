#include<stdio.h>
#include<ctype.h>

int main(){

    char unit;
    float temp;

    printf("Is the temperature in Celsius (C) or Fahrenheit (F)?  ");
    scanf("%c", &unit);

    unit = toupper(unit);

    if(unit == 'C'){
        printf("Enter the temperature in Celsius:\n");
        scanf("%f", &temp);
        temp = temp * 1.8 + 32;
        printf("The temperature in Fahrenheit is: %.2f\n", temp);
    }
    else if(unit == 'F'){
        printf("Enter the temperature in Fahrenheit:\n");
        scanf("%f", &temp);

        temp = (temp - 32) / 1.8;

        printf("The temperature in Celsius is: %.2f\n", temp);
    }
    else{
        printf("Invalid unit");
    }

    return 0;
}