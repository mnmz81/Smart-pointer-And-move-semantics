#include "Edge.h"

/******************************************************/
Edge::Edge(shared_ptr<Vertex>& d,Shipping& temp):from(temp.getSource()),dest(d),weightBoxs(temp.getBox()),weightTime(temp.getTime()){
    this->allShiping.push_back(temp);
 }
/******************************************************/
Edge::Edge(const Edge& temp):from(temp.from),dest(temp.dest),weightBoxs(temp.weightBoxs),weightTime(temp.weightTime),allShiping(temp.allShiping){}
/******************************************************/
Edge::Edge(Edge&& temp):from(temp.from),dest(temp.dest),weightBoxs(temp.weightBoxs),weightTime(temp.weightTime),allShiping(temp.allShiping){}
/******************************************************/
void Edge::upDateShipping(Shipping& newShiping){
    this->allShiping.push_back(newShiping);
    weightBoxs+=newShiping.getBox();
    weightTime+=newShiping.getTime();
    dest->getInfo().getNewShipping(newShiping);
 }
/******************************************************/
string Edge::getDest(){
        return dest->getInfo().Getlabel();
 }
/******************************************************/
bool operator==(const Edge& lhs,const Edge& rhs){
    if(*(lhs.dest)==*(rhs.dest)) return true;
    return false;
 }
/******************************************************/
bool operator==(const Edge &lhs, const string &rhs) {
    if(lhs.dest->getInfo().Getlabel()==rhs) return true;
    return false;
 }
/******************************************************/
ostream& operator<<(ostream& out,const Edge& temp){
    int sum=0;
    if(temp.allShiping.size()!=0) sum=temp.weightTime/temp.allShiping.size();
    out<<temp.dest->getInfo().Getlabel()<<","<<sum<<endl;
    return out;
 }
/******************************************************/
Edge &Edge::operator=(const Edge &rhs) {
    if(this==&rhs) return *this;
    from=rhs.from;
    dest=rhs.dest;
    weightBoxs=rhs.weightBoxs;
    weightTime=rhs.weightTime;
    allShiping.clear();
    allShiping.assign(rhs.allShiping.begin(),rhs.allShiping.end());
    return *this;
 }
/******************************************************/
Edge &Edge::operator=(Edge &&rhs) {
    if(this==&rhs) return *this;
    from=rhs.from;
    dest=rhs.dest;
    weightBoxs=rhs.weightBoxs;
    weightTime=rhs.weightTime;
    allShiping.clear();
    allShiping.assign(rhs.allShiping.begin(),rhs.allShiping.end());
    return *this;
 }
 /******************************************************/