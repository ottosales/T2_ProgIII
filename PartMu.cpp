#include "PartMu.h"

using namespace std;

PartMu::PartMu(string natureza, string editora, string formInstrumental, string cidade, string numPaginas) : Publicacao(numPaginas, cidade){
    this->natureza = natureza;
    this->editora = editora;
    this->formInstrumental = formInstrumental;
    this->identificador = 'F';
}

PartMu::~PartMu() = default;