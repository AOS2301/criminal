#include "../../include/jogo/Leitor.h"
#include <iostream>
#include <fstream>
#include <limits> 

Leitor::Leitor()
{
}

Leitor::~Leitor()
{
}

void Leitor::lerArquivo(string caminho)
{
    ifstream arq(caminho);
    string linha;
    if (!arq.is_open()) {
        cerr << "Erro: nao foi possivel abrir " << caminho << endl;
        return;
    }

    while (getline(arq, linha)) {
        cout << linha << endl;
    }
}

int Leitor::lerOpcao(int minimo, int maximo)
{
    int selecao;
    while (true) {
        cout << "> ";
        if (cin >> selecao && selecao >= minimo && selecao <= maximo) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return selecao;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Opcao invalida. Digite um numero entre "
             << minimo << " e " << maximo << "." << endl;
    }
}

void Leitor::pausar()
{
    cout << "(Pressione Enter para continuar)";
    string linha;
    getline(cin, linha);
}