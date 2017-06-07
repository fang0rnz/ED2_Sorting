#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "ordena.h"

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
#define NREGISTERS(x)  (sizeof(x) / 32)
#define REGISTROS 3

typedef FILE* ArqEntradaTipo;

int EnchePaginas(int a,ArqEntradaTipo b){
    
}

ArqEntradaTipo AbreArqSaida(int a){
    ArqEntradaTipo arq;
    char* nome = malloc  (sizeof (char)*30);
    sprintf (nome, "%d.bin",a); 
    arq = fopen(nome, "w+");
    return arq;
   
}

void DescarregaPaginas(ArqEntradaTipo arq){
    
}

void AbreArqEntrada(ArqEntradaTipo* ar, int low,int lim){
    printf("\n NA FUNCAO ABREARQUIVO, LOW FOI ENTREGUE COMO %d E LIM COMO %d", low, lim);
    int i;
    char nome[100];
    ArqEntradaTipo arquivo;
    int count = 0;
    for (i=low; i<=lim; i++){
        snprintf (nome, 100, "%d.bin", i);
        printf("\n%s aberto", nome);
        arquivo = fopen(nome, "r");
        ar[count] = arquivo;
        count++;
    }
    
}
void IntercaleGeral(ArqEntradaTipo* entry,int a,int b,ArqEntradaTipo exitfile){
    int vectorsize = b-a+1, i;
    Registro32 auxvector[vectorsize];
    Registro32 regmin;
    regmin.chave = CHAR_MAX;
    int intmin;
    
    for (i=0; i<vectorsize; i++){   //Setta todas as chaves do vetor auxiliar para o minimo
        auxvector[i].chave = CHAR_MIN;
    }
    
    for (i=0; i<vectorsize; i++){
        if (auxvector[i].chave < regmin.chave){
            if (feof(entry[i]))
                auxvector[i].chave = CHAR_MAX;
            else{
                fread(&auxvector[i], sizeof(Registro32), 1, entry[i]);
                intmin = i;
                regmin = auxvector[i];
            }
        }
    }
    
}

void Intercale(ArqEntradaTipo* entry,int a,int b,ArqEntradaTipo exitfile){
       Registro32 exitreg;
       Registro32 reg1;
       Registro32 reg2;
       int turnA = 1;
       int turnB = 1;
       int exit = 0;
       printf("\n***%d***\n", b-a+1);
//       int fimA = feof(entry[b]);
//       int fimB = feof(entry[b]);
       while (!(feof(entry[0]) && feof(entry[1]))){
//           fimA = feof(entry[a]);
//           fimB = feof(entry[b]);
           if (turnA){
            fread(&reg1, sizeof(Registro32), 1, entry[0]);
            if (feof(entry[0]) ){
//                printf("\nentrou1\n");
//                fread(&reg1, sizeof(Registro32), 1, entry[b]);
                reg1.chave = CHAR_MAX;
            }
           }
           if(turnB){
            fread(&reg2, sizeof(Registro32), 1, entry[1]);
                if (feof(entry[1])){
//                    fread(&reg2, sizeof(Registro32), 1, entry[a]);
//                    printf("\nentrou\n");
                    reg2.chave = CHAR_MAX;
                }
           }
           printf("\nCOMPARANDO %c & %c", reg1.chave, reg2.chave);
           exitreg = MinimoReg32(reg1, reg2, &turnA, &turnB);
           
           printf("\n turnA eh %d e turnB eh %d", turnA, turnB);
           if (exitreg.chave != CHAR_MAX)
            fwrite(&exitreg, sizeof(Registro32), 1, exitfile);
//                      fimA = feof(entry[a]);
//           fimB = feof(entry[b]);
           printf("\nMENOR CHAVE eh %c", exitreg.chave);
       }
       printf("\nCHAVES DENTRO DO ARQUIVO DE SAIDA:");
       rewind(exitfile);
      while(!feof(exitfile)){
           Registro32 reg;
           printf("%c ", reg.chave);
           fread(&reg, sizeof(Registro32), 1, exitfile);
           
           
           
       } 
 
       
       
       
}
Registro32 MinimoReg32 (Registro32 first, Registro32 second, int *turnA, int *turnB){
    
    if (first.chave <= second.chave){
        *turnA = 1; *turnB = 0;
        return first;
    }
    else {
        *turnA = 0; *turnB = 1;
        return second;
    }
    }

int Minimo(int low,int high){
    if (low<=high)
        return low;
    else
        return high;
        
}

void ApagaArquivo(char* fileName){
    int flag;
    
    flag = remove(fileName);
    
    if(flag==0){
        printf("arquivo deletado com sucesso!");
    }else{
        printf("erro ao deletar o arquivo.");
    }
}

ArqEntradaTipo abreArquivo(char* fileName){
    FILE* file = fopen(fileName,"r");
    
    if(file!=NULL){
        return file;
    }
    
    printf("arquivo nao localizado ou com falhas");
}

