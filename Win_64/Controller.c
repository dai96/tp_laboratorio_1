#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;

    pFile=fopen(path,"r");

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        retorno=1;
        parser_EmployeeFromText(pFile,pArrayListEmployee);
    }

    fclose(pFile);

    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;

}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* this;
    char id[20],nombre[20],horas[20],sueldo[20];
    int retorno=-1,auxId;

    if (this!=NULL && pArrayListEmployee!=NULL)
    {
        retorno=1;
        auxId=ll_len(pArrayListEmployee)+1;
        itoa(auxId,id,10);
        getNombres("nombre",nombre,10);
        getNumeros("horas trabajadas",horas,4);
        getNumeros("sueldo",sueldo,8);
        this=employee_newParametros(id,nombre,horas,sueldo);
        ll_add(pArrayListEmployee,this);

    }
    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* this;
    int retorno=-1,horas,sueldo,i,len,returnedId;
    char nombre[20];
    int auxId;

    if (pArrayListEmployee!=NULL && this!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        auxId=getInt("numero de id");

        for (i=0;i<len;i++)
        {
            this=ll_get(pArrayListEmployee,i);
            employee_getId(this,&returnedId);

            if (auxId==returnedId)
            {
                retorno=1;
                getNombres("nombre",nombre,20);
                strcpy(this->nombre,nombre);

                horas=getInt("horas trabajadas");
                this->horasTrabajadas=horas;

                sueldo=getInt("sueldo");
                this->sueldo=sueldo;

                printf("Modificacion realizada\n");
                break;

            }

        }
    }

    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* this;
    int retorno=-1,auxId,i,len,returnedId;
    char opcion;

    len=ll_len(pArrayListEmployee);
    auxId=getInt("numero de id");

    if (pArrayListEmployee!=NULL && this!=NULL)
    {
            for (i=0;i<len;i++)
        {
            this=ll_get(pArrayListEmployee,i);
            employee_getId(this,&returnedId);

             if (auxId==returnedId)
             {
                printf("Esta seguro que desea borrar el siguiente dato?");
                printf("\n\n  ID \t\t   Nombre \t\t  Horas \t\t  Sueldo \n\n");
                printf("%4d  %20s %20d %20d \n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
                opcion=son();
                if (opcion=='S')
                {
                    ll_remove(pArrayListEmployee,i);
                    employee_delete(this);
                    printf("Dato borrado\n");
                    break;
                }
                else
                {
                    printf("Dato no borrado\n");
                }
             }

        }

    }


    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1,i,auxId,auxHoras,auxSueldo,len;
    char auxNombre[20];

    Employee* this;

    if(pArrayListEmployee!=NULL && this!=NULL)
    {
        retorno=1;
        len=ll_len(pArrayListEmployee);
        printf("\n\n  ID \t\t   Nombre \t\t  Horas \t\t  Sueldo \n\n");

        for(i=0;i<len;i++)
        {
            this=ll_get(pArrayListEmployee,i);

            employee_getId(this,&auxId);
            employee_getNombre(this,auxNombre);
            employee_getHorasTrabajadas(this,&auxHoras);
            employee_getSueldo(this,&auxSueldo);

            printf("%4d  %20s %20d %20d \n",auxId,auxNombre,auxHoras,auxSueldo);
        }
    }

    return retorno;

}

 int ordenarId (void* employeeUno, void* employeeDos)
{
    int retorno=-2;
    Employee* empleadoUno;
    Employee* empleadoDos;

    if(employeeUno!=NULL && employeeDos!=NULL)
        {
            empleadoUno=(Employee*)employeeUno;
            empleadoDos=(Employee*)employeeDos;
            if((empleadoUno->id) < (empleadoDos->id))
            {
                retorno=1 ;
            }
            else if((empleadoUno->id) == (empleadoDos->id))
            {
                retorno=0;
            }
            else if((empleadoUno->id) > (empleadoDos->id))
            {
                retorno=-1 ;
            }
        }

    return retorno;
}

int ordenarNombre (void* employeeUno, void* employeeDos)
{
    int retorno = -2;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(employeeUno!=NULL && employeeDos!=NULL)
        {
            empleadoUno=(Employee*)employeeUno;
            empleadoDos=(Employee*)employeeDos;
            retorno=stricmp(empleadoUno->nombre,empleadoDos->nombre);
        }

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1,opcion;

    if(pArrayListEmployee!=NULL)
    {
        printf("\n1-ID ascendente\n2-ID descendente\n3-Nombre ascendente\n4-Nombre descendente\n");
        opcion=getInt("opcion");
        switch(opcion)
           {
                case 1:
                    ll_sort(pArrayListEmployee,ordenarId, 0);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                case 2:
                    ll_sort(pArrayListEmployee,ordenarId, 1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                case 3:
                    ll_sort(pArrayListEmployee,ordenarNombre, 0);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                case 4:
                    ll_sort(pArrayListEmployee,ordenarNombre, 1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                default:
                    printf("Error, selecione un numero del 1 al 4");
                    break;
           }
        retorno =1;
       }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    Employee* this;

    int retorno=-1,i,auxId,auxHoras,auxSueldo,len;
    char auxNombre[20];

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        retorno=1;
        len=ll_len(pArrayListEmployee);
        pFile=fopen(path,"w");
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0;i<len;i++)
        {
            this=(Employee*)ll_get(pArrayListEmployee,i);

            employee_getId(this,&auxId);
            employee_getNombre(this,auxNombre);
            employee_getHorasTrabajadas(this,&auxHoras);
            employee_getSueldo(this,&auxSueldo);

            fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
        }

        fclose(pFile);
    }
    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

