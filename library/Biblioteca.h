//
// Created by Eimy Corcino on 7/25/2020.
//
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

struct Libros
{
    int id;
    char nombre_libros[20];
    int cantidad_items;
};

void AgregarLibros();
void Usuario(struct Libros *libros);
char AreYouTeacher();
//void Pedidos(struct Libros *libro);
void List_Products(struct Libros *libros, int n);
void Roles_menu(struct Libros *libros);

char AreYouTeacher()
{
    system("cls");
    char option;
    fflush(stdin);
    printf("Usted es maestro (escribir Y si es verdadero o N si es falso):\t"); scanf("%s", &option);

    if(option == 'y')
        return option;
    else if(option == 'n')
        return option;
    else
        AreYouTeacher();
}

void AgregarLibros()
{
    struct Libros *libros;
    int cantidad;
    system("cls");
    printf("\n\nAgregar producto\n\n");
    printf("Cantidad de producto que deseas agregar?: \t"); scanf("%d", &cantidad);

    libros = (struct Libros *)malloc(cantidad * sizeof(struct Libros *));

    fflush(stdin);

    for(int i = 0; i < cantidad; i++)
    {
        system("cls");
        libros->id = i;
        printf("Agregar el nombre del libro: \t"); scanf("%[^\n]", &(libros+i)->nombre_libros);
        printf("Agregar la cantidad de libros que 'habra' disponible: \t"); scanf("%d", &(libros+i)->cantidad_items);
        fflush(stdin);
    }
    fflush(stdin);
    system("cls");
    printf("Saliendo...\n\n");
    List_Products(libros, cantidad);
    Roles_menu(libros);
}

void Usuario(struct Libros *libros)
{
    int matricula;
    char respuesta;

    system("cls");
    printf("Escribir su matricula: \t"); scanf("%d", &matricula);
    if(matricula == 0)
    {
        printf("Favor en escribir su matricula :)");
        getchar();
    }
    else if(matricula != 0)
    {
        printf("\n\nDeseas ver la lista de los libros disponible (escribir 'Y' para un si o 'N' para un no): \t"); scanf("%s", &respuesta);
        printf("\n\nMostrando una lista de %d elementos\n", 3);
        getchar();
        if(respuesta == 'y')
            List_Products(libros,3);
    }
}

void List_Products(struct Libros *libros, int n)
{
    system("cls");
    printf("\n\nLista de los Libros\n");
    printf("\n\nID || Nombre || Disponibilidad \n");
    for(int i = 0; i < n; i++)
    {
        printf("\n\n%d || %s || %d \n", ((libros+i)->id + 1), (libros+i)->nombre_libros, (libros+i)->cantidad_items);
    }
}

void Pedidos(struct Libros *libro)
{
    int buscar, retiro;
    char respuesta;
    printf("\n\nQue libro deseas adquirir:\t"); scanf("%d", &buscar);

    if(buscar == (libro->id + 1))
    {
        printf("\n\nUsted ha seleccionado '%s' ", libro->nombre_libros);
        printf("Deseas arquirir el '%s' (escribir 'Y' para un si o 'N' para un no):", libro->nombre_libros); scanf("%s", &respuesta);
        if(respuesta == 'y')
        {
            printf("Cuantos deseas retirar: \t"); scanf("%d", &retiro);
            libro->cantidad_items = libro->cantidad_items - retiro;
            List_Products(libro,3);
        }
    }
    else if(buscar > (libro->id + 1))
        printf("\n\nEl libro aun no se ha agregado :(\n\n");
    else if(buscar < (libro->id + 1))
        printf("\n\nEl libro no existe :()\n\n");
}