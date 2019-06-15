#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
        Employee* this;
        char auxId[20],auxNombre[20],auxHoras[20],auxSueldo[20];
        int r;

        if(pFile!=NULL && pArrayListEmployee!=NULL)
        {

            fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]",auxId,auxNombre,auxHoras,auxSueldo);

            do
            {
                r=fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]",auxId,auxNombre,auxHoras,auxSueldo);
                this=employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
                if(this!=NULL && r==4)
                {
                    ll_add(pArrayListEmployee,this);
                }

            }while(!feof(pFile));

            printf("\nCarga exitosa\n\n");
        }
        else
        {
            printf("\nEl archivo no existe\n\n");
        }

    return 1;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

return 1;


}
