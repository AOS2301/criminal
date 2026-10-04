#ifndef CenaNarrativa_H
#define CenaNarrativa_H

#include <string>
#include "Cena.h"
using namespace std;

class CenaNarrativa : public Cena
{
protected:
    string texto;
public:
    CenaNarrativa();
    virtual ~CenaNarrativa();
    
    //void executarCena(ifstream cena) override;
};

#endif