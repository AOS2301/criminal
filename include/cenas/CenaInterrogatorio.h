#ifndef CenaInterrogatorio_H
#define CenaInterrogatorio_H

#include <string>
#include "Cena.h"
using namespace std;

class CenaInterrogatorio : public Cena
{
protected:
    int sucesso;
    int falha;
public:
    CenaInterrogatorio();
    virtual ~CenaInterrogatorio();
    
    void carregar(ifstream &arq) override;
    
};

#endif