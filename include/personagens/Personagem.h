#ifndef Personagem_H
#define Personagem_H

#include <string>
using namespace std;

class Personagem
{
protected:
    string nome;
    int habilidade; // detetive: calma      | suspeito: resistência
    int energia; // detetive: observação | suspeito: astúcia

public:
    Personagem(string nome, int habilidade, int energia);
    virtual ~Personagem();

    string getNome();
};

#endif