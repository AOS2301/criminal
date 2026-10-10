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
            // telas/abertura.txt diz que a opção 2 é "Carregar jogo", mas
            // isso ainda não existe — aqui ela só encerra o programa, igual
            // à opção 4 ("Sair"). TODO: implementar carregamento de save.
            return;
        }
        else if (selecao == 3)
        {
            mostrarCreditos();
            leitor.pausar();
        }
        // Bug: aqui estava "else if (selecao == 2)" de novo (duplicado).
        // Como selecao == 2 já é tratado acima, esse bloco nunca executava
        // e a opção 4 ("Sair", válida pelo lerOpcao(1, 4)) não tinha efeito:
        // o loop simplesmente voltava a mostrar o menu.
        else if (selecao == 4)
        {
            return;
        }
    }
}

void Jogo::jogar(){
    // Bug: havia também um atributo "cenaAtual" em Jogo.h; essa variável
    // local tem o mesmo nome e esconde (shadow) o membro, que fica sem uso.
    int cenaAtual = 1;
    while(true){
        Cena* cena = CenaFactory::criar(cenaAtual);
        if (cena == nullptr) break;

        // cena->jogar(detetive) só compila agora porque Cena::jogar() foi
        // corrigido para "virtual int jogar(Detetive* detetive) = 0;"
        // (antes era "virtual void jogar() = 0;", sem parâmetro e sem
        // retorno, incompatível com esta chamada).
        cenaAtual = cena->jogar(detetive);
        delete cena;
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