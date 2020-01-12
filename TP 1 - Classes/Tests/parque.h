#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InfoCartao {
public:
	string nome;
	bool presente;
};

class ParqueEstacionamento {
	unsigned int vagas;
	const unsigned int lotacao;
	vector<InfoCartao> clientes;
	const unsigned int numMaximoClientes;
public:
	ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli); //Implementada
	bool adicionaCliente(const string & nome); //Implementada
	bool retiraCliente(const string & nome); //Implementada
	bool entrar(const string & nome); //Implementada
	bool sair(const string & nome); //Implementada
	int posicaoCliente(const string & nome) const; //Implementada
	unsigned int getNumLugares() const; //Implementada
	unsigned int getNumMaximoClientes() const; //Implementada
	unsigned int getNumVagas() const; //Implementada
	unsigned int getNumLugaresOcupados() const; //Implementada
	unsigned int getNumClientesAtuais() const; //Implementada
	void incrementaVagas(unsigned int n); //Implementada
	void decrementaVagas(unsigned int n); //Implementada
	bool estaNoParque(const string & nome); //Implementada
	const ParqueEstacionamento & operator += (const ParqueEstacionamento & p2); 
};
