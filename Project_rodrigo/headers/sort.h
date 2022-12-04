#ifndef sort_h
#define sort_h

#include "../headers/TADdicionario.h"

void imprimir(TPalavra *v,int tam);
void bolha(ListaPala *lp);
void insertionsort(int *v,int tam);
void selectionsort(int *v, int tam);
void metodoheap(int *v,int tam, int i);
void heapsort(int *v, int tam);
void shellsort(int *v, int tam);
int metodoquicksort(int *v,int left,int right);
void quicksort(int *v,int left,int right);
void metodomerge(int *v,int *vaux,int inicio,int meio, int fim);

#endif