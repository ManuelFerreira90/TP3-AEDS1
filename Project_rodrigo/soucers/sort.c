#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
    clock_t start, end;

    int i,j,p=1;
    int tam = lp->nroElem;
    TPalavra aux ;

    TPalavra vet[tam];
    copiaparaodernar(lp,vet);
    
    double time;
    start = clock();
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
    end = clock();
    
    printf("\nbubblesort:\n");
    imprimir(vet,tam);

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f seg\n",time);
}

//insertion sort
void insertionsort(ListaPala *lp){
    clock_t start, end;

    int i,j,p=1;
    int tam = lp->nroElem;
    double time;
    TPalavra aux;

    TPalavra vet[tam];
    copiaparaodernar(lp,vet);

    start = clock();
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
    end = clock();

    printf("\ninsertionsort:\n");
    imprimir(vet, tam);

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("tempo de execucao: %f\n",time);
}

//selection sort
void selectionsort(ListaPala *lp){
    clock_t start, end;

    int i,j,p=1,min;
    int tam = lp->nroElem;
    double time;
    TPalavra aux;

    TPalavra vet[tam];
    copiaparaodernar(lp,vet);

    start = clock();
    for(i=0;i<tam;i++){
        min=i;
        for(j=i+1;j<tam;j++){
            while(vet[min].item[p] == vet[j].item[p] && (vet[min].item[p] && vet[j].item[p])) p++;
            if(vet[j].item[p]<vet[min].item[p]) min = j;

            p = 1;
        }
        aux=vet[min];
        vet[min] = vet[i];
        vet[i] = aux;
    }
    end = clock();

    printf("s\nelectionsort:\n");
    imprimir(vet, tam);
    
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("tempo de execucao: %f\n",time);
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
void shellsort(ListaPala *lp){
    clock_t start, end;

    int h,i,var,j,p=1;
    int tam = lp->nroElem;
    double time;
    TPalavra aux;

    TPalavra vet[tam];
    copiaparaodernar(lp,vet);
    
    start = clock();
    if(sizeof(vet) < 1){
        while(h<tam){
            h=h*3+1;
        }
        
        do{
            h = h / 3;
            for(i=h;i<tam;i++){
                aux = vet[i];
                j = i;


                while(vet[j-h].item[p] == aux.item[p] && (vet[j-h].item[p] && aux.item[p])) p++; 
                
                while(vet[j-h].item[p] > aux.item[p]){  
                    
                    vet[j] = vet[j-h];
                    
                    j = j-h;
                    if(j>=h){
                        p=1;
                        while(vet[j-h].item[p] == aux.item[p] && (vet[j-h].item[p] && aux.item[p])) p++;
                    }
                    if(j < h)break;
                }
                p=1;
                vet[j] = aux;
            } 
        }while(h != 1);
    }
    end = clock();
        

    printf("\nshellsort:\n");
    imprimir(vet, tam);

    time = (double)(end - start) /CLOCKS_PER_SEC;
    printf("tempo de execucao: %f\n",time);
    
    return;
}

//quicksort ****nao******
void particaoQ(int esq, int dir, int *j, int *i,TPalavra *vet){
    int p=1,q=1;
    TPalavra pivo,aux;
    *i = esq; *j = dir;
    pivo = vet[(*i+*j)/2];

    do{
        //while(vet[*i].item[p] == pivo.item[p] && (vet[*i].item[p] && pivo.item[p])) p++; 
        while (pivo.item[p] > vet[*i].item[p]) (*i)++;
        
        //while(vet[*j].item[q] == pivo.item[q] && (vet[*j].item[q] && pivo.item[q])) q++; 
        while (pivo.item[q] < vet[*j].item[q]) (*j)--;

        printf("%d %d %s,",*i,*j,pivo.item);
        if (*i <= *j){
            aux = vet[*i]; 
            vet[*i] = vet[*j]; 
            vet[*j] = aux;
            (*i)++; (*j)--;
            
        }
        
    }while (*i <= *j);
}


void ordenaQ(int esq, int dir, TPalavra *vet){
    int i,j;

    particaoQ(esq,dir,&i,&j,vet);
    //if(esq < j)ordenaQ(esq,j,vet);
    //if(i < dir)ordenaQ(i,dir,vet);
}


void quicksort(ListaPala *lp){
    int esq = 1;
    int dir = lp->nroElem-1;
    int tam = lp->nroElem;
    
    TPalavra vet[tam];
    copiaparaodernar(lp,vet);

    ordenaQ(esq,dir,vet);

    imprimir(vet,tam);
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

