#include "jogador.h"

void Jogador::adicionaAposta(const Aposta & ap)
{
	this->apostas.insert(ap);
}

unsigned Jogador::apostasNoNumero(unsigned num) const
{
	unsigned int soma = 0;
	tabHAposta::const_iterator it = this->apostas.begin();

	for(it; it != this->apostas.end(); it++)
	{
		if(it->contem(num))
			soma++;
	}

	return soma;
}

tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{
	tabHAposta money;
	money.clear();
	tabHAposta::const_iterator it = this->apostas.begin();

	for(it; it != apostas.end(); it++)
	{
		if(it->calculaCertos(sorteio) > 3)
			money.insert(*it);
	}

	return money;
}
