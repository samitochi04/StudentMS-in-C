#include<stdio.h>

void sort(int array[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void print(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
}

int main(){

    int prices[]= {1, 2, 5, 55};
    int size = sizeof(prices)/sizeof(prices[0]);

    sort(prices, size);
    print(prices, size);



    for(int i = 0; i < 4; i++){
        printf("$%.2lf\n", prices[i]);
    }
    
    int numbers[4][4] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int rows = sizeof(numbers)/sizeof(numbers[0]);
    int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d", numbers[i][j]);
        }
        printf("\n");
    }


    return 0;
}