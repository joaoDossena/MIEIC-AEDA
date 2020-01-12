#include "veiculo.h"
#include <iostream>

using namespace std;

//Constructors
Veiculo::Veiculo(string mc, int m, int a)
{
	this->marca = mc;
	this->mes = m;
	this->ano = a;
}

Motorizado::Motorizado(string mc, int m, int a,string c,int cil) : Veiculo(mc, m, a)
{
	this->combustivel = c;
	this->cilindrada = cil;
}

Automovel::Automovel(string mc, int m, int a,string c, int cil) : Motorizado(mc, m, a, c, cil)
{

}

Camiao::Camiao(string mc, int m, int a,string c, int cil,int cm) : Motorizado(mc, m, a, c, cil)
{
	this->carga_maxima = cm;
}

Bicicleta::Bicicleta(string mc, int m, int a,string t) : Veiculo(mc, m, a)
{
	this->tipo = t;
}

//Get Functions
//Veiculo
string Veiculo::getMarca() const
{
	return this->marca;
}

int Veiculo::getAno() const
{
	return this->ano;
}

int Veiculo::getMes() const
{
	return this->mes;
}

//Bicicleta
string Bicicleta::getTipo() const
{
	return this->tipo;
}

//Motorizado
string Motorizado::getCombustivel() const
{
	return this->combustivel;
}

int Motorizado::getCilindrada() const
{
	return this->cilindrada;
}

//Camiao
int Camiao::getCarga_maxima() const
{
	return this->carga_maxima;
}

//Other Functions
//Veiculo
int Veiculo::info() const
{
	cout << "Marca: " << this->getMarca() << endl;
	cout << "Mês: " << this->getMes() << endl;
	cout << "Ano: " << this->getAno() << endl;


	return 3;
}

bool Veiculo::operator <(const Veiculo & v) const
{
	bool result;

	if(this->ano < v.ano)
		result = true;
	else if(this->ano == v.ano && this->mes < v.mes)
		result = true;
	else
		result = false;

	return result;
}

//Bicicleta
int Bicicleta::info() const
{
	Veiculo::info();
	cout << "Tipo: " << this->getTipo() << endl;

	return 4;
}

float Bicicleta::calcImposto() const
{
	return 0.0;
}

//Motorizado
int Motorizado::info() const
{
	Veiculo::info();
	cout << "Combustível: " << this->getCombustivel() << endl;
	cout << "cilindrada: " << this->getCilindrada() << endl;

	return 5;
}

//Automovel
int Automovel::info() const
{
	return Motorizado::info();
}

//Camiao
int Camiao::info() const
{
	Motorizado::info();
	cout << "Carga máxima: " << this->getCarga_maxima() << endl;

	return 6;
}

//calcImposto
float Motorizado::calcImposto() const
{
	float result;

	if(this->getAno() > 1995)
	{
		if(this->getCombustivel() == "gasolina")
		{
			if(this->getCilindrada() <= 1000)
				result = 14.56;
			else if(this->getCilindrada() <= 1300)
				result = 29.06;
			else if(this->getCilindrada() <= 1750)
				result = 45.15;
			else if(this->getCilindrada() <= 2600)
				result = 113.98;
			else if(this->getCilindrada() <= 3500)
				result = 181.17;
			else
				result = 320.89;
		}
		else
		{
			if(this->getCilindrada() <= 1500)
				result = 14.56;
			else if(this->getCilindrada() <= 2000)
				result = 29.06;
			else if(this->getCilindrada() <= 3000)
				result = 45.15;
			else
				result = 113.98;
		}
	}
	else
	{
		if(this->getCombustivel() == "gasolina")
		{
			if(this->getCilindrada() <= 1000)
				result = 8.10;
			else if(this->getCilindrada() <= 1300)
				result = 14.56;
			else if(this->getCilindrada() <= 1750)
				result = 22.65;
			else if(this->getCilindrada() <= 2600)
				result = 54.89;
			else if(this->getCilindrada() <= 3500)
				result = 87.13;
			else
				result = 148.37;
		}
		else
		{
			if(this->getCilindrada() <= 1500)
				result = 8.10;
			else if(this->getCilindrada() <= 2000)
				result = 14.56;
			else if(this->getCilindrada() <= 3000)
				result = 22.65;
			else
				result = 54.89;
		}
	}

	return result;
}