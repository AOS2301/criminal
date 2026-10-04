#include "../../include/personagens/Investigador.h"
#include <iostream>

Investigador::Investigador(string nome, int observacao, int calma, int intuicao, Caderno caderno, int cafe)
    : Detetive(nome, observacao, calma, intuicao, caderno, cafe)
{
}

bool Investigador::podeExaminar()
{
    return false; 
}

void Investigador::listarInfos()
{
    cout << nome << endl;
    cout << observacao << endl;
    cout << intuicao << endl;
    cout << "Caderno está vazio por enquanto" << endl;
    cout << cafe << endl;
    cout << "Investigador!" << endl;
}