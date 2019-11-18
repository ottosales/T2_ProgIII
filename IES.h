#ifndef IES_H_
#define IES_H_

#include <string>
#include <set>

#include "PPG.h"

class PPG;

using namespace std;

class IES{
    private:
        string nome;
        string sigla;
        string siglaNomeConcat;
        vector<PPG*> PPGs;
    
    public:
        IES(string, string);
        ~IES();

        void registraPPG(PPG*);
        string getNome();
        string getSigla();
        bool existeNaLista(string);

        static bool compareTo(IES*, IES*);

        string ies();
};

#endif