/* 
 * File:   ssm.c
 * Author: Andrea Romanello     
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct SegmentoStruct{
    int somma;
    int inizio;
    int fine;
};

typedef struct SegmentoStruct* Segmento;

Segmento nuovoSegmento(int, int, int);
Segmento ssm(int [], int);

int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

