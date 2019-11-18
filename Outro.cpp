#include "Outro.h"

using namespace std;

Outro::Outro(string natureza, string idioma, string editora, string cidade, string numPaginas) : Publicacao(numPaginas, cidade){
    this->natureza = natureza;
    this->idioma = idioma;
    this->editora = editora;
    this->identificador = 'E';
}

Outro::~Outro() = default;