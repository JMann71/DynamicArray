# DynamicArray
### Created by Jarod Manness

This is a simple project and demonstration of creating a dynamic array that can be resized.
Included are a number of helper files that can assist in common tasks such as sorting, reversing, etc.

Main serves as a demonstration of the created functionality and is not required.

## Description of Functionality

### createdVector
Member variable holding the pointer to the array  

### CreateVector
Takes one argument and creates a new array based on the argument. Returns the array.  
Example of creating a new array of size 4:  
`int* vector = CreateVector(4);`  

### Resize
Takes one argument and resizes the array based on the given argument. Returns void.  
Example of resizing the array to size 8:  
`Resize(8);`  

### Append
Appends a value to the end of the array. If appending would exceed the max size, resizes the array to double the current size. Returns void.  
Example of appending the integer 2:  
`Append(2);`  

### Delete
Takes no arguments and frees the memory of the array and resets all member variables. Returns void.  
Example:  
`Delete();`  

### Pop
Takes no arguments and deletes the last element of the array. Returns the value deleted.  
Example:  
`int popped = Pop();`  

### GetMax and GetSize
Simple Getter functions that return the maximum capacity and the current size of the array.  

### Sort
Takes no arguments and sorts the array from low to high. Returns void.  
Example:  
`Sort();`  

### Find
Takes one argument and searches for the value within the array. Returns true if found, false if not.  
Example for finding the integer 2 within the array:  
`bool found = Find(2);`  

### Insert
Takes 2 arguments, value and position. Inserts the value to the array at the given position. Shifts other values forward to accomodate.  
Example of inserting 8 to position 2:  
`Insert(8, 2);`  

### Reverse
Takes no arguments and reverses the array.  
Example:  
`Reverse();`  
