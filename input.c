#include<stdio.h>
#include<string.h>

int main(){

    char name[20];
    int age;

    printf("Enter your name: ");
    // scanf("%s", &name);
    fgets(name, 20, stdin);
    name[strlen(name)-1] = '\0';

    printf("Enter your age: ");
    scanf("%d", &age);

    // if(age >= 18) printf("You are an adult\n");
    if(age >= 18) {
        printf("You are an adult\n");
    }
    else {
        printf("You are not an adult\n");
        printf("You are %d years old\n", age);
    }

    printf("Your name is %s\n", name);


    return 0;
}