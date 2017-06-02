/* 
 * File:   ordena.h
 * Author: gferreira
 *
 * Created on June 2, 2017, 2:35 PM
 */

#ifndef ORDENA_H
#define	ORDENA_H

#ifdef	__cplusplus
extern "C" {
#endif


    
struct arqEntrada{
    
};

typedef struct arqEntrada ArqEntradaTipo;

int EnchePaginas(int a,ArqEntradaTipo b);

ArqEntradaTipo AbreArqSaida(int a);

void DescarregaPaginas(int n);

void AbreArqEntrada(ArqEntradaTipo* ar, int lim,int low);

void Intercale(ArqEntradaTipo* entrada,int a,ArqEntradaTipo saida);

int Minimo(int low,int high);

void Apague_Arquivo(ArqEntradaTipo* ar);
    
    
  
#ifdef	__cplusplus
}
#endif

#endif	/* ORDENA_H */

