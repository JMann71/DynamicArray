#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// current maximum capacity of the vector
int max_capacity;
// current size of the vector, meaning how many elements hold actual values minus one
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
    vector = (int *)malloc(size  * sizeof(int)); // allocates the amount of memory required for the number of initial elements
    *max = size;
    *reserved = 0;
    for(int i = 0; i < *max; i++){
        vector[i] = 0;
    }
    return vector;
}

/*
    @desc This function creates a new array of a given size, copies data from an input array into it, then reassigns the pointer to the new array
    @author Jarod Manness
    @params {array} Input array to be copied to the new larger array
    @params {size} The size of the new array
    @params {max} member variable holding the max capacity of the array
    @params {reserved} member variable holding the number of used elements minus one
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


/*
    @desc This function appends an element to the end of the array.
            If the array can't hold any more elements, the array is resized to double it's current max capacity
    @author Jarod Manness
    @params {element} Element to be added to the end of the array
    @params {array} The array to be added to
    @params {max} The max capacity of the array
    @params {reserved} The number of elements reserved and have data minus one
*/
void Append(int element, int *array, int *max, int *reserved){
    *reserved = *reserved + 1;
    if(*max < *reserved){
        Resize(array, *max * 2, max, reserved);
    }
    array[*reserved - 1] = element;
}

/*
    @desc This function deletes and frees the memory associated with an input array.
            Also resets max capacity and reserved variables to 0.
    @author Jarod Manness
    @params {array} The array to be deleted
    @params {max} The max capacity of the array
    @params {reserved} The number of elements reserved and have data minus one
*/
void Delete(int *array, int *max, int *reserved){
    free(array);
    *max = 0;
    *reserved = 0;
}


/*
    @desc This function gets the value in the last element of the array, returns it, then resets it to 0
    @author Jarod Manness
    @params {array} The array to use
    @params {reserved} The number of elements reserved and have data minus one
*/
int Pop(int *array, int *reserved){
    int ret = array[*reserved - 1];
    array[*reserved - 1] = 0;
    *reserved = *reserved - 1;
    return ret;
}

/*
    @desc This function returns the max capacity for use outside this file
    @author Jarod Manness
*/
int GetMax() {
    return max_capacity;
}

/*
    @desc This function returns the current size for use outside this file
    @author Jarod Manness
*/
int GetSize() {
    return reserved_size;
}

/*
    @desc This function uses a simple bubble sort algorithm to sort an array
    @author Jarod Manness
    @params {array} The array to use
    @params {reserved} The number of elements reserved and have data minus one
*/
void Sort(int *array, int* reserved){
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(int i = 0; i < (*reserved - 1); i++){
            if(array[i] > array[i + 1]){
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                sorted = false;
            }
        }
    }
}

/*
    @desc this function takes in a value and returns true or false if it's an element of the array
    @author Jarod Manness
    @params {value} The value to search for
    @params {array} The array to use
    @params {reserved} The number of elements reserved and have data minus one
*/
bool Find(int value, int *array, int* reserved){
    for(int i = 0; i < *reserved; i++){
        if(array[i] == value){
            return true;
        }
    }
    return false;
}

void main(){
    int *createdVector = CreateVector(3, &max_capacity, &reserved_size);
    Append(2, createdVector, &max_capacity, &reserved_size);
    Append(4, createdVector, &max_capacity, &reserved_size);
    Append(8, createdVector, &max_capacity, &reserved_size);
    Append(5, createdVector, &max_capacity, &reserved_size);
    Append(7, createdVector, &max_capacity, &reserved_size);
    Append(12, createdVector, &max_capacity, &reserved_size);
    Append(3, createdVector, &max_capacity, &reserved_size);
    Append(1, createdVector, &max_capacity, &reserved_size);
    printf("Unsorted\n");
    for(int i = 0; i < reserved_size; i++){
        printf("%d \n", createdVector[i]);
    }
    Sort(createdVector, &reserved_size);
    printf("Sorted\n");
    for(int i = 0; i < reserved_size; i++){
        printf("%d \n", createdVector[i]);
    }
    bool found = Find(18, createdVector, &reserved_size);
    if(found){
        printf("Found\n");
    }
    else {
        printf("Not Found\n");
    }
    getchar();
}