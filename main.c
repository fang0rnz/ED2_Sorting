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
    tic = clock();//inicia a contagem do tempo

    //OrdeneExterno();
    
    elapsedTime();
    

   return (EXIT_SUCCESS);
}

