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

    
    OrdeneExterno();
    
    //printf("%c",103);
    
   return (EXIT_SUCCESS);
}

