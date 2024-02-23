#include <math.h>
#include <stdio.h>
#include <string.h>

//Convierte un número representado como una cadena de caracteres en su equivalente en base 10.
long toBase10(char *num, int baseFrom) {
    long valor = 0;
    int longitud  = strlen(num);
    for(int i = 0; i < longitud ; i++) {
        if(num[i] >= '0' && num[i] <= '9') {
            valor += (num[i] - '0') * pow(baseFrom, longitud  - 1 - i);
        } else if(num[i] >= 'A' && num[i] <= 'F') {
            valor += (num[i] - 'A' + 10) * pow(baseFrom, longitud  - 1 - i);
        } else if(num[i] >= 'a' && num[i] <= 'f') {
            valor += (num[i] - 'a' + 10) * pow(baseFrom, longitud  - 1 - i);
        }
    }
    return valor;
}



// Función para convertir un número de base 10 a cualquier base
void fromBase10(long num, int baseTo, char *respuesta) {
    char digits[] = "0123456789ABCDEF";
    char buffer[50] = "";
    int i = 0;

    while(num > 0) {
        buffer[i++] = digits[num % baseTo];
        num /= baseTo;
    }

    if(i == 0) {
        strcpy(respuesta, "0");
    } else {
        // Invertir el resultado
        int j = 0;
        while(i > 0) {
            respuesta[j++] = buffer[--i];
        }
        respuesta[j] = '\0';
    }
}

//Realiza la conversión de un número de una base a otra.
void conversionBases() {
    char num[50];
    int baseFrom, baseTo;
    long numInBase10;
    char result[50];

    printf("Ingrese el número: ");
    scanf("%s", num);
    printf("Ingrese la base original (entre 2 y 16): ");
    scanf("%d", &baseFrom);
    printf("Ingrese la base a la cual convertir (entre 2 y 16): ");
    scanf("%d", &baseTo);

    if(baseFrom < 2 || baseFrom > 16 || baseTo < 2 || baseTo > 16) {
        printf("Las bases deben estar entre 2 y 16.\n");
        return;
    }

    numInBase10 = toBase10(num, baseFrom);
    fromBase10(numInBase10, baseTo, result);

    printf("El número %s en base %d es %s en base %d.\n", num, baseFrom, result, baseTo);
}
