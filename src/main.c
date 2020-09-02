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
    printf("Digite o nome do arquivo que deseja ler: \n");
    scanf("%s", &nome_arquivo);

    system("cls");

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

    double primeiro_nao_zero;

    for (int i = 0; i < quantidade_de_linhas; i++)
    {
        if(matriz[i][i] == 0.0)
        {
            // Pegar primeiro não zero da linha
            primeiro_nao_zero = 0.0;
            for (int j = 0; j < quantidade_de_linhas; j++)
            {
                if(matriz[i][j] != 0.0)
                {
                    primeiro_nao_zero = matriz[i][j];
                    break;
                }
            }

            printf("--->> %f\n", primeiro_nao_zero);
            system("pause");
            
            if(primeiro_nao_zero == 0.0)
            {
                operacao_impossivel();
            }
            else
            {
                // Se tiver um número válido, vamos trocar
                for (int j = 0; j < quantidade_de_linhas; j++)
                {
                    if(i == j)
                    {
                        matriz[i][j] = primeiro_nao_zero;
                        break;
                    }
                    else if(primeiro_nao_zero != 0.0 && primeiro_nao_zero == matriz[i][j])
                    {
                        matriz[i][j] = 0.0;
                        primeiro_nao_zero = 0.0;
                    }
                }
            }
        }
    }

    // Verificação de valores corretos - INICIO
    for (int a = 0; a < tamanho_matriz; a++) {
        for (int b = 0; b < (tamanho_matriz+1); b++) {
            printf(" [%d][%d] = %f\n", a, b, matriz[a][b]);
        }
    }
    // Verificação de valores corretos - FIM

    // /*
    // Parte 5 - Fazer cálculo do passo 7.
    // */
    // int numdivisor_linha = matriz[0][0];
    // float divisao1linha_linha;
    //
    // for (j = 0; j < quantidade_de_colunas; j++)
    // {
    //     matriz[0][0] = 1;
    //     divisao1linha_linha = matriz[0][j] / numdivisor_linha;
    // }
    // /*
    // Parte 6 - Fazer cálculo do passo 8.
    // */
    // float numeroparazerar_coluna = - matriz[i][0], zerar_coluna;
    //
    // for(i = 1; i < quantidade_de_linhas; i++)
    // {
    //     zerar_coluna = matriz[i][0] * numeroparazerar_coluna;
    // }
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
