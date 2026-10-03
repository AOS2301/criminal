#include "../../include/jogo/JogoSalvo.h"
#include <iostream>
#include <fstream>
#include <limits> 

JogoSalvo::JogoSalvo()
{
}

JogoSalvo::~JogoSalvo()
{
}

void JogoSalvo::salvarJogo(string nomeSave)
{
    ofstream arq("data/" + nome + ".txt");
}