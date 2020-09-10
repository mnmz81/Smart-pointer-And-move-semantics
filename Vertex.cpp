#include "Vertex.h"
/*************************************************/
Vertex::Vertex(){}
/*************************************************/
Vertex::Vertex(Storage& temp):storage(temp){}
/*************************************************/
Vertex::Vertex(string& name_):storage(name_){}
/*************************************************/
Vertex::Vertex(const Vertex &v):storage(v.storage),EdgeArray(v.EdgeArray){}
/*************************************************/
Vertex::Vertex(Vertex &&v):storage(v.storage),EdgeArray(v.EdgeArray){}
/*************************************************/
void Vertex::addToOldEdge(shared_ptr<Vertex>& dest, Shipping &w){
    vector<Edge>::iterator b=EdgeArray.begin();
    vector<Edge>::iterator e=EdgeArray.end();
    while (b!=e){
        while (b!=e){
            if( b->dest->storage==dest->storage) {
                b->upDateShipping(w);
                return;
            }
            b++;
        }
    }
 }
/*************************************************/
void Vertex::addNewEdge(shared_ptr<Vertex>& dest, Shipping& w) {
    Edge edgeD(dest,w);
    edgeD.dest->getInfo().getNewShipping(w);
    EdgeArray.push_back(edgeD);
 }
/*************************************************/
bool Vertex::removeEdgeTo(shared_ptr<Vertex>& d) {
    if(!hasEdge(d->getInfo())) return false;
    typename vector<Edge>::iterator it= EdgeArray.begin();
    typename vector<Edge>::iterator ite= EdgeArray.end();
    while (it!=ite){
        if( it->dest->storage==d->storage) {
            EdgeArray.erase(it);
            return true;
        }
        else it++;
    }
 }
/*************************************************/
void Vertex::addEdge(shared_ptr<Vertex>& dest, Shipping &w){
    if(hasEdge(dest->getInfo())) addToOldEdge(dest,w);
    else addNewEdge(dest,w);
 }
/*************************************************/
bool Vertex::hasEdge(Storage &store){
    vector<Edge>::iterator b=EdgeArray.begin();
    vector<Edge>::iterator e=EdgeArray.end();
    while (b!=e){
        if( b->dest->storage==store) return true;
        b++;
    }
    return false;
 }
/*************************************************/
Edge Vertex::getEdge(Storage &store) {
    vector<Edge>::iterator b=EdgeArray.begin();
    vector<Edge>::iterator e=EdgeArray.end();
    while (b!=e){
        if( b->dest->storage==store) return *b;
        b++;
    }
 }
/*************************************************/
ostream& operator<<(ostream& out,const Vertex& temp){
    out<<temp.storage;
    return out;
 }
/*************************************************/
Vertex& Vertex::operator=(const Vertex& rhs){
    if(this==&rhs ) return *this;
    storage=rhs.storage;
    EdgeArray.clear();
    EdgeArray.assign(rhs.EdgeArray.begin(),rhs.EdgeArray.end());
    return *this;
 }
/*************************************************/
Vertex& Vertex::operator=(Vertex&& rhs){
    storage=rhs.storage;
    EdgeArray.clear();
    EdgeArray.assign(rhs.EdgeArray.begin(),rhs.EdgeArray.end());
    return *this;
 }
/*************************************************/
bool operator==(const Vertex &lhs, const Vertex &rhs) {
    return lhs.storage == rhs.storage;
 }
/*************************************************/
bool operator==(const Vertex& lhs,const Storage& rhs){
     return lhs.storage == rhs;
 }
/*************************************************/