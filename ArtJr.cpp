#include "ArtJr.h"

using namespace std;

ArtJr::ArtJr(string titulo, string idioma, string cidade, string 
data, string ISSN, string final, string inicial) : Publicacao(final, inicial, cidade) {
    this->titulo = titulo;
    this->idioma = idioma;
    this->data = data;
    this->ISSN = ISSN;
    this->identificador = 'B';
}

ArtJr::~ArtJr() = default;