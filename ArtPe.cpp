#include "ArtPe.h"

using namespace std;

ArtPe::ArtPe(string natureza, string idioma, string editora, string volume, string fasciculo, string serie,
string ISSN, string cidade, string final, string inicial) : Publicacao(final, inicial, cidade){
    this->natureza = natureza;
    this->idioma = idioma;
    this->editora = editora;
    this->volume = volume;
    this->fasciculo = fasciculo;
    this->serie = serie;
    this->ISSN = ISSN;
    this->identificador = 'C';
}