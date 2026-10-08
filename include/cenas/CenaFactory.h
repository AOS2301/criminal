#ifndef CenaFactory_H
#define CenaFactory_H

#include <fstream>
#include "Cena.h"

class CenaFactory
{
public:
    // static: não precisa criar um objeto CenaFactory para usar
    static Cena* criar(int numero);
};

#endif