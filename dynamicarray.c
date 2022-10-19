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
    @params {max} member variable holding the max capacity of the array
    @params {reserved} member variable holding the number of used elements
    @return {vector} a pointer to the created array
*/
int* CreateVector(int size, int *max, int *reserved){
    int *vector;
    vector = (int *)malloc(size * sizeof(int)); // allocates the amount of memory required for the number of initial elements
    *max = size;
    *reserved = size;
    return vector;
}

/*
    @desc This function creates a new array of a given size, copies data from an input array into it, then reassigns the pointer to the new array
    @author Jarod Manness
    @params {array} Input array to be copied to the new larger array
    @params {size} The size of the new array
    @params {max} member variable holding the max capacity of the array
    @params {reserved} member variable holding the number of used elements
*/
void Resize(int *array, int size, int *max, int *reserved) {
    // New Array must be larger than old
    if(size < *max) {
        return;
    }
    int *newVector;
    newVector = (int *)malloc(size * sizeof(int)); // Creates a new array of the requested size
    for(int i = 0; i < *reserved; i++){
        newVector[i] = array[i];
    }
    free(array);

    array = newVector;
    newVector = NULL;
    *max = size;
    return;
}

void main(){
    int *createdVector = CreateVector(3, &max_capacity, &reserved_size);
    getchar();
}