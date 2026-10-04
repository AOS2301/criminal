#ifndef Cena_H
#define Cena_H

#include <string>
using namespace std;

class Cena
{
protected:
    string tipoCena;
    string texto;
public:
    Cena();
    virtual ~Cena();

    virtual void executarCena(Cena* cena) = 0;

    string getTexto();
};

#endif