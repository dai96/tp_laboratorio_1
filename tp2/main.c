#include <stdlib.h>
#include "ArrayEmployees.h"

#define T 1000

int main()
{
    Employee lista [T];
    initEmployees(lista,T);
    int index, opcion,order,flag=0,i;

    do
    {
        opcion = menuDeOpciones("\n1.Alta\n2.Modificar\n3.Baja\n4.Informar\n10.Salir\nElija una opcion: ");

        for (i=0;i<T;i++)
        {
            if(lista[i].isEmpty==OCUPADO)
            {
                flag=1;
                break;
            }

        }

        if (flag==0 && opcion!=1)
        {
            printf("Error! La lista de empleados esta vacia\n");
        }
        else
        {
                 switch(opcion)
        {
            case 1:
                altaEmployee(lista,T);
                break;

            break;
            case 2:
                modificar(lista,T);
                break;
            case 3:
                index=getInt("legajo a borrar");
                removeEmployee(lista,T,index);

            break;

            case 4:
                order=getInt("1-Ascendente     2-Descendente");
                sortEmployees(lista,T,order);
                printEmployees(lista,T);
                break;

        }
    }}while(opcion!=10);



}







