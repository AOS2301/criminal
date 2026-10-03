#ifndef Caderno_H
#define Caderno_H

#include <string>
#include "../itens/Item.h"
#include <vector>
using namespace std;

class Caderno
{
private:
    vector<Item*> itens;
    Item* ferramentaEquipada;

public:
    Caderno();
    //Caderno(string nome, int observacao, int calma, int intuicao);
    virtual ~Caderno();
};

#endif