#ifndef Detetive_H
#define Detetive_H

#include <string>
#include "Personagem.h"
#include "../caderno/Caderno.h"
using namespace std;

class Detetive : public Personagem
{
protected:
    Caderno caderno;
    int intuicao;
    int cafe;

public:
    Detetive(string nome, int habilidade, int energia, Caderno caderno, int intuicao, int cafe);
    virtual ~Detetive();

    Caderno getCaderno();
    int getIntuicao();
    int getCafe();
};

#endif