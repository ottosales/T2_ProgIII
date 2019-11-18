#include "Livro.h"

using namespace std;

Livro::Livro(string natureza, string titulo, string idioma, string editora, 
string ISBN, string cidade, string numPaginas) : Publicacao (numPaginas, cidade){
    this->natureza = natureza;
    this->titulo = titulo;
    this->idioma = idioma;
    this->editora = editora;   
    this->ISBN = ISBN; 
    this->identificador = 'D';
}

Livro::~Livro() = default;