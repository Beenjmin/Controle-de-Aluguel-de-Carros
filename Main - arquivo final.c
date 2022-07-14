/*Avalição Etapa 3
--> Integrantes:  
Benjamim Marcos
Bruna Saraiva
Ramon Moreira
Uriel Ewerton
--> Tema-Problemática: 
Controle de aluguel de automóveis.
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
//VARIAVEIS GLOBAIS ----------------------------------------------------------------------------------------------------------------------------------
int a=0; //Índice de controle do struct carro[a]
int acumulador=0,controle=0; //Acumulador: varivável auxiliar ao total de carros cadastrados. Controle: controle de carros não disponíveis na lista do usuário.
int v[50];//o tamanho desse vetor deve ser da quantidade total de carros possíveis, atua junto com a variável controle.

struct ficha                        //struct global com as variaveis utilizadas em todo o codigo
    {
        char marca[30], modelo[30], combustivel[30], arcon[30]; //variáveis utilizadas para o cadastro do carro. 
        int quantidade,quantidadefixa; //"quantidade" é a disponível conforme são alugados os carros. "quantidadefixa" é o total de cada tipo que a empresa possui(que só muda se o adm quiser/empresa comprar mais carros para a frota)
    }carro[2];
//FUNCOES DO ADM ----------------------------------------------------------------------------------------------------------------------------------
int senha()
{
    setlocale(LC_ALL, "Portuguese");
    char senha[20] = "aabbr", pass[20]; //A senha é "aabbr" (iniciais de todos do grupo em ordem alfabetica)
    int login = 1;

    printf("Digite a senha de admistrador: ");
    while(login!=0){
        scanf("%s", pass);

        if (strcmp(senha, pass) == 0){
            return 1;
        }
        else
            printf("Senha inválida!\nDigite a senha novamente: ");
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
        case 1:                                 //switch fiat
            for(int i=0;i<=6;i++)                  //loop que coloca um texto que esta dentro de um vetor dentro da "posicao" marca dentro do struct carro.
                carro[a].marca[i]=fiat[i];
            //Abaixo as funcoes que chamam outras funcoes:
            modelo(opcao_marca); 
            combustivel();
            ar();
            mp = Comparacao(); //a variável mp recebe o resultado de Comparação. 
            if(mp == 1){
                system("cls");
                return printf("Um carro igual já foi cadastrado.\n\n"); //return como condição de parada para a função caso haja um carro igual ja cadastrado.
            }else if(mp == 0){
                quantidade();
            }
            triste=0; //Executa a forma de parada do loop.
            break;
        case 2:                                //switch toyota
            for(int i=0;i<=6;i++)                //loop que coloca um texto que esta dentro de um vetor dentro da "posicao" marca dentro do struct carro.
                carro[a].marca[i]= toyota[i];
            modelo(opcao_marca);
            combustivel();
            ar();
            mp = Comparacao();      //a variável mp recebe o resultado de Comparação. 
            if(mp == 1){
                system("cls");
                return printf("Um carro igual já foi cadastrado.\n\n"); //return como condição de parada para a função caso haja um carro igual ja cadastrado.
            }else if(mp == 0){
                quantidade();
            }
            triste=0;//Executa a forma de parada do loop.
            break;
        default:
            printf("Selecione somente valores da lista acima.");
            break;
        }
    }
    system("cls");
    //o printf abaixo serve para demonstrar o carro que foi adicionado.
    printf("-> Veiculo Cadastrado:\nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nQuantidade: %d\n\n",carro[a].marca, carro[a].modelo, carro[a].combustivel, carro[a].arcon, carro[a].quantidade);
    a++; //Aqui a variável "a" global cresce conforme é adicionado mais carros no sistema. Manipulando o vetor carro[] na struct. 
}
int modelo(int x) //recebe o scanf da função cadastro acima como argumento para a marca do carro já selecionada. 
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
        if(strcmp(carro[i].marca, carro[a].marca) == 0 && strcmp(carro[i].modelo, carro[a].modelo) == 0 && strcmp(carro[i].combustivel, carro[a].combustivel) == 0 && strcmp(carro[i].arcon, carro[a].arcon) == 0)
        {
            return 1;
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
            carro[a].quantidadefixa += carro[a].quantidade; //somando o valor variável ao total(por carro)
            acumulador += carro[a].quantidadefixa;
            if(carro[a].quantidade > 50 || acumulador > 50){ //reversor, caso o adm insira números fora do parâmetro- contem redundancia de verificação
                acumulador -= carro[a].quantidade; // isso aqui volta a quantidade anterior do acumulador para que a pessoa tenha chances de colocar a quantidade restante.
                carro[a].quantidadefixa -= carro[a].quantidade;
                printf("\nLimite de estoque excedido. Você ainda pode cadastrar %d carros\n", limite - acumulador);
            }else
                break;
        }
        else
            printf("Somente números positivos e diferentes de 0, digite novamente.");
    }
}
int adicaoEstoque() 
//Essa função serve para adicionarmos mais carros que já foram cadastrados no estoque, aumentando a quantidade selecionada. 
{
    int opcao, resp=-1, num, limite=50;

    printf("Digite uma das opções acima (digite 0 para sair):\n> "); //no caso, a do estoque, que aparece acima (observe como as duas funções na main).
    while(resp!=0){
        scanf("%d", &opcao);
        if(opcao < 0 || opcao > a){ //não pode ultrapassar o "a", pois "a" significa a quantidade total de carros já cadastrados.
            printf("Digite uma das opções acima (digite 0 para sair):\n> ");
        }else if(opcao == 0){    //saída
            system("cls");
            break;
        }else{
            opcao -= 1;     //Essa variável é diminuída um valor para que seja manipulada o seu número correspondente do carro[].
            printf("Digite a quantidade de carros para serem adicionadas ao tipo escolhido:\n> ");
            while(resp!=0){
                scanf("%d",&num);
                if(carro[opcao].quantidadefixa > 0 && num > 0)
                {
                    carro[opcao].quantidade += num; //a variável quantidade é somada ao numero digitado em scanf("%d",&num);. Mesma coisa abaixo.
                    carro[opcao].quantidadefixa += num; //rt acima
                    acumulador += num; //rt acima
                    if(carro[opcao].quantidade > 50 || acumulador > 50){
                        carro[opcao].quantidade -= num; //volta a condicao anterior.
                        carro[opcao].quantidadefixa -= num; //volta a condicao anterior.
                        acumulador -= num; //volta a condicao anterior.
                        printf("Não foi possível adicionar essa quantidade ao estoque. Você só pode adicionar até %d carros:\n> ", limite - acumulador);
                    }else{
                        system("cls");
                        return printf("Concluído com sucesso\n");
                    }
                }else if(num<=0){ //condição seja digitado uma opção invalida.
                    printf("Digite apenas números positivos:\n> " );
                }
            }
        }
    }
}
void estoque() //ESTOQUE referido a quantidade de carros que vao aparecer para o ADM.
{
    printf("Estoque: \n");
    for(int i=0; i<a; i++){
        printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatização: %s \nQuantidade disponível para aluguel: %d \nQuantidade total cadastrada desse modelo: %d\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon, carro[i].quantidade,carro[i].quantidadefixa);
    }
}
//FUNCOES DO CLIENTE ----------------------------------------------------------------------------------------------------------------------------------
void estoque_cliente()
{
    printf("Todos os carros do catálogo:\n");
    for(int i=0; i<a; i++){
        if (carro[i].quantidade > 0){
            printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
            v[i+1]=1; //registra posições que o cliente vai poder selecionar na função alugarCarro()
        }
        else if (carro[i].quantidade == 0){
            printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Esgotado\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
            v[i+1]=0; //registra posições que o cliente vai poder selecionar na função alugarCarro()
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
    if (num == 1){                   // opção de marca 1
    system("cls");
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].marca,fiat) == 0 && carro[i].quantidade > 0){           //disponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=1;
                controle = 1;    //impede a exibição dessa lista se ela estiver vazia
                block = 0;
            }
            else               //impede que o cliente selecione carros fora da lista
                v[i+1]=0;
                block = 0;

        }
    }
    else if(num == 2){
    system("cls");                 //opção de marca 2
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].marca,toyota) == 0 && carro[i].quantidade > 0){            //disponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=1;
                controle = 1;    //impede a exibição dessa lista se ela estiver vazia
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
    printf("Escolha o tipo de combustível que deseja visualizar: \n1- Gasolina \n2- Flex");
    while(block!=0){
    printf("\n> ");
    scanf("%d", &num);
    if (num == 1)   {                   // opção de combustível 1
    system("cls");
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].combustivel,comb1) == 0 && carro[i].quantidade > 0){             //disponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=1;
                controle = 1;    //impede a exibição dessa lista se ela estiver vazia
                block = 0;
            }
            else
                v[i+1]=0;
                block = 0;
        }
    }
    else if(num == 2){                 //opção de combustível 2
    system("cls");
        for(int i=0; i<a; i++){
            if (strcmp(carro[i].combustivel,comb2) == 0 && carro[i].quantidade > 0){             //disponível
                printf("-> Carro %d: \nMarca: %s \nModelo: %s \nCombustivel: %s \nClimatizacao: %s \nStatus: Disponivel\n\n",i+1, carro[i].marca, carro[i].modelo, carro[i].combustivel, carro[i].arcon);
                v[i+1]=1;
                controle = 1;    //impede a exibição dessa lista se ela estiver vazia
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
int custoAluguel()        //Calculo do preço cobrado ao cliente
{
    int dias, block = -1;
    float preco;
    printf("Por quantos dias você deseja alugar o carro?\n> ");
    while (block !=0){
        
        scanf("%d", &dias);

        if (dias > 30 || dias<=0){
            printf("Dado inválido! A quantidade máxima de dias para alugar é de 30 dias!\n");
            printf("Por quantos dias voce deseja alugar o carro?\n> ");
        }
        else 
        {
          return preco = (float) dias*60;  
        }
    }
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
        else if(v[opcao]==1){              //usa o vetor v[] para impedir que o usuário selecione carros fora da lista que está sendo exibida
            npreco = custoAluguel();
            printf("O aluguel do veiculo saira por R$ %.2f. Voce deseja alugar esse veiculo?\n1- Sim\t2- Nao\n", npreco);
            scanf("%d", &num);
            opcao -= 1; //voltar uma posicao do vetor carro e nao dar erro :D
            if(num == 1){
                carro[opcao].quantidade = carro[opcao].quantidade - 1;
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
        case 1:                                //Área do ADM
        senha();
        system("cls");
        while(resp!=0)
        {
            printf("-----------------Selecione qual opcao voce deseja-----------------\n");
            printf("1- Cadastrar carro;\n2- Mostrar estoque;\n3- Adicionar ao estoque;\n4- Voltar a tela inicial\n> ");
            scanf("%d", &num);
            if (num == 1){                  //Cadastrar carro
                system("cls");
                if (acumulador >= 50){
                    puts("Limite de cadastros excedido! Voce ainda pode listar os carros cadastrados ou voltar para o menu principal.\n");
                }else {
                Cadastro(); //Função para cadastrar os carros, todas as outras funções de cadastro do ADM estão dentro dela.
            }
            }else if (num == 2){           //Mostrar estoque
                system("cls");
                estoque();
                printf("Quantidade de veiculos cadastrados: %d\n\n", acumulador);
            }else if (num == 3){           //Renovar estoque
                if (acumulador >= 50){
                    system("cls");
                    printf("Limite de cadastros excedido! Você ainda pode listar os carros cadastrados ou voltar para o menu principal.\n");
                }else if (a == 0){
                    system("cls");
                    printf("Ainda nao ha carros cadastrados no estoque.\n");
                }else if (a > 0){
                    system("cls");
                    estoque();
                    adicaoEstoque();
                    }
            }else if (num == 4){           //Voltar a tela inicial
                system("cls");
                break;
            }else if(num<=0 || num>4){
                system("cls");
                printf("Selecione uma das opcões abaixo.\n\n");
            }
        }
        break;
        case 2:                            //Área do usuario
        system("cls");
        while(resp!=0)
        {
            printf("-----------------Listar automoveis disponiveis----------------- \n");
            printf("1- Todos os carros do catálogo; \n2- Por marca (disponíveis); \n3- Por tipo de combustivel (disponíveis); \n4- Sair.\n> ");
            scanf("%d", &num);
            if (num == 1){                //Todos os carros disponiveis;
                if(acumulador < 1){ //if para caso nao haja nenhum carro cadastrado no sistema.
                    system("cls");
                    printf("Ainda nao ha carros disponiveis para aluguel, tente mais tarde.\n");
                }else{
                    system("cls");
                    estoque_cliente();
                    alugarCarro();
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
                        controle=0; //o controle volta ao valor 0 para que funcione caso haja
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
                        break;
                    }
                }
            }else if (num == 4){        //Sair
                system("cls");
                break;
            }else if(num<0 || num>4){
                system("cls");
                printf("Digite um caracter válido.\n\n");
            }
        }
        break;
        default:
            system("cls");
            puts ("Selecione um caractere válido abaixo\n");
        }
        menu_principal();
    }
    return 0;
}