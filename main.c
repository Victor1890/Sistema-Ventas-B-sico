//
// Created by Eimy Corcino on 7/25/2020.
//

#include <stdio.h>
#include <windows.h>
#include "library/Biblioteca.h"

void Roles_menu(_Libros *libros);

void main()
{
    struct Libros *libros;
    fflush(stdin);
    SetConsoleTitle("Proyecto final de Eimy Corcino - 20186245");
    Roles_menu(libros);
}

void Roles_menu(_Libros *libros)
{
    int option = 0;
    system("cls");
    printf("\n\n 1-) Estudiante \t 2-) Maestro\n\n");
    printf("\n\n Elegir una opcion: \t"); scanf("%d", &option);

    switch (option)
    {
        case 1:
            Usuario(libros);
            //Pedidos(libros);
            break;
        case 2:
            if(AreYouTeacher() == 'y')
                AgregarLibros();
        break;
        default:
            system("cls");
            Roles_menu(libros);
        break;
    }
}