#include "Graph.h"

Graph::Graph(){}
/***********************************************/
Graph::Graph(const Graph& temp):vertexSet(temp.vertexSet){}
/***********************************************/
Graph::Graph(Graph&& temp):vertexSet(temp.vertexSet){}
/***********************************************/
Graph::~Graph(){}
/***********************************************/
void Graph::addVertex(Storage &in) {
    typename vector<shared_ptr<Vertex>>::iterator it= vertexSet.begin();
    typename vector<shared_ptr<Vertex>>::iterator ite= vertexSet.end();
    for (; it!=ite; it++)
        if ((*it)->getInfo() == in) return;
    shared_ptr<Vertex> v1(new Vertex(in));
    vertexSet.push_back(v1);
 }
/***********************************************/
void Graph::addEdge(const Storage& sourc, const Storage&dest, Shipping& w) {
    typename vector<shared_ptr<Vertex>>::iterator it= vertexSet.begin();
    typename vector<shared_ptr<Vertex>>::iterator ite= vertexSet.end();
    int found=0;
    shared_ptr<Vertex>  edgeS, edgeD;
    while (found!=2 && it!=ite ){
        if ((*it)->storage == sourc){edgeS=*it; found++;}
        if ((*it)->storage == dest){edgeD=*it; found++;}
        it ++;
    }
    edgeS->addEdge(edgeD,w);
 }
/***********************************************/
void Graph::removeVertex(Storage& in){
    shared_ptr<Vertex> t(new Vertex(in));
    typename vector<shared_ptr<Vertex>>::iterator it= vertexSet.begin();
    typename vector<shared_ptr<Vertex>>::iterator ite= vertexSet.end();
    for (; it!=ite; it++) {
        if (*t== *((*it).get())){
            vertexSet.erase(it);
            typename vector<shared_ptr<Vertex>>::iterator it1= vertexSet.begin();
            typename vector<shared_ptr<Vertex>>::iterator it1e= vertexSet.end();
            for (; it1!=it1e; it1++) {
                (*it1)->removeEdgeTo(t);
            }
            return;
        }
    }
 }
/***********************************************/
void Graph::AddToGraph(Shipping &temp) {
    string sourceName=temp.getSource();
    string destinationName=temp.getDestination();
    Storage source(sourceName);
    Storage destination(destinationName);
    addVertex(source);
    addVertex(destination);
    addEdge(source,destination,temp);
 }
/***********************************************/
void Graph::removeEdge(const Storage &sourc, const Storage &dest) {
    typename vector<shared_ptr<Vertex>>::iterator it= vertexSet.begin();
    typename vector<shared_ptr<Vertex>>::iterator ite= vertexSet.end();
    int found=0;
    shared_ptr<Vertex> edgeS, edgeD;
    while (found!=2 && it!=ite ) {
        if ((*it)->storage == sourc) {edgeS=*it;found++;}
        if ((*it)->storage == dest) {edgeD=*it; found++;}
        it ++;
    }
    if (found!=2) return;
    edgeS->removeEdgeTo(edgeD);
 }
/***********************************************/
shared_ptr<Vertex> Graph::getVertex(Storage &sourc){
    typename vector<shared_ptr<Vertex>>::iterator it= vertexSet.begin();
    typename vector<shared_ptr<Vertex>>::iterator ite= vertexSet.end();
    while (it!=ite ) {
        if ((*it)->storage == sourc) return *it;
        it ++;
    }
    return nullptr;
 }
/***********************************************/
void Graph::AddNewDispatching(string& sourc,ShipmentTrack& t){
    vector<shared_ptr<Vertex>>::iterator b=vertexSet.begin();
    vector<shared_ptr<Vertex>>::iterator e=vertexSet.end();
    while(b!=e){
        if((*b)->storage.Getlabel()==sourc){
            (*b)->storage.sendNewShipping(t);
        }
        b++;
    }
 }
/***********************************************/
void Graph::printVertexEdge(Storage& sourc){
    vector<shared_ptr<Vertex>>::iterator b=vertexSet.begin();
    vector<shared_ptr<Vertex>>::iterator e=vertexSet.end();
    string sourcName=sourc.Getlabel();
    while (b!=e){
        if((*b)->getInfo()==sourc) break;
        b++;
    }
    if(b==e) throw Graph::NotInDateBase(sourcName);
    if((*b)->EdgeArray.size()==0){
        cout<<sourcName<<" no outbound nodes"<<endl;
        return;
    }
    vector<Edge>::iterator be=(*b)->EdgeArray.begin();
    vector<Edge>::iterator ee=(*b)->EdgeArray.end();
    while (be!=ee){
        cout<<(*be);
        be++;
    }
 }
/***********************************************/
void Graph::printEdgeGroup(Storage& sourc){
    bool flag=false;
    typename vector<shared_ptr<Vertex>>::iterator it= vertexSet.begin();
    typename vector<shared_ptr<Vertex>>::iterator ite= vertexSet.end();
    string sourcName=sourc.Getlabel();
    vector<Edge> temp;
    while (it!=ite ){
        if((*it)->getInfo()==sourc) flag=true;
        if ((*it)->hasEdge(sourc))
            temp.push_back((*it)->getEdge(sourc)); 
        it ++;
    }
    if(!flag) throw Graph::NotInDateBase(sourcName);
    if(temp.size()==0){
        cout<<sourcName<<" no inbound nodes"<<endl;
    }
    vector<Edge>::iterator be=temp.begin();
    vector<Edge>::iterator ee=temp.end();
    while (be!=ee){
        cout<<(*be).from<<","<<(*be).getWeightTime()<<endl;
        be++;
    }
 } 
/***********************************************/
void Graph::getBalance(Storage& sourc,Date& time_){
    typename vector<shared_ptr<Vertex>>::iterator it= vertexSet.begin();
    typename vector<shared_ptr<Vertex>>::iterator ite= vertexSet.end();
    string sourcName=sourc.Getlabel();
    while (it!=ite){
        if((*it)->getInfo()==sourc) break;
        it++;
    }
    if(it==ite) throw Graph::NotInDateBase(sourcName);
    (*it)->getInfo().BalanceByTime(time_);
 }
/*******************************************/
int Graph::findIndex(string& temp){
    typename vector<shared_ptr<Vertex>>::iterator it= vertexSet.begin();
    typename vector<shared_ptr<Vertex>>::iterator ite= vertexSet.end();
    for (int i = 0; it!=ite; it++,i++)
        if((*it)->storage.Getlabel()==temp) return i;
    throw Graph::NotInDateBase(temp);
 }
/***********************************************/
ostream& operator<<(ostream& out,const Graph& temp){
    typename vector<shared_ptr<Vertex>>::const_iterator it=temp.vertexSet.cbegin();
    typename vector<shared_ptr<Vertex>>::const_iterator ite= temp.vertexSet.cend();
    for (; it!=ite; it++) out<<**it;
    return out;
 }
/***********************************************/
Graph& Graph::operator=(const Graph& rhs){
    if(this==&rhs) return *this;
    vertexSet.clear();
    vertexSet.assign(rhs.vertexSet.begin(),rhs.vertexSet.end());
    return *this;
 }
/***********************************************/
Graph& Graph::operator=(Graph&& rhs){
    if(this==&rhs) return *this;
    vertexSet.clear();
    vertexSet.assign(rhs.vertexSet.begin(),rhs.vertexSet.end());
    return *this;
 }
/***********************************************/
void Graph::Dijkstra(string& source, string& dest){
    int sourceIndex = findIndex(source),destIndex = findIndex(dest);
    if (sourceIndex == -1)throw NotInDateBase(source);
    if (destIndex == -1) throw NotInDateBase(dest);
    int sizeOfVertex =vertexSet.size();
    vector<double> temp1(sizeOfVertex, MaxNum);
    vector<bool> temp2(sizeOfVertex, false);
    vector<string> via(sizeOfVertex, "null");
    temp1[sourceIndex] = 0;
    via[sourceIndex] = "Head";
    for (int j = 0; j < sizeOfVertex - 1; j++){
        int minInd = minIndex(temp1,temp2);
        temp2[minInd] = true;
        int edgeSize =vertexSet[minInd]->getEdgeArray().size();
        for (int i = 0; i < edgeSize; i++){
            string destName = vertexSet[minInd]->getEdgeArray()[i].getDest();
            int dest = findIndex(destName);
            double weight = temp1[minInd] + vertexSet[minInd]->getEdgeArray()[i].getWeightTime() + abs(vertexSet[sourceIndex]->storage.GetboxsInTheStore());
            if (!temp2[dest] && weight < temp1[dest]){
                via[dest] = vertexSet[minInd]->storage.Getlabel();
                temp1[dest] = weight;
            }
        }
    }
    if (temp1[destIndex] != MaxNum){
        temp1[destIndex] = fabs(abs(vertexSet[destIndex]->storage.GetboxsInTheStore())) + temp1[destIndex];
        cout << "The path is:" << endl;
        printPathDijkstra(via, destIndex);
        cout << vertexSet[destIndex]->storage.Getlabel() << endl;
        cout << "The distance: " << temp1[destIndex] << endl;
    }
    else cout << "route unavailable" << endl;
 }
/***********************************************/
int Graph::minIndex(vector<double>& temp1, vector<bool>& temp2){
    double min = MaxNum, min_index;

    for (int i = 0; i < temp1.size(); i++){
        if (temp2[i] == false && temp1[i] <= min){
            min = temp1[i];
            min_index = i;
        }
    }
    return min_index;
 }
/***********************************************/
void Graph::printPathDijkstra(vector<string>& via, int next){
    if (via[next] == "Head") return;
    printPathDijkstra(via, findIndex(via[next]));
    cout << via[next] << " to ";
 }
/***********************************************/