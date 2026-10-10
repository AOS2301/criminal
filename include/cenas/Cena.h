#ifndef Cena_H
#define Cena_H

#include <string>
#include <fstream> // faltava: carregar() recebe ifstream&, mas o header não incluía <fstream>
#include "../personagens/Detetive.h"
using namespace std;

class Cena
{
protected:
    string texto;
public:
    Cena();
    virtual ~Cena();

    virtual void carregar(ifstream &arq) = 0;

    virtual int jogar(Detetive* detetive) = 0;
};

#endif