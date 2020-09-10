#ifndef CLION_HOOGIEBOOGIE_H
#define CLION_HOOGIEBOOGIE_H

#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Shipping.h"
#include "FileHandler.h"
#include <string>

//this class is the simulation compony

using namespace std;

class HoogieBoogie
{
private:
    Graph shippingGraph;
    bool checkName(string& temp);
    bool checkTime(string& temp);
public:
    //ctor and dtor//
    HoogieBoogie();
    HoogieBoogie(HoogieBoogie& temp);
    HoogieBoogie(HoogieBoogie&& temp);
    ~HoogieBoogie();
    //func//
    void OpenFile(string& temp);
    void outBound(string& temp);
    void inbound(string& name);
    void shortest(string& node_source,string& node_target);
    void inventory(string& node,string& time);
    void printShipping(string& name);
    class cinError{
    public:
        cinError(){}
        virtual void PrintError(){
            cout<<"USAGE: 'open',<file> *or* <node>,'outbound'/'inbound' *or* <node>,'inventory',dd/mm HH:mm *or* <node>,<node>,'shortest' *or* ‘exit’ *to terminate*"<<endl;
        }
    };
};


#endif //CLION_HOOGIEBOOGIE_H
