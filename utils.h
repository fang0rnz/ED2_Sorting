/* 
 * File:   utils.h
 * Author: gferreira
 *
 * Created on June 8, 2017, 1:25 PM
 */

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    
    
clock_t tic;

void elapsedTime(){
  clock_t toc = clock();
  printf("\n\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}

void geraArquivo(int potenciaDois,char* nomeArquivo){
   int i, n;
   time_t t;
   
   n = pow(2,potenciaDois);
   
   FILE*fp = fopen(nomeArquivo,"w");
   
   
   srand((unsigned) time(&t));

   
   for( i = 0 ; i < n ; i++ ) 
   {
      fprintf(fp,"%d\n", rand() % 1000000000);
   }
    
   fclose(fp);
}
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

