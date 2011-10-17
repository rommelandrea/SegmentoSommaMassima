/* 
 * File:   ssm.c
 * Author: Andrea Romanello     
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN -10
#define MAX 10

/*
 * 
 */
struct SegmentoStruct{
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

void riempiArrayCasuale(int a[], int length, signed int max, signed int min){
    int i;
    
    srand(time(NULL));
    
    for(i=0; i<length; i++)
        a[i] = (rand()%(max+min))-min;
}

void print(int a[], int length){
    int i;
    printf("stampo l'array\n");
    for(i=0; i<length; i++){
        printf("%d-->", a[i]);
    }
    printf("\n");
}

int maxPeriodoGelo(int a[], int length){
    int max, temp, i, j = 0;
    
    for(i=0; i<length; i++){
        for(j=i; j<length; j++){
            if(a[j]<0){
                temp++;
                if(temp>max)
                    max=temp;
            }else{
                temp = 0;
            }
        }
    }
    
    return max;
}

int main(int argc, char** argv) {
    int length;
    length = 10;
    
    signed int min = -10;
    signed int max = 10;
    
    signed int a[length];
    
    printf("%d", max+min);
    
    riempiArrayCasuale(a, length, min, max);
    
    //print(a, length);
    
    return (EXIT_SUCCESS);
}

