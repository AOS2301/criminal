#ifndef Perito_H
#define Perito_H

#include <string>
#include "Personagem.h"
#include "Detetive.h"
#include "../caderno/Caderno.h"
using namespace std;

class Perito : public Detetive
{
protected:

public:
    Perito(string nome, int observacao, int energia, int intuicao, Caderno caderno,  int cafe);
    bool podeExaminar() override;
    void listarInfos() override;
};

#endif