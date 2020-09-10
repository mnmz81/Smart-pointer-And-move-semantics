#ifndef CLION_GRAPH_H
#define CLION_GRAPH_H

#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "FileHandler.h"
#include <memory>


//this class is data base of the simulation

using namespace std;

class Graph {
private:
    vector<shared_ptr<Vertex>> vertexSet;
    void addVertex(Storage &in);
    void addEdge(const Storage &sourc, const Storage &dest, Shipping& w);
    Graph& operator=(const Graph& rhs);
    Graph& operator=(Graph&& rhs);
    const int MaxNum=1000000000;
    void printPathDijkstra(vector<string>& route, int next);
    int minIndex(vector<double>& temp1, vector<bool>& temp2);
public:
    //ctor and dtor
    Graph();
    Graph(const Graph& temp);
    Graph(Graph&& temp);
    ~Graph();
    //getter and setter
    int getNumVertex() const{return vertexSet.size();};
    vector<shared_ptr<Vertex>> getVertexSet()  { return vertexSet;};
    int findIndex(string& temp);
    //func
    void removeVertex(Storage& in);
    void AddToGraph(Shipping& temp);
    void removeEdge(const Storage &sourc, const Storage &dest);
    void AddNewDispatching(string& source,ShipmentTrack& t);
    shared_ptr<Vertex> getVertex(Storage &sourc);
    void printVertexEdge(Storage& sourc);
    void printEdgeGroup(Storage& sourc);
    void getBalance(Storage& source,Date& time_);
    void Dijkstra(string& source, string& dest);
   //operator
    friend ostream& operator<<(ostream& out, const Graph& temp);
    class NotInDateBase{
    public:
        NotInDateBase(string& t):temp(t){}
        virtual void PrintError(){
            cout <<temp<<" does not exist in the database."<<endl;
        }
    protected:
        string temp;
    };
};

#endif //CLION_GRAPH_H
