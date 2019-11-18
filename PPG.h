#ifndef PPG_H_
#define PPG_H_

#include <string>
#include <vector>
#include <map>
#include "Publicacao.h"
#include "IES.h"

class IES;

using namespace std;

class PPG{
    private:
        string titulo;
        string ID;
        vector<IES*> iess;
        vector<Publicacao*> pubs;

    public:
        PPG(string, string);
        ~PPG();

        void inserePub(Publicacao*); 
        void registraIES(IES*);
        int getIesNum();
        string getTitulo();
        string getID();
        vector<IES*> getIES();
        bool existeNaLista(string);
        int getNumPublicacoes();

        static bool compareTo(PPG*, PPG*);

        static string rede(map<string, PPG*>);

        string ppg();

};
#endif