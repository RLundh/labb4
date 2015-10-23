#ifndef __LABB4_H__
#define __LABB4_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//The length of the reister
#define REGISTER_LENGTH 10

//The standard length of a char array
#define STD_STRING 15

//
#define AGE_SIZE 4

//
#define INPUT_FILE "./fordorn.txt"


struct Person{
    char firstName[STD_STRING];
    char lastName[STD_STRING];
    char age[AGE_SIZE];
};

struct Vehicle{
    char vehicleType[STD_STRING];
    char vehicleMake[STD_STRING];
    char registrationNum[STD_STRING];
    struct Person owner;
    int initilized;
};

static const struct Vehicle empty ={{0}};

//Fills the register with NULL pointers
void clearRegister(struct Vehicle* vehicleRegister);


//Adds elements to the register from a file
void addFromFile(struct Vehicle* vehicleRegister);


//If possible adds an element to the register
void addElement(struct Vehicle* vehicleRegister);

//Removes the element on place "place" from the register
void removeElement(struct Vehicle* vehicleRegister, int place);


//Sorts the register in alfabetical order by carMake
void sortRegister(struct Vehicle* vehicleRegister);


//Prints the element om place "place"
void printElement(struct Vehicle* vehicleRegister, int place);

//Prints the entire register
void printRegister(struct Vehicle* vehicleRegister);

#endif