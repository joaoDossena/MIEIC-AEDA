#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "bst.h"


class PalavraSignificado {
      string palavra;
      string significado;
public:
       PalavraSignificado(string p, string s): palavra(p), significado(s) {}
       string getPalavra() const { return palavra; }
       string getSignificado() const { return significado; }
       void setSignificado(string sig) { significado=sig; }
       bool operator < (const PalavraSignificado &ps1) const;
       bool operator==(const PalavraSignificado &ps1) const;
       friend ostream& operator<<(ostream &output, PalavraSignificado &ps);
};

class Dicionario
{
      BST<PalavraSignificado> palavras;
public:
      Dicionario(): palavras(PalavraSignificado("","")){};
      BST<PalavraSignificado> getPalavras() const;
      void lerDicionario(ifstream &fich);
      string consulta(string palavra) const;
      bool corrige(string palavra, string significado);
      void imprime() const;

};


class PalavraNaoExiste
{
private:
      string palavraAntes;
      string significadoAntes;
      string palavraApos;
      string significadoApos;
public:
      PalavraNaoExiste(string palAntes, string sigAntes, string palApos, string sigApos)
      {
            palavraAntes = palAntes;
            significadoAntes = sigAntes;
            palavraApos = palApos;
            significadoApos = sigApos;
      }
	string getPalavraAntes() const { return this->palavraAntes; }
	string getSignificadoAntes() const { return this->significadoAntes; }
	string getPalavraApos() const { return this->palavraApos; }
	string getSignificadoApos() const { return this->significadoApos; }
};


#endif
