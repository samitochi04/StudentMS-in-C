#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// funcion prototype
void birthday(char name[]);
void findMax(int x, int y);

int main(){
    
    birthday("Fellow Bro");

    findMax(3, 4);
    
    return 0;
}

void birthday(char name[]){
    printf("Happy Cake Day, %s!\n", name);
}

void findMax(int x, int y){
    
    int num =  (x > y) ? x : y;
    printf("%d", num);
}