#include "jogo.h"
#include <sstream>


ostream &operator << (ostream &os, Circulo &c1)
{
	string estadoStr;
	if(c1.estado == true)
		estadoStr = "true";
	else
		estadoStr = "false";

	os << c1.pontuacao << "-" << estadoStr << "-" << c1.nVisitas << endl;
	return os;
}


BinaryTree<Circulo> Jogo::iniciaJogo(int pos, int nivel, vector<int> &pontos, vector<bool> &estados)
{
	Circulo c1(pontos[pos], estados[pos]);
	if(nivel == 0)
		return BinaryTree<Circulo>(c1);
	else
	{
		BinaryTree<Circulo> filhoEsq = iniciaJogo(2*pos + 1, nivel - 1, pontos, estados);
		BinaryTree<Circulo> filhoDir = iniciaJogo(2*pos + 2, nivel - 1, pontos, estados);
		return BinaryTree<Circulo>(c1, filhoEsq, filhoDir);
	}
}



Jogo::Jogo(int niv, vector<int> &pontos, vector<bool> &estados)
{
	this->jogo = iniciaJogo(0, niv, pontos, estados);
}

string Jogo::escreveJogo()
{
	BTItrLevel<Circulo> it(this->jogo);
	stringstream result("");
	while (!it.isAtEnd()) {
		result << it.retrieve();
		it.advance();
	}
	return result.str();
}


int Jogo::jogada()
{
	int pos = 1; int pontos = -1;
	BTItrLevel<Circulo> it(this->jogo);
	if(it.isAtEnd())
		return pontos;
	while(true)
	{
		Circulo &c1 = it.retrieve();
		bool estado = c1.getEstado();
		int n;
		if(estado == false)
			n = pos;
		else
			n = pos + 1;
		c1.mudaEstado();
		c1.incNVisitas();
		pontos = c1.getPontuacao();
		int i = 0;
		while(i < n && !it.isAtEnd())
		{
			it.advance();        // avanca p/ filho esquerdo ou direito
			i++;
		}

		if(!it.isAtEnd())
			pos += n;
		else
			break;
	}

	return pontos;
}


int Jogo::maisVisitado()
{
	int maxVis = -1;
	BTItrLevel<Circulo> it(this->jogo);

	if(it.isAtEnd())
		return maxVis;
	else
	{
		it.advance();
		while(!it.isAtEnd())
		{
			Circulo c1 = it.retrieve();
			int nVis = c1.getNVisitas();
			if(nVis > maxVis)
				maxVis = nVis;
			it.advance();
		}
	}

	return maxVis;
}

