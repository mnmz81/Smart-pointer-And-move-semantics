#include "Simulation.h"

/*********************************************/
Simulation::Simulation():outputName("output.dat"){}
/*********************************************/
Simulation::~Simulation() {}
/*********************************************/
void Simulation::initialization(int argc, char *argv[]) {
    if(argc==0) {
        return;
    }
    else{
        string t(argv[0]);
        if(t=="-p"){
            if(argc==1) throw FileHandler::OpenFileError();
            else setFileName(argv[1]);
            return;
        }
        hogi.OpenFile(t);
        initialization(argc-1,&argv[1]);
    }
 }
/*********************************************/
void Simulation::run() {
    while (true){
        try{
            cout<<"please inter a input:"<<endl;
            vector<string> tmp=this->getDataFromCin();
            if(tmp.size()==1){
                if(tmp[0]=="print"){
                        hogi.printShipping(outputName);
                        continue;
                }
                cout<<"USAGE: 'open',<file> *or* <node>,'outbound'/'inbound' *or* <node>,'inventory',dd/mm HH:mm *or* <node>,<node>,'shortest' *or* ‘exit’ *to terminate*"<<endl;
                if(tmp[0]=="exit") return;
                continue;
            }
            if(tmp.size()==2){
                if (tmp[0]=="open"){
                    hogi.OpenFile(tmp[1]);
                    continue;
                }
                if(tmp[1]=="outbound"){
                    hogi.outBound(tmp[0]);
                    continue;
                }
                if(tmp[1]=="inbound"){
                    hogi.inbound(tmp[0]);
                    continue;
                }
                throw HoogieBoogie::cinError();
            }
            if(tmp.size()==3){
                if(tmp[1]=="inventory"){
                    hogi.inventory(tmp[0],tmp[2]);
                    continue;
                }
                if(tmp[0]=="shortest"){
                    hogi.shortest(tmp[1],tmp[2]);
                    continue;
                }
            }
            throw HoogieBoogie::cinError();
        }
        catch(FileHandler::InputError& t){
            t.PrintError();
        }
        catch(FileHandler::OpenFileError& t){
            t.PrintError();
        }
        catch(Graph::NotInDateBase& t){
            t.PrintError();
        }
        catch(HoogieBoogie::cinError& t){
            t.PrintError();
        }
    }
 }
/*********************************************/
void Simulation::setFileName(char* name){
    outputName.erase();
    outputName.assign(name);
 }
/*********************************************/
vector<string> Simulation::getDataFromCin(){
    vector<string> tmp;
    string line;
    string temp1,temp2,temp3;
    getline(cin,line);
    string::iterator b=line.begin();
    string::iterator e=line.end();
    while (b!=e && *b!=','){temp1+=*b;b++;}
    tmp.push_back(temp1);
    if(b==e) return tmp;
    b++;
    while (b!=e && *b!=','){temp2+=*b;b++;}
    tmp.push_back(temp2);
    if(b==e) return tmp;
    b++;
    while (b!=e){temp3+=*b;b++;}
    tmp.push_back(temp3);
    return tmp;
 }
/*********************************************/