/*
Repositório do Código: https://github.com/renatojuniorrs/projeto-integrado-b

Integrantes

Guilherme Araujo Alexandre 20133153
Lucas Ament 20011615
Renato Donizeti da Silva Junior 20014023

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <assert.h>
#include "./mods/functions.c"

int main()
{
    setlocale( LC_ALL, "" );
    system("COLOR F0");
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
    printf("Digite o nome do arquivo que deseja ler. \n - Ou digite 1 ou 2 ou 3 para selecionar o arquivo padrao. \n >> ");
    scanf("%s", &nome_arquivo);

    system("cls");

    if(nome_arquivo[0] == '1'){
        strcpy(nome_arquivo, "../files/1.txt");
    }else if(nome_arquivo[0] == '2'){
        strcpy(nome_arquivo, "../files/2.txt");
    }else if(nome_arquivo[0] == '3'){
        strcpy(nome_arquivo, "../files/3.txt");
    }

    printf("-- Estamos tentando abrir o arquivo: %s\n", nome_arquivo);
    fp = fopen(nome_arquivo, "rb");
    if (fp)
    {
        fscanf(fp, "%u", &tamanho_matriz);
    }
    else
    {
        printf("-- Nao conseguimos abrir o arquivo: %s :P\n", nome_arquivo);
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

    /*
    Parte 6 - Fazer cálculo do passo 8.
    */
    double segundo_elemento = (-matriz[1][0]), auxiliarsoma;
    for(int j = 0; j < (tamanho_matriz+1); j++)
    {
        // pegar os elementos da primeira linha e multiplicar com o elemento da segunda linha/primeira coluna
        auxiliarsoma = matriz[0][j] * segundo_elemento;

        // pegar a "multiplicação imaginaria" e somar com os elementos REAIS da segunda lina
        matriz[1][j] = matriz[1][j] + auxiliarsoma;
    }

    // Verificação de valores corretos - FIM

    /*
    Parte 7 - Fazer cálculo do passo 9.
    */
    double segundadiagonalprincipal = matriz[1][1];
    for(int j = 0; j < (tamanho_matriz+1); j++)
    {
        matriz[1][j] = matriz[1][j] / segundadiagonalprincipal;
    }


    /*
    // Parte 7 - Fazer cálculo do passo 10.
    */
    if(tamanho_matriz > 2)
    {
        double numeroauxiliar = (-matriz[2][1]), multiplicacaoauxiliar;
        for(int j = 0; j < (tamanho_matriz+1); j++)
        {
            multiplicacaoauxiliar = matriz[1][j] * numeroauxiliar;
            matriz[2][j] = matriz[2][j] + multiplicacaoauxiliar;

        }
    }else{
        double numeroauxiliar = (-matriz[0][1]), multiplicacaoauxiliar;
        for(int j = 0; j < (tamanho_matriz+1); j++)
        {
            multiplicacaoauxiliar = matriz[1][j] * numeroauxiliar;
            matriz[0][j] = matriz[0][j] + multiplicacaoauxiliar;

        }
    }


    // Parte 8 - Fazer cálculo do passo 11.
    if(tamanho_matriz > 2)
    {
        double terceiradiagonalprincipal = matriz[2][2];
        for (int j = 0; j < (tamanho_matriz+1); j++)
        {
            matriz[2][j] = matriz[2][j] / terceiradiagonalprincipal;
        }
    }


    // Parte 9 - Fazer cálculo do passo 12.
    if(tamanho_matriz > 2)
    {
        double segundamulticao, segundoauxiliar = (-matriz[0][2]);
        for(int j = 0; j < (tamanho_matriz+1); j++)
        {
            segundamulticao = matriz[2][j] * segundoauxiliar;
            matriz[0][j] = matriz[0][j] + segundamulticao;
        }
    }

    /*
    // Parte 10 - Fazer cálculo do passo 13.
    // */
    if(tamanho_matriz > 2)
    {
        double terceiramulticao, terceiroauxiliar = (-matriz[1][2]);
        for(int j = 0; j < (tamanho_matriz+1); j++)
        {
            terceiramulticao = matriz[2][j] * terceiroauxiliar;
            matriz[1][j] = matriz[1][j] + terceiramulticao;
        }
    }

    system("cls");
    // /*
    // Parte 11 -Exibir o resultado - passo 14.
    printf("\n\n----- Resultados \n");
    for(int i = 0; i < tamanho_matriz; i++)
    {
        printf("\n\n Variaveis %d = %.2f", i+1, matriz[i][tamanho_matriz]);
    }

    printf("\n\n");
    return 0;
}
