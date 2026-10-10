#ifndef Suspeito_H
#define Suspeito_H

#include <string>
#include "Personagem.h"
using namespace std;

class Suspeito : public Personagem
{
protected:
    
public:
    Suspeito(string nome, int observacao, int energia);
    virtual ~Suspeito();

    void listarInfos() override;
};

#endif