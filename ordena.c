#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void OrdeneExterno(){
    int OrdemIntercalacao=2;
    
    int NBlocos = 0;
    
    int i;
    
    ArqEntradaTipo ArqEntrada, ArqSaida;
    
    ArqEntradaTipo ArrArqEnt[OrdemIntercalacao];
    
    short Fim;
    
    int Low, High, Lim;
    
    NBlocos = 0;
    
    ArqEntrada ;//abrir arquivo a ser ordenado;
    
    do /*Formacao inicial dos NBlocos ordenados */
        
    { NBlocos++;
    
    Fim = EnchePaginas(NBlocos, ArqEntrada);
    
    //OrdeneInterno;
    
    ArqSaida = AbreArqSaida(NBlocos);
    
    DescarregaPaginas(ArqSaida);
    
    fclose(ArqSaida);
    
    } while (!Fim);
    
    fclose(ArqEntrada);
    
    Low = 0;
    
    High = NBlocos-1;
    
    while (Low < High){ /* Intercalacao dos NBlocos ordenados */ 
        
        Lim = Minimo(Low + OrdemIntercalacao -1, High);
    
    AbreArqEntrada(ArrArqEnt, Low, Lim);
    
    High++;
    
    ArqSaida = AbreArqSaida(High);
    
    Intercale(ArrArqEnt, Low, Lim, ArqSaida);
    
    fclose(ArqSaida);
    
    for(i= Low; i < Lim; i++){
        fclose(ArrArqEnt[i]);
    
    Apague_Arquivo(ArrArqEnt[i]);
    
    }
    
    Low += OrdemIntercalacao;
    
    }
    
    //Mudar o nome do arquivo High para o nome fornecido pelo usuario;
    
}
