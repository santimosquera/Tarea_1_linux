
//importamos interfaz de entrada y salida.
#include <stdio.h>

//importamos las intefaces en los directortorios actuales.
#include "Base.h"
#include "TexHist.h"

int main() {
    int opcion; // variable para guadar las seleccion del menu.

    // imprime el menu para seleccionar el punto 2 o el punto 3 de la tarea.
    printf("Seleccione una opción:\n");
    printf("1. Generar histograma de caracteres de un archivo\n");
    printf("2. Convertir números entre diferentes bases\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    //creamos el menu para la seleccion de punto 2 o punto 3.
    switch(opcion) {
        // creamos la opcion 1 para el punto 2.
        case 1:  
            histogramaCaracteres();
            break;
        // creamos la opcion 2 para el punto 3.
        case 2:
            conversionBases();
            break;
        // En caso de que no se seleccione una opcion valida.
        default:
            printf("Opción no válida.\n");
    }

    return 0; // finalizamos el programa.
}
