#include "aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Aposta::contem(unsigned num) const
{
	bool result = false;
	tabHInt::const_iterator it = this->numeros.find(num);
	if(it != this->numeros.end())
		result = true;

	return result;
}


void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
	this->numeros.clear();
	unsigned int i = 0, nValores = 0;
	while(nValores < n)
	{
		pair<tabHInt::iterator, bool> res = this->numeros.insert(valores[i]);
		if(res.second == true)
			nValores++;
		i++;
	}
}

unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
	unsigned int certos = 0;
	tabHInt::const_iterator it = sorteio.begin();

	for (it; it != sorteio.end(); it++)
	{
		if(this->contem(*it))
			certos++;
	}

    return certos;
}

//Exercício 2:
unsigned int Aposta::somaNumeros() const
{
	unsigned int soma = 0;
	tabHInt::const_iterator it = this->numeros.begin();

	for(it; it != this->numeros.end(); it++)
	{
		soma += (*it);
	}

	return soma;
}

unsigned int Aposta::tamanho() const
{
	return this->numeros.size();
}


