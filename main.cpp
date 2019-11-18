#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <exception>

#include "CSV.h"
#include "IES.h"
#include "PPG.h"

using namespace std;



int main(){

    string local, nomeArquivo;
    cin >> local;
    
    map<string, PPG*> mapPPG;
    map<string, IES*> mapIES;


    try{
        for(int i = 0; i < 7; i++){
            cin >> nomeArquivo;
            string entrada = local + nomeArquivo;

            CSV::loadData(entrada, &mapPPG, &mapIES);
        }
        string comando;
        cin >> comando;
        if(comando == "rede")
            cout << PPG::rede(mapPPG);
        
        else if(comando == "ppg"){
            string cod;
            cin >> cod;
            if(mapPPG.count(cod))
                cout << mapPPG[cod]->ppg();
            else
                cout << "PPG nao encontrado." << endl;
        }   
        
        else if(comando == "ies"){
            string cod;
            cin >> cod;
            bool encontrou = false;

            for(auto a : mapIES){
                if(a.second->getSigla() == cod){
                    cout << a.second->ies();
                    encontrou = true;
                }
            }
            if(!encontrou)
                cout << "IES nao encontrada." << endl;
        }


        else
            cout << "Comando desconhecido." << endl;
        
    }
    catch(exception&){
        cout << "Erro de I/O" << endl;
    }

    mapPPG.clear();
    mapIES.clear();

    return 0;
}   