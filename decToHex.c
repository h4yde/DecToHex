#include <stdio.h>
#include <math.h>
#include <string.h>

//Funciones de apoyo
//invertir string
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main()
{
    //constante de conversiones
    char heximalBase[16] = "0123456789ABCDEF";
    
    //resultado
    char resInt[200]="";
    char resFloat[200]="";
    
    //numero a convertir
    double decimalNumber = 193.78;
    
    //verificar con https://es.planetcalc.com/862/
    
    //division del numero a convertir
    int intDecimalNumber = (int) decimalNumber;
    double floatDecimalNumber = decimalNumber - intDecimalNumber;
    
    
    //PARTE 1: conversion de enteros
    int division = (int) intDecimalNumber / 16;
    int residuo = (int) intDecimalNumber % 16;
    
    while(division > 16)
    {
        strncat(resInt, &heximalBase[residuo], 1);
        intDecimalNumber = division;
        division = (int) intDecimalNumber / 16;
        residuo = (int) intDecimalNumber % 16;
    }
    
    if(division < 16)
    {
        strncat(resInt, &heximalBase[residuo], 1);
        strncat(resInt, &heximalBase[division], 1);
    }
    
    
    //PARTE 2: conversion de la fraccion
    while(floatDecimalNumber != 0)
    {
        double multiplication = floatDecimalNumber*16;
        int entero = (int) multiplication;
        floatDecimalNumber = multiplication - entero;
        strncat(resFloat, &heximalBase[entero], 1);
    }
    
    
    //imprimimos los resultados
    strrev(resInt);
    printf("El resultado de convertir %f a hexadecimal es: %s", decimalNumber, resInt);
    if(strlen(resFloat) > 0) printf(".%s", resFloat);
    return 0;
}
