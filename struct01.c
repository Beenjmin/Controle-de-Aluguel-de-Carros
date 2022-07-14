#include <stdio.h>
#include <stdlib.h>


  struct ficha                        //struct de nome ficha com s� uma das caracter�sticas
    {
        char marca[30], modelo[30], combustivel[30], arcon[30];
        int quantidade;
    }carro[2];                          //vari�vel, no caso um vetor, com 3(?) carros

int main()
{
    char fiat[6]= "fiat",toyota[15]= "toyota";
    int opcao_marca=0, triste=1;

    printf("Seleciona a marca que voce deseja comprar:\n1- para fiat.\n2- para toyota.");

    while(triste!=0){
    printf("\n> ");
    scanf("%d",&opcao_marca);
        switch(opcao_marca){
        case 1:

        for(int i=0;i<=6;i++)                  //loop que coloca um texto que est� dentro de um vetor dentro da "posi��o" marca dentro do struct carro(nesse carro o primeiro do vetor)
            carro[0].marca[i]=fiat[i];
            //Abaixo as fun��es que chamam outras fun��es:
            modelo(opcao_marca);
            combustivel();
            ar();

        for(int i=0;i<=6;i++)         //loop que coloca um texto que est� dentro de um vetor dentro da "posi��o" marca dentro do struct carro(nesse carro o primeiro do vetor)
            carro[0].marca[i]=fiat[i];

        triste=0;
        break;
        case 2:
        for(int i=0;i<=6;i++)
            carro[0].marca[i]= toyota[i];
            modelo(opcao_marca);
            combustivel();
            ar();
        triste=0;
        break;
        default:
            printf("Selecione um valor valido");
            break;
        }
    }
    system("cls");
    printf("-> Veiculo Alugado:\nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s\n",carro[0].marca, carro[0].modelo, carro[0].combustivel, carro[0].arcon);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int modelo(int x)
{
    char mobi[6] = "Mobi", argo[6] = "Argo", etios[10] = "Etios", corolla[10] = "Corolla";
    int opcao_modelo = 0, resp=-1;

    if(x == 1){
        printf("Escolha o modelo do carro:\n1-Mobi\n2-Argo");
        while(resp!=0){
            printf("\n> ");
            scanf("%d",&opcao_modelo);
                 if (opcao_modelo == 1)
                 {
                    for(int i=0;i<=6;i++)
                    carro[0].modelo[i] = mobi[i];
                    break;
                 }
                 else if (opcao_modelo == 2)
                 {
                    for(int i=0;i<=6;i++)
                    carro[0].modelo[i] = argo[i];
                    break;
                 }
                 else
                    printf("caractere invalido");
        }
    }else if(x == 2){
        while(resp!=0){
        printf("Escolha o modelo do carro:\n1- Etios\n2- Corolla\n>");
             scanf("%d",&opcao_modelo);
                 if (opcao_modelo == 1)
                 {
                    for(int i=0;i<=6;i++)
                    carro[0].modelo[i] = etios[i];
                    break;
                 }
                 else if (opcao_modelo == 2)
                 {
                    for(int i=0;i<=6;i++)
                    carro[0].modelo[i] = corolla[i];
                    break;
                 }
                 else
                    printf("caractere invalido");
        }
    }

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int combustivel()
{
    char comb1[10] = "Gasolina", comb2[10] = "Flex";
    int op_comb = 0, resp=-1;

        printf("Escolha a forma de abastecimento do carro:\n1- Gasolina\n2- Flex");
        while(resp!=0){
                printf("\n> ");
                scanf("%d",&op_comb);

                 if (op_comb == 1)
                 {
                    for(int i=0;i<=10;i++)
                    carro[0].combustivel[i] = comb1[i];
                    break;

                 }
                 else if (op_comb == 2)
                 {
                    for(int i=0;i<=6;i++)
                    carro[0].combustivel[i] = comb2[i];
                    break;

                 }
                 else
                    printf("dado invalido");
        }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------
int ar()
{
    char ar1[25] = "Ar condicionado", ar2[25] = "Sem ar condicionado";
    int op_ar =0, resp=-1;

    printf("Escolha a climatizacao do  carro: \n1- Com Ar-Condicionado\n2- Sem Ar-condicionado");
        while(resp!=0){
                printf("\n> ");
                 scanf("%d",&op_ar);

                 if (op_ar == 1)
                 {
                    for(int i=0;i<=25;i++)
                    carro[0].arcon[i] = ar1[i];
                    break;

                 }
                 else if (op_ar == 2)
                 {
                    for(int i=0;i<=25;i++)
                    carro[0].arcon[i] = ar2[i];
                    break;

                 }
                 else
                    printf("dado invalido");
        }

    //printf("%s",carro[0].marca);

}
