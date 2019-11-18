#include "Publicacao.h"
#include <stdexcept>
#include "StringUtils.h"

Publicacao::Publicacao(string numPaginas, string cidade){
    this->cidade = cidade;
    this->numPaginas = validaPaginas(numPaginas);
}

Publicacao::Publicacao(string final, string inicial, string cidade){
    this->cidade = cidade;
    this->numPaginas = calculaPaginas(parseInt(final), parseInt(inicial));
}

Publicacao::~Publicacao() = default;

int Publicacao::parseInt(string s){
    try {
        if (cpp_util::isNumber(s)) return stoi(s);
        else return -1;
    }
    catch (exception& e) {
        return -1;
    }
}

int Publicacao::validaPaginas(string numPaginas){
    int pgs = 0;
    if(parseInt(numPaginas) >= 0)
        pgs = parseInt(numPaginas);
    return pgs;
}

int Publicacao::calculaPaginas(int final, int inicial){
    long pgs = 0;
    if(inicial >= 0 && final >= 0)
        if(inicial <= final)
            if(final - inicial < 2000)
                pgs = final - inicial + 1;

    return pgs;
}

int Publicacao::getPaginas(){
    return this->numPaginas;
}

char Publicacao::getIdentificador(){
    return this->identificador;
}