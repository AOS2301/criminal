#ifndef Detetive_H
#define Detetive_H

#include <string>
#include "Personagem.h"
#include "../caderno/Caderno.h"
#include "../itens/Item.h"
using namespace std;

class Detetive : public Personagem
{
protected:
    int intuicao;
    Caderno caderno;
    int cafe;

public:
    Detetive(string nome, int observacao, int calma, int intuicao, Caderno caderno,  int cafe);
    virtual ~Detetive();

    int getIntuicao();
    Caderno getCaderno();
    int getCafe();

    virtual void listarInfos() = 0;
    virtual bool podeExaminar() = 0;
};

#endif