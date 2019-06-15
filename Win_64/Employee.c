#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee=(Employee*)malloc(sizeof(Employee));

    if(pEmployee!=NULL)
    {
        return pEmployee;
    }
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;
    int auxId,auxHorasTrabajadas,auxSueldo;
    pEmployee=employee_new();

    if(pEmployee!=NULL)
    {
        auxId=atoi(idStr);
        auxHorasTrabajadas=atoi(horasTrabajadasStr);
        auxSueldo=atoi(sueldoStr);
        employee_setId(pEmployee,auxId);
        employee_setHorasTrabajadas(pEmployee,auxHorasTrabajadas);
        employee_setNombre(pEmployee,nombreStr);
        employee_setSueldo(pEmployee,auxSueldo);

        return pEmployee;
    }
}
void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    if (this!=NULL)
    {
        this->id=id;
    }
    return 1;
}
int employee_getId(Employee* this,int* id)
{
    if (this!=NULL)
    {
        *id=this->id;
    }
    return 1;
}
int employee_setNombre(Employee* this,char* nombre)
{
    if (this!=NULL)
    {
        strcpy(this->nombre,nombre);
    }

    return 1;
}

int employee_getNombre(Employee* this,char* nombre)
{
    if (this!=NULL)
    {
        strcpy(nombre,this->nombre);
    }

    return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)//set para poner
{
    if (this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
    }

    return 1;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)//get para guardar
{
    if (this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
    }
    return 1;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    if (this!=NULL)
    {
       this->sueldo=sueldo;
    }
    return 1;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    if (this!=NULL)
    {
         *sueldo=this->sueldo;
    }
   return 1;
}


