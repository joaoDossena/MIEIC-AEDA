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

	if(this->veiculos.size() == 0)
		result = 0;
	else
	{
		menor = this->veiculos.at(0)->getAno();
		for(auto &x: this->veiculos)
		{
			temp = x->getAno();
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

	for(auto &x: this->veiculos)
	{
		if(x->getAno() == anoM)
			result.push_back(x);
	}
	

	return result;
}

float Frota::totalImposto() const
{
	float soma = 0;
	//vector<Veiculo *>::iterator it; 

	for(auto &x: this->veiculos)
	{
		soma += x->calcImposto();
	}

	return soma;
}