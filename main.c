#include <stdio.h>
#include <stdlib.h>

int main(){

    int matriz_a_linha = 4;
    int matriz_a_coluna = 4;

    int matriz_b_linha = 4;
    int matriz_b_coluna = 4;

    // Cria matriz A
    int **matriz_a = (int **)malloc(matriz_a_linha * sizeof(int *));

    for (int i = 0; i < matriz_a_linha; i++) {
        matriz_a[i] = (int *)malloc(matriz_a_coluna * sizeof(int));
    }

    int a_counter = 1;
    for (int i = 0; i < matriz_a_linha; i++) {
        for (int j = 0; j < matriz_a_coluna; j++) {
            matriz_a[i][j] = a_counter;
            a_counter++;
        }
    }

    // Cria matriz B
    int **matriz_b = (int **)malloc(matriz_b_linha * sizeof(int *));

    for (int i = 0; i < matriz_b_linha; i++) {
        matriz_b[i] = (int *)malloc(matriz_b_coluna * sizeof(int));
    }

    int b_counter = 2;
    for (int i = 0; i < matriz_b_linha; i++) {
        for (int j = 0; j < matriz_b_coluna; j++) {
            matriz_b[i][j] = b_counter;
            b_counter++;
        }
    }

    // Matriz resuldado

    int **matriz_resultado = (int **)malloc(matriz_a_linha * sizeof(int *));

    for (int i = 0; i < matriz_a_linha; i++) {
        matriz_resultado[i] = (int *)malloc(matriz_b_coluna * sizeof(int));
    }

    for (int i = 0; i < matriz_a_linha; i++) {
        for (int j = 0; j < matriz_b_coluna; j++) {
            matriz_resultado[i][j] = 0;
            for(int k = 0; k < matriz_a_linha; k++){
                matriz_resultado[i][j] += matriz_a[i][k] * matriz_b[k][j];
            }
        }
    }


    for (int i = 0; i < matriz_a_linha; i++) {
        for (int j = 0; j < matriz_b_coluna; j++) {
            printf("[");
            if(matriz_a[i][j] < 100) printf("0");
            if(matriz_a[i][j] < 10) printf("0");
            printf("%d] ", matriz_a[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < matriz_a_linha; i++) {
        for (int j = 0; j < matriz_b_coluna; j++) {
            printf("[");
            if(matriz_b[i][j] < 100) printf("0");
            if(matriz_b[i][j] < 10) printf("0");
            printf("%d] ", matriz_b[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < matriz_a_linha; i++) {
        for (int j = 0; j < matriz_b_coluna; j++) {
            printf("[");
            if(matriz_resultado[i][j] < 100) printf("0");
            if(matriz_resultado[i][j] < 10) printf("0");
            printf("%d] ", matriz_resultado[i][j]);
        }
        printf("\n");
    }

    return 1;
}
