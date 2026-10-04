#ifndef Jogo_H
#define Jogo_H

#include <string>
#include "Leitor.h"
#include "../cenas/Cena.h"
#include "../personagens/Detetive.h"
#include "../personagens/Perito.h"
#include "../personagens/Investigador.h"
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
    void jogar();
    void criarPersonagem();
    void mostrarCreditos();
    Leitor getLeitor();
    //void lerCena(Cena &cena);
};

#endif