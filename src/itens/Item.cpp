#include "../../include/itens/Item.h"
#include <iostream>

Item::Item()
{
}

Item::Item(string nome): nome(nome)
{
}

Item::~Item()
{
}

string Item::getNome(){
    return nome;
}
