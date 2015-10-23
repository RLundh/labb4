#include "labb4.h"

//Fills the register with NULL pointers
void clearRegister(struct Vehicle* vehicleRegister)
{
    int i;
    for(i = 0; i < REGISTER_LENGTH; i++)
    {
        vehicleRegister[i] = empty;
    }
}

/*
void sortArray(struct Vehicle* array, int length, memeber)
{
    int x, y;
    for(x=0; x<length; x++)

	{
        for(y=0; y<length-1; y++)
		{
			if(strcmp(array[y].member, array[y+1].member) > 0)
			{
				struct Vehicle temp = array[y+1];
				
				array[y+1] = array[y];
				array[y] = temp;

			}
		}
	}
}
*/

void sortArray(struct Vehicle* array, int length)
{
    int x, y;
    for(x=0; x<length; x++)

	{
        for(y=0; y<length-1; y++)
		{
			if(strcmp(array[y].vehicleMake, array[y+1].vehicleMake) > 0)
			{
				struct Vehicle temp = array[y+1];
				
				array[y+1] = array[y];
				array[y] = temp;

			}
		}
	}
}

//Sorts the register in alfabetical order by carMake
void sortRegister(struct Vehicle* vehicleRegister)
{
    int length;
    int i;
    for(i = 0; i < REGISTER_LENGTH; i++)
    {
        length = length + vehicleRegister[i].initilized;
    }
    
    sortArray(vehicleRegister, length);
}



int main()
{
    struct Vehicle vehicleRegister[REGISTER_LENGTH];
    clearRegister(vehicleRegister);
    addFromFile(vehicleRegister);
    
    int place;
    
    char charChoice;
    // intChoice;
    static int loop = 1;
    while(loop == 1)
    {
        printf("Välj opperation:\n");
        printf("  1.Lägg till fordon.\n");
        printf("  2. Ta bort fordon.\n");
        printf("  3. Sortera efter bilmärke.\n");
        printf("  4. Print fordon.\n");
        printf("  8. Print register.\n");
        printf("  9. Exit.\n");
        scanf("%c", &charChoice);
        
      /*  if(isdigit(charChoice))
        {
            intChoice = charChoice - '0';
        }
        else
        {
            intChoice = 0;
        }*/
        
        switch((int) charChoice - '0')//intChoice)
        {
            case 1:
                if(vehicleRegister[REGISTER_LENGTH].initilized != 1)
                {
                    addElement(vehicleRegister);
                }
                else
                {
                    printf("Fullt register, ta bort element först.\n");
                }
                break;
            case 2:
                if(vehicleRegister[0].initilized == 1)
                {
                    printf("Vilket element?\n");
                    scanf("%d", &place);
                    removeElement(vehicleRegister, place);
                }
                else
                {
                    printf("Tomt register, lägg till element först.\n");
                }
                break;
            case 3:
                if(vehicleRegister[0].initilized == 1)
                {
                    sortRegister(vehicleRegister);
                    printf("Registret är sorterat.\n");
                }
                else
                {
                    printf("Tomt register, lägg till element först.\n");
                }
                break;
            case 4:
                if(vehicleRegister[0].initilized == 1)
                {
                    printf("Vilket element?\n");
                    scanf("%d", &place);
                    printElement(vehicleRegister, place);
                }
                else
                {
                    printf("Tomt register, lägg till element först.\n");    
                }
                break;
            case 8:
                if(vehicleRegister[0].initilized == 1)
                {
                printRegister(vehicleRegister);
                }
                else
                {
                    printf("Tomt register, lägg till element först.\n");
                }
                break;
            case 9:
                loop++;
                break;
            default:
                printf("Ej giltigt kommando.\n\n");
        }
    }
   return 1;     
}