#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "ordena.h"

//#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
//#define NREGISTERS(x)  (sizeof(x) / 32)


//262144
#define REGISTROS 16384
#define INTERCALACOES 4
#define ARQ_ENTRADA "entrada22"

typedef FILE* ArqEntradaTipo;

int EnchePaginas(int a,ArqEntradaTipo b){
    
}

//nao fecha o arquivo, mas a funçao so e chamada uma vez e o fecha
ArqEntradaTipo AbreArqSaida(int a){
    ArqEntradaTipo arq;
    //char* nome = malloc  (sizeof (char)*30);
    char nome[30];
    snprintf (nome,30, "%d.bin",a); 
    arq = fopen(nome, "w+");
    return arq;
   
}

void deletaArquivos(int a){
    char nome[30];
    snprintf (nome,30, "%d.bin",a);
    
    int flag;
    
    flag = remove(nome);
    
    if(flag==0){
        //printf("arquivo deletado com sucesso!");
    }else{
        printf("erro ao deletar o arquivo.");
    }
}

void DescarregaPaginas(ArqEntradaTipo arq){
    
}

void AbreArqEntrada(ArqEntradaTipo* ar, int low,int lim){
    //printf("\n NA FUNCAO ABREARQUIVO, LOW FOI ENTREGUE COMO %d E LIM COMO %d", low, lim);
    int i;
    char nome[100];
    ArqEntradaTipo arquivo;
    int count = 0;
    for (i=low; i<=lim; i++){
        snprintf (nome, 100, "%d.bin", i);
        //printf("\n%s aberto", nome);
        arquivo = fopen(nome, "r");
        ar[count] = arquivo;
        count++;   
    }
}
void IntercaleGeral(ArqEntradaTipo* entry,int a,int b,ArqEntradaTipo exitfile){
    int vectorsize = b-a+1, i;
    //printf("\nIntercaleGeral vectorsize: %d", vectorsize);
    Registro32 auxvector[vectorsize];
    Registro32 regmin;
    //regmin.chave = CHAR_MAX;
    regmin.chave = INT_MAX;
    int intmin;
    
    for (i=0; i<vectorsize; i++){   //Setta todas as chaves do vetor auxiliar para o minimo
        //auxvector[i].chave = CHAR_MIN;
        auxvector[i].chave = INT_MIN;
    }
    
    //char aux = CHAR_MAX;
    int aux = INT_MAX;
    for (i=0; i<vectorsize; i++){
        fread(&auxvector[i], sizeof(Registro32), 1, entry[i]);
        //printf("\nregistro minimo eh %c e o da vez eh %c", regmin.chave, auxvector[i].chave);
        if (auxvector[i].chave<regmin.chave){
            regmin = auxvector[i];
            intmin = i;
        }
        //printf("\n o menor registro eh %c, no arquivo[%d]", regmin.chave, intmin);
    }
    
    int allUnread = 1;
    int contsaida = 0;
    do{
        //printf("\nEscrevendo registro %c do arquivo [%d] na posicao [%d] do vetor saida", regmin.chave,intmin, contsaida++);        
        //if (regmin.chave != CHAR_MAX) //better safe than sorry
        if (regmin.chave != INT_MAX) //better safe than sorry
            fwrite(&regmin, sizeof(Registro32), 1, exitfile);
        //printf("\nSubstituindo registro %c por ", auxvector[intmin].chave);
        fread(&auxvector[intmin], sizeof(Registro32), 1, entry[intmin]);
        if (feof(entry[intmin])){
            //auxvector[intmin].chave = CHAR_MAX;
            auxvector[intmin].chave = INT_MAX;
        }
        //printf("%c na posicao %d do vetor auxiliar", auxvector[intmin].chave, intmin);
//        if (feof(entry[intmin])){
//            auxvector[intmin].chave = CHAR_MAX;
//        }
        
            intmin = MinIndex(auxvector, vectorsize);
//            printf("\nNOVO INTMIN VALE %d", intmin );
            regmin = auxvector[intmin];


      
        int count = 0;
        
        for (i=0; i<vectorsize; i++){ //verifica se ja leu ate o final de todos os arquivos
            if (feof(entry[i])){
                count++;
//                printf("\nO arquivo de indice [%d] foi lido completamente.", i);
            }
        }
//        printf("\n Quantidade de arquivos que foram lidos completamente: %d", count);
        
        if (count==vectorsize)
            allUnread = 0;
            
    }while (allUnread);
    
//           printf("\nCHAVES DENTRO DO ARQUIVO DE SAIDA:");
      while(!feof(exitfile)){
           Registro32 reg;
//           printf("%c ", reg.chave);
           fread(&reg, sizeof(Registro32), 1, exitfile);
      }
    
//    for (i=0; i<vectorsize; i++){
//        if (auxvector[i].chave < regmin.chave){
//            if (feof(entry[i])){
//                auxvector[i].chave = CHAR_MAX;
//                intmin = i;
//                regmin.chave = CHAR_MAX;
//            }
//            else{
//                fread(&auxvector[i], sizeof(Registro32), 1, entry[i]);
//                intmin = i;
//                regmin = auxvector[i];
//                printf("\nO INDICE DO VETORARQUIVO COM A MENOR CHAVE EH %d e contem a chave %c", intmin, regmin.chave);
//            }
//        }
//    }
    
}
int MinIndex (Registro32* entry, int vectorsize){
    int i;
    int menor;
    //char aux = CHAR_MAX;
    int aux = INT_MAX;
    for (i=0; i<vectorsize; i++){
//        printf("\nCOMPARANDO %c e %c", entry[i].chave, aux);
        if (entry[i].chave <= aux){
            
            menor = i;
            aux = entry[i].chave;
            
        }
//        printf("\nO MENOR EH %c DE INDICE %d.", aux, menor);
    }
    return menor;
}
void Intercale(ArqEntradaTipo* entry,int a,int b,ArqEntradaTipo exitfile){
       Registro32 exitreg;
       Registro32 reg1;
       Registro32 reg2;
       int turnA = 1;
       int turnB = 1;
       int exit = 0;
//       printf("\n***%d***\n", b-a+1);
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
                //reg1.chave = CHAR_MAX;
                reg1.chave = INT_MAX;
            }
           }
           if(turnB){
            fread(&reg2, sizeof(Registro32), 1, entry[1]);
                if (feof(entry[1])){
//                    fread(&reg2, sizeof(Registro32), 1, entry[a]);
//                    printf("\nentrou\n");
                    //reg2.chave = CHAR_MAX;
                    reg2.chave = INT_MAX;
                }
           }
//           printf("\nCOMPARANDO %c & %c", reg1.chave, reg2.chave);
           exitreg = MinimoReg32(reg1, reg2, &turnA, &turnB);
           
//           printf("\n turnA eh %d e turnB eh %d", turnA, turnB);
           //if (exitreg.chave != CHAR_MAX)
           if (exitreg.chave != INT_MAX)
            fwrite(&exitreg, sizeof(Registro32), 1, exitfile);
//                      fimA = feof(entry[a]);
//           fimB = feof(entry[b]);
//           printf("\nMENOR CHAVE eh %c", exitreg.chave);
       }
//       printf("\nCHAVES DENTRO DO ARQUIVO DE SAIDA:");

       
       
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
    int OrdemIntercalacao=INTERCALACOES;    
    int NBlocos = 0;
    int i;
    
    ArqEntradaTipo ArqEntrada, ArqSaida;
    ArqEntradaTipo ArrArqEnt[OrdemIntercalacao];
    
    int Low, High, Lim;
    
    NBlocos = 0;
    
    segregaArquivos(ARQ_ENTRADA, REGISTROS, &NBlocos);

    
    Low = 0;
//    printf ("%d", NBlocos);
    High = NBlocos-1;
    Lim = Minimo(Low + OrdemIntercalacao -1, High);
    
    while (Low < High){ /* Intercalacao dos NBlocos ordenados */ 
       
          
       Lim = Minimo(Low + OrdemIntercalacao -1, High);
//        printf ("\nAbreArqEntrada sendo chamado com low=%d, lim=%d, high=%d\n", Low, Lim, High);
       AbreArqEntrada(ArrArqEnt, Low, Lim); //abre array de n arquivos, sendo o primeiro low, 
//        printf ("\nDepois AbreArqEnt low=%d, lim=%d, high=%d\n", Low, Lim, High);
       High++;
    
       ArqSaida = AbreArqSaida(High);

   
//       printf ("\nIntercale sendo chamado com low=%d, lim=%d, high=%d\n", Low, Lim, High);
        IntercaleGeral(ArrArqEnt, Low, Lim, ArqSaida);
    
        fclose(ArqSaida);
        
        int count=0;
        for(i= Low; i <= Lim; i++){
            
            fclose(ArrArqEnt[count]);
            deletaArquivos(i);
            count++;

       } 

    
    
    Low += OrdemIntercalacao;
    
    }
    
    

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
    int a;
    //Registro32 vet[numeroRegistros];
    Registro32 *vet = malloc(numeroRegistros*sizeof(Registro32));
    int count=0;
    int var = 0;  //var = numero pra referencia no arquivo
    

    char nome[30];
    
 
    if(file==NULL){
        printf("maoeeee\n");
    }
    
    while(!feof(file)){
       fscanf(file,"%d ",&a);//ignora o \n no final\n
       vet[count].chave=a;
       count++;
       
       if(count==numeroRegistros){
           
           
           //char cast = (char)var;
           snprintf (nome,30, "%d.bin",var);
           output = fopen(nome,"w");
           qsort(vet, count, sizeof(Registro32), comparaRegistro32);
           fwrite(vet,sizeof(Registro32),count,output);//escreve todo o vetor de uma vez no arquivo
           
           fclose(output);
           
           FILE* output;
           
           output = fopen(nome,"r");
           fread(vet,sizeof(Registro32),count,output);
           int i = 0;
           for(i=0;i<count;i++)
//           printf("%c",vet[i].chave);
           count=0;
           var++;   //seta var sempre o proximo registro de arquivo
//           printf("\n");
       }
    }
    
    //dumpa o resto do buffer
    if (count!=0){

    snprintf (nome,30, "%d.bin",var);
      var++;  
    
    output = fopen(nome,"w");
    
    //int i;
    //for (i = 0; i < count; i++) {
        //a=vet[i].chave;
    qsort(vet, count, sizeof(Registro32), comparaRegistro32);
    fwrite(vet,sizeof(Registro32),count,output);
        int i;
        for (i = 0; i < count; i++) {
//            printf("%c",vet[i].chave);
        }
        //putc(a,output);

    //}
    }
    //fecha os arquivos, libera memoria alocada para o nome do arquivo e apaga o arquivo de entrada
    
    *NBlocos = var;
    
    fclose(output);
    fclose(file);
    free(vet);

    
    //remove(arquivoEntrada);
}