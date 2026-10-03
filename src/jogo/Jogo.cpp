#include "../../include/jogo/Jogo.h"
#include <iostream>

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    getLeitor().lerArquivo("telas/abertura.txt");

    while (true)
    {
        if (getLeitor().lerOpcao(1, 4) == 1)
        {
            criarPersonagem();
            return;
        }
        else if (getLeitor().lerOpcao(1, 4) == 2)
        {
            return;
        }
        else if (getLeitor().lerOpcao(1, 4) == 3)
        {
            mostrarCreditos();
            return;
        }
        else if (getLeitor().lerOpcao(1, 4) == 2)
        {
            return;
        }
    }
}

void Jogo::criarPersonagem()
{   
    getLeitor().lerArquivo("telas/criacaoDetetive.txt");
    
}

void Jogo::mostrarCreditos()
{   
    getLeitor().lerArquivo("telas/creditos.txt");
    
}

Leitor Jogo::getLeitor()
{
    return leitor;
}

