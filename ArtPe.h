#ifndef ARTPE_H_
#define ARTPE_H_

#include "Publicacao.h"

using namespace std;

class ArtPe : public Publicacao{
    private:
        string natureza;
        string idioma;
        string editora;
        string volume;
        string fasciculo;
        string serie;
        string ISSN;

    public:
        ArtPe(string, string, string, string, string, string, string, string, string, string);
        ~ArtPe();
};

#endif