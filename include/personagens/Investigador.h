#ifndef Investigador_H
#define Investigador_H

#include <string>
#include "Personagem.h"
#include "Detetive.h"
#include "../caderno/Caderno.h"
using namespace std;

class Investigador : public Detetive
{
protected:

public:
    Investigador(string nome, int observacao, int energia, int intuicao, Caderno caderno,  int cafe);
    bool podeExaminar() override;
    void listarInfos() override;
};

#endif