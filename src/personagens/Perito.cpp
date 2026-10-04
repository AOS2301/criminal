#include "../../include/personagens/Perito.h"
#include <iostream>

Perito::Perito(string nome, int observacao, int calma, int intuicao, Caderno caderno, int cafe)
    : Detetive(nome, observacao, calma, intuicao, caderno, cafe)
{
}

bool Perito::podeExaminar()
{
    return true; 
}

void Perito::listarInfos()
{
    cout << nome << endl;
    cout << observacao << endl;
    cout << intuicao << endl;
    cout << "Caderno está vazio por enquanto" << endl;
    cout << cafe << endl;
    cout << "Perito!" << endl;
}