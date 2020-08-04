//
// Created by Eimy Corcino on 7/25/2020.
//
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

struct Libros
{
    int id;
    char nombre_libros[30];
    int cantidad_items;
};

void AgregarLibros();
char AreYouTeacher();
void Usuario(struct Libros *libros);
void Pedidos(struct Libros *libro);
void List_Products(struct Libros *libros, int n);
void Roles_menu(struct Libros *libros);

int num = 0;

void Usuario(struct Libros *libros)
{
    int matricula;
    char respuesta;

    system("cls");
    printf("Escribir su matr%ccula: \t",161); scanf("%d", &matricula);
    if(matricula == 0)
    {
        printf("Favor en escribir su matricula :)");
        getchar();
    }
    else if(matricula != 0)
    {
        printf("\n\n%cDeseas ver la lista de los libros disponible%c, (escribir 'Y' para un si o 'N' para un no): \t", 168,63); scanf("%s", &respuesta);
        if(respuesta == 'y')
            List_Products(libros,num);
    }
}

char AreYouTeacher()
{
    system("cls");
    char option;
    fflush(stdin);
    printf("Usted es bibliotecario (escribir Y si es verdadero o N si es falso):\t"); scanf("%s", &option);

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
    printf("%cCantidad de producto que deseas agregar%c: \t", 168, 63); scanf("%d", &cantidad);

    num = cantidad;

    libros = (struct Libros *)malloc(cantidad * sizeof(struct Libros *));

    fflush(stdin);

    for(int i = 0; i < cantidad; i++)
    {
        //system("cls");

        (libros+i)->id = i;

        printf("Agregar el nombre del libro: \t"); scanf("%[^\n]", &(libros+i)->nombre_libros);
        printf("Agregar la cantidad de libros que 'habr%c' disponible: \t", 160); scanf("%d", &(libros+i)->cantidad_items);
        fflush(stdin);
    }
    fflush(stdin);
    system("cls");
    printf("Saliendo...\n\n");
    List_Products(libros, num);
    Roles_menu(libros);
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
    printf("\n\nQue libro deseas adquirir (seleccionar con el ID):\t"); scanf("%d", &buscar);

    for(int i = 0; i < num; i++)
    {
        if(buscar == ((libro + i)->id + 1))
        {
            printf("\n\nUsted ha seleccionado '%s' \n\n", (libro + i)->nombre_libros);
            printf("%cDeseas arquirir el '%s'%c (escribir 'Y' para un si o 'N' para un no):",168, (libro + i)->nombre_libros, 63); scanf("%s", &respuesta);
            if(respuesta == 'y')
            {
                printf("%cCuantos deseas retirar%c: \t", 168, 63); scanf("%d", &retiro);
                (libro + i)->cantidad_items = (libro + i)->cantidad_items - retiro;
                printf("\n\nEl '%s' a sido retirado, pase un buen d%ca", (libro + i)->nombre_libros, 161);
                List_Products(libro, num);
                printf("\n\n%cDeseas salir%c (escribir 'Y' para un si o 'N' para un no):\t",168 ,63); scanf("%s", &respuesta);
                if(respuesta == 'y')
                    List_Products(libro,num);
                else if(respuesta == 'n')
                {
                    List_Products(libro, num);
                }
            }
        }
        else if(buscar > (libro->id + 1))
        {
            printf("\n\nEl libro aun no se ha agregado :(\n\n");
            system("cls");
        }
        else if(buscar < (libro->id + 1))
        {
            printf("\n\nEl libro no existe :()\n\n");
            system("cls");
        }
    }
}