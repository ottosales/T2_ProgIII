#include "CSV.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <exception>
#include "Tokenizer.h"
#include "Anais.h"
#include "ArtJr.h"
#include "Outro.h"
#include "Publicacao.h"
#include "NumberUtils.h"
#include "Traducao.h"
#include "ArtPe.h"
#include "Livro.h"
#include "PartMu.h"

using namespace std;

void CSV::loadData(string entrada, map<string, PPG*>* MAPAPPG, map<string, IES*>* MAPAIES){
    ifstream in(entrada);

    map<string, PPG*> &mapPPG = *MAPAPPG;
    map<string, IES*> &mapIES = *MAPAIES;

    if(in.fail()){
        throw exception(); 
    }
    string linha;
    getline(in, linha);
    while(getline(in, linha)) {
        cpp_util::Tokenizer tok(linha, ';');
        vector<string> dados = tok.remaining();
        
        //se PPG e IES existem:
        if(mapPPG.count(dados[0]) && mapIES.count(dados[2] + " " + dados[3])){
            if(!mapPPG[dados[0]]->existeNaLista(dados[3]))
                mapPPG[dados[0]]->registraIES(mapIES[dados[2] + " " + dados[3]]);

            if(!mapIES[dados[2] + " " + dados[3]]->existeNaLista(dados[0]))
                mapIES[dados[2] + " " + dados[3]]->registraPPG(mapPPG[dados[0]]);
        }

        //se o PPG ja existe mas a IES nao existe:
        else if(mapPPG.count(dados[0]) && !mapIES.count(dados[2] + " " + dados[3])){
            IES* tempIES = new IES(dados[3], dados[2]);
            mapIES[dados[2] + " " + dados[3]] = tempIES;
            if(!mapPPG[dados[0]]->existeNaLista(dados[3]))
                mapPPG[dados[0]]->registraIES(mapIES[dados[2] + " " + dados[3]]);

            if(!mapIES[dados[2] + " " + dados[3]]->existeNaLista(dados[0]))
                mapIES[dados[2] + " " + dados[3]]->registraPPG(mapPPG[dados[0]]);
        }

        //se a IES existe mas o PPG nao existe:
        else if(!mapPPG.count(dados[0]) && mapIES.count(dados[2] + " " + dados[3])){
            PPG* tempPPG = new PPG(dados[1], dados[0]);
            mapPPG[dados[0]] = tempPPG;
            if(!mapPPG[dados[0]]->existeNaLista(dados[3]))
                mapPPG[dados[0]]->registraIES(mapIES[dados[2] + " " + dados[3]]);

            if(!mapIES[dados[2] + " " + dados[3]]->existeNaLista(dados[0]))
                mapIES[dados[2] + " " + dados[3]]->registraPPG(mapPPG[dados[0]]);
        }

        //se nem a IES nem o PPG existem
        else{
            PPG* tempPPG = new PPG(dados[1], dados[0]);
            IES* tempIES = new IES(dados[3], dados[2]);
            mapPPG[dados[0]] = tempPPG;
            mapIES[dados[2] + " " + dados[3]] = tempIES;
            
            if(!mapPPG[dados[0]]->existeNaLista(dados[3]))
                mapPPG[dados[0]]->registraIES(mapIES[dados[2] + " " + dados[3]]);

            if(!mapIES[dados[2] + " " + dados[3]]->existeNaLista(dados[0]))
                mapIES[dados[2] + " " + dados[3]]->registraPPG(mapPPG[dados[0]]);
        }


        //Cria Anal
        if(dados[7] == "8"){
            Anais* a = new Anais(dados[5], dados[8], dados[9], dados[13], dados[14], dados[15], dados[16], dados[18]);
            mapPPG[dados[0]]->inserePub(a);
        }

        //Cria ArtJr
        else if(dados[7] == "9"){
            ArtJr* artJr = new ArtJr(dados[8], dados[12], dados[13], dados[9], dados[15], dados[10], dados[11]);
            mapPPG[dados[0]]->inserePub(artJr);
        }

        //Cria Outro
        else if(dados[7] == "10"){
            Outro* O = new Outro(dados[8], dados[12], dados[9], dados[10], dados[13]);
            mapPPG[dados[0]]->inserePub(O);
        }

        //Traducao
        else if(dados[7] == "21"){
            Traducao* trad= new Traducao(dados[8], dados[10], dados[11], dados[13], dados[12], dados[14], dados[17]);
            mapPPG[dados[0]]->inserePub(trad);
        }

        //ArtPe
        else if(dados[7] == "25"){
            ArtPe* artPe = new ArtPe(dados[8], dados[14], dados[18], dados[9], dados[10], dados[11], dados[21], dados[19], dados[12], dados[13]);
            mapPPG[dados[0]]->inserePub(artPe);
        }

        //Livro
        else if(dados[7] == "26"){
            Livro* livro = new Livro(dados[9], dados[15], dados[21], dados[10], dados[12], dados[11], dados[38]);
            mapPPG[dados[0]]->inserePub(livro);
        }

        //PartMu
        else if(dados[7] == "28"){
            PartMu* partMu = new PartMu(dados[8], dados[10], dados[9], dados[11], dados[13]);
            mapPPG[dados[0]]->inserePub(partMu);
        }


    }
    in.close();
}