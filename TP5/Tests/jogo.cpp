/*
 * jogo.cpp
 */

#include "jogo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = frase.find(' ');
  while (pos != string::npos) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}

Jogo::Jogo()
{}

Jogo::Jogo(list<Crianca>& lc2)
{
  this->criancas = lc2;
}

void Jogo::insereCrianca(const Crianca &c1)
{
  this->criancas.push_back(c1);
}

list<Crianca> Jogo::getCriancasJogo() const
{
    list<Crianca> res;
    res = this->criancas;
    return res;
}

string Jogo::escreve() const
{
    string res = "";
    list<Crianca> l1 = this->criancas;
    list<Crianca>::iterator it;

    for(it = l1.begin(); it != l1.end(); it++)
    {
      res += it->escreve() + "\n";
    }

    return res;
}

// a implementar
Crianca& Jogo::perdeJogo(string frase)
{
  Crianca *c1 = new Crianca();
  list<Crianca> l1 = this->criancas;
  list<Crianca>::iterator it;
  int numPal = this->numPalavras(frase), i = 0;
    while(l1.size()!=1)
    { 
      
      for(it = l1.begin(); it != l1.end(); it++)
      {
        if(l1.size() == 1)
          break;

        i++;

        if(i==numPal)
        {
          l1.erase(it);
          i = 0;
        }

      }

    }

 
    *c1 = l1.front();
    return *c1;
}

// a implementar
list<Crianca>& Jogo::inverte()
{
    return criancas;
}

// a implementar
list<Crianca> Jogo::divide(unsigned id)
{
    list<Crianca> res;
    return res;
}

void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
  this->criancas = l1; 
}

// a implementar
bool Jogo::operator==(Jogo& j2)
{
	return true;
}

// a implementar
list<Crianca> Jogo::baralha() const
{
    list<Crianca> res;
    return res;
}
