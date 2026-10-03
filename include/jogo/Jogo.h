#ifndef Jogo_H
#define Jogo_H

#include <string>
#include "Leitor.h"
#include "../personagens/Detetive.h"
using namespace std;

class Jogo
{
private:
    Detetive* detetive;
    Leitor leitor;
    int cenaAtual;
public:
    Jogo();
    ~Jogo();

    void executar();
    void criarPersonagem();
    void mostrarCreditos();
    Leitor getLeitor();
    //void lerCena(Cena &cena);
};

#endif