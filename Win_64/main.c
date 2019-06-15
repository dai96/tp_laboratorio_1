#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    printf("-----------------------------TP3----------------------------------\n");
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
        {
            opcion=menuDeOpciones("1-Cargar txt \n2-Cargar binario \n3-Alta \n4-Modificar \n5-Baja \n6-Listar \n7-Ordenar \n8-Guardar en txt \n9-Guardar en binario \n\n10-Salir \n\n");
            switch(opcion)
            {
                case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                    break;
                case 2:
                    break;
                case 3:
                controller_addEmployee(listaEmpleados);
                    break;
                case 4:
                controller_editEmployee(listaEmpleados);
                    break;
                case 5:
                controller_removeEmployee(listaEmpleados);
                    break;
                case 6:
                controller_ListEmployee(listaEmpleados);
                    break;
                case 7:
                    controller_sortEmployee(listaEmpleados);
                    break;
                case 8:
                    controller_saveAsText("data.csv",listaEmpleados);
                    break;
                case 9:
                    break;
                default:
                    if (opcion!=10)
                    {
                      printf("Error, elija una opcion del 1 al 10");
                    }
                    break;
            }
            system("pause");
            system("cls");
        }while(opcion!=10);

    return 1;
}

