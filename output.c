#include "labb4.h"

//Prints the element om place "place"
void printElement(struct Vehicle* vehicleRegister, int place)
{
    struct Vehicle vehicle = vehicleRegister[place];
    
    printf("Fordon #%d:\n", place);
    printf("    Fordonstyp: %s\n", vehicle.vehicleType);
    printf("    Fordonsmärke: %s\n", vehicle.vehicleMake);
    printf("    Registreringsnummer: %s\n", vehicle.registrationNum);
    printf("  Ägare:\n");
    printf("    Namn: %s %s\n", vehicle.owner.firstName, vehicle.owner.lastName);
    printf("    Ålder: %s\n", vehicle.owner.age);
}

//Prints the entire register
void printRegister(struct Vehicle* vehicleRegister)
{
    int i;
    for(i = 0; i < REGISTER_LENGTH; i++)
    {
        if(vehicleRegister[i].initilized == 1)
        {
            printElement(vehicleRegister, i);
            printf("----------------\n\n");
        }
        else
        {
            i = REGISTER_LENGTH;
        }
    }
}