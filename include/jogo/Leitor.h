#ifndef Leitor_H
#define Leitor_H

#include <string>
using namespace std;

class Leitor
{
public:
    Leitor();
    ~Leitor();

    void lerArquivo(string caminhoArquivo);
    int lerOpcao(int minimo, int maximo);
    void pausar();
    //void lerCena(Cena &cena);
};

#endif