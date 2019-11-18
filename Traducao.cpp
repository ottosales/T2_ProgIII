#include "Traducao.h"

using namespace std;

Traducao::Traducao(string natureza, string titulo, string idioma, string editora, string idiomaTraducao, 
string cidade, string numPaginas) : Publicacao(numPaginas, cidade){
    this->natureza = natureza;
    this->titulo = titulo;
    this->idioma = idioma;
    this->editora = editora;
    this->idiomaTraducao = idiomaTraducao;
    this->identificador = 'G';
}

Traducao::~Traducao() = default;