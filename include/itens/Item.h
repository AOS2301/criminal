#ifndef Item_H
#define Item_H

#include <string>
using namespace std;

class Item
{
protected:
    string nome;
public:
    Item();
    Item(string nome);
    virtual ~Item();

    string getNome();
};

#endif