#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <assert.h>

#include<iostream>
#include <fstream>

#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>

using namespace std;


int operacao_impossivel(){
    printf("Operação Impossível!");
    return 1;
}


void carregaMatriz(char* nomeArq, double** mat)
{
    int qtdLins, lin, qtdCols, col;

    FILE* arq = fopen(nomeArq, "r");

    fscanf(arq, "%u", &qtdLins);
    qtdCols = qtdLins+1;

    for (lin = 0; lin < qtdLins; lin++)
        for (col = 0; col < qtdCols; col++)
        {

            fscanf(arq, "%lf", &mat[lin][col]);

        }

}

double** novamatriz (int quantidade_de_linhas, int quantidade_de_colunas)
{
    double** ret = (double**)malloc(quantidade_de_linhas*sizeof(double*));

    int linha;

    for (linha=0; linha<quantidade_de_linhas; linha++)
    ret[linha] = (double*)malloc(quantidade_de_colunas*sizeof(double));

    return ret;
}

int verificar_zeros_diagonal_principal(double** matriz, int quantidade_de_linhas)
{
    for (int i = 0; i < quantidade_de_linhas; i++)
    {
        if(matriz[i][i] == 0.0)
        {
            return 0;
        }
    }
    return 1;
}

int ler_char(char* nome_arquivo, char* text)
{
    printf("%s", text);
    scanf("%s", nome_arquivo);
    return 1;
}

int valores_padroes(char* nome_arquivo)
{
    if(nome_arquivo[0] == '1'){
        strcpy(nome_arquivo, "../files/1.txt");
    }else if(nome_arquivo[0] == '2'){
        strcpy(nome_arquivo, "../files/2.txt");
    }else if(nome_arquivo[0] == '3'){
        strcpy(nome_arquivo, "../files/3.txt");
    }
    return 1;
}

int ler_arquivo(char* nome_arquivo, int* tamanho_matriz)
{
    FILE *fp;
    fp = fopen(nome_arquivo, "rb");
    int valorAnterior = *tamanho_matriz;
    if (fp)
    {
        printf("-- Estamos tentando abrir o arquivo: %s\n", nome_arquivo);
        fscanf(fp, "%u", tamanho_matriz);
    }
    else
    {
        fclose(fp);
        printf("-- Nao conseguimos abrir o arquivo: %s :P\n", nome_arquivo);
        // system("pause");
        return 0;
    }
    if(valorAnterior == *tamanho_matriz){
        printf("-- Nao conseguimos abrir o arquivo: %s\n", nome_arquivo);
        return 0;
    }
    return 1;
}

int calculo_passo_5(double** matriz, int tamanho_matriz){
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
                return operacao_impossivel();
            }
            else
            {
                cont = 0;
            }
        }
    }
}

int calculo_passo_6(double** matriz, int tamanho_matriz){
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
        return operacao_impossivel();
    }
    return 0;
}

int calculo_passo_7(double** matriz, int tamanho_matriz){
    double primeiro_elemento =  matriz[0][0];
    for (int j = 0; j < (tamanho_matriz+1); j++)
    {
        matriz[0][j] = matriz[0][j] / primeiro_elemento;
    }
    return 0;
}

int calculo_passo_8(double** matriz, int tamanho_matriz){
    double segundo_elemento = (-matriz[1][0]), auxiliarsoma;
    for(int j = 0; j < (tamanho_matriz+1); j++)
    {
        // pegar os elementos da primeira linha e multiplicar com o elemento da segunda linha/primeira coluna
        auxiliarsoma = matriz[0][j] * segundo_elemento;

        // pegar a "multiplicação imaginaria" e somar com os elementos REAIS da segunda lina
        matriz[1][j] = matriz[1][j] + auxiliarsoma;
    }
    return 0;
}

int calculo_passo_9(double** matriz, int tamanho_matriz){
    double segundadiagonalprincipal = matriz[1][1];
    for(int j = 0; j < (tamanho_matriz+1); j++)
    {
        matriz[1][j] = matriz[1][j] / segundadiagonalprincipal;
    }
    return 0;
}

int calculo_passo_10(double** matriz, int tamanho_matriz){
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
    return 0;
}

int calculo_passo_11(double** matriz, int tamanho_matriz){
    if(tamanho_matriz > 2)
    {
        double terceiradiagonalprincipal = matriz[2][2];
        for (int j = 0; j < (tamanho_matriz+1); j++)
        {
            matriz[2][j] = matriz[2][j] / terceiradiagonalprincipal;
        }
    }
    return 0;
}

int calculo_passo_12(double** matriz, int tamanho_matriz){
    if(tamanho_matriz > 2)
    {
        double segundamulticao, segundoauxiliar = (-matriz[0][2]);
        for(int j = 0; j < (tamanho_matriz+1); j++)
        {
            segundamulticao = matriz[2][j] * segundoauxiliar;
            matriz[0][j] = matriz[0][j] + segundamulticao;
        }
    }
    return 0;
}

int calculo_passo_13(double** matriz, int tamanho_matriz){
    if(tamanho_matriz > 2)
    {
        double terceiramulticao, terceiroauxiliar = (-matriz[1][2]);
        for(int j = 0; j < (tamanho_matriz+1); j++)
        {
            terceiramulticao = matriz[2][j] * terceiroauxiliar;
            matriz[1][j] = matriz[1][j] + terceiramulticao;
        }
    }
    return 0;
}

int resultado(double** matriz, int tamanho_matriz){
    // system("cls");

    printf("\n\n----- Resultados \n");
    for(int i = 0; i < tamanho_matriz; i++)
    {
        printf("\n\n Variaveis %d = %.2f", i+1, matriz[i][tamanho_matriz]);
    }
    return 0;
}

int calcular_gauss(double** matriz, int tamanho_matriz){
    // Parte 3 - Fazer cálculo do passo 5.
    int falha5 = calculo_passo_5(matriz, tamanho_matriz);

    if(falha5 == 1){
        return 1;
    }

    // Fazer cálculo do passo 6.
    int falha6 = calculo_passo_6(matriz, tamanho_matriz);

    if(falha6 == 1){
        return 1;
    }

    // Fazer cálculo do passo 7.
    int falha7 = calculo_passo_7(matriz, tamanho_matriz);

    if(falha7 == 1){
        return 1;
    }

    // Fazer cálculo do passo 8.
    int falha8 = calculo_passo_8(matriz, tamanho_matriz);

    if(falha8 == 1){
        return 1;
    }

    // Fazer cálculo do passo 9.
    int falha9 = calculo_passo_9(matriz, tamanho_matriz);
    if(falha9 == 1){
        return 1;
    }

    // Fazer cálculo do passo 10.
    int falha10 = calculo_passo_10(matriz, tamanho_matriz);
    if(falha10 == 1){
        return 1;
    }

    // Fazer cálculo do passo 11.
    int falha11 = calculo_passo_11(matriz, tamanho_matriz);
    if(falha11 == 1){
        return 1;
    }

    // Fazer cálculo do passo 12.
    int falha12 = calculo_passo_12(matriz, tamanho_matriz);
    if(falha12 == 1){
        return 1;
    }

    // Fazer cálculo do passo 13.
    int falha13 = calculo_passo_13(matriz, tamanho_matriz);
    if(falha13 == 1){
        return 1;
    }

    return 0;
}
