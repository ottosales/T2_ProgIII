#include "PPG.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <sstream>
#include "Anais.h"
#include "ArtJr.h"
#include "Outro.h"
#include "Publicacao.h"
#include "NumberUtils.h"
#include "Traducao.h"
#include "ArtPe.h"
#include "Livro.h"
#include "PartMu.h"

using namespace std;

PPG::PPG(string titulo, string cod){
    this->titulo = titulo;
    this->ID = cod;
}

PPG::~PPG(){
    this->pubs.clear();
    
}

void PPG::inserePub(Publicacao* pb){
    this->pubs.push_back(pb);
}

void PPG::registraIES(IES* ies){
    this->iess.push_back(ies);
}

int PPG::getIesNum(){
    return this->iess.size();
}

string PPG::getTitulo(){
    return this->titulo;
}

string PPG::getID(){
    return this->ID;
}

vector<IES*> PPG::getIES(){
    return this->iess;
}

int PPG::getNumPublicacoes(){
    return this->pubs.size();
}

bool PPG::existeNaLista(string ies){
    for(auto a : this->iess)
        if(a->getNome() == ies)
            return true;

    return false;
}

bool PPG::compareTo(PPG* a, PPG* b){
    return (a->titulo.compare(b->titulo) < 0);
}

string PPG::rede(map<string, PPG*> mapPPG){
    string saida = "Programas em rede:\n";
    for(auto a : mapPPG){
        if(a.second->getIesNum() > 1){
            saida += a.second->getID() + ": " + a.second->getTitulo() + "\n";
            vector<IES*> ies = a.second->getIES();
            sort(ies.begin(), ies.end(), IES::compareTo);
            for(auto i : ies)
                saida += "\t- " + i->getSigla() + " (" + i->getNome() + ")\n";
        }
    }

    return saida;
}

string PPG::ppg(){
    string saida = "Programa: " + this->titulo + "\n" + "Instituicoes:\n";
    sort(iess.begin(), iess.end(), IES::compareTo);
    for(auto a : iess)
        saida += "\t- " + a->getSigla() + " (" + a->getNome() + ")\n";

    saida += "\nQuantidade de producoes por tipo:\n";
    int contaAnais = 0;
    int contaArtJr = 0;
    int contaArtPe = 0;
    int contaLivros = 0;
    int contaPartMu = 0;
    int contaTraducoes = 0;
    int contaOutros = 0;
    int somaPaginas = 0;

    for(auto a : this->pubs){
 
         if(a->getIdentificador() == 'A')
            contaAnais++;
        else if(a->getIdentificador() == 'B')
            contaArtJr++;
        else if(a->getIdentificador() == 'C')
            contaArtPe++;
        else if(a->getIdentificador() == 'D')
            contaLivros++;
        else if(a->getIdentificador() == 'E')
            contaOutros++;
        else if(a->getIdentificador() == 'F')
            contaPartMu++;
        else if(a->getIdentificador() == 'G')
            contaTraducoes++;

        /* if(typeid(*a) == typeid(Anais))
            contaAnais++;
        else if(typeid(*a) == typeid(ArtJr))
            contaArtJr++;
        else if(typeid(*a) == typeid(ArtPe))
            contaArtPe++;
        else if(typeid(*a) == typeid(Livro))
            contaLivros++;
        else if(typeid(*a) == typeid(PartMu))
            contaPartMu++;
        else if(typeid(*a) == typeid(Traducao))
            contaTraducoes++;
        else if(typeid(*a) == typeid(Outro))
            contaOutros++;*/

        somaPaginas += a->getPaginas();
    }

    ostringstream contaAnaisStream, contaArtJrStream, contaArtPeStream, contaLivrosStream, contaPartMuStream, contaTraducoesStream, contaOutrosStream, somaPaginasStream;
    contaAnaisStream << contaAnais;
    contaArtJrStream << contaArtJr;
    contaArtPeStream << contaArtPe;
    contaLivrosStream << contaLivros;
    contaPartMuStream << contaPartMu;
    contaTraducoesStream << contaTraducoes;
    contaOutrosStream << contaOutros;
    somaPaginasStream << somaPaginas;

    saida += "\t- Artigos em anais de eventos: " + contaAnaisStream.str() + "\n";
    saida += "\t- Artigos em jornais e revistas: " + contaArtJrStream.str() + "\n";
    saida += "\t- Artigos em periodicos cientificos: " + contaArtPeStream.str() + "\n";
    saida += "\t- Livros: " + contaLivrosStream.str() + "\n";
    saida += "\t- Partituras musicais: " + contaPartMuStream.str() + "\n";
    saida += "\t- Traducoes: " + contaTraducoesStream.str() + "\n";
    saida += "\t- Outros: " + contaOutrosStream.str() + "\n\n";

    saida += "Total de paginas produzidas pelo PPG: " + somaPaginasStream.str() + "\n";

    return saida;
}