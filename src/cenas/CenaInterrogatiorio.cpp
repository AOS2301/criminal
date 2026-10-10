#include "../../include/cenas/CenaInterrogatorio.h"
#include <iostream>
#include <fstream>

// Bug: nenhum atributo era inicializado aqui. Se carregar() não encontrar
// alguma linha ("A:", "R:", "S:", "I:") no arquivo, astucia/resistencia/
// encerraInterrogatorio/sucesso/falha ficavam com lixo de memória (UB).
CenaInterrogatorio::CenaInterrogatorio()
    : astucia(0), resistencia(0), encerraInterrogatorio(false),
      sucesso(0), falha(0)
{
}

CenaInterrogatorio::~CenaInterrogatorio()
{
}

int CenaInterrogatorio::jogar(Detetive* detetive)
{
    cout << texto << endl;

    Suspeito* suspeito = new Suspeito(nomeMonstro, astucia, resistencia);

    int resultado = batalha(detetive, suspeito);

    delete suspeito;
    return resultado;
}

int CenaInterrogatorio::batalha(Detetive* detetive, Suspeito* suspeito)
{
    // TODO: implementar a batalha entre detetive e suspeito.
    return sucesso;
}

void CenaInterrogatorio::carregar(ifstream& arq)
{
    getline(arq, texto);                       // 2ª linha: o texto
    string linha;
    while (getline(arq, linha))
    {
        if (linha.empty()) continue;

        // Última linha do arquivo: "sucesso;falha" (sem prefixo)
        // Bug: find(';') pode retornar string::npos se a linha não tiver ';'
        // (ex.: linha mal formatada) — substr(pos+1) com pos==npos dá UB.
        // Também não há tratamento se stoi falhar (lança std::invalid_argument
        // e a exceção sobe sem ser tratada, encerrando o programa).
        if (linha.size() < 2 || linha[1] != ':')
        {
            size_t pos = linha.find(';');
            sucesso = stoi(linha.substr(0, pos));
            falha   = stoi(linha.substr(pos + 1));
            break;
        }

        char tipo = linha[0];
        string valor = linha.substr(2);
        if (!valor.empty() && valor[0] == ' ') valor.erase(0, 1);

        switch (tipo)
        {
            case 'N': nomeMonstro = valor;               break;
            case 'A': astucia = stoi(valor);             break;
            case 'R': resistencia = stoi(valor);         break;
            case 'S': encerraInterrogatorio = (valor == "S"); break;
            case 'I': item = valor;                      break; // parse do item depois
        }
    }
}