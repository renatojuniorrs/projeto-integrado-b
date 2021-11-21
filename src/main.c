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

    int tamanho_matriz = 0;
    char nome_arquivo[1024], line[1024];

    // Leitura do nome do Arquivo
    ler_char(nome_arquivo, "Digite o nome do arquivo que deseja ler. \n - Ou digite 1 ou 2 ou 3 para selecionar o arquivo padrao. \n>> ");
    system("cls");

    // Verifica se é um valor padrão
    valores_padroes(nome_arquivo);

    // realiza a leitura do arquivo inteiro
    ler_arquivo(nome_arquivo, &tamanho_matriz);

    // Criar matriz com a quantidade n linhas e (n+1) colunas
    double** matriz = novamatriz(tamanho_matriz, (tamanho_matriz+1));
    carregaMatriz(nome_arquivo, matriz);

    calcular_gauss(matriz, tamanho_matriz);

    // Exibir o resultado - passo 14.
    resultado(matriz, tamanho_matriz);

    printf("\n\n");
    return 0;
}