void OrdeneExterno(){
    int OrdemIntercalacao=2;
    
    int NBlocos = 0;
    
    int i;
    
    ArqEntradaTipo ArqEntrada, ArqSaida;
    
    ArqEntradaTipo ArrArqEnt[OrdemIntercalacao];
    
    short Fim;
    
    int Low, High, Lim;
    
    NBlocos = 0;
    
    segregaArquivos("arquivoentrada.txt", 3, &NBlocos);
    
    
    Low = 0;
    printf ("%d", NBlocos);
    High = NBlocos-1;
//    Lim = Minimo(Low + OrdemIntercalacao -1, High);
//    
//    AbreArqEntrada(ArrArqEnt, Low, Lim);
//    ArqSaida = AbreArqSaida(High+1);
//        Registro32* reg;
//        reg = (Registro32 *) malloc(sizeof(Registro32)*3);
//        fread(reg, sizeof(Registro32), 3, ArrArqEnt[0]);
//        printf("\nPrimeira chave do arquivo eh %c", reg[0].chave);
//        printf("\n ArrArqEnt tem %d elementos no vetor", NELEMS(ArrArqEnt));
//        free(reg);
//        fseek(ArrArqEnt[0], 0, SEEK_END); // seek to end of file
//        int size = ftell(ArrArqEnt[0]); // get current file pointer
//        rewind(ArrArqEnt[0]); // seek back to beginning of file
//        printf("\n size is %d bytes", size);
//        Intercale(ArrArqEnt, Low, Lim, ArqSaida);
//    
    
    while (Low < High){ /* Intercalacao dos NBlocos ordenados */ 
        
          
       Lim = Minimo(Low + OrdemIntercalacao -1, High);
        printf ("\nAbreArqEntrada sendo chamado com low=%d, lim=%d, high=%d\n", Low, Lim, High);
       AbreArqEntrada(ArrArqEnt, Low, Lim); //abre array de n arquivos, sendo o primeiro low, 
        printf ("\nDepois AbreArqEnt low=%d, lim=%d, high=%d\n", Low, Lim, High);
       High++;
    
       ArqSaida = AbreArqSaida(High);

//       Registro32* reg;
//       reg = (Registro32 *) malloc(sizeof(Registro32)*3);
//       
//       fread(reg, sizeof(Registro32), 3, ArrArqEnt[1]);
//       printf("\n%c\n", reg[0].chave);
       
   
       printf ("\nIntercale sendo chamado com low=%d, lim=%d, high=%d\n", Low, Lim, High);
        Intercale(ArrArqEnt, Low, Lim, ArqSaida);
    
        fclose(ArqSaida);
        
        int count=0;
        for(i= Low; i <= Lim; i++){
            
            fclose(ArrArqEnt[count]);
            count++;

       } 

            //Apague_Arquivo(ArrArqEnt[i]);
    
    Low += OrdemIntercalacao;
    
    }
    
    //Mudar o nome do arquivo High para o nome fornecido pelo usuario;
    
//    }
}

int comparaRegistro32(const void* a, const void* b){
    Registro32 a1;
    Registro32 b1;
    a1 = *(Registro32*)a;
    b1 = *(Registro32*)b;
    return a1.chave-b1.chave;
}

void segregaArquivos(char* arquivoEntrada,int numeroRegistros, int *NBlocos){
    FILE* file = abreArquivo(arquivoEntrada);
    FILE* output;
    char a;
    Registro32 vet[numeroRegistros];
    int count=0;
    
    int var = 0;  //var = numero pra referencia no arquivo
    
    char* nome = malloc  (sizeof (char)*30);
    
    
    while(!feof(file)){
       fscanf(file,"%c ",&a);//ignora o \n no final\n
       vet[count].chave=a;
       count++;
       
       if(count==numeroRegistros){
           
           
           //char cast = (char)var;
           sprintf (nome, "%d.bin",var);
           output = fopen(nome,"w");
           qsort(vet, count, sizeof(Registro32), comparaRegistro32);
           fwrite(vet,sizeof(Registro32),count,output);//escreve todo o vetor de uma vez no arquivo
           
           fclose(output);
           output = fopen(nome,"r");
           fread(vet,sizeof(Registro32),count,output);
           int i = 0;
           for(i=0;i<count;i++)
           printf("%c",vet[i].chave);
           count=0;
           var++;   //seta var sempre o proximo registro de arquivo
           printf("\n");
       }
    }
    
    //dumpa o resto do buffer
    if (count!=0){

    sprintf (nome, "%d.bin",var);
      var++;  
    
    output = fopen(nome,"w");
    
    //int i;
    //for (i = 0; i < count; i++) {
        //a=vet[i].chave;
    qsort(vet, count, sizeof(Registro32), comparaRegistro32);
    fwrite(vet,sizeof(Registro32),count,output);
        int i;
        for (i = 0; i < count; i++) {
            printf("%c",vet[i].chave);
        }
        //putc(a,output);

    //}
    }
    //fecha os arquivos, libera memoria alocada para o nome do arquivo e apaga o arquivo de entrada
    
    *NBlocos = var;
    
    fclose(output);
    fclose(file);
    free(nome);

    
    //remove(arquivoEntrada);
}