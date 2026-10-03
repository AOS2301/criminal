#include "../../include/personagens/Detetive.h"
#include <iostream>

Detetive::Detetive(string nome, int observacao, int calma, int intuicao, Caderno caderno, int cafe): Personagem(nome, observacao, calma), caderno(caderno), cafe(cafe)
{
}

Detetive::~Detetive()
{
}

int Detetive::getIntuicao()
{
    return intuicao;
}

Caderno Detetive::getCaderno()
{
    return caderno;
}

int Detetive::getCafe()
{
    return cafe;
}

void Detetive::listarInfos()
{
    cout << nome << endl;
    cout << observacao << endl;
    cout << intuicao << endl;
    cout << "Caderno está vazio por enquanto" << endl;
    cout << cafe << endl;
}