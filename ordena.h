#ifndef ORDENA_H
#define	ORDENA_H

#ifdef	__cplusplus
extern "C" {
#endif
  
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
    

typedef FILE* ArqEntradaTipo;

typedef struct {
    char conteudo[31];
    char chave;
}Registro32;

int EnchePaginas(int a,ArqEntradaTipo b);

ArqEntradaTipo AbreArqSaida(int a);


void DescarregaPaginas(ArqEntradaTipo arq);

void AbreArqEntrada(ArqEntradaTipo* ar, int lim,int low);

void Intercale(ArqEntradaTipo* entrada,int a,int b,ArqEntradaTipo saida);

void segregaArquivos(char* arquivoEntrada,int numeroRegistros, int *NBlocos);

Registro32 MinimoReg32 (Registro32 first, Registro32 second,  int *turnA, int *turnB);

int Minimo(int low,int high);

void ApagaArquivo(char* fileName);//ok
    
ArqEntradaTipo abreArquivo(char* fileName);//ok

void OrdeneExterno(); 

#ifdef	__cplusplus
}
#endif

#endif	/* ORDENA_H */

