#include "../../include/cenas/CenaInterrogatorio.h"
#include <iostream>
#include <fstream>

CenaInterrogatorio::CenaInterrogatorio()
{
}

CenaInterrogatorio::~CenaInterrogatorio()
{
}

void CenaInterrogatorio::carregar(ifstream& arq)
{
    getline(arq, texto);                  // 2ª linha: o texto
    string linha;
    getline(arq, linha);                  // "10;11"
    size_t pos = linha.find(';');
    sucesso = stoi(linha.substr(0, pos));
    falha   = stoi(linha.substr(pos + 1));
}