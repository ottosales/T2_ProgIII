#include "IES.h"
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

IES::IES(string nome, string sigla){
    this->nome = nome;
    this->sigla = sigla;
    this->siglaNomeConcat = this->sigla +  " " + this->nome;
}

IES::~IES() = default;

void IES::registraPPG(PPG* ppg){
    this->PPGs.push_back(ppg);
}

string IES::getNome(){
    return this->nome;
}

string IES::getSigla(){
    return this->sigla;
}

bool IES::existeNaLista(string ppg){
    for(auto a : this->PPGs)
        if(a->getTitulo() == ppg)
            return true;
    
    return false;
}

bool IES::compareTo(IES* a, IES* b){
    return (a->siglaNomeConcat.compare(b->siglaNomeConcat) < 0);
}

string IES::ies(){
    string saida = this->nome + " (" + this->sigla + "):\n";
    sort(this->PPGs.begin(), this->PPGs.end(), PPG::compareTo);
    map<string, string> mapaNomesPPGs;

    for(auto a : this->PPGs){
        ostringstream strs;
        strs << a->getNumPublicacoes();
        mapaNomesPPGs[a->getTitulo()] = strs.str();
    }

    for(auto a : mapaNomesPPGs){
        saida += "\t- " + a.first + ": " + a.second + " producoes\n";
    }
        

    return saida;

}