#include "labb4.h"

//Adds elements to the register from a file
void addFromFile(struct Vehicle* vehicleRegister)
{
    FILE* fileStream = fopen(INPUT_FILE, "r");
    if(fileStream != NULL)
    {
    int i;
    int iMax = (char)fgetc(fileStream) - '0';
    fseek(fileStream, sizeof("\n"), SEEK_CUR);
    
    struct Vehicle vehicle;
    struct Person person;
    
    for(i = 0; i < iMax; i++)
    {
        fgets(vehicle.vehicleType, STD_STRING, fileStream);
        fgets(vehicle.vehicleMake, STD_STRING, fileStream);
        fgets(vehicle.registrationNum, STD_STRING, fileStream);
        
        fgets(person.firstName, STD_STRING, fileStream);
        fgets(person.lastName, STD_STRING, fileStream);
        fgets(person.age, AGE_SIZE, fileStream);
        
        vehicle.owner = person;
        vehicle.initilized = 1;
        vehicleRegister[i] = vehicle;
        
        fseek(fileStream, sizeof(char), SEEK_CUR);
    }
    printf("Register laddat från fil.\n");
    fclose(fileStream);
    }
    else
    {
        printf("Ingen register fil hittad. Registret är tomt.\n");
    }
}