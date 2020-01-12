#include <queue>
#include <cstdlib>
#include "balcao.h"
#include "exceptions.h"

using namespace std;

Cliente::Cliente()
{
	this->numPresentes = rand() % 5 + 1;
}

int Cliente::getNumPresentes() const
{
    return this->numPresentes;
}


Balcao::Balcao(int te): tempo_embrulho(te)
{
	this->tempo_atual = 0;
	this->prox_chegada = rand() % 20 + 1;
	this->prox_saida = 0;
	this->clientes_atendidos = 0;
}
//
void Balcao:: proximoEvento()
{

}

void Balcao::chegada()
{
	Cliente *c = new Cliente; //Creates new client
	this->clientes.push(*c); //Inserts them in the queue

	this->prox_chegada = rand() % 20 + 1;
	this->prox_saida += this->tempo_atual + c->getNumPresentes() * this->tempo_embrulho;
	cout << "tempo = " << tempo_atual << "\nchegou novo cliente com " << c->getNumPresentes() << " presentes";

}

//a alterar
void Balcao::saida()
{
	Cliente *c = new Cliente;
	*c = this->getProxCliente();
	cout << endl << this->getProxSaida() <<endl;
	this->prox_saida -= c->getNumPresentes() * this->tempo_embrulho;
	this->clientes.pop();
	cout << "";
}


int Balcao::getTempoAtual() const
{
	 return tempo_atual;
}

int Balcao::getProxChegada() const
{
	 return prox_chegada;
}

//a alterar
ostream & operator << (ostream & out, const Balcao & b1)
{
     return out;
}

int Balcao::getTempoEmbrulho() const
{
	return this->tempo_embrulho;
}

int Balcao::getProxSaida() const
{
	return this->prox_saida;
}

int Balcao::getClientesAtendidos() const
{
	return this->clientes_atendidos;
}

Cliente & Balcao::getProxCliente()
{
    Cliente *c = new Cliente();

    if(this->clientes.empty())
    	throw FilaVazia();
    else
    	*c = this->clientes.front();

    return *c;
}

      
