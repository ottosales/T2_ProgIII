#ifndef CSV_H_
#define CSV_H_

#include <cstdio>
#include <string>
#include <map>
#include "PPG.h"
#include "IES.h"

using namespace std;

class CSV{
    public:
        static void loadData(string, map<string, PPG*>*, map<string, IES*>*);
};



#endif