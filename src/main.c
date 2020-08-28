#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

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
    int tamanho_matriz;
     printf("Qual o tamanho da matriz?");
     scanf("%d", &tamanho_matriz);

    // Criar matriz com a quantidade n linhas e (n+1) colunas

    // Perguntar ao usuario qual é o arquivo que ele vai ler
    // Tentar ler o arquivo, se não conseguir ler o arquivo, dar uma mensagem de erro
    // Se conseguir ler o arquivo, ler linha a linha do arquivo e colocar na matriz

    FILE *file;
    file = fopen ("ProjetoIntB.txt","w");

    float matriz[3][4];

    fscanf(file, "%i %i %i", &matriz[0][0], &matriz[0][1], &matriz[0][2], &matriz[0][3]);

    printf("%i %i %i", matriz[0][0], matriz[0][1], matriz[0][2], matriz[0][3]);

    fclose(file);

    // Essa parte sai - inicio

    float matriz[3][4] =  {
        {
            0,3,2,28
        },
        {
            4,0,2,24
        },
        {
            2,3,0,16
        },
    };


    // Essa parte sai - fim


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
     for(c = 0; c < quantidade_de_linhas; c++)
     {
       for(j = 0; j <= quantidade_de_linhas; j++)
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
         count = 0;
       }
     }
   }
       //matriz[0][0]/matriz[1][0]
       //matriz[0][1]/matriz[1][1]
       //matriz[0][2]//matriz[2][2]

        //PRIMEIRO par de linhas
        // if( (matriz[quantidade_de_colunas][i]/matriz[quantidade_de_colunas][(i+1)]) == (matriz[(quantidade_de_colunas+1)][i]/matriz[(quantidade_de_colunas+1)][(i+1)]) // 0/4 != 3/0
        // && ((matriz[quantidade_de_colunas][i]/matriz[quantidade_de_colunas][(i+1)]) == (matriz[(quantidade_de_colunas+2))][i]/matriz[(quantidade_de_colunas+2)][(i+2)]))// 0/4 != 2/2
        // && ((matriz[(quantidade_de_colunas+1)][i]/matriz[(quantidade_de_colunas+1)][(i+1)]) == (matriz[(quantidade_de_colunas+2))][i]/matriz[(quantidade_de_colunas+2)][(i+2)])) // 3/0 !=0 2/2
        // {
        //    operacao_impossivel();
        // }
        // else
        // {
        //     // SEGUNDO par de linhas

        // }
        //     /* code */
    }

    // Verificação de valores corretos - INICIO
    if(matriz[2][2] != 2){
        operacao_impossivel();
    }
    // Verificação de valores corretos - FIM

    /*
        Parte 4 - Fazer cálculo do passo 6.
    */
    // Não pode ter 0 na diagonal principal

    int primeiro_nao_zero;

    for (int i = 0; i < quantidade_de_linhas; i++)
    {
        if(matriz[i][i] == 0)
        {
            primeiro_nao_zero = 0;
            // Pegar primeiro não zero da linha
            for (int j = 0; j < quantidade_de_linhas; j++)
            {
                if(matriz[i][j] !=  0)
                {
                    primeiro_nao_zero = matriz[i][j];
                    break;
                }
            }

            if(primeiro_nao_zero == 0)
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
                    else if(primeiro_nao_zero != 0 && primeiro_nao_zero == matriz[i][j])
                    {
                        matriz[i][j] = 0;
                        primeiro_nao_zero = 0;
                    }
                }
            }
        }
    }


    /*
        Parte 5 - Fazer cálculo do passo 7.
    */


    /*
        Parte 6 - Fazer cálculo do passo 8.
    */


    /*
        Parte 7 - Fazer cálculo do passo 9.
    */


    /*
        Parte 7 - Fazer cálculo do passo 10.
    */


    /*
        Parte 8 - Fazer cálculo do passo 11.
    */


    /*
        Parte 9 - Fazer cálculo do passo 12.
    */


    /*
        Parte 10 - Fazer cálculo do passo 13.
    */


    /*
        Parte 11 -Exibir o resultado - passo 14.
    */


    return 0;
}

int operacao_impossivel(){
    system("clear");
    printf("- Não é possível concluir esta operação!");
    system("pause");

    return 0;
}


double** novamatriz (unsigned int quantidade_de_linhas, unsigned int quantidade_de_colunas)
{
  double** ret = (double**)malloc(quantidade_de_linhas*sizeof(double*));

  unsigned int linha;

  for (linha=0; linha<quantidade_de_linhas; linha++)
      ret[linha] = (double*)malloc(quantidade_de_colunas*sizeof(double));

    return ret;
}
