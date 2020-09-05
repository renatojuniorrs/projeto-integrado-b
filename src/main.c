#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <assert.h>
#include "./mods/functions.c"

int main()
{
    setlocale(LC_ALL,"portuguese");
     system("COLOR 1F");
    /*
    Parte 1 - Ler variáveis de um arquivo
    - Ler arquivo
    */

    /*
    Parte 2 - Montar uma matriz a partir do arquivo
    */

    // Ler o tamnho da matriz (n)

    FILE *fp;
    unsigned int tamanho_matriz;
    char nome_arquivo[1024], line[1024];
    printf("Digite o nome do arquivo que deseja ler. \n - Ou digite 0 para selecionar o arquivo padrao. \n>> ");
    scanf("%s", &nome_arquivo);

    system("cls");

    if(nome_arquivo[0] == '0'){
        strcpy(nome_arquivo, "../files/ProjetoIntB.txt");
    }

    printf("-- Estamos tentando abrir o arquivo: %s\n", nome_arquivo);
    fp = fopen(nome_arquivo, "rb");
    if (fp)
    {
        fscanf(fp, "%u", &tamanho_matriz);
    }
    else
    {
        printf("-- Não conseguimos abrir o arquivo: %s :P\n", nome_arquivo);
        system("pause");
    }
    fclose(fp);

    // Criar matriz com a quantidade n linhas e (n+1) colunas
    double** matriz = novamatriz(tamanho_matriz, (tamanho_matriz+1));
    carregaMatriz(nome_arquivo, matriz);


    /*
    Parte 3 - Fazer cálculo do passo 5.
    */
    int quantidade_de_colunas = tamanho_matriz-1;
    int quantidade_de_linhas = tamanho_matriz; // Não esquecer de subtrair
    int cont = 0, c;
    float divisao_linha, incremento_linha;

    // Ver se a divisão das linhas não seja igual para continuar o cálculo
    for (int i = 0; i < quantidade_de_linhas; i++)
    {
        for(int c = 0; c < quantidade_de_linhas; c++)
        {
            for(int j = 0; j <= quantidade_de_linhas; j++)
            {
                if( i != c && c > i)
                {
                    if(j == 0)
                    {
                        divisao_linha = matriz[i][j] / matriz[c][j];
                        incremento_linha = divisao_linha;
                    }
                    incremento_linha = matriz[i][j] / matriz[c][j];
                    if(divisao_linha == incremento_linha)
                    {
                        cont++;
                    }
                }
            }
            if(cont == quantidade_de_linhas + 1)
            {
                operacao_impossivel();
            }
            else
            {
                cont = 0;
            }
        }
    }




    /*
    Parte 4 - Fazer cálculo do passo 6.
    */
    // Não pode ter 0 na diagonal principal
    double temp = 0;
    if(verificar_zeros_diagonal_principal(matriz, tamanho_matriz) == 0){
        for (int i = 0; i < tamanho_matriz; i++) {
            if (matriz[i][i] == 0.00) {
                if((i+1) < (tamanho_matriz-1)){
                    for (int k = 0; k < (tamanho_matriz+1); k++) {
                        temp = matriz[i][k];
                        matriz[i][k] = matriz[(i+1)][k];
                        matriz[(i+1)][k] = temp;
                    }
                }else if((i-1) > 0){
                    for (int k = 0; k < (tamanho_matriz+1); k++) {
                        temp = matriz[i][k];
                        matriz[i][k] = matriz[(i-1)][k];
                        matriz[(i-1)][k] = temp;
                    }

                }
            }
        }
    }

    if(verificar_zeros_diagonal_principal(matriz, tamanho_matriz) == 0){
        operacao_impossivel();
    }

    /*
    Parte 5 - Fazer cálculo do passo 7.
    */

    double primeiro_elemento =  matriz[0][0];
    for (int j = 0; j < (tamanho_matriz+1); j++)
    {
        matriz[0][j] = matriz[0][j] / primeiro_elemento;
    }

    //TODO: ATENÇÃO -- Daqui em diante está errado ou não foi testado

    /*
    Parte 6 - Fazer cálculo do passo 8.
    */
    double numeroparazerar_coluna, zerar_coluna;

    for(int i = 1; i < quantidade_de_linhas; i++)
    {
        numeroparazerar_coluna = - matriz[i][0];
        zerar_coluna = matriz[i][0] * numeroparazerar_coluna;
    }

    // ATENÇÃO: ESTE TRECHO DO CÓDIGO SERVE PARA TESTAR SE ESTÁ CORRETO OS VALORES DA MATRIZ
    // Verificação de valores corretos - INICIO
    printf("\n\n----- Debug \n");
    for (int a = 0; a < tamanho_matriz; a++) {
        for (int b = 0; b < (tamanho_matriz+1); b++) {
            printf(" [%d][%d] = %.2f\n", a, b, matriz[a][b]);
        }
    }
    // Verificação de valores corretos - FIM


    // /*
    // Parte 7 - Fazer cálculo do passo 9.
    //*/
    // // Nao pode ter 0 na diagonal principal
    //
    // int segundo_nao_zero;
    //
    // for (int i=0; i < quantidade_de_linhas; i++);
    // {
    //      if(matriz[i][i] == 0);
    //      {
    //       segundo_nao_zero = 0;
    //       //Pegar segundo nao zero da linha
    //       for (int j = 0; j < quantidade_de_linhas; j++);
    //       {
    //           if(matriz[i][j] != 0);
    //           {
    //                 segundo_nao_zero = matriz[i][j];
    //                 break;
    //         }
    //     }
    //
    //        if(segundo_nao_zero == 0);
    //        {
    //           operacao_impossivel();
    //        }
    //        else
    //        {
    //             //Se tiver um numero valido vamos trocar
    //            for (int j= 0; j < quantidade_de_linhas; j++);
    //            {
    //                 if(i == j)
    //                 {
    //                      matriz[i][j] = segundo_nao_zero;
    //                      break
    //                 }
    //                 else if(segundo_nao_zero != 0 && segundo_nao_zero == matriz[i][j])
    //                 {
    //                    matriz [i][j] = 0;
    //                    segundo_nao_zero = 0;
    //                 }
    //             }
    //         }
    //     }
    // }
    // /*
    // Parte 7 - Fazer cálculo do passo 10.
    // */
    // // Não pode ter 0 na diagonal principal
    //
    // int segundo_nao_zero;
    //
    // for(int i=0; i < quantidade_de_colunas; i++);
    // {
    //       if(matriz[i][i] == 0);
    //       {
    //       segundo_nao_zero = 0;
    //       //Pegar segundo nao zero da linha
    //       for (int j = 0; j < quantidade_de_colunas; j++);
    //       {
    //           if (matriz[i][j] != 0);
    //           {
    //                  segundo_nao_zero = matriz[i][j];
    //                  break;
    //          }
    //       }
    //
    //        if(segundo_nao_zero == 0);
    //        {
    //            operacao_impossivel();
    //        }
    //        else
    //        {
    //              //Se tiver um numero valido vamos trocar
    //              for (int j = 0; j < quantidade_de_colunas; j++);
    //              {
    //                   if(i == j)
    //                   {
    //                         matriz[i][j] =segundo_nao_zero;
    //                         break
    //                   }
    //                   else if(segundo_nao_zero != 0 && segundo_nao_zero == matriz[i][j]);
    //                   {
    //                      matriz [i][j] = 0;
    //                      segundo_nao_zero = 0;
    //                   }
    //              }
    //          }
    //      }
    //  }
    // /*
    // Parte 8 - Fazer cálculo do passo 11.
    // */
    //
    //
    // /*
    // Parte 9 - Fazer cálculo do passo 12.
    // */
    //
    //
    // /*
    // Parte 10 - Fazer cálculo do passo 13.
    // */
    //
    //
    // /*
    // Parte 11 -Exibir o resultado - passo 14.
    // */


    return 0;
}
