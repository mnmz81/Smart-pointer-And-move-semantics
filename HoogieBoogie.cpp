#include "HoogieBoogie.h"

/**************************************************/
HoogieBoogie::HoogieBoogie(){}
/**************************************************/
HoogieBoogie::~HoogieBoogie(){}
/**************************************************/
HoogieBoogie::HoogieBoogie(HoogieBoogie &temp):shippingGraph(temp.shippingGraph) {}
/**************************************************/
HoogieBoogie::HoogieBoogie(HoogieBoogie &&temp):shippingGraph(temp.shippingGraph) {}
/**************************************************/
void HoogieBoogie::OpenFile(string& temp) {
    FileHandler t(temp);
    string source;
    Date time1;
    int num;
    vector<shared_ptr<Shipping>> array=t.getShipping();
    for (int i = 0; i < array.size(); ++i) shippingGraph.AddToGraph(*array[i]);
    source=array[0]->getSource();
    time1=array[0]->getLeavingTime();
    num=t.GetAllBox();
    ShipmentTrack newShipp(time1,num);
    this->shippingGraph.AddNewDispatching(source,newShipp); 
 }
/**************************************************/
void HoogieBoogie::outBound(string& temp){
    if(!checkName(temp)) throw cinError();
    Storage t(temp);
    this->shippingGraph.printVertexEdge(t);
    return;
 }
/**************************************************/
void HoogieBoogie::inbound(string& temp){
    if(!checkName(temp)) throw cinError();
    Storage t(temp);
    shippingGraph.printEdgeGroup(t);
 }
/**************************************************/
void HoogieBoogie::inventory(string& node,string& time_){
    if(!checkTime(time_)||!checkName(node)) throw cinError();
    Date date(time_);
    Storage source(node);
    this->shippingGraph.getBalance(source,date);
 }
/**************************************************/
void HoogieBoogie::shortest(string& node_source,string& node_target){
       if(!checkName(node_source)||!checkName(node_target)) throw cinError();
     this->shippingGraph.Dijkstra(node_source,node_target);
 }
/**************************************************/
void HoogieBoogie::printShipping(string& outputName){
    ofstream file;
    file.open(outputName);
    file<<this->shippingGraph;
    file.close();
 }
/**************************************************/
bool HoogieBoogie::checkName(string& temp) {
    string::iterator s=temp.begin();
    string::iterator e=temp.end();
    int count=0;
    while(s!=e){
        count++;
        if(!isalpha(*s) && *s!=' ') return false;
        s++;
    }
    return count <= 16;
 }
/**************************************************/
bool HoogieBoogie::checkTime(string& temp) {
    string::iterator s=temp.begin();
    string::iterator e=temp.end();
    string da,mo,ho,mi;
    while (isdigit(*s)){
        da+=*s;
        s++;
    }
    if(*s !='/'|| da.length() >2) return false;
    s++;
    while (isdigit(*s)) {
        mo+=*s;
        s++;
    }
    if(*s !=' '|| mo.length() >2) return false;
    s++;
    while (isdigit(*s)) {
        ho+=*s;
        s++;
    }
    if(*s !=':'|| ho.length() >2) return false;
    s++;
    while (isdigit(*s) && s != temp.end()){
        mi+=*s;
        s++;
    }
    s++;
    if(mi.length() >2) return false;
    if((stoi(da)>31)||(stoi(da)<1)||(stoi(mo)>12)||(stoi(mo)<1)||(stoi(ho)>24)
       ||(stoi(ho)<1)||(stoi(mi)>61)||(stoi(mi)<0))
        return false;
    return true;
 }
/*********************************/