#include "../../include/cenas/CenaNarrativa.h"
#include <iostream>
#include <fstream>
CenaNarrativa::CenaNarrativa()
{
}

CenaNarrativa::~CenaNarrativa()
{
}

void CenaNarrativa::carregar(ifstream& arq)
{
    getline(arq, texto);                  // 2ª linha: o texto
    string linha;
    getline(arq, linha);                  // "10;11"
    size_t pos = linha.find(';');
    if(linha == "I"){
        //é um tipo de ITEM
    }
}