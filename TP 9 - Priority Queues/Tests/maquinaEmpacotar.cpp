#include "maquinaEmpacotar.h"
#include <sstream>
#include <algorithm>


MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}

unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs)
{
	vector<Objeto>::iterator it = objs.begin();

	while(it != objs.end())
	{
		if(it->getPeso() <= this->capacidadeCaixas)
		{
			this->objetos.push(*it);
			it = objs.erase(it);
		}
		else
			it++;
	}

	return this->objetos.size();
}

Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {
	vector<Caixa> temp;
	bool found = false;
	Caixa cx;

	while(!this->caixas.empty())
	{
		cx = this->caixas.top();
		this->caixas.pop();
		if(cx.getCargaLivre() >= obj.getPeso())
		{
			found = true;
			break;
		}
		else
			temp.push_back(cx);
	}

	for(unsigned int i = 0; i < temp.size(); i++)
	{
		this->caixas.push(temp[i]);
	}

	if(found == false)
		cx = Caixa(capacidadeCaixas);

	return cx;
}

unsigned MaquinaEmpacotar::empacotaObjetos() {

	while(!this->objetos.empty())
	{
		Objeto o1 = this->objetos.top();
		this->objetos.pop();

		Caixa c1 = procuraCaixa(o1);
		c1.addObjeto(o1);
		this->caixas.push(c1);
	}

	return this->caixas.size();
}

string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {
	stringstream result;

	if(this->objetos.empty())
		result << "Nao ha objetos!" << endl;
	else
	{
		HEAP_OBJS buffer = this->objetos;
		while(!buffer.empty())
		{
			Objeto o1 = buffer.top();
			buffer.pop();

			result << o1 << endl;
		}
	}

	return result.str();
}

// a alterar
Caixa MaquinaEmpacotar::caixaMaisObjetos() const {
	Caixa cx;
	HEAP_CAIXAS buffer = this->caixas;
	if(buffer.empty())
		throw MaquinaSemCaixas();
	else
	{
		cx = buffer.top();
		buffer.pop();
		while(!buffer.empty())
		{
			if(cx.getSize() < buffer.top().getSize())
				cx = buffer.top()
			buffer.pop();
		}
	}

	return cx;
}



