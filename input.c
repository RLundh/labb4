#include "labb4.h"


static struct Vehicle getElement()
{
    struct Person person;
    struct Vehicle vehicle;
        
    printf("Fordonstyp:\n");
    scanf("%s", vehicle.vehicleType);
   
    printf("Fordonsmärke:\n");
    scanf("%s", vehicle.vehicleMake);
        
    printf("Registreringsnummer:\n");
    scanf("%s", vehicle.registrationNum);
     
            
    printf("Ägarens Förnamn:\n");
    scanf("%s", person.firstName);
    
    printf("Ägarens Efternamn:\n");
    scanf("%s", person.lastName);
  
    printf("Ägarens Ålder:\n");
    scanf("%s", person.age);
    
    
    vehicle.owner = person;
    vehicle.initilized = 1;
    return vehicle;
}


//If possible adds an element to the register
void addElement(struct Vehicle* vehicleRegister)
{
    struct Vehicle vehicle;
    int i = 0;
    vehicle = getElement();
    
    while(i < REGISTER_LENGTH)
    {
        if(vehicleRegister[i].initilized == 1)
        {
            i++;
        }
        else
        {
            vehicleRegister[i] = vehicle;
            i = REGISTER_LENGTH;
        }
    }
}


//Removes the element on place "place" from the register
void removeElement(struct Vehicle* vehicleRegister, int place)
{
    vehicleRegister[place] = empty;
    struct Vehicle temp;
    
    int i;
    for(i = 0; i < REGISTER_LENGTH; i++)
    {
        if(vehicleRegister[i].initilized == 0)
        {
            if(vehicleRegister[i + 1].initilized == 1)
            {
                temp = vehicleRegister[i];
                vehicleRegister[i] = vehicleRegister[i + 1];
                vehicleRegister[i + 1] = temp;
            }
            else
            {}
        }
        else
        {}
    }
}