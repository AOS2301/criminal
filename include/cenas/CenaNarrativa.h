#ifndef CenaNarrativa_H
#define CenaNarrativa_H

#include <string>
#include <vector>
#include <utility>
#include "Cena.h"
using namespace std;

class CenaNarrativa : public Cena
{
protected:
    // Cada escolha "#N: descricao" do arquivo vira um par <proximaCena, descricao>.
    // TODO: as condições "{forense}" e itens exigidos "[Lanterna]" das linhas
    // "#N{...}" / "#N[...]" ainda não são lidas nem verificadas aqui.
    vector<pair<int, string>> opcoes;

public:
    CenaNarrativa();
    virtual ~CenaNarrativa();

    void carregar(ifstream &arq) override;
    // Antes CenaNarrativa não sobrescrevia jogar(): como Cena::jogar() é
    // puro virtual, isso tornava CenaNarrativa uma classe abstrata e
    // "new CenaNarrativa()" em CenaFactory::criar não compilava.
    int jogar(Detetive* detetive) override;
};

#endif