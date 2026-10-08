#include "../../include/cenas/CenaFactory.h"
#include "../../include/cenas/CenaNarrativa.h"
#include "../../include/cenas/CenaInterrogatorio.h"
// ... includes das outras filhas
#include <fstream>
#include <iostream>

Cena* CenaFactory::criar(int numero)
{
    ifstream arq("historia/" + to_string(numero) + ".txt");
    if (!arq.is_open()) {
        cerr << "Erro: cena " << numero << " nao encontrada" << endl;
        return nullptr;
    }

    string tipo;
    getline(arq, tipo);              // 1ª linha: n, t, i, e, a ou f

    Cena* cena = nullptr;
    if      (tipo == "n") cena = new CenaNarrativa();
    else if (tipo == "i") cena = new CenaInterrogatorio();
    /*else if (tipo == "t") cena = new CenaTeste();
    
    else if (tipo == "e") cena = new CenaEnigma();
    else if (tipo == "a") cena = new CenaAcusacao();
    else if (tipo == "f") cena = new CenaFinal();*/

    if (cena != nullptr) {
        cena->carregar(arq);         // a filha lê o resto do arquivo
    }
    return cena;
}