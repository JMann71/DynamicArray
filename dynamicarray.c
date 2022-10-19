#include <stdio.h>
#include <stdlib.h>

// current maximum capacity of the vector
int max_capacity;
// current size of the vector, meaning how many elements hold actual values
int reserved_size;

/*
    @desc This function creates an array of integers based on the size passed in
    @author Jarod Manness
    @params {size} number of elements to initialize
    @return {vector} a pointer to the created array
*/
int* CreateVector(int size, int *max, int *reserved){
    int *vector;
    vector = (int *)malloc(size * sizeof(int)); // allocates the amount of memory required for the number of initial elements
    *max = size;
    *reserved = size;
    return vector;
}

void main(){
    int *createdVector = CreateVector(3, &max_capacity, &reserved_size);
    getchar();
}