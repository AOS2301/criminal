#include "../../include/jogo/Leitor.h"
#include <iostream>
#include <fstream>

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
            return selecao;
        }
        cin.clear();
        cout << "Opcao invalida. Digite um numero entre "
             << minimo << " e " << maximo << "." << endl;
    }
}
