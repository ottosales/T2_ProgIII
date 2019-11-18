#ifndef PARTMU_H_
#define PARTMU_H_

#include "Publicacao.h"

using namespace std;

class PartMu : public Publicacao{
    private:
        string natureza;
        string editora;
        string formInstrumental;

    public:
        PartMu(string, string, string, string, string);
        ~PartMu();
};

#endif