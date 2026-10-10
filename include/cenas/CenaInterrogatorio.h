#ifndef CenaInterrogatorio_H
#define CenaInterrogatorio_H

#include <string>
#include "Cena.h"
#include "../personagens/Personagem.h"
#include "../personagens/Suspeito.h"

using namespace std;

class CenaInterrogatorio : public Cena
{
protected:
    string nomeMonstro;
    int astucia;
    int resistencia;
    bool encerraInterrogatorio;
    string item;

    int sucesso;
    int falha;
public:
    CenaInterrogatorio();
    virtual ~CenaInterrogatorio();
    
    void carregar(ifstream &arq) override;
    int jogar(Detetive* detetive) override; // retorna o número da próxima cena (sucesso ou falha)

    int batalha(Detetive* detetive, Suspeito* suspeito); // implementar a lógica da batalha
};

#endif