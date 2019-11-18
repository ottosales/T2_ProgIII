#ifndef LIVRO_H_
#define LIVRO_H_

#include "Publicacao.h"

using namespace std;

class Livro : public Publicacao{
    private:
        string natureza;
        string titulo;
        string idioma;
        string editora;
        string ISBN;

    public:
        Livro(string, string, string, string, string, string, string);
        ~Livro();
};

#endif