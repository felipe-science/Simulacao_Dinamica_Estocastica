#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Npassos 10000
#define Namostras 1000


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

int main()
{
    srand(time(NULL));

    int i, j;
    int w_auxiliar[Npassos], media_posicao[Npassos];
    FILE *arquivo;
  
    // Abrindo o arquivo
    arquivo = fopen("Npasso_Mposicao.txt", "w");

    // Inicializando os vetores
    for(i = 0; i < Npassos; i++)
        media_posicao[i] = 0;
        w_auxiliar[i] = 0;
    
    for(i = 0; i < Namostras; i++)
    {
        caminhada_aleatoria(w_auxiliar);
        for(j = 0; j < Npassos; j++)
        {
            media_posicao[j] = media_posicao[j]+w_auxiliar[j];
        }
    }

    // Gerando a média
    for(i = 0; i < Npassos; i++)
    {
        media_posicao[i] = media_posicao[i]/Namostras;
        fprintf(arquivo,"%d\n",media_posicao[i]);
    }

    // fechando arquivo
    fclose(arquivo);
  
    return 0;
}