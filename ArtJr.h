#ifndef ARTJR_H_
#define ARTJR_H_

#include "Publicacao.h"

class ArtJr : public Publicacao{
    private:
        string titulo;
        string idioma;
        string data;
        string ISSN;

    public:
        ArtJr(string, string, string, string, string, string, string);
        ~ArtJr();
};

#endif