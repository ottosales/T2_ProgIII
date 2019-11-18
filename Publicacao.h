#ifndef PUBLICACAO_H_
#define PUBLICACAO_H_

#include <iostream>
#include <string>

using namespace std;

class Publicacao{
    protected:
        string cidade;
        int numPaginas;
        char identificador;
    
    public:
        Publicacao(string, string);
        Publicacao(string, string, string);
        ~Publicacao();
        int getPaginas();
        int parseInt(string);
        int validaPaginas(string numPaginas);
        int calculaPaginas(int, int);
        char getIdentificador();
};


#endif