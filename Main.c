#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
//VARIAVEIS GLOBAIS ----------------------------------------------------------------------------------------------------------------------------------
int a=0; //índice de controle do struct carro[a]
int acumulador=0; //varivável auxiliar ao total de carros cadastrados.
struct ficha                        //struct global com as variaveis utilizadas em todo o codigo
    {
        char marca[30], modelo[30], combustivel[30], arcon[30];
        int quantidade;
    }carro[2];
//FUNCOES DO ADM ----------------------------------------------------------------------------------------------------------------------------------
int senha()
{
    char senha[20] = "aabbr", pass[20];
    int login = 1;

    printf("Digite a senha de admistrador: ");
    while(login!=0){
        scanf("%s", pass);

        if (strcmp(senha, pass) == 0){
            return 1;
        }
        else
            printf("Senha invalida!\nDigite a senha novamente: ");
    }
}
int Cadastro() //Funcao cadastro que puxa todas as outras funcoes necessarias para realizar o cadastro do carro dentro do struct carro.
{
    char fiat[6]= "Fiat",toyota[15]= "Toyota";
    int opcao_marca=0, triste=1;

    printf("Seleciona a marca que voce deseja comprar:\n1- para Fiat.\n2- para Toyota.");

    while(triste!=0){
    printf("\n> ");
    scanf("%d",&opcao_marca);
        switch(opcao_marca){
        case 1:

        for(int i=0;i<=6;i++)                  //loop que coloca um texto que esta dentro de um vetor dentro da "posicao" marca dentro do struct carro(nesse carro o primeiro do vetor)
            carro[a].marca[i]=fiat[i];
            //Abaixo as funcoes que chamam outras funcoes:
            modelo(opcao_marca); 
            combustivel();
            ar();
            quantidade();

        triste=0; //Executa a forma de parada do loop.
        break;
        case 2:
        for(int i=0;i<=6;i++)
            carro[a].marca[i]= toyota[i];
            modelo(opcao_marca);
            combustivel();
            ar();
            quantidade();
        triste=0;
        break;
        default:
            printf("Selecione um valor válido");
            break;
        }
    }
    system("cls");
    printf("-> Veiculo Cadastrado:\nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nQuantidade: %d\n\n",carro[a].marca, carro[a].modelo, carro[a].combustivel, carro[a].arcon, carro[a].quantidade);
} 
int modelo(int x)
{
    char mobi[6] = "Mobi", argo[6] = "Argo", etios[10] = "Etios", corolla[10] = "Corolla"; //Tipos de carros das marcas Fiat(Mobi e Argo) e Toyota(Etios e Corolla)
    int opcao_modelo = 0, resp=-1;

    if(x == 1){
        printf("Escolha o modelo do carro:\n1-Mobi\n2-Argo");
        while(resp!=0){
            printf("\n> ");
            scanf("%d",&opcao_modelo);
                 if (opcao_modelo == 1)
                 {
                    for(int i=0;i<=6;i++)
                    carro[a].modelo[i] = mobi[i];
                    break;
                 }
                 else if (opcao_modelo == 2)
                 {
                    for(int i=0;i<=6;i++)
                    carro[a].modelo[i] = argo[i];
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
                    carro[a].modelo[i] = etios[i];
                    break;
                 }
                 else if (opcao_modelo == 2)
                 {
                    for(int i=0;i<=6;i++)
                    carro[a].modelo[i] = corolla[i];
                    break;
                 }
                 else
                    printf("caractere invalido");
        }
    }

}
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
                    carro[a].combustivel[i] = comb1[i];
                    break;
                 }
                 else if (op_comb == 2)
                 {
                    for(int i=0;i<=6;i++)
                    carro[a].combustivel[i] = comb2[i];
                    break;
                 }
                 else
                    printf("caractere invalido");
        }
}
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
                    carro[a].arcon[i] = ar1[i];
                    break;

                 }
                 else if (op_ar == 2)
                 {
                    for(int i=0;i<=25;i++)
                    carro[a].arcon[i] = ar2[i];
                    break;

                 }
                 else
                    printf("caractere invalido");
        }
}
int quantidade()
{
    int teste=-1, limite=50;
    printf("Digite a quantidade de carros adicionados deste tipo: ");
        while(teste!=0){
            printf("\n> ");
            scanf("%d",&carro[a].quantidade);

            if(carro[a].quantidade > 0)
            {
                acumulador += carro[a].quantidade;
                if(carro[a].quantidade > 50 || acumulador > 50){
                    acumulador -= carro[a].quantidade; // isso aqui volta a quantidade anterior do acumulador para que a pessoa tenha chances de colocar a quantidade restante.
                    printf("\nLimite de estoque excedido.Voce ainda pode cadastrar %d carros\n", limite - acumulador);
                }else
                    break;
            }
            else
            printf("Somente números positivos e diferentes de 0, digite novamente.");
        }
}
void estoque() //ESTOQUE referido a quantidade de carros que vao aparecer para o ADM. 
{
    printf("Estoque: \n");
    for(int i=0; i<a; i++){
        printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nQuantidade: %d\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon, carro[i].quantidade);
    }
}
//FUNCOES DO CLIENTE ----------------------------------------------------------------------------------------------------------------------------------
void estoque_cliente()
{
    printf("Todos os carros disponiveis:\n");              
    for(int i=0; i<a; i++){
        if (carro[i].quantidade > 0)
            printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
        else if (carro[i].quantidade == 0)
            printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
    }
    printf("Escolha um carro digitando o numero correspondente:\n");
}
void estoque_marca_cliente()
{
    char fiat[6]= "Fiat",toyota[15]= "Toyota";
    int num;
    printf("Escolha a marca que deseja visualizar: \n1- Fiat \n2- Toyota \n> ");
    scanf("%d", &num);
    if (num == 1)   {                   // opção de marca 1
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].marca,fiat) == 0 && carro[i].quantidade > 0)             //disponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
            else if (strcmp(carro[i].marca,fiat) == 0 && carro[i].quantidade == 0)       //indisponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
        }
    }
    else if(num == 2){                 //opção de marca 2
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].marca,toyota) == 0 && carro[i].quantidade > 0)             //disponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
            else if (strcmp(carro[i].marca,toyota) == 0 && carro[i].quantidade == 0)       //indisponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
        }
    }
    printf("Escolha um carro digitando o numero correspondente:\n");
}
void estoque_combustivel_cliente()
{
    char comb1[10] = "Gasolina", comb2[10] = "Flex";
    int num;
    printf("Escolha o tipo de combustível que deseja visualizar: \n1- Gasolina \n2- Flex \n> ");
    scanf("%d", &num);
    if (num == 1)   {                   // opção de combustível 1
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].combustivel,comb1) == 0 && carro[i].quantidade > 0)             //disponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
            else if (strcmp(carro[i].combustivel,comb1) == 0 && carro[i].quantidade == 0)       //indisponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
        }
    }
    else if(num == 2){                 //opção de combustível 2
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].combustivel,comb2) == 0 && carro[i].quantidade > 0)             //disponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
            else if (strcmp(carro[i].combustivel,comb2) == 0 && carro[i].quantidade == 0)       //indisponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
        }
    }
    printf("Escolha um carro digitando o numero correspondente:\n"); 
}
int custoAluguel()
{
    int dias, preco;
    printf("Por quantos dias voce deseja alugar o carro?\n> ");
    scanf("%d", &dias);
    return preco = dias*60;
}
int alugarCarro()
{
    int opcao, resp=-1, npreco=0, num;
    printf("Qual carro voce deseja alugar?");
    while(resp!=0){
        printf("\n> ");
        scanf("%d", &opcao);
            if(opcao<=0 || opcao > a){
                printf("Digite uma das opcoes acima ");
            }else{
                npreco = custoAluguel();
                printf("O aluguel do veiculo saira por %d R$. Voce deseja alugar esse veiculo?\n1- Sim\t2- Nao\n", npreco);
                scanf("%d", &num);
                opcao -= 1; //voltar uma posicao do vetor carro e nao dar erro :D
                    if(num == 1){
                        carro[opcao].quantidade = carro[opcao].quantidade - 1; 
                        acumulador -= 1;
                        break;
                    }else if(num == 2){
                        break;
                    }else 
                        printf("Caracter invalido");
            }
    }
}
void menu_principal() //Funcao mais importante do codigo todo.
{
    printf ("--------------------- Menu Principal --------------------- \n\n");
    printf ("Escolha seu usuario:\n");
    printf ("1 - Administrador\n");
    printf ("2 - Cliente\n");
    printf ("Entre com o numero correspondente ao seu tipo de usuario:");
}
//MAIN -----------------------------------------------------------------------------------------------------------------------------------------------
int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int user, resp=-1, num;

    menu_principal();

    while(resp!=0){
    printf("\n> ");
    scanf ("%d", &user);
        switch (user)
        {
        case 1:
           senha();
            system("cls");
                while(resp!=0)
                {
                printf("Selecione qual opcao voce deseja\n1- Cadastrar carro;\n2- Mostrar estoque;\n3- Voltar a tela inicial;\n> ");
                scanf("%d", &num);
                    if (num == 1){
                        system("cls");
                        if (acumulador >= 50){
                        puts("Limite de cadastros excedido! Voce ainda pode listar os carros cadastrados ou voltar para o menu principal.\n");
                        }else {
                        Cadastro(); //Função para cadastrar os carros, todas as outras funções de cadastro do ADM estão dentro dela.
                        a++;
                        }
                    }else if (num == 2){
                        system("cls");
                        estoque();
                        printf("Quantidade de veiculos cadastrados: %d\n\n", acumulador);
                    }else if (num == 3){
                        system("cls");
                        break;
                    }else if(num<=0 || num>3){
                        system("cls");
                        printf("Selecione uma das opcoes abaixo.\n\n");
                    }
                }
        break;
        case 2:
            system("cls");
            while(resp!=0)
            {
            printf("-----------------Listar automoveis disponiveis----------------- \n1- Todos os carros disponiveis; \n2- Por marca; \n3- Por tipo de veiculo; \n4- Sair;\n> ");
            scanf("%d", &num);

            if (num == 1){    
                if(acumulador < 1){ //if para caso nao haja nenhum carro cadastrado no sistema.
                    system("cls");
                    printf("Ainda nao ha carros disponiveis para aluguel, tente mais tarde.\n");
                }else{
                    system("cls");        
                    estoque_cliente();  
                    alugarCarro();
                    system("cls");
                    printf("Seu carro foi alugado.\n");
                    break;
                }
            }else if (num == 2){
                 if(acumulador < 1){
                    system("cls");
                    printf("Ainda nao ha carros disponiveis para aluguel, tente mais tarde.\n");
                }else{
                    system("cls");
                    estoque_marca_cliente();
                    alugarCarro();
                    system("cls");
                    printf("Seu carro foi alugado.\n");
                    break;
                }
            }else if (num == 3){
                 if(acumulador < 1){
                    system("cls");
                    printf("Ainda nao ha carros disponiveis para aluguel, tente mais tarde.\n");
                }else{
                    system("cls");
                    estoque_combustivel_cliente();
                    alugarCarro();
                    system("cls");
                    printf("Seu carro foi alugado.\n");
                    break;
                }
            }else if (num == 4){
                system("cls");
                break;
            }else if(num<0 || num>4){
                system("cls");
                printf("Digite um caracter valido.\n\n");
                } 
            }
        break;
        default:
            system("cls");
            puts ("Selecione um caractere valido abaixo\n");
        }
    menu_principal();
    }
    return 0;
}
