#include <stdio.h>
#include <stdlib.h>


/** \brief suma dos datos
*
* \param primer operandor
* \param segundo operador
* \return resultado de la operacion
*
*/
float suma(float a, float b)
{
    float x;

    x=a+b;

    return x;
}

/** \brief resta dos datos
*
* \param primer operandor
* \param segundo operador
* \return resultado de la operacion
*
*/
float resta(float a, float b)
{
    float x;

    x=a-b;

    return x;
}

/** \brief multiplica dos datos
*
* \param primer operandor
* \param segundo operador
* \return resultado de la operacion
*
*/
float multiplicacion(float a, float b)
{
    float x;

    x=a*b;

    return x;
}

/** \brief multiplica dos datos
*
* \param primer operandor
* \param segundo operador
* \return resultado de la operacion
*
*/
float dividir(float a, float b)
{
    float x=-1;

    if (b!=0)
        x=a/b;

    return x;
}

/** \brief Realiza factorial
*
* \param operandor
* \return resultado de la operacion
*
*/
float factorial (float a)
{
    int i;
    float fact=1;
    for (i=1;i<=a;i++)
    {
        fact=fact*i;
    }
    return fact;
}

