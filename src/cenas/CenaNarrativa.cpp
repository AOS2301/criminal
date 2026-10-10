#include "../../include/cenas/CenaNarrativa.h"
#include "../../include/jogo/Leitor.h"
#include <iostream>
#include <fstream>

CenaNarrativa::CenaNarrativa()
{
}

CenaNarrativa::~CenaNarrativa()
{
}

void CenaNarrativa::carregar(ifstream& arq)
{
    // Bug: a leitura do texto estava comentada ("//getline(arq, texto)"),
    // então "texto" nunca era preenchido e nenhuma outra linha era lida.
    getline(arq, texto); // 2ª linha do arquivo: o texto da cena

    string linha;
    while (getline(arq, linha))
    {
        if (linha.empty()) continue;

        // Só trata o caso simples "#N: descricao". Linhas "I:" (item) e
        // "C:" (coleta) ainda não são tratadas — TODO.
        if (linha[0] == '#')
        {
            size_t fimNumero = linha.find_first_not_of("0123456789", 1);
            int proximaCena = stoi(linha.substr(1, fimNumero - 1));

            size_t pos = linha.find(':');
            string descricao = (pos != string::npos) ? linha.substr(pos + 1) : "";
            if (!descricao.empty() && descricao[0] == ' ') descricao.erase(0, 1);

            opcoes.push_back({proximaCena, descricao});
        }
    }
}

int CenaNarrativa::jogar(Detetive* detetive)
{
    cout << texto << endl;

    if (opcoes.empty())
    {
        // Cena sem escolhas: não há para onde ir.
        return -1;
    }

    for (size_t i = 0; i < opcoes.size(); i++)
    {
        cout << (i + 1) << " - " << opcoes[i].second << endl;
    }

    Leitor leitor;
    int escolha = leitor.lerOpcao(1, (int)opcoes.size());
    return opcoes[escolha - 1].first;
}