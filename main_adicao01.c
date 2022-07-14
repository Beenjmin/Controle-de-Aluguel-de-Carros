#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
//VARIAVEIS GLOBAIS ----------------------------------------------------------------------------------------------------------------------------------
int a=0; //�ndice de controle do struct carro[a]
int acumulador=0,controle=0; //variv�vel auxiliar ao total de carros cadastrados.
int v[50];//o tamanho desse vetor deve ser da quantidade total de carros poss�veis

struct ficha                        //struct global com as variaveis utilizadas em todo o codigo
    {
        char marca[30], modelo[30], combustivel[30], arcon[30];
        int quantidade;
    }carro[2];
//FUNCOES DO ADM ----------------------------------------------------------------------------------------------------------------------------------
int senha()
{
    setlocale(LC_ALL, "Portuguese");
    char senha[20] = "aabbr", pass[20];
    int login = 1;

    printf("Digite a senha de admistrador: ");
    while(login!=0){
        scanf("%s", pass);

        if (strcmp(senha, pass) == 0){
            return 1;
        }
        else
            printf("Senha inv�lida!\nDigite a senha novamente: ");
    }
}
int Cadastro() //Funcao cadastro que puxa todas as outras funcoes necessarias para realizar o cadastro do carro dentro do struct carro.
{
    char fiat[6]= "Fiat",toyota[15]= "Toyota";
    int opcao_marca=0, triste=1, mp;

    printf("Seleciona a marca que voce deseja comprar:\n1- para Fiat.\n2- para Toyota.");

    //obs: permanecemos o nome da variavel como triste por que somos um grupo emo (me passa Salete pra eu nao ficar triste);
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
        mp = Comparacao();
        //printf("%d", mp);
        //system("pause");
        //Comparacao();
        if(mp == 1){
            system("cls");
            printf("Um carro igual j� foi cadastrado.\n\n");
            //system("pause");
            return 1; //return como condi��o de parada para a funcao.
        }else if(mp == 0){
            quantidade();
            //a++;
        }
        triste=0; //Executa a forma de parada do loop.
        break;
        case 2:
        for(int i=0;i<=6;i++)
            carro[a].marca[i]= toyota[i];
        modelo(opcao_marca);
        combustivel();
        ar();
        mp = Comparacao();
        //printf("%d", mp);
        //system("pause");
        //Comparacao();
        if(mp == 1){
            system("cls");
            printf("Um carro igual j� foi cadastrado\n");
            system("pause");
            return system("cls");
        }else if(mp == 0){
            quantidade();
            //a++;
        }
        triste=0;
        break;
        default:
            printf("Selecione somente valores da lista acima");
            break;
        }
    }
    system("cls");
    printf("-> Veiculo Cadastrado:\nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nQuantidade: %d\n\n",carro[a].marca, carro[a].modelo, carro[a].combustivel, carro[a].arcon, carro[a].quantidade);
    a++;
}
int modelo(int x)
{
    char mobi[6] = "Mobi", argo[6] = "Argo", etios[10] = "Etios", corolla[10] = "Corolla"; //Tipos de carros das marcas Fiat(Mobi e Argo) e Toyota(Etios e Corolla)
    int opcao_modelo = 0, resp=-1;

    if(x == 1){
        printf("Escolha o modelo do carro:\n1- Mobi\n2- Argo");
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
                printf("Selecione somente valores da lista acima.");
        }
    }else if(x == 2){
        while(resp!=0){
            printf("Escolha o modelo do carro:\n1- Etios\n2- Corolla\n> ");
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
                printf("Selecione somente valores da lista acima.");
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
            printf("Selecione somente valores da lista acima.");
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
            printf("Selecione somente valores da lista acima");
    }
}
int Comparacao()
{
    for(int i=0; i<a; i++)
    {
        //printf("%d\n", i);
        //system("pause");
        if(strcmp(carro[i].marca, carro[a].marca) == 0 && strcmp(carro[i].modelo, carro[a].modelo) == 0 && strcmp(carro[i].combustivel, carro[a].combustivel) == 0 && strcmp(carro[i].arcon, carro[a].arcon) == 0)
        {
            return 1;
            //printf("Esse carro ja foi cadastrado");
        }else if (i == a-1)
            return 0;
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
                printf("\nLimite de estoque excedido. Voce ainda pode cadastrar %d carros\n", limite - acumulador);
            }else
                break;
        }
        else
            printf("Somente n�meros positivos e diferentes de 0, digite novamente.");
    }
}
int reposicaoEstoque()
{
    int opcao, resp=-1, num, limite=50;

    /*if(a == 0){ //condicao de parada caso nao haja nenhum carro cadastrado.
        return 1;                                                                         //est� gerando um "Estoque: " ao inv�s de um aviso
    }else if(a >= 1){*/
        printf("Digite uma das opcoes acima (digite 0 para sair):\n> "); //no caso, a do estoque.
        while(resp!=0){
            scanf("%d", &opcao);
            if(opcao < 0 || opcao > a){
                printf("Digite uma das opcoes acima (digite 0 para sair):\n> ");
            }else if(opcao == 0){    //sa�da
                system("cls");
                break;
            }else{
                opcao -= 1; //FUNDAMENTAL PARA O FUNCIONAMENTO DA FUNCAO POR CAUSA DO VETOR;
                printf("Digite a quantidade de carros para serem adicionadas ao tipo escolhido:\n> ");
                while(resp!=0){
                    scanf("%d",&num);
                    //carro[opcao].quantidade += num; //adiciona o valor escolhido � quantidade para o vetor do carro selecionado.
                    if(carro[opcao].quantidade > 0 && num > 0)
                    {
                        carro[opcao].quantidade += num;
                        acumulador += num;
                        if(carro[opcao].quantidade > 50 || acumulador > 50){
                            carro[opcao].quantidade -= num; //volta a condicao anterior.
                            acumulador -= num; //volta a condicao anterior.
                            printf("N�o foi poss�vel adicionar essa quantidade ao estoque. Voc� so pode adicionar at� %d carros:\n> ", limite - acumulador);
                        }else
                            return system("cls");
                    }else if(num<=0){
                            //carro[opcao].quantidade += num;
                            //acumulador -= num;
                            printf("Digite apenas n�meros positivos:\n> " );
                    }
                }
            }
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
    printf("Todos os carros do cat�logo:\n");
    for(int i=0; i<a; i++){
        if (carro[i].quantidade > 0){
            printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
            v[i+1]=1;
        }
        else if (carro[i].quantidade == 0){
            printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
            v[i+1]=0;
        }
    }
    printf("Escolha um carro digitando o numero correspondente:\n");
}
void estoque_marca_cliente()
{
    char fiat[6]= "Fiat",toyota[15]= "Toyota";
    int num, block=-1;
    printf("Escolha a marca que deseja visualizar: \n1- Fiat \n2- Toyota");
    while(block!=0){
    printf("\n> ");
    scanf("%d", &num);
    if (num == 1){                   // op��o de marca 1
    system("cls");
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].marca,fiat) == 0 && carro[i].quantidade > 0){           //dispon�vel
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=1;
                controle = 1;    //impede a exibi��o dessa lista se ela estiver vazia
                block = 0;
            }
            else               //impede que o cliente selecione carros fora da lista
                v[i+1]=0;
                block = 0;


        }
    }
    else if(num == 2){
    system("cls");                 //op��o de marca 2
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].marca,toyota) == 0 && carro[i].quantidade > 0){            //dispon�vel
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=1;
                controle = 1;    //impede a exibi��o dessa lista se ela estiver vazia
            }
            else if (strcmp(carro[i].marca,toyota) == 0 && carro[i].quantidade == 0){      //indispon�vel
                //printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=0;
                block = 0;
            }
            else
                v[i+1]=0;
                block = 0;
        }
    }else if(num <= 0 || num >2){
        printf("Selecione uma das opcoes acima.");
        }
    }

}
int estoque_combustivel_cliente()
{
    char comb1[10] = "Gasolina", comb2[10] = "Flex";
    int num, block=-1;
    printf("Escolha o tipo de combust�vel que deseja visualizar: \n1- Gasolina \n2- Flex");
    while(block!=0){
    printf("\n> ");
    scanf("%d", &num);
    if (num == 1){                   // op��o de combust�vel 1
    system("cls");
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].combustivel,comb1) == 0 && carro[i].quantidade > 0){             //dispon�vel
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=1;
                controle = 1;    //impede a exibi��o dessa lista se ela estiver vazia
                block = 0;
            }
            else if (strcmp(carro[i].combustivel,comb1) == 0 && carro[i].quantidade == 0){      //indispon�vel
                //printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                block = 0;
                v[i+1]=0;
            }
            else
                v[i+1]=0;
                block = 0;
        }
    }
    else if(num == 2){                 //op��o de combust�vel 2
    system("cls");
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].combustivel,comb2) == 0 && carro[i].quantidade > 0){             //dispon�vel
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=1;
                controle = 1;    //impede a exibi��o dessa lista se ela estiver vazia
                block = 0;
            }
            else if (strcmp(carro[i].combustivel,comb2) == 0 && carro[i].quantidade == 0){       //indispon�vel
                //printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=0;
                block = 0;
            }
            else
                v[i+1]=0;
                block = 0;
        }
    }else if(num <= 0 || num >2){
        printf("Selecione uma das opcoes acima.");
        }
    }
}
int custoAluguel()
{
    int dias;
    float preco;
    printf("Por quantos dias voce deseja alugar o carro?\n> ");
    scanf("%d", &dias);
    return preco = (float) dias*60;
}
int alugarCarro()
{
    int opcao, resp=-1, num;
    float npreco=0;
    printf("Qual carro voce deseja alugar?");
    while(resp!=0){
        printf("\n> ");
        scanf("%d", &opcao);
        if(opcao<=0 || opcao > a){
            printf("Digite uma das opcoes acima ");
        }
        else if(v[opcao]==1){
            npreco = custoAluguel();
            printf("O aluguel do veiculo saira por R$ %.2f. Voce deseja alugar esse veiculo?\n1- Sim\t2- Nao\n", npreco);
            scanf("%d", &num);
            opcao -= 1; //voltar uma posicao do vetor carro e nao dar erro :D
            if(num == 1){
                carro[opcao].quantidade = carro[opcao].quantidade - 1;
                acumulador -= 1;
                system("cls");
                return printf("O carro foi alugado\n");
                break;
            }else if(num == 2){
                system("cls");
                return printf("Aluguel nao efetuado\n");
                break;
            }else
                printf("Caracter invalido");
        }
        //else if(v[opcao]==0)
          //  printf("Carro indispon�vel. Por favor, selecione outro.");
        else
            printf("Digite uma das opcoes acima ");
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
        case 1:// AREA DO ADM
        senha();
        system("cls");
        while(resp!=0)
        {
            printf("-----------------Selecione qual opcao voce deseja-----------------\n");
            printf("1- Cadastrar carro;\n2- Mostrar estoque;\n3- Renovar estoque;\n4- Voltar a tela inicial\n> ");
            scanf("%d", &num);
            if (num == 1){                  //Cadastrar carro
                system("cls");
                if (acumulador >= 50){
                    puts("Limite de cadastros excedido! Voce ainda pode listar os carros cadastrados ou voltar para o menu principal.\n");
                }else {
                Cadastro(); //Fun��o para cadastrar os carros, todas as outras fun��es de cadastro do ADM est�o dentro dela.
                //a++;
            }
            }else if (num == 2){           //Mostrar estoque
                system("cls");
                estoque();
                printf("Quantidade de veiculos cadastrados: %d\n\n", acumulador);
            }else if (num == 3){           //Renovar estoque
                if (acumulador >= 50){
                    printf("Limite de cadastros excedido! Voce ainda pode listar os carros cadastrados ou voltar para o menu principal.\n");
                }else if (a == 0){
                    system("cls");
                    printf("Ainda nao ha carros cadastrados no estoque.\n");
                }else if (a > 0){
                    system("cls");
                    estoque();
                    reposicaoEstoque();
                    }
            }else if (num == 4){           //Voltar a tela inicial
                system("cls");
                break;
            }else if(num<=0 || num>4){
                system("cls");
                printf("Selecione uma das opc�es abaixo.\n\n");
            }
        }
        break;
        case 2://AREA DO USUARIO
        system("cls");
        while(resp!=0)
        {
            printf("-----------------Listar automoveis disponiveis----------------- \n");
            printf("1- Todos os carros do cat�logo; \n2- Por marca (dispon�veis); \n3- Por tipo de combustivel (dispon�veis); \n4- Sair.\n> ");
            scanf("%d", &num);
            if (num == 1){                //Todos os carros disponiveis;
                if(acumulador < 1){ //if para caso nao haja nenhum carro cadastrado no sistema.
                    system("cls");
                    printf("Ainda nao ha carros disponiveis para aluguel, tente mais tarde.\n");
                }else{
                    system("cls");
                    estoque_cliente();
                    alugarCarro();
                    //system("cls");
                    //printf("Seu carro foi alugado.\n");
                    break;
                }
            }else if (num == 2){           //Por marca
                if(acumulador < 1){
                    system("cls");
                    printf("Ainda nao ha carros disponiveis para aluguel, tente mais tarde.\n");
                }else{
                    system("cls");
                    estoque_marca_cliente();
                        if(controle==1){
                            printf("Escolha um carro digitando o numero correspondente:\n");
                            alugarCarro();
                            controle=0;
                            //system("cls");
                            //printf("Seu carro foi alugado.\n");
                            break;
                        }
                }
            }else if (num == 3){            //Por tipo de combustivel
                if(acumulador < 1){
                    system("cls");
                    printf("Ainda nao ha carros disponiveis para aluguel, tente mais tarde.\n");
                }else{
                    system("cls");
                    estoque_combustivel_cliente();
                        if(controle==1){
                            printf("Escolha um carro digitando o numero correspondente:\n");
                            alugarCarro();
                            controle = 0;
                            //system("cls");
                            //printf("Seu carro foi alugado.\n");
                            break;
                        }
                }
            }else if (num == 4){        //Sair
                system("cls");
                break;
            }else if(num<0 || num>4){ //CASO HAJA UMA OPCAO INVALIDA
                system("cls");
                printf("Digite um caracter v�lido.\n\n");
            }
        }
        break;
        default:
            system("cls");
            puts ("Selecione um caractere v�lido abaixo\n");
        }
        menu_principal();
    }
    return 0;
}
/*ERROS PRESENTES NA VERS�O 1.0 DO C�DIGO:
    1- Arrumar o erro (j� mencionado antes) de cadastrar o mesmo carro pela segunda vez e ele aparecer como outra op��o de tipo de carro.
       Um exemplo, se cadastrarmos o primeiro carro e colocarmos uma quantidade igual a 50 (enchendo o p�tio por completo) e um usu�rio comprar um
       carro (diminuindo -1 no total dos 50) e depois formos adicionar mais um desse mesmo carro no cadastro (voltando a ter um total de 50), esse
       cadastro adicionar� o mesmo carro so que como "carro 2".

    2- Problema na hora de alugar o carro. -> Fun��o alugar carro.
    Nessa fun��o apresenta o seguinte erro ap�s o scanf("%d", &opcao);
         if(opcao<=0 || opcao > a){
                printf("Digite uma das opcoes acima ");
            }else{
    Observe que o "if - op��o > a" est� manipulando a vari�vel "a" que sempre cresce com a adi��o de um novo carro cadastrado.
    Por�m, se tentarmos alugar um carro a partir da op��o marca ou modelo, podemos adicionar um n�mero maior do que est� aparecendo na lista e passar.
    Sendo que, por exemplo, se tiverem 4 carros adicinonar e sendo 2 deles da marca fiat, so poderia selecionar duas op��es na hora da compra, por�m
    � poss�vel selecionar digitar o numero 4 e comprar o carro no vetor equivalente ao numero 4.
*/
