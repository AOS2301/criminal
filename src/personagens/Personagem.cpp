#include "../../include/personagens/Personagem.h"
#include <iostream>

Personagem::Personagem(string nome, int observacao, int calma): nome(nome), observacao(observacao), calma(calma)
{
}

Personagem::~Personagem()
{
}

string Personagem::getNome()
{
    return nome;
}

int Personagem::getObservacao()
{
    return observacao;
}

int Personagem::getCalma()
{
    return calma;
}