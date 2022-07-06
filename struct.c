#include <stdio.h>
#include <stdlib.h>

  struct ficha                        //struct de nome ficha com só uma das características
    {
        char marca[30], modelo[30], combustivel[30], arcon[30];
    }carro[2];                          //variável, no caso um vetor, com 3(?) carros



int main()
{

    //char fiat[6]= "fiat",toyota[15]= "toyota";
    //int opcao_marca=0;

    marca ();

}

//----------------------------------------------------------------------------------------------------------------------------------


int marca ()
{


    char fiat[6]= "Fiat",toyota[15]= "Toyota";
    int opcao_marca=0;

    printf("Escolha a marca do carro:\n1-Fiat\n2-Toyota\n3-Ford\n>");
    scanf("%d",&opcao_marca);

   switch(opcao_marca){
    case 1:
        for(int i=0;i<=6;i++)                  //loop que coloca um texto que está dentro de um vetor dentro da "posição" marca dentro do struct carro(nesse carro o primeiro do vetor)
            carro[0].marca[i]=fiat[i];
            modelo(); //aqui ha um problema: preciso criar uma funcao modelo pra cada marca
            combustivel();
            ar();
    break;
    case 2:
        for(int i=0;i<=6;i++)
            carro[0].marca[i]= toyota[i];
            combustivel();
            ar();
    break;
    }
    printf("Marca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s",carro[0].marca, carro[0].modelo, carro[0].combustivel, carro[0].arcon);

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------

int modelo ()
{
    char mobi[6] = "Mobi", argo[6] = "Argo", etios[10] = "Etios", corolla[10] = "Corolla";
    int opcao_modelo = 0;

    printf("Escolha o modelo do carro:\n1-Mobi\n2-Argo\n>");
                 scanf("%d",&opcao_modelo);

                 if (opcao_modelo == 1)
                 {
                    for(int i=0;i<=6;i++)
                    carro[0].modelo[i] = mobi[i];

                 }
                 else if (opcao_modelo == 2)
                 {
                    for(int i=0;i<=6;i++)
                    carro[0].modelo[i] = argo[i];

                 }
                 else
                    printf("caractere invalido");
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------

int combustivel()
{
    char comb1[10] = "Gasolina", comb2[10] = "Flex";
    int op_comb = 0;

        printf("Escolha a forma de abastecimento do carro:\n1- Gasolina\n2- Flex\n>");
                 scanf("%d",&op_comb);

                 if (op_comb == 1)
                 {
                    for(int i=0;i<=10;i++)
                    carro[0].combustivel[i] = comb1[i];

                 }
                 else if (op_comb == 2)
                 {
                    for(int i=0;i<=6;i++)
                    carro[0].combustivel[i] = comb2[i];

                 }
                 else
                    printf("dado invalido");
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------

void ar()
{
    char ar1[25] = "Ar condicionado", ar2[25] = "Sem ar condicionado";
    int op_ar =0;

    printf("Escolha a climatizacao do  carro: \n1- Com Ar-Condicionado\n2- Sem Ar-condicionado\n>");
                 scanf("%d",&op_ar);

                 if (op_ar == 1)
                 {
                    for(int i=0;i<=25;i++)
                    carro[0].arcon[i] = ar1[i];

                 }
                 else if (op_ar == 2)
                 {
                    for(int i=0;i<=25;i++)
                    carro[0].arcon[i] = ar2[i];

                 }
                 else
                    printf("dado invalido");


}
