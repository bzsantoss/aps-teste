#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "alg.h"

// Função para esperar pela entrada do usuário (pressionar Enter)
void waitForEnter() {
    printf("\nPressione Enter para continuar...");
    fflush(stdin); // Limpa o buffer de entrada
    getchar();     // Aguarda o pressionamento de Enter
}

// Função para imprimir o tipo de ordenação
void printSortType(const char *sortType) {
    printf("\n===========================================\n");
    printf("Ordenacao em %s: \n", sortType);
    printf("===========================================\n");
}

// Função para imprimir resultados dos algoritmos
void printResults(clock_t totalTime, const char *algorithmName) {
    printf("-------------------------------------------\n");
    printf("Tempo total para %s: %f segundos\n", algorithmName, ((double)totalTime) / CLOCKS_PER_SEC);
    printf("-------------------------------------------\n");
}

// Algoritmos de Ordenação
void MyQuickSort(int *array, int size) {
    int endIndex = size, currentIndex;
    if (size <= 1) {
        return;
    } else {
        int pivot = array[0];
        int leftIndex = 1;
        int rightIndex = size - 1;

        do {
            while ((leftIndex < size) && (array[leftIndex] <= pivot)) {
                leftIndex++;
            }

            while (array[rightIndex] > pivot) {
                rightIndex--;
            }

            if (leftIndex < rightIndex) { // faz troca
                int temp = array[leftIndex];
                array[leftIndex] = array[rightIndex];
                array[rightIndex] = temp;
                leftIndex++;
                rightIndex--;
            }

            for (currentIndex = 0; currentIndex < endIndex; currentIndex++) {
                printf("%d ", array[currentIndex]);
            }
            printf("\n");
        } while (leftIndex <= rightIndex);

        // troca pivo
        array[0] = array[rightIndex];
        array[rightIndex] = pivot;

        // Ordena sub-vetores restantes
        // Recursividade
        MyQuickSort(array, rightIndex);
        MyQuickSort(&array[leftIndex], size - leftIndex);
        for (currentIndex = 0; currentIndex < endIndex; currentIndex++) {
            printf("%d ", array[currentIndex]);
        }
        printf("\n");
    }
}

void MySelectionSort(int *array, int size) {
    int i, j, k, min;
    for (i = 0; i < (size - 1); i++) {
        min = i;
        for (j = (i + 1); j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (i != min) {
            int swap = array[i];
            array[i] = array[min];
            array[min] = swap;
            for (k = 0; k < size; k++) {
                printf("%d ", array[k]);
            }
            printf("\n");
        }
    }
}

void MyBubbleSort(int *array, int size) {
    int i, j = size, k;
    int swapped;
    do {
        size--;
        swapped = 0;
        for (i = 0; i < size; i++) {
            if (array[i] > array[i + 1]) {
                int temp = 0;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
                for (k = 0; k < j; k++) {
                    printf("%d ", array[k]);
                }
                printf("\n");

                waitForEnter(); // Aguarda a entrada do usuário após cada etapa
            }
        }
    } while (swapped);
}

// Gerador de Dados Aleatórios
void MyDataGenerator(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

// Imprime o array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    printf("############## Sistema de controle do Geoprocessamento da Floresta Amazonica ##############\n\n");
    printf("Este programa tem como objetivo utilizar as imagens geradas pelos satélites da floresta \nAmazonica já catalogadas e ordena-las. Para isso, são utilizados três métodos de ordenação,\nonde cada um tem sua singularidade.\n\n\n");

    const int array_size = 15;
    int originalArray[array_size];
    srand(time(NULL));
    for (int i = 0; i < array_size; i++) {
        originalArray[i] = rand() % 100;
    }

    printf("\nVetor Original: ");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", originalArray[i]);
    }

    int tempArray[array_size];
    for (int i = 0; i < array_size; i++) {
        tempArray[i] = originalArray[i];
    }

    // Ordena os dados antes de imprimir e medir o tempo
    clock_t sortTime;

    printSortType("QuickSort");
    sortTime = clock();
    MyQuickSort(tempArray, array_size);
    sortTime = clock() - sortTime;
    printResults(sortTime, "QuickSort");

    // Reinicializa o vetor temporário
    for (int i = 0; i < array_size; i++) {
        tempArray[i] = originalArray[i];
    }

    printSortType("SelectionSort");
    sortTime = clock();
    MySelectionSort(tempArray, array_size);
    sortTime = clock() - sortTime;
    printResults(sortTime, "SelectionSort");

    // Reinicializa o vetor temporário
    for (int i = 0; i < array_size; i++) {
        tempArray[i] = originalArray[i];
    }

    printSortType("BubbleSort");
    sortTime = clock();
    MyBubbleSort(tempArray, array_size);
    sortTime = clock() - sortTime;
    printResults(sortTime, "BubbleSort");

    printf("\n-------------------------------------------\n");
    printf("\nPressione qualquer tecla para encerrar o programa: \n");
    printf("-------------------------------------------\n");
    waitForEnter();

    return 0; // Indica que o programa foi concluído com sucesso
}
