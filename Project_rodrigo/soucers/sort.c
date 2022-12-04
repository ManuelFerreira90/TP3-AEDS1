#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/sort.h"


//imprimir elementos
void imprimir(TPalavra *v,int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("%s\n",v[i].item);
    }
    printf("\n");
}

//bubbler sort
void bubblesort(ListaPala *lp){
    int i,j,p=1;
    int tam = lp->nroElem;
    TPalavra aux ;

    TPalavra vet[tam];
    copiaparaodernar(lp,vet);

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            while(vet[i].item[p] == vet[j].item[p] && (vet[i].item[p] && vet[j].item[p])){
                    p++;
            }

            if(vet[i].item[p] < vet[j].item[p]){
                
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                
            }p=1;
        }
    }
    
    printf("\nbubblesort:\n");
    imprimir(vet,tam);
}

//insertion sort
void insertionsort(ListaPala *lp){
    int i,j,p=1;
    int tam = lp->nroElem;
    TPalavra aux;

    TPalavra vet[tam];
    copiaparaodernar(lp,vet);

    for(i=1;i<tam;i++){
        aux = vet[i];
        j=i-1;

        while(vet[i].item[p] == vet[j].item[p] && (vet[i].item[p] && vet[j].item[p]))p++;

        while(j>=0 && vet[j].item[p] > aux.item[p]){
            vet[j+1] = vet[j];
            j--;
            p = 1;
        }
        vet[j+1] = aux;
    }

    printf("\ninsertionsort:\n");
    imprimir(vet, tam);
    
    return;
}

//selection sort
void selectionsort(ListaPala *lp){
    int i,j,p=1,min;
    int tam = lp->nroElem;
    TPalavra aux;

    TPalavra vet[tam];
    copiaparaodernar(lp,vet);

    for(i=0;i<tam;i++){
        min=i;
        for(j=i+1;j<tam;j++){
            while(vet[min].item[p] == vet[j].item[p] && (vet[min].item[p] && vet[j].item[p])) p++;
            if(vet[j].item[p]<vet[min].item[p]) min=j;

            p = 1;
        }
        aux=vet[min];
        vet[min] = vet[i];
        vet[i] = aux;
    }

    printf("selectionsort:\n");
    imprimir(vet, tam);
    
    return;
}

//heap sort
void metodoheap(int *v,int tam, int i){
    int raiz = i, esquerda = (2*i)+1, direita = (2*i)+2,aux;
    if(esquerda < tam && v[esquerda] > v[raiz]) raiz = esquerda;
    if(direita < tam && v[direita] > v[raiz]) raiz = direita;
    if(raiz!=i){
        aux=v[i];
        v[i]=v[raiz];
        v[raiz]=aux;
        metodoheap(v,tam,raiz);
    }
}

void heapsort(int *v, int tam){
    int i,j,aux;
    for(i=tam/2-1;i>=0;i--){
        metodoheap(v,tam,i);
    }
    for(j=tam-1;j>0;j--){
        aux = v[0];
        v[0] = v[j];
        v[j] = aux;
        metodoheap(v,j,0);
    }

    printf("heapsort:\n");
    //imprimir(v, tam);

    return;
}

//shell sort
void shellsort(int *v, int tam){
    int h,i,var,j;
    while(h<tam){
        h=h*3+1;
    }
    h = h / 3;
    while(h>0){
        for(i=h;i<tam;i++){
            var = v[i];
            j = i;
            while(j>=h && v[j-h]>var){
                v[j] = v[j-h];
                j = j-h; 
            }
            v[j]=var;
        }
        h=h/2;
    }    

    printf("shellsort:\n");
    //imprimir(v, tam);
    
    return;
}

//quicksort
int metodoquicksort(int *v,int left,int right){
    int meio = (left + right) / 2;
    int i = left - 1;
    int j = right + 1;
    int pivo = v[meio],aux;
    while(1){
        do{
            i++;
        }while(v[i]<pivo);
        do{
            j--;
        }while(v[j]>pivo);
        if(i>=j) return j;
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        
    }
}

void quicksort(int *v,int left,int right){
    int var;
    if(left < right){
        var = metodoquicksort(v,left,right);
        quicksort(v,left,var);
        quicksort(v,var+1,right);
    }
    
    return;
}

//merge sort
void metodomerge(int *v,int *vaux,int inicio,int meio, int fim){
    int i,j=0,k=0;
    for(i=inicio;i<=fim;i++) vaux[i] = v[i];
    j=inicio;
    k=meio+1;
    for(i=inicio;i<=fim;i++){
    	if(j>meio) v[i] = vaux[k++];
    	else if(k>fim) v[i] =vaux[j++];
    	else if(vaux[j] < vaux[k]) v[i] = vaux[j++];
    	else v[i] = vaux[k++]; 
    }	
    
    return;
}

void mergesort(int *v,int *vaux,int inicio,int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergesort(v,vaux,inicio,meio);
        mergesort(v,vaux,meio+1,fim);
        metodomerge(v,vaux,inicio,meio,fim);
    }
}

