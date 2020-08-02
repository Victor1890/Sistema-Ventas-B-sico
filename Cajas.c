//
// Created by victo on 7/25/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ALTURA_MAX_TUNEL 41


int Volumen(int longitud, int ancho, int altura);
void CalcularCaja(int longitud, int ancho, int altura);

void main()
{
    int numeroCajas = 0;
    printf("Introduzca el numero de Cajas: \t"); scanf("%d", &numeroCajas); //Números de Cajas

    SetConsoleTitle("Eimy Corcino 2018-6245");

    printf("Introduzca las dimensiones de las cajas en forma de las dimensiones largo, ancho y alto.\n");
    printf("Ejemplo: Introduzca dimensiones: 10 20 30\n");
    printf("Significa 10 de largo, 20 de ancho y 30 de alto\n");

    for (int i = 0; i < numeroCajas; i++) //Obteniendo los datos de cada Caja ingresada
    {
        int longitud, ancho, altura;
        fflush(stdin);
        printf("Intruducir el largo %d: \t", i); scanf("%d", &longitud);
        printf("Intruducir el ancho %d: \t", i); scanf("%d", &ancho);
        printf("Intruducir el alto %d: \t", i); scanf("%d", &altura);

        for(int o = 0; o < numeroCajas; o++) //Calculando cada dato de cada Caja
        {
            system("cls");
            CalcularCaja(longitud, ancho, altura); //Calculando los datos por cada Caja
            fflush(stdin);
        }
        system("cls");
    }
}

void CalcularCaja(int longitud, int ancho, int altura)
{
    if(altura < ALTURA_MAX_TUNEL) //si altura es menor de 41, es verdadero
        printf("el volumen de la caja es: %d \n", Volumen(longitud, ancho, altura));
    else
        printf("La caja no cumple con los parametros :( \n");
    system("pause");
}

int Volumen(int longitud, int ancho, int altura){ return longitud * ancho * altura; }