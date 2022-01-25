/* Um exemplo de jogo-da-velha simples */

#include <stdio.h>
#include <stdlib.h>

//matriz do jogo
char matrix[3][3];

//prototipos
char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

//main
int main()
{
    char done;

    printf("Jogo da Velha 0.1 \n");
    printf("Criado por Cristiano Camacho 24/01/2022\n");
    printf("Voce estara jogando contra o computador.\n\n");

    done = ' ';
    init_matrix();

    do
    {
        disp_matrix();
        get_player_move();
         done = check(); //verifica se há um vencedor
         if(done != ' ') break; //vencedor
        get_computer_move();
         done = check(); //verifica se há um vencedor
    }while(done== ' ');

        if(done == 'X') printf("Voce ganhou!\n");
        else printf("Eu ganhei!!!!\n");

    disp_matrix();//mostra as posicoes finais
}

//inicializa a matrix
void init_matrix(void)
{
    int i, j;

    for(i=0; i<3; i++)
        for(j=0; j<3; j++) matrix[i][j] = ' ';
}

//obtem sua jogada
void get_player_move(void)
{
    int x, y;

    printf("\nDigite as coordenadas para o X e Y: ");
    scanf("%d%d", &x, &y);

    x--; y--;

    if(matrix[x][y] != ' ') {
        printf("Posicao invalida, tente novamente! \n");
            get_player_move();
    }
    else matrix[x][y] = 'X';
}

//obtem uma jogada do computador
void get_computer_move(void)
{
    int i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++)
            if(matrix[i][j] == ' ') break;
        if(matrix[i][j] == ' ') break;
    }

    if(i*j==9) {
        printf("empate\n");
        exit(0);
    }
    else
       matrix[i][j] = 'O';
}

//mostra a matriz na tela
void disp_matrix(void)
{
    int t;
    for (t=0; t<3 ;t++){
        printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
        if(t != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

//verifica se há um vencedor
char check(void)
{
    int i;

    for (i=0; i<3 ;i++)//verirfica as linhas
        if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) return matrix[i][0];

    for (i=0; i<3 ;i++)//verirfica as colunas
        if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) return matrix[0][i];

    //verifica e testa as diagonais
       if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) return matrix[0][0];
       if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) return matrix[0][2];

    return ' ';
}
