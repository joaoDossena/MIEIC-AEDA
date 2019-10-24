#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>

using namespace std;


bool InfoCartao::operator< (const InfoCartao *cliente)
{
	bool result;
	if(this->frequencia < cliente->frequencia || (this->frequencia == cliente->frequencia && this->nome < cliente->nome))
		result = true;
	else
		result = false;
	return result;
}


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }

unsigned int ParqueEstacionamento::getNumLugares() const { return lotacao; }

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const { return lotacao-vagas; }


// a imnplementar
int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
	vector<InfoCartao> v = this->getClientes();
	vector<InfoCartao>::iterator it;
	vector<string> vstr;
	for(it = v.begin(); it != v.end(); it++)
	{
		vstr.push_back(it->nome);
	}
    return sequentialSearch(vstr, nome);
}

//a implementar
int ParqueEstacionamento::getFrequencia(const string &nome) const
{
	int pos = this->posicaoCliente(nome), result;
	if(pos == -1)
		throw ClienteNaoExistente(nome);
	else
		result = this->getClientes()[pos].frequencia;

    return result;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
	clientes.push_back(info);
	numClientes++;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
	vagas--;
	clientes[pos].frequencia++;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}

		
// a implementar
void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
	vector<InfoCartao> *v;
	v = this->getClientes();
	insertionSort(v);
}


// a implementar
void ParqueEstacionamento::ordenaClientesPorNome()
{

 
}



// a implementar
vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2)
{
    vector<string> nomes;
    return nomes;
}


// a implementar
ostream & operator<<(ostream & os, const ParqueEstacionamento & pe)
{
    return os;
}


// a implmentar
InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const
{
    InfoCartao info;
    return info;
}


ClienteNaoExistente::ClienteNaoExistente(string nomeCriado)
{
	this->nome = nomeCriado;
}

ClienteNaoExistente::~ClienteNaoExistente()
{}

string ClienteNaoExistente::getNome()
{
	return this->nome;
}