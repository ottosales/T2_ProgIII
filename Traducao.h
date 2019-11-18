#ifndef TRADUCAO_H_
#define TRADUCAO_H_

#include "Publicacao.h"

using namespace std;

class Traducao : public Publicacao{
    private:
        string natureza;
        string titulo;
        string idioma;
        string editora;
        string idiomaTraducao;

        public:
            Traducao(string, string, string, string, string, string, string);
            ~Traducao();
};


#endif
