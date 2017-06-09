/* 
 * File:   main.c
 * Author: lmoraes
 *
 * Created on June 2, 2017, 11:29 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
 #include <sys/time.h>

#include "ordena.h"
#include "utils.h"
/*
 * 
 */
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main(int argc, char** argv) { 
    struct timeval inicio;
    struct timeval final;
   
    int i= 0;
    double total = 0.0;
    double tempoSeconds = 0.0;
 
    gettimeofday(&inicio, NULL);
    

    OrdeneExterno();

    
    gettimeofday(&final, NULL);
    
    
    tempoSeconds = final.tv_sec - inicio.tv_sec + ((final.tv_usec - inicio.tv_usec)/1000000.0); 
    printf("\nExecucao em: %lf segundos", tempoSeconds);
   return (EXIT_SUCCESS);
}

