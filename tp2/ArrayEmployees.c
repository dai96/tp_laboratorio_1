#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<strings.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int initEmployees(Employee list[], int len)
{
    int i, retorno=-1;

    for (i=0;i<len;i++)
    {
       list[i].isEmpty=LIBRE;
       retorno=0;
    }

    return retorno;
}


int addEmployee(Employee list [], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i, retorno=-1;

    for (i=0;i<len;i++)
    {
        if (list[i].isEmpty==LIBRE)
        {
            list[i].id=id;
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);
            list[i].salary=salary;
            list[i].sector=sector;
            list[i].isEmpty=OCUPADO;
            retorno=0;
            break;

        }
    }

    return retorno;
}


void altaEmployee (Employee list[], int len)
{
    int id,sector;
    float salary;
    char aceptar,name[51],lastName[51];


        id=idIncremental(list,len);
        getNombres("nombre",name);
        getNombres("apellido",lastName);
        salary=getFlotante("salario");
        sector=getInt("sector");
        printf("Esta seguro que desea agregar estos datos?");
        aceptar=son();

        if (aceptar=='S')
        {
            addEmployee(list,len,id,name,lastName,salary,sector);
        }

}

int idIncremental(Employee list[],int len)
{
    int retorno = 0, i;
    if(len > 0)
    {
        if (list[0].isEmpty==LIBRE)
        {
            return 1;
        }
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
                    if(list[i].id>retorno)
                    {
                         retorno=list[i].id;
                    }

            }

        }
    }

    return retorno+1;///y retorna el lugar siguiente
}

int printEmployees(Employee list [], int len)
{
    int i;
    for (i=0;i<len;i++)
    {
        if (list[i].isEmpty==OCUPADO)
        {
            printf("\n%d %s %s %.2f %d",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }

    }
    printf("\n\n\n");
    return 0;
}

int findEmployeeById(Employee list[], int len,int id)
{
    int i,retorno=-1;
    for (i=0;i<len;i++)
    {
        if (list[i].id==id && list[i].isEmpty==OCUPADO)
        {
            retorno=i;
            break;
        }

    }
    return retorno;
}

void modificar(Employee list[], int len)
{

    int index, opcion,verificar;
    index=getInt("legajo a modificar");
    verificar=findEmployeeById(list,len,index);

    if (verificar!=-1)
    {

            printf("Que desea modificar?");
            printf("\n1-Nombre     2-Apellido     3-Salario      4-Sector");
            opcion=getInt("opcion");

        switch(opcion)
        {
            case 1:
                getNombres("nuevo nombre",list[index].name);
                break;

            break;
            case 2:
                getNombres("nuevo apellido",list[index].lastName);
                break;
            case 3:
                list[index].salary=getFlotante("nuevo salario");
            break;

            case 4:
                list[index].sector=getInt("nuevo sector");
                break;
        }

    }
    else
        printf("Error, legajo no existe\n");

}


int removeEmployee(Employee list[], int len, int id)
{
    int retorno=-1,verificar;
    char opcion;
    verificar=findEmployeeById(list,len,id);


    if (verificar!=-1)
    {
                list[id].isEmpty=LIBRE;
                printf("Borrado");
                retorno=0;

    }
    else
        printf("Error el legajo no existe\n");

    return retorno;
}

int sortEmployees(Employee list[], int len, int order)
{
    int i,j;
    Employee aux;
    for (i=0;i<len-1;i++)
    {
        for (j=i+1;j<len;j++)
        {
            if (order==1)
            {
                    if(strcmp(list[i].lastName,list[j].lastName)>0)
                    {
                        aux=list[i];

                        list[i]=list[j];

                        list[j]=aux;
                    }
            }

            if (order==2)
            {
                if(strcmp(list[i].lastName,list[j].lastName)<0)
                    {
                        aux=list[i];

                        list[i]=list[j];

                        list[j]=aux;
                    }
            }

        }
    }
    return 0;
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}


int getInt (char mensaje [])
{
    int retorno;
    printf("Ingrese %s:",mensaje);
    scanf("%d", &retorno);
    return retorno;
}

float getFlotante (char mensaje [])
{
    float retorno;
    printf("Ingrese %s:",mensaje);
    scanf("%f",&retorno);

    return retorno;
}

char getCaracter (char mensaje [])
{
    char retorno;
    printf("Ingrese %s:",mensaje);
    fflush(stdin);
    scanf("%c",&retorno);

    return retorno;
}

void getString(char mensaje [],char vec[])
{
    char retorno [200];
    printf("Ingrese %s:",mensaje);
    fflush(stdin);
    gets(retorno);
    strcpy(vec,retorno);
}

void getNombres (char mensaje [], char vec [])
{
    char retorno [20];
    printf("Ingrese %s:",mensaje);
    fflush(stdin);
    gets(retorno);
    strlwr(retorno);
    retorno[0]=toupper(retorno[0]);
    stringToUpper(retorno);
    strcpy(vec,retorno);
}

void stringToUpper (char vec [])
{
    int i;
    for (i=0;vec[i]!='\0';i++)
    {
        if (vec[i]==' ')
        {
            i++;
            vec[i]=toupper(vec[i]);
            i--;
        }
    }

}

int esNumerico(char vec[])
{
   int i=0, retorno=1;
   while(vec[i] != '\0')
   {
       if(vec[i] < '0' || vec[i] > '9')
           retorno=0;
       i++;
   }
   return retorno;
}

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

void validarString (char validar [], int tam, char solicita[])
{
    while (strlen(validar)>tam)
    {
        printf("Error! reingrese %s:",solicita);
        fflush(stdin);
        gets(validar);
    }
}

char son(void)
{
    char opcion;
    opcion=getCaracter("S/N");
    opcion=toupper(opcion);
    while (opcion!='S' && opcion!='N')
    {
        printf("Error! porfavor ingrese solo S o N\n");
        opcion=getCaracter("S/N");
        opcion=toupper(opcion);
    }

   return opcion;
}
