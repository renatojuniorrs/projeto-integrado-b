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

    // Perguntar ao usuario qual o tamanho da matriz? (n)
    // Ler o tamnho da matriz (n)
    int tamanho_matriz = 50;
    // printf("Qual o tamanho da matriz?\n");
    // scanf("%d", &tamanho_matriz);

    // Criar matriz com a quantidade n linhas e (n+1) colunas
    double** matriz = novamatriz(tamanho_matriz, (tamanho_matriz+1));

    // Perguntar ao usuario qual é o arquivo que ele vai ler
    char  arquivo[1024]; // String
    matriz = ler_arquivo(matriz);
    print_f("%d", matriz[0][0]);
    system("pause");
//
//     // Tentar ler o arquivo, se não conseguir ler o arquivo, dar uma mensagem de erro
//
//
//     // Se conseguir ler o arquivo, ler linha a linha do arquivo e colocar na matriz
//
//
//     FILE *file;
//     file = fopen ("ProjetoIntB.txt","w");
//
//     float matriz[3][4];
//
//     fscanf(file, "%i %i %i", &matriz[0][0], &matriz[0][1], &matriz[0][2], &matriz[0][3]);
//
//     printf("%i %i %i", matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]);
//
//     fclose(file);
//
//     // Essa parte sai - inicio
//
//     float matriz[3][4] =  {
//         {
//             0,3,2,28
//         },
//         {
//             4,0,2,24
//         },
//         {
//             2,3,0,16
//         },
//     };
//
//
//     // Essa parte sai - fim
//
//
//     /*
//     Parte 3 - Fazer cálculo do passo 5.
//     */
//     int quantidade_de_colunas = tamanho_matriz-1;
//     int quantidade_de_linhas = tamanho_matriz; // Não esquecer de subtrair
//     int cont = 0, c;
//     float divisao_linha, incremento_linha;
//
//     // Ver se a divisão das linhas não seja igual para continuar o cálculo
//     for (int i = 0; i < quantidade_de_linhas; i++)
//     {
//         for(c = 0; c < quantidade_de_linhas; c++)
//         {
//             for(j = 0; j <= quantidade_de_linhas; j++)
//             {
//                 if( i != c && c > i)
//                 {
//                     if(j == 0)
//                     {
//                         divisao_linha = matriz[i][j] / matriz[c][j];
//                         incremento_linha = divisao_linha;
//                     }
//                     incremento_linha = matriz[i][j] / matriz[c][j];
//                     if(divisao_linha == incremento_linha)
//                     {
//                         cont++;
//                     }
//                 }
//             }
//             if(cont == quantidade_de_linhas + 1)
//             {
//                 operacao_impossivel();
//             }
//             else
//             {
//                 count = 0;
//             }
//         }
//     }
// }
//
// // Verificação de valores corretos - INICIO
// if(matriz[2][2] != 2){
//     operacao_impossivel();
// }
// // Verificação de valores corretos - FIM
//
// /*
// Parte 4 - Fazer cálculo do passo 6.
// */
// // Não pode ter 0 na diagonal principal
//
// int primeiro_nao_zero;
//
// for (int i = 0; i < quantidade_de_linhas; i++)
// {
//     if(matriz[i][i] == 0)
//     {
//         primeiro_nao_zero = 0;
//         // Pegar primeiro não zero da linha
//         for (int j = 0; j < quantidade_de_linhas; j++)
//         {
//             if(matriz[i][j] !=  0)
//             {
//                 primeiro_nao_zero = matriz[i][j];
//                 break;
//             }
//         }
//
//         if(primeiro_nao_zero == 0)
//         {
//             operacao_impossivel();
//         }
//         else
//         {
//             // Se tiver um número válido, vamos trocar
//             for (int j = 0; j < quantidade_de_linhas; j++)
//             {
//                 if(i == j)
//                 {
//                     matriz[i][j] = primeiro_nao_zero;
//                     break;
//                 }
//                 else if(primeiro_nao_zero != 0 && primeiro_nao_zero == matriz[i][j])
//                 {
//                     matriz[i][j] = 0;
//                     primeiro_nao_zero = 0;
//                 }
//             }
//         }
//     }
// }
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
/*
// // Nao pode ter 0 na diagonal principal

int segundo_nao_zero;

for (int i=0; i < quantidade_de_linhas; i++);
{
      if(matriz[i][i] == 0);
      {
       segundo_nao_zero = 0;
       //Pegar segundo nao zero da linha
       for (int j = 0; j < quantidade_de_linhas; j++);
       {
           if(matriz[i][j] != 0);
           {
            segundo_nao_zero = matriz[i][j];
            break;
         }
     }

      if(segundo_nao_zero == 0);
      {
          operacao_impossivel();
    }
    else
{
           //Se tiver um numero valido vamos trocar
          for (int j= 0; j < quantidade_de_linhas; j++);
  {
      if(i == j)
      {
              matriz[i][j] = segundo_nao_zero;
              break
            }
            else if(segundo_nao_zero != 0 && segundo_nao_zero == matriz[i][j])

      }

  }
    }
}


*/
//                 {
//                     matriz[i][j] = primeiro_nao_zero;
//                     break;
//                 }
//                 else if(primeiro_nao_zero != 0 && primeiro_nao_zero == matriz[i][j])
//                 {
//                     matriz[i][j] = 0;
//                     primeiro_nao_zero = 0;
//                 }
//             }
//         }
//     }
// }
//  {
//  printf("Exibindo os valores da matriz \n\n");
//printf("matriz[%d] = %d \n", i, matriz[]);
//}


}
/*
// /*
// Parte 7 - Fazer cálculo do passo 10.
// */
//
//
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
