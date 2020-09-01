int operacao_impossivel(){
    system("cls");
    printf("- Não é possível concluir esta operação!");
    system("pause");

    return 0;
}

double* str_split(char* a_str, const char a_delim)
{
    char piece[1024] = "";
    size_t i, arr_size = 0;

    for (i = 0; i < strlen(a_str); i++) {
        if(a_str[i] == " "){
            piece = "";
            arr_size++;
        }
    }
    arr_size++;

    double* matriz;
    double* matriz = (double* )malloc(arr_size*sizeof(double));

    arr_size = 0;

    for (i = 0; i < strlen(a_str); i++) {
        if(a_str[i] == " "){
            sscanf(piece, "%lf", &matriz[arr_size]);
            arr_size++;
            piece = "";
        }else{
            piece = piece + a_str[i];
            arr_size++;
        }
    }
    sscanf(piece, "%lf", &matriz[arr_size]);

    return matriz;
}

double** novamatriz (unsigned int quantidade_de_linhas, unsigned int quantidade_de_colunas)
{
    double** ret = (double**)malloc(quantidade_de_linhas*sizeof(double*));

    unsigned int linha;

    for (linha=0; linha<quantidade_de_linhas; linha++)
    ret[linha] = (double*)malloc(quantidade_de_colunas*sizeof(double));

    return ret;
}

double** ler_arquivo(double** matriz)
{
    double* tokens;
    FILE *fp;
    int line_m = 0, column_m = 0;
    char nome_arquivo[1024], line[1024];
    printf("Digite o nome do arquivo que deseja ler: \n");
    scanf("%s", &nome_arquivo);
    // system("cls");
    printf("-- Estamos tentando abrir o arquivo: %s\n", nome_arquivo);
    fp = fopen(nome_arquivo, "rb");
    if (fp)
    {
        while (fgets(line, sizeof(line), fp)) {
            tokens = str_split(line, " ");
            if (tokens)
            {
                for (size_t i = 0; i < (sizeof(tokens) / sizeof(double)); i++) {
                    matriz[line_m][column_m] = tokens[i];
                    column_m++;
                }
            }
            line_m++;
        }
    }
    else
    {
        printf("-- Não conseguimos abrir o arquivo: %s :P\n", nome_arquivo);
        system("pause");
    }
    fclose(fp);

    return matriz;
}
