#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 256

void histogramaCaracteres() {
    char archivo[] = "texto de prueb.txt";
    FILE *file;
    int c;
    int frequencia_caracter[MAX_CHAR] = {0};
    int contador_caracter = 0;

    file = fopen(archivo, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(file)) != EOF) {
        if (c >= 0 && c < MAX_CHAR) {
            frequencia_caracter[c]++;
        } else {
            contador_caracter++;
        }
    }

    fclose(file);

    printf("Histograma de caracteres ASCII:\n");
    for (int i = 0; i < MAX_CHAR; i++) {
        if (frequencia_caracter[i] > 0) {
            printf("'%c' (%d): %d veces\n", i, i, frequencia_caracter[i]);
        }
    }
    if (contador_caracter > 0) {
        printf("Caracteres posiblemente multibyte detectados: %d veces\n", contador_caracter);
    }
} 