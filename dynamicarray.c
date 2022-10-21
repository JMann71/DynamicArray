#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The pointer to the created array
int* createdVector;
// Member variable holding the maximum capacity of the array
int _max;
// Member variable holding the actual size of the array
int _size;

/*
    @desc This function creates an array of integers based on the size passed in
    @author Jarod Manness
    @params {size} number of elements to initialize
*/
int* CreateVector(int size){
    // Create a new pointer
    int* array;
    // Allocate memory based on the given size
    array = (int *)malloc(size * sizeof(int));
    // Set all entries to 0
    for(int i = 0; i < size; i++){
        array[i] = 0;
    }
    // Set member variables
    _max = size;
    _size = 0;
    // Return the created array
    return array;
}

/*
    @desc This function creates a new array of a given size, copies data from an input array into it, then reassigns the pointer to the new array
    @author Jarod Manness
    @params {size} The size of the new array
*/
void Resize(int size){
    // Create a new pointer
    int* newArray;
    // Allocate memory based on the given size
    newArray = (int *)malloc(size * sizeof(int));
    // Copy data from the old array into the new
    for(int i = 0; i < _size; i++){
        newArray[i] = createdVector[i];
    }
    // Free the memory from the old array
    free(createdVector);
    // Reassign the old pointer to the new array
    createdVector = newArray;
    // Reset the new array pointer
    newArray = NULL;
    _max = size;
}


/*
    @desc This function appends an element to the end of the array.
            If the array can't hold any more elements, the array is resized to double it's current max capacity
    @author Jarod Manness
    @params {value} Element to be added to the end of the array
*/
void Append(int value){
    // Check if the number of elements is equal to or exceeds the max capacity and resize if true
    if(_size >= _max){
        Resize(_max * 2);
    }
    // Set the last element to the given value
    createdVector[_size] = value;
    // Increment the actual size value
    _size++;
}

/*
    @desc This function deletes and frees the memory associated with an input array.
            Also resets max capacity and reserved variables to 0.
    @author Jarod Manness
*/
void Delete(){
    // Free the memory from the array
    free(createdVector);
    // Reset the pointer
    createdVector = NULL;
    // Reset member variables
    _max = 0;
    _size = 0;
}


/*
    @desc This function gets the value in the last element of the array, returns it, then resets it to 0
    @author Jarod Manness
*/
int Pop(){
    // Get the last entry in the array
    int ret = createdVector[_size - 1];
    // Set that entry back to zero
    createdVector[_size] = 0;
    // Decrement the actual size value
    _size--;
    // Return the value
    return ret;
}

/*
    @desc This function returns the max capacity for use outside this file
    @author Jarod Manness
*/
int GetMax() {
    return _max;
}

/*
    @desc This function returns the current size for use outside this file
    @author Jarod Manness
*/
int GetSize() {
    return _size;
}

/*
    @desc This function uses a simple bubble sort algorithm to sort an array
    @author Jarod Manness
*/
void Sort(){
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(int i = 0; i < (_size - 1); i++){
            if(createdVector[i] > createdVector[i + 1]){
                int tmp = createdVector[i];
                createdVector[i] = createdVector[i + 1];
                createdVector[i + 1] = tmp;
                sorted = false;
            }
        }
    }
}

/*
    @desc this function takes in a value and returns true or false if it's an element of the array
    @author Jarod Manness
    @params {value} The value to search for
*/
bool Find(int value){
    for(int i = 0; i < _size; i++){
        if(createdVector[i] == value){
            return true;
        }
    }
    return false;
}

/*
    @desc this function inserts a given value to a given position within the array
    @author Jarod Manness
    @params {value} the value to be inserted
    @params {position} the position to place the value
*/
void Insert(int value, int position){
    // Check if the array needs to be resized
    if(_size >= (_max - 1)){
        Resize(_max * 2);
    }
    // Shift all elements past the input position forward
    for(int i = _size - 1; i >= position; i--){
        createdVector[i] = createdVector[i - 1];
    }
    // Set the array at position to the given value
    createdVector[position] = value;
}

/*
    @desc this function reverses the array
    @author Jarod Manness
*/
void Reverse() {
    int* newArray;
    newArray = (int *)malloc(_max * sizeof(int));
    int j = 0;
    for(int i = _size - 1; i >= 0; i--){
        newArray[j] = createdVector[i];
        j++;
    }
    free(createdVector);

    createdVector = newArray;
    newArray = NULL;
}

void main(){
    createdVector = CreateVector(3);
    Append(2);
    Append(4);
    Append(8);
    Append(5);
    Append(7);
    Append(12);
    Append(3);
    Append(1);
    printf("Unsorted\n");
    for(int i = 0; i < _size; i++){
        printf("%d \n", createdVector[i]);
    }
    Sort(createdVector, _size);
    printf("Sorted\n");
    for(int i = 0; i < _size; i++){
        printf("%d \n", createdVector[i]);
    }
    bool found = Find(18);
    if(found){
        printf("Found\n");
    }
    else {
        printf("Not Found\n");
    }
    Insert(84, 2);
    for(int i = 0; i < _size; i++){
        printf("%d \n", createdVector[i]);
    }
    Reverse();
    printf("Reversed:\n");
    for(int i = 0; i < _size; i++){
        printf("%d \n", createdVector[i]);
    }
    printf("Popped\n");
    int tmp = Pop();
    printf("%d\n", tmp);
    for(int i = 0; i < _size; i++){
        printf("%d \n", createdVector[i]);
    }
    Delete();
    getchar();
}