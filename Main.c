#include <stdio.h>
#include <locale.h>

int senha()
{
    char senha[10] = "aabbr", pass[10];
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
int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int user, resp=-1, num;
    //char senha[10] = "aabbr", pass[10]; /* duas senhas foram criadas para comparar, pois nao consegui comparar as strings normalmente, da conflito de tipo,
     //entao é preciso usar o strcmp*/

    printf ("--------------------- Menu Principal --------------------- \n\n");
    printf ("Escolha seu usuario:\n");
    printf ("1 - Administrador\n");
    printf ("2 - Cliente\n");
    printf ("Entre com o numero correspondente ao seu tipo de usuario:");

    while(resp!=0){
    printf("\n> ");
    scanf ("%d", &user);
        switch (user)
        {
        case 1:
            senha();
            printf("Digite um numero(teste): ");
            scanf("%d", &num);

            /*puts("Digite sua senha > \n");
            scanf ("%s",&pass);
                while ( strcmp (senha,pass)!= 0)
                {
            puts("Senha inválida! Digite a senha correta > \n");
            scanf ("%s", &pass);
                }
            puts ("\nEntrando no menu do Administrador . . . . . . . . . . .\n");*/
        break;
        case 2:
            puts ("\nEntrando no menu do Cliente . . . . . . . . . . . . . .\n");
        break;
        default:
            puts ("Caractere invalido");
        }
    system("cls");
    printf ("--------------------- Menu Principal --------------------- \n\n");
    printf ("Escolha seu usuario:\n");
    printf ("1 - Administrador\n");
    printf ("2 - Cliente\n");
    printf ("Entre com o numero correspondente ao seu tipo de usuario:");
    }

}
