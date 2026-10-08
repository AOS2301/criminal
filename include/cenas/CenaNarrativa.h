#ifndef CenaNarrativa_H
#define CenaNarrativa_H

#include <string>
#include "Cena.h"
using namespace std;

class CenaNarrativa : public Cena
{
protected:

public:
    CenaNarrativa();
    virtual ~CenaNarrativa();
    
    void carregar(ifstream &arq) override;
    
};

#endif