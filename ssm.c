/* 
 * File:   ssm.c
 * Author: Andrea Romanello     
 * 
 * Esercitazione 3 parte 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Struttura per immagazzinare la sequenza di somme 
 */
struct SegmentoStruct {
    int somma;
    int inizio;
    int fine;
};

typedef struct SegmentoStruct* Segmento;

int maxPeriodoGelo(int [], int);
int sm(int [], int);
Segmento nuovoSegmento(int, int, int);
Segmento ssm(int [], int);
void riempiArrayCasuale(int [], int, signed int, signed int);
void print(int [], int);

/**
 * riempie un array di numeri casuali compresi tra min e max
 * @param a array
 * @param length lunghezza array
 * @param min valore minim
 * @param max valore massimo
 */
void riempiArrayCasuale(int a[], int length, int min, int max) {
    int i;

    srand(time(NULL));

    for (i = 0; i < length; i++)
        a[i] = ((rand() % (max - min)) + min);
}

/**
 * questa funzione stampa l'array
 * @param a array
 * @param length lunghezza array
 */
void print(int a[], int length) {
    int i;
    printf("stampo l'array\n");
    for (i = 0; i < length; i++) {
        printf("%d-->", a[i]);
    }
    printf("\n");
}

/**
 * questa funzione restituisce il numero massimo di valori negativi consecutivi
 * @param a array
 * @param length lunghezza dell'array
 * @return numero massimo di elementi negativi
 */
int maxPeriodoGelo(int a[], int length) {
    int max, temp, i;
    max = temp = 0;

    for (i = 0; i < length; i++) {
        if (a[i] < 0) {
            temp++;
            if (temp > max)
                max = temp;
        } else {
            temp = 0;
        }
    }
    return max;
}

/**
 * somma massima degli elementi dell'array
 * @param a array
 * @param length lunghezza array
 * @return somma massima
 */
int sm(int a[], int length){
    int somma, max, i, j;
    max = somma = a[0];
    
    for(i=0; i<length; i++){
        somma = a[i];
        
        for(j=i; j<length; j++){
            if(i!=j)
                somma = somma + a[j];
            
            if(somma>max){
                max = somma;
            }
        }
    }
    return max;
}
 
/**
 * crea un segmento assegnando alle variabili la somma l'indice dell'inizio
 * e della fine
 * @param sm somma
 * @param i inizio
 * @param f fine
 * @return segmento creato
 */
Segmento nuovoSegmento(int sm, int i, int f){
    Segmento s;
    
    if(s = malloc(sizeof(Segmento))){
        exit(EXIT_FAILURE);
    }
    s->somma = sm;
    s->inizio = i;
    s->fine = f;
    
    return s;
}

/**
 * questo metodo restituisce il segmento di somma massima
 * @param a array
 * @param length lunghezza array
 * @return segmento di somma massima
 */
Segmento ssm(int a[], int length){
    Segmento s;
    int somma, i, j;
    somma = a[0];
    
    s = nuovoSegmento(somma, i, j);
    return s;
}

/**
 * main del programma
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    int length, periodo;
    length = 10;

    int min = -10;
    int max = 10;

    int a[length];

    printf("stampo min + max ");
    printf("%d\n", max + min);

    printf("entro in riempi casuale\n");
    riempiArrayCasuale(a, length, min, max);

    print(a, length);

    periodo = maxPeriodoGelo(a, length);

    printf("\n\nil max periodo di gelo e' %d", periodo);

    return (EXIT_SUCCESS);
}

