#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo(); 
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);


//exceção NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N> 
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }


//exceção NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

//exceção ArestaRepetida
template <class A>
class ArestaRepetida {
public:
	No<N,A> *inicio, *destino;
	ArestaRepetida(No<N,A>* start, No<N,A>* dest) {
		inicio = start;
		destino = dest;
	}
};

template <class A>
std::ostream & operator <<(std::ostream &out, const ArestaRepetida<A> &ar)
{out << "Start: " << ar.inicio << endl << "Destination: " << ar.destino << endl; return out;}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class N, class A>
Grafo<N,A>::Grafo()
{

}

template <class N, class A>
Grafo<N, A>::~Grafo()
{

}

template <class N, class A>
int Grafo<N,A>::numNos(void) const
{
	return this->nos.size();
}

template <class N, class A>
int Grafo<N,A>::numArestas(void) const
{
	int soma = 0;

	for(unsigned int i = 0; i < this->nos.size(); i++)
	{
		soma += this->nos.at(i)->arestas.size();
	}

	return soma/2;
}




template <class N, class A>
Grafo<N,A> & Grafo<N, A>::inserirNo(const N &dados)
{
	unsigned int i;
	for(i = 0; i < this->nos.size(); i++)
	{
		if(this->nos.at(i)->info == dados)
		{
			throw NoRepetido<N>(dados);
		}
	}
	
	No<N,A> *ptr = new No<N,A>(dados);
	this->nos.push_back(ptr);

	return *this;
}


template <class N, class A>
Grafo<N,A> & Grafo<N,A>::inserirAresta(const N &inicio, const N &fim, const A &val)
{
	unsigned int i, j;

	for(i = 0; i < this->nos.size(); i++)
	{
		if(this->nos.at(i) == &inicio)
		{
			for(j = 0; j < this->nos.at(i).arestas.size(); j++)
			{
				if((this->nos.at(i).arestas.at(j).destino == &fim) && (this->nos.at(i).arestas.at(j).valor == &val))
				{
					throw ArestaRepetida<A>(&inicio, &fim);
				}
			}

			break;
		}
	}

	Aresta<N,A> *ptr = new Aresta<N,A>(&fim, val);
	this->nos.at(i).arestas.push_back(*ptr);

	return *this;
}