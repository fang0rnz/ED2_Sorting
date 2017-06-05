/* 
 * File:   main.c
 * Author: lmoraes
 *
 * Created on June 2, 2017, 11:29 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"
/*
 * 
 */
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char** argv) {
   /*
   FILE* file = abreArquivo("arquivoentrada.txt");
   printf("briuu");
   //Apague_Arquivo("arquivoentrada.txt");
   
   printf("ewwww");
   
   int values[] = { 40, 10, 100, 90, 20, 25 };
   
   int n;
  qsort (values, 6, sizeof(int),compare);
  
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
   */
    
    segregaArquivos("arquivoentrada.txt",3);
    
    //printf("%c",103);
    
   return (EXIT_SUCCESS);
}

