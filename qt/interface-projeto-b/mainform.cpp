/*
 * Renato Donizeti da Silva Junior RA 20014023
 *
 */

#include "mainform.h"
#include "ui_mainform.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>

#include "./src/mods/functions.cpp"

using namespace std;

void messageShow()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Impossível Calcular");
    msgBox.setText("Não é possível realizar o cálculo, o arquivo não parece estar em um formato válido para leitura");
    msgBox.exec();
}

bool is_file_exist(const string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

MainForm::MainForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}


void MainForm::on_pushButton_2_clicked()
{

    // QMessageBox msgBox;
    // msgBox.setText(ui->fileInputName->text());
    // msgBox.exec();

    // Arquivo e variáveis
    QString fileName = ui->fileInputName->text();
    QString fileContent = ui->fileEditorText->toPlainText();

    ofstream file;
    file.open (fileName.toStdString());
    file << fileContent.toStdString();
    file.close();

}


void MainForm::on_pushButton_clicked()
{
    string textLine;
    QString fileName = ui->fileInputName->text();
    QString finalResult;
    finalResult.fromStdString("");

    if(!is_file_exist(fileName.toStdString())){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Arquivo não existe!");
        msgBox.setText(ui->fileInputName->text()+" Não foi encontrado");
        msgBox.exec();
        return;
    }

    int tamanho_matriz = 0;
    char * nome_arquivo = fileName.toStdString().data();
    int falhou = 0;
    // realiza a leitura do arquivo inteiro
    ler_arquivo(nome_arquivo, &tamanho_matriz);
    if(tamanho_matriz <= 0){
        messageShow();
        return;
    }
    // Criar matriz com a quantidade n linhas e (n+1) colunas
    double** matriz = novamatriz(tamanho_matriz, (tamanho_matriz+1));
    carregaMatriz(nome_arquivo, matriz);

    falhou = calcular_gauss(matriz, tamanho_matriz);
    printf("%d", falhou);
    if(falhou == 1){
        messageShow();
        return;
    }
    // Exibir o resultado - passo 14.

    for(int i = 0; i < tamanho_matriz; i++)
    {
        string resultado = std::to_string(matriz[i][tamanho_matriz]);
        string variavel = std::to_string(i+1);
        string resultadoFinal = "";
        resultadoFinal += "Variavel ";
        resultadoFinal += variavel;
        resultadoFinal += ": ";
        resultadoFinal += resultado;
        resultadoFinal += "\n";
        finalResult.append(QString::fromStdString(resultadoFinal));
    }

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Resultado");
    msgBox.setText(finalResult);
    msgBox.exec();
}


void MainForm::on_pushButton_3_clicked()
{
    string textLine;
    QString fileName = ui->fileInputName->text();
    ifstream readFile(fileName.toStdString());

    if(!is_file_exist(fileName.toStdString())){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Arquivo não existe!");
        msgBox.setText(ui->fileInputName->text()+" Não foi encontrado");
        msgBox.exec();
        return;
    }


    ui->fileEditorText->clear();
    while (getline (readFile, textLine)) {
      ui->fileEditorText->appendPlainText(QString::fromStdString(textLine));
    }
    readFile.close();
}


void MainForm::on_fileInputName_editingFinished()
{
    string textLine;
    QString fileName = ui->fileInputName->text();
    ifstream readFile(fileName.toStdString());

    if(is_file_exist(fileName.toStdString())){
        this->on_pushButton_3_clicked();
    }
}

