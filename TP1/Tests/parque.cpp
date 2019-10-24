#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli)
{
    vagas = lot;
}

unsigned int ParqueEstacionamento::getNumLugares() const
{
    return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const
{
    return numMaximoClientes;
}

unsigned int ParqueEstacionamento::getNumVagas() const
{
    return vagas;
}

void ParqueEstacionamento::decrementaVagas(unsigned int n)
{
    if(this->getNumVagas() >= n)
        this->vagas -= n;
}

void ParqueEstacionamento::incrementaVagas(unsigned int n)
{
    if(this->getNumVagas() + this->getNumLugares() <= this->getNumMaximoClientes())
        this->vagas += n;
}

bool ParqueEstacionamento::estaNoParque(const string &nome)
{
    bool result;
    vector<InfoCartao>::const_iterator it;
    for(it = this->clientes.begin(); it < this->clientes.end(); it++)
    {
        if(it->nome == nome)
        {
            result = it->presente;
            break;
        }
    }
    return result;
}

int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    vector<InfoCartao>::const_iterator it;
    int i = 0;
    for(it = this->clientes.begin(); it < this->clientes.end(); it++, i++)
    {
        if(it->nome == nome)
        {
            return i;
        }
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome)
{
    bool result;
    if((this->posicaoCliente(nome) == -1) && (this->getNumVagas() > 0))
    {
        InfoCartao cli;
        cli.nome = nome;
        cli.presente = false;
        clientes.push_back(cli);
        result = true;
        decrementaVagas(1);
    }
    else
        result = false;

    return result;
}

bool ParqueEstacionamento::entrar(const string & nome)
{
    bool result;
    if(this->posicaoCliente(nome) == -1 || this->getNumMaximoClientes() - this->getNumLugares() <=0 || this->estaNoParque(nome))
        result = false;
    else
    {
        this->clientes.at(this->posicaoCliente(nome)).presente = true;
        result = true;
    }
    return result;
}

bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	int pos = this->posicaoCliente(nome);
    bool result;
    if(pos >=0 && this->clientes.at(pos).presente == false)
    {
        this->clientes.erase(this->clientes.begin() + pos);
        result = true;
    }
    else
        result = false;

    return result;
}

bool ParqueEstacionamento::sair(const string & nome)
{
    int pos = this->posicaoCliente(nome);
    bool result;
    if(pos == -1 || this->clientes.at(pos).presente == false)
        result = false;
    else
    {
        this->clientes.at(pos).presente = false;
        result = true;
        incrementaVagas(1);
    }
    return result;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const
{
    unsigned int i = 0;
    vector<InfoCartao>::const_iterator it;
    for(it = this->clientes.begin(); it < this->clientes.end(); it++)
    {
        if(it->presente)
            i++;
    }
    return i;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const
{
    return this->clientes.size();
}