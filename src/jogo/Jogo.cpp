#include "../../include/jogo/Jogo.h"
#include <iostream>
#include <vector>

Jogo::Jogo()
{
    detetive = nullptr;
}

Jogo::~Jogo()
{
    if (detetive != nullptr)
    {
        delete detetive;
    }
}

void Jogo::executar()
{
    while (true)
    {
        leitor.imprimirArquivo("telas/abertura.txt");
        int selecao = leitor.lerOpcao(1, 4);
        if (selecao == 1)
        {
            criarPersonagem();
            leitor.pausar();
            jogar();
            return;
        }
        else if (selecao == 2)
        {
            return;
        }
        else if (selecao == 3)
        {
            mostrarCreditos();
            leitor.pausar();
        }
        else if (selecao == 2)
        {
            return;
        }
    }
}

void Jogo::jogar(){
    int cenaAtual = 1;
    while(true){
        Cena* cena = CenaFactory::criar(cenaAtual);
        //Comandos do jogo
    }
}

void Jogo::criarPersonagem()
{
    string nome;
    leitor.imprimirArquivo("telas/criacaoDetetive.txt");
    cout << "Nome do detetive: ";
    getline(cin, nome);
    while (nome == "")
    {
        cout << "O nome nao pode ficar vazio: ";
        getline(cin, nome);
    }

    int observacao = 4;
    int calma = 8;
    int intuicao = 4;
    int guardados = 0;

    // O jogador escolhe quanto vai em cada atributo; o que sobrar fica guardado
    int restantes = 10;

    int limite = 6;
    if (restantes < limite)
    {
        limite = restantes;
    }

    cout << "Pontos extras em OBSERVACAO (0 a " << limite << "):" << endl;
    int extraO = leitor.lerOpcao(0, limite);
    restantes = restantes - extraO;

    limite = 8;
    if (restantes < limite)
    {
        limite = restantes;
    }
    cout << "Pontos extras em CALMA (0 a " << limite << "):" << endl;
    int extraC = leitor.lerOpcao(0, limite);
    restantes = restantes - extraC;

    limite = 6;
    if (restantes < limite)
    {
        limite = restantes;
    }
    cout << "Pontos extras em INTUICAO (0 a " << limite << "):" << endl;
    int extraI = leitor.lerOpcao(0, limite);
    restantes = restantes - extraI;

    observacao = 4 + extraO;
    calma = 8 + extraC;
    intuicao = 4 + extraI;
    guardados = restantes;

    if (guardados > 0)
    {
        cout << "Voce guardou " << guardados << " ponto(s). Use quando quiser na tela de inventario." << endl;
    }

    cout << "Perfil do detetive:" << endl;
    cout << "  1 - Perito (ja tem analise forense)" << endl;
    cout << "  2 - Investigador de campo (precisa do Kit forense)" << endl;
    int perfil = leitor.lerOpcao(1, 2);

    delete detetive; // seguro mesmo se for nullptr

    Caderno caderno;
    if (perfil == 1)
    {
        detetive = new Perito(nome, observacao, calma, intuicao, caderno, 3);
    } else
    {
        detetive = new Investigador(nome, observacao, calma, intuicao, caderno, 3);
    }

    detetive->listarInfos();
    detetive->podeExaminar();
}

void Jogo::mostrarCreditos()
{
    leitor.imprimirArquivo("telas/creditos.txt");
}