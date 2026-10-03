#ifndef Leitor_H
#define Leitor_H

#include <string>
#include "cenas/Cena.h"
using namespace std;

class Leitor
{
private:
    string caminhoArquivo;
public:
    Leitor();
    ~Leitor();

    void lerArquivo(string caminhoArquivo);
    int lerOpcao(int minimo, int maximo);
    //void lerCena(Cena &cena);
};

#endif