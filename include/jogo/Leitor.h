#ifndef Leitor_H
#define Leitor_H

#include <string>
using namespace std;

class Leitor
{
public:
    Leitor();
    ~Leitor();

    void imprimirArquivo(string caminhoArquivo);
    int lerOpcao(int minimo, int maximo);
    void pausar();
};

#endif