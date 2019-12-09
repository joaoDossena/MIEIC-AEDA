#include <iostream>
#include <string>
#include <fstream>
#include "dicionario.h"
#include "bst.h"

using namespace std;



BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}

bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
	bool result = false;
	if(this->palavra < ps1.palavra)
     result = true;
 	return result;
}

bool PalavraSignificado::operator==(const PalavraSignificado &ps1) const
{
	bool result = false;
	if(this->palavra == ps1.palavra && this->significado == ps1.significado)
		result = true;
	return result;
}

ostream& operator <<(ostream &output, PalavraSignificado &ps)
{
	output << ps.palavra << endl << ps.significado << endl;
	return output;
}

void Dicionario::lerDicionario(ifstream &fich)
{
	string palavra, significado;
	while(!fich.eof())
	{
		getline(fich, palavra);
		getline(fich, significado);

		this->palavras.insert(PalavraSignificado(palavra, significado));     
	}

	return;
}

string Dicionario::consulta(string palavra) const
{
	PalavraSignificado p1(palavra, "");
	PalavraSignificado px = this->palavras.find(p1);
	PalavraSignificado pNotFound("", "");

	if(px == pNotFound)
	{
		BSTItrIn<PalavraSignificado> it(this->palavras);
		string palAntes = "", sigAntes = "", palApos = "", sigApos = "";

		while(!it.isAtEnd() && it.retrieve() < p1)
		{
			palAntes = it.retrieve().getPalavra();
			sigAntes = it.retrieve().getSignificado();
			it.advance();
		}

		if(!it.isAtEnd())
		{
			palApos = it.retrieve().getPalavra();
			sigApos = it.retrieve().getSignificado();
		}
		throw PalavraNaoExiste(palAntes, sigAntes, palApos, sigApos);
	}
	else
		return px.getSignificado();
}

//a alterar
bool Dicionario::corrige(string palavra, string significado)
{
	bool jaExistia = false;
	
	BSTItrIn<PalavraSignificado> it(this->palavras);
	PalavraSignificado pal = this->palavras.find(PalavraSignificado(palavra, ""));

	if(pal == PalavraSignificado("", ""))
	{
		this->palavras.insert(PalavraSignificado(palavra, significado));
	}
	else
	{
		this->palavras.remove(PalavraSignificado(palavra, ""));
		pal.setSignificado(significado);
		this->palavras.insert(pal);
		jaExistia = true;
	}

    return jaExistia;
}

void Dicionario::imprime() const
{
	this->palavras.printTree();
    return;
}

