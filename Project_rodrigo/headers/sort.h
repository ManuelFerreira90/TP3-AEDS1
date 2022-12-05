#ifndef sort_h
#define sort_h

#include "TADdicionario.h"

void imprimir(TPalavra *v,int tam);
void bubblesort(ListaPala *lp);
void insertionsort(ListaPala *lp);
void selectionsort(ListaPala *lp);
void metodoheap(int *v,int tam, int i);
void heapsort(int *v, int tam);
void shellsort(ListaPala *lp);
void particaoQ(int esq, int dir, int *j, int *i,TPalavra *vet);
void ordenaQ(int esq, int dir, TPalavra *vet);
void quicksort(ListaPala *lp);
void metodomerge(int *v,int *vaux,int inicio,int meio, int fim);

#endif