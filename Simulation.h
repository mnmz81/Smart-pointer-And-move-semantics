#ifndef CLION_SIMULATION_H
#define CLION_SIMULATION_H

#include <iostream>
#include "HoogieBoogie.h"
#include "FileHandler.h"

//this class is the Simulation

using namespace std;

class Simulation {
    private:
        string outputName;
        HoogieBoogie hogi;
        void setFileName(char* name);
        vector<string> getDataFromCin();
    public:
    Simulation();
    ~Simulation();
    //fun//
    void initialization(int argc, char *argv[]);
    void initialization(){};
    void run();
    
};


#endif //CLION_SIMULATION_H
