#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    float a=0, b=0,sum,res,multi,divi,facA,facB;
    char seguir='s';

   while (seguir=='s')
   {
       system("cls");
       printf("-------------Calculadora------------\n\n");
       printf("1-Ingresar primer operando (A=%.2f)\n",a);
       printf("2-Ingresar segundo operando (B=%.2f)\n",b);
       printf("3-Calcular\n");
       printf("4-Resultados\n");
       printf("\n5-Salir\n\n\n");

       scanf("%d",&opcion);
       fflush(stdin);

       switch (opcion)
            {
                case 1:
                    system("cls");
                    printf("Ingrese primer operando: ");
                    scanf("%f",&a);
                    break;

                case 2:
                    system("cls");
                    printf("Ingrese segundo operando: ");
                    scanf("%f",&b);
                    break;

                case 3:
                    system("cls");
                    printf("\nCalculando.....\n\n\n\n");
                    sum=suma(a,b);
                    res=resta(a,b);
                    multi=multiplicacion(a,b);
                    divi=dividir(a,b);
                    facA=factorial(a);
                    facB=factorial(b);
                    system("pause");
                    break;

                case 4:
                    system("cls");
                    printf("-------------Resultados---------------\n\n");
                    printf("La suma de %.2f y %.2f es %.2f\n\n",a,b,sum);
                    printf("La resta de %.2f y %.2f es %.2f\n\n",a,b,res);
                    printf("La multiplacacion de %.2f y %.2f es %.2f\n\n",a,b,multi);
                    if (divi==-1)
                        printf("No se puede dividir por 0\n\n");
                    else
                        printf("La division de %.2f y %.2f es %.2f\n\n",a,b,divi);
                    if (a<0)
                        printf("%.2f es negativo, no se puede factorear\n\n",a);
                    else
                        printf("El factorial de %.2f es %.2f\n\n",a,facA);
                    if (b<0)
                        printf("%.2f es negativo, no se puede factorear\n\n",b);
                    else
                        printf("El factorial de %.2f es %.2f\n\n\n\n",b,facB);

                    system("pause");
                    break;

                case 5:
                    system("cls");
                    seguir='n';
                    break;

                default:
                    system("cls");
                    printf("\nPorfavor ingrese opcion del 1 al 5 \n\n");
                    system("pause");
                    break;
           }
   }
    return 0;
}

