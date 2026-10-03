#ifndef Personagem_H
#define Personagem_H

#include <string>
using namespace std;

class Personagem
{
protected:
    string nome;
    int observacao; // detetive: observação | suspeito: astúcia
    int calma; // detetive: calma      | suspeito: resistência
    
public:
    Personagem(string nome, int observacao, int calma);
    virtual ~Personagem();

    string getNome();
    int getObservacao();
    int getCalma();

    virtual void listarInfos() = 0;
};

#endif