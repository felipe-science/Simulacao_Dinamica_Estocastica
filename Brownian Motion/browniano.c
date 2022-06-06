#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 100
#define N_AMOSTRAS 10
#define T_FINAL 100
#define LCM 0.000000001
#define LTM 0.000000001


void caminhada_aleatoria(int Npassos, int pos[2])
{

    int i, j, x, y, a;

    x = 0; y = 0;
    for (i = 0; i < Npassos; i++)
    {

        a = (rand() % 4);
        if(a == 0)
            x = x+1;
        if(a == 1)
            x = x-1;
        if(a == 2)
            y = y+1;
        if(a == 3)
            y = y-1;

    }

    pos[0] = x;
    pos[1] = y;

}

float calcular_mediax(int dadosx[N_AMOSTRAS])
{
    int i;
    float soma, media;

    soma = 0;
    for (i = 0; i < N_AMOSTRAS; i++)
    {
        soma = soma+dadosx[i];
    }

    media = soma/N_AMOSTRAS;
    return media;
}


float calcular_mediax2(int dadosx[N_AMOSTRAS])
{
    int i;
    float soma, media;

    soma = 0;
    for (i = 0; i < N_AMOSTRAS; i++)
    {
        soma = soma+((dadosx[i])*(dadosx[i]));
    }

    media = soma/N_AMOSTRAS;
    return media;
}


float calcular_mediay(int dadosy[N_AMOSTRAS])
{
    int i;
    float soma, media;

    soma = 0;
    for (i = 0; i < N_AMOSTRAS; i++)
    {
        soma = soma+dadosy[i];
    }

    media = soma/N_AMOSTRAS;
    return media;
}



float calcular_mediay2(int dadosy[N_AMOSTRAS])
{
    int i;
    float soma, media;

    soma = 0;
    for (i = 0; i < N_AMOSTRAS; i++)
    {
        soma = soma+((dadosy[i])*(dadosy[i]));
    }

    media = soma/N_AMOSTRAS;
    return media;
}






int main()
{
    srand (time(NULL));
    
    int i, t, N, tfinal, pos[2], dadosx[N_AMOSTRAS], dadosy[N_AMOSTRAS];
    float mediax[T_FINAL], mediay[T_FINAL], mediax2[T_FINAL], mediay2[T_FINAL];
    

	FILE *f = fopen("media_posicao.txt", "w");
	
	if (f == NULL) // Se não conseguiu criar
	{
	    printf("Problemas na CRIACAO do arquivo\n");
	    return 0;
	}
   

    fprintf(f,"#  <x>         <x²>         <y>        <y²>\n");    
    for (t = 1; t <= T_FINAL; t++)
    {
        for(i = 0; i < N_AMOSTRAS; i++)
        {
            caminhada_aleatoria(t,pos);
            dadosx[i] = pos[0];
            dadosy[i] = pos[1];
        }

        mediax[t-1] = calcular_mediax(dadosx);
        mediay[t-1] = calcular_mediax(dadosy);

        mediax2[t-1] = calcular_mediax2(dadosx);
        mediay2[t-1] = calcular_mediay2(dadosy);


        
         
		fprintf (f,"%f    %f    %f    %f\n",mediax[t-1], mediax2[t-1], mediay[t-1], mediay2[t-1]);
	
            
        printf("%d \n",t);    

    }
   
    

    return 0;
}
