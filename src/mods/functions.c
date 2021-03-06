int operacao_impossivel(){
    system("cls");
    printf("- Não é possível concluir esta operação!");
    system("pause");

    return 0;
}


void carregaMatriz(char* nomeArq, double** mat)
{
    unsigned int qtdLins, lin, qtdCols, col;

    FILE* arq = fopen(nomeArq, "r");

    fscanf(arq, "%u", &qtdLins);
    qtdCols = qtdLins+1;

    for (lin = 0; lin < qtdLins; lin++)
        for (col = 0; col < qtdCols; col++)
        {
            fscanf(arq, "%lf", &mat[lin][col]);
        }
}

double** novamatriz (unsigned int quantidade_de_linhas, unsigned int quantidade_de_colunas)
{
    double** ret = (double**)malloc(quantidade_de_linhas*sizeof(double*));

    unsigned int linha;

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
