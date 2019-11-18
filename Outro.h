#ifndef OUTRO_H_
#define OUTRO_H_
#include "Publicacao.h"

using namespace std;

class Outro : public Publicacao{
    private:
        string natureza;
        string idioma;
        string editora;
    
    public:
        Outro(string, string, string, string, string);
        ~Outro();

};

#endif