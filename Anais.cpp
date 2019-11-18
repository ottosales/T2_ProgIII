#include "Anais.h"

using namespace std;

Anais::Anais(string ID, string natureza, string titulo, string final, string inicial,
string evento, string cidade, string idioma) : Publicacao(final, inicial, cidade){
    this->titulo = titulo;
    this->ID = ID;
    this->natureza = natureza;
    this->evento = evento;
    this->idioma = idioma;
    this->identificador = 'A';
}

Anais::~Anais() = default;

