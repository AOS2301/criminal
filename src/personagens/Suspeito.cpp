#include "../../include/personagens/Suspeito.h"
#include <iostream>

Suspeito::Suspeito(string nome, int observacao, int energia): Personagem(nome, observacao, energia)
{
}

Suspeito::~Suspeito()
{
}

void Suspeito::listarInfos()
{
    cout << "Suspeito: " << nome << endl;
}
