#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ordena.h"

#define REGISTROS 3

typedef FILE* ArqEntradaTipo;

int EnchePaginas(int a,ArqEntradaTipo b){
    
}

ArqEntradaTipo AbreArqSaida(int a){
    
}

void DescarregaPaginas(ArqEntradaTipo arq){
    
}

void AbreArqEntrada(ArqEntradaTipo* ar, int low,int lim){
    int i;
    char* nome = malloc  (sizeof (char)*30);
    FILE* arquivo;
    printf("%d", lim);
    for (i=low; i<=lim; i++){
        sprintf (nome, "arquivo%d",i);
        printf(nome);
        arquivo = fopen(nome, "r");
        ar[i] = arquivo;
    }
    fclose(arquivo);
    free(nome);    
}

void Intercale(ArqEntradaTipo* entrada,int a,int b,ArqEntradaTipo saida){
    
    
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
    
    printf("\n%d", NBlocos);
    
    Low = 0;
    
    High = NBlocos-1;
    Lim = Minimo(Low + OrdemIntercalacao -1, High);
    
    AbreArqEntrada(ArrArqEnt, Low, Lim);
  
    
    
//    while (Low < High){ /* Intercalacao dos NBlocos ordenados */ 
//        
          
//        Lim = Minimo(Low + OrdemIntercalacao -1, High);
        
//        AbreArqEntrada(ArrArqEnt, Low, Lim); //abre array de n arquivos, sendo o primeiro low, 
//    
//        High++;
//    
//        ArqSaida = AbreArqSaida(High);
//    
//        Intercale(ArrArqEnt, Low, Lim, ArqSaida);
//    
//        fclose(ArqSaida);
//    
//        for(i= Low; i < Lim; i++){
//            fclose(ArrArqEnt[i]);
//    
//            //Apague_Arquivo(ArrArqEnt[i]);
//        }
//    
//    Low += OrdemIntercalacao;
//    
//    }
    
    //Mudar o nome do arquivo High para o nome fornecido pelo usuario;
    
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
           sprintf (nome, "arquivo%d",var);
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

    sprintf (nome, "arquivo%d",var);
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