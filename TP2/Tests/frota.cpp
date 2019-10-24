#include "frota.h"
#include <string>

using namespace std;


void Frota::adicionaVeiculo(Veiculo *v1)
{
	this->veiculos.push_back(v1);
}

int Frota::numVeiculos()const
{
	return this->veiculos.size();
}

int Frota::menorAno()const
{
	int result, menor, temp;
	vector<Veiculo>::iterator it;

	if(this->veiculos.size() == 0)
		result = 0;
	else
	{
		menor = this->veiculos.at(0)->getAno();
		for(it = this->veiculos.begin() + 1; it != this->veiculos.end(); it++)
		{
			temp = it->getAno();
			if(temp < menor)
				menor = temp;
		}
		result = menor;
	}

	return result;
}

vector<Veiculo *> Frota::operator() (int anoM) const
{
	vector<Veiculo *> result;
	vector<Veiculo *>::iterator it;

	for(it = this->veiculos.begin(); it != this->veiculos.end(); it++)
	{
		if(it->getAno() == anoM)
			result.push_back(it);
	}
	

	return result;
}

float Frota::totalImposto() const
{
	float soma = 0;
	vector<Veiculo *>::iterator it; 

	for(it = this->veiculos.begin(); it != this->veiculos.end(); it++)
	{
		soma += (*it)->calcImposto();
	}

	return soma;
}