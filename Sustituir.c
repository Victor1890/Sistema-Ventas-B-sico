//
// Created by victo on 7/20/2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Sustituir(char origen[], char destino[]);

void main()
{
    char origen[10], destino[100];
    printf("Favor en escribir cualquier caracter: \t"); scanf("%[^\n]", &origen);
    Sustituir(origen, destino);
    printf("Cadena original: \t %s \n", origen);
    printf("Cadena alterada: \t %s \n", destino);
}

void Sustituir(char origen[], char destino[])
{
    char text[51];
    int a = 0,b = 0,tam = 0,blancos = 0;
    tam = strlen(origen);
    fflush(stdin);
    for(a = 0; a < tam; a++)
    {
        if(origen[a] != ' ')
        {
            destino[b] = origen[a];
            b++;
        }
        else
        {
            blancos++;
            destino[b] = (rand()%56)+65;
            destino[b+1] = (rand()%56)+65;
            b+=2;
        }
    }
    fflush(stdin);
    destino[b] = '\0';
}