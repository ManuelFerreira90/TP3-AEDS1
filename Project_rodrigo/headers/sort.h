#ifndef sort_h
#define sort_h

#include "TADdicionario.h"

void imprimir(TPalavra *v,int tam);
void bubblesort(ListaPala *lp);
void insertionsort(ListaPala *lp);
void selectionsort(ListaPala *lp);
void metodoheap(int *v,int tam, int i);
void heapsort(int *v, int tam);
void shellsort(int *v, int tam);
int metodoquicksort(int *v,int left,int right);
void quicksort(int *v,int left,int right);
void metodomerge(int *v,int *vaux,int inicio,int meio, int fim);

#endif