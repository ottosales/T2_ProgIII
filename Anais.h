#ifndef ANAIS_H_
#define ANAIS_H_

#include "Publicacao.h"

using namespace std;

class Anais : public Publicacao{
    private:
        string titulo;
        string ID;
        string natureza;
        string idioma;
        string evento;

    public:
        Anais(string, string, string, string, string, string, string, string);
        ~Anais();
};

#endif