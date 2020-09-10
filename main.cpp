#include <iostream>
#include <string>
#include "FileHandler.h"
#include "Simulation.h"

using namespace std;

int main(int argc, char *argv[])
{  
    Simulation t;
    try{
        if(argc<3) throw FileHandler::OpenFileError();
        string tmp(argv[1]);
        if(tmp !="-f") throw FileHandler::OpenFileError();
        t.initialization(argc-2,&argv[2]);
    }
    catch(FileHandler::InputError& t){
        t.PrintError();
        return 0;
    }
    catch(FileHandler::OpenFileError& t){
            t.PrintError();
            return 0;
    }
    t.run();
    
}
