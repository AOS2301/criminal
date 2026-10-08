#ifndef Cena_H
#define Cena_H

#include <string>
using namespace std;

class Cena
{
protected:
    string texto;
public:
    Cena();
    virtual ~Cena();

    virtual void carregar(ifstream &arq) = 0;
};

#endif