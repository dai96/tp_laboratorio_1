#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<strings.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

int getInt (char mensaje [])
{
    int retorno,validar;
    printf("Ingrese %s: ",mensaje);
    fflush(stdin);
    validar=scanf("%d", &retorno);
    while(validar==0)
    {
        printf("Error! reingrese %s (solo numeros): ",mensaje);
        fflush(stdin);
        validar=scanf("%d",&retorno);
        if (validar==1)
        {
            break;
        }
    }

    return retorno;
}
//}while(! scanf("%d", &datos_cliente.edad);
//si ingresas un numero en el scanf te devuelve 1 por numero, 0 si es no njmero
float getFloat (char mensaje [])
{
    float retorno;
    printf("Ingrese %s: ",mensaje);
    scanf("%f",&retorno);

    return retorno;
}

char getCaracter (char mensaje [])
{
    char retorno;
    printf("Ingrese %s: ",mensaje);
    fflush(stdin);
    scanf("%c",&retorno);

    return retorno;
}

void getString(char mensaje [],char vec[],int maximoCaracteres, char validacion[])
{
    char retorno [200];
    printf("Ingrese %s: ",mensaje);
    fflush(stdin);
    gets(retorno);
    validarString(retorno,maximoCaracteres,validacion);
    strcpy(vec,retorno);

}

void getNombres (char mensaje [], char vec [], int max)
{
    char retorno [20];
    int i;
    getString(mensaje,retorno,max,"hasta 10 caracteres");
    i=esSoloLetras(retorno);
    while (i==0)
    {
        getString("solamente letras",retorno,max,"hasta 10 caracteres");
        i=esSoloLetras(retorno);
        if (i==1)
        {
            break;
        }
    }
    strlwr(retorno);
    retorno[0]=toupper(retorno[0]);
    stringToUpper(retorno);
    strcpy(vec,retorno);
}

void getNumeros (char mensaje [], char vec [], int max)
{
    char retorno [20];
    int i;
    getString(mensaje,retorno,max,mensaje);
    i=esNumerico(retorno);
    while (i==0)
    {
        getString("solamente numeros",retorno,max,mensaje);
        i=esNumerico(retorno);
        if (i==1)
        {
            break;
        }
    }
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
       if( vec[i] < '0' || vec[i] > '9')
       {
           retorno=0;
           break;
       }
       else
        {
            i++;
        }

   }
   return retorno;
}

int esSoloLetras(char str[])
{
   int i=0,retorno=1;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
           retorno=0;
           break;
       }
       else
        {
            i++;
        }
   }
   return retorno;
}

char validarString (char validar [], int tam, char solicita[])
{
    while (strlen(validar)>tam)
    {
        printf("Error! reingrese %s:",solicita);
        fflush(stdin);
        gets(validar);
    }
    return validar;
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


int validarMes(int mes, int dia)
{
    while (mes>12 || mes<1)
    {
        mes=getInt("mes valido (1-12)");
    }
    if (dia==31)
    {
         while(mes!=1 && mes!=3 && mes!=5 && mes!=7 && mes!=8 && mes!=10 && mes!=12)
        {
            mes=getInt("mes valido para la fecha que eligio (fecha:31)");
        }
    }
    if (dia==30)
    {
        while(mes==2)
        {
            mes=getInt("mes valido para la fecha que eligio (fecha:30)");
        }
    }

   return mes;
}


int validarNumeros (int dato, int minimo, int maximo)
{
    while (dato<minimo || dato>maximo)
    {
        dato=getInt("valor valido");
    }
    return dato;
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    opcion=getInt("opcion");

    return opcion;
}

