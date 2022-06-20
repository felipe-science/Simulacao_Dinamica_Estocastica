#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define Npassos 1000
#define Namostras 100

void zeros(int v[Npassos]);
int caminhada_aleatoria(int w[Npassos]);



int main()
{
    srand(time(NULL));

    int i, j;
    int w_auxiliar[Npassos], somaq[Npassos]; 
    
    FILE *arquivo;
  
    // Abrindo o arquivo
    arquivo = fopen("Npasso_Mposicao.txt", "w");

    zeros(somaq);
    for(i = 0; i < Namostras; i++)
    {
        zeros(w_auxiliar);
        caminhada_aleatoria(w_auxiliar);
        for (j = 0; j < Npassos; j++)
        {
            somaq[j] = somaq[j]+w_auxiliar[j]*w_auxiliar[j];
        }

    }
    
    for(i = 0; i < Npassos; i++)
    {
        fprintf(arquivo,"%f\n",sqrt(somaq[i]));
    }

    
    // fechando arquivo
    fclose(arquivo);
  
    return 0;
}

// zerando vetores
void zeros(int v[Npassos])
{
    int i;
    for(i = 0; i < Npassos; i++)
        v[i] = 0;
}


int caminhada_aleatoria(int w[Npassos])
{
    int i, yi, sorteio;

    for(i = 0; i < Npassos; i++)
        w[i] = 0;

    // Definindo a posição inicial
    for (i = 1; i < Npassos; i++)
    {
        sorteio = rand()%2;
        if(sorteio == 0)
            yi = -1;
        else
            yi = +1;
        w[i] = w[i-1]+yi;
    }
    
}