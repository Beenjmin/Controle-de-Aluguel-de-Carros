#include <stdio.h>
#include <stdlib.h>

  struct ficha                        //struct de nome ficha com s� uma das caracter�sticas
    {
        char marca[30];
    }carro[2];                          //vari�vel, no caso um vetor, com 3(?) carros



int main()
{

    char fiat[6]= "fiat",toyota[15]= "toyota";
    int opcao_marca=0;

    marca ();

}
int marca ()
{


    char fiat[6]= "fiat",toyota[15]= "toyota";
    int opcao_marca=0;

    printf("Selecione 1 para fiat e 2 para toyota");
    scanf("%d",&opcao_marca);

   switch(opcao_marca){
    case 1:
        for(int i=0;i<=6;i++)                  //loop que coloca um texto que est� dentro de um vetor dentro da "posi��o" marca dentro do struct carro(nesse carro o primeiro do vetor)
            carro[0].marca[i]=fiat[i];
    break;
    case 2:
        for(int i=0;i<=6;i++)
            carro[0].marca[i]= toyota[i];
    break;
    }
    printf("%s",carro[0].marca);
}
