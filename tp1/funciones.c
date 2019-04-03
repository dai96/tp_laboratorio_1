#include <stdio.h>
#include <stdlib.h>


float suma(float a, float b)
{
    float x;

    x=a+b;

    return x;
}

float resta(float a, float b)
{
    float x;

    x=a-b;

    return x;
}

float multiplicacion(float a, float b)
{
    float x;

    x=a*b;

    return x;
}


float dividir(float a, float b)
{
    float x=-1;

    if (b!=0)
        x=a/b;

    return x;
}

float factorial (float a)
{
    int i;
    float fact=1;
    if(a == 0 || a == 1)
        fact = 1;
    else
    {
        for (i=1;i<=a;i++)
        {
            fact=fact*i;
        }
    }
    return fact;
}
