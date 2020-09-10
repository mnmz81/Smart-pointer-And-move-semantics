#ifndef CLION_VERTEX_H
#define CLION_VERTEX_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Storage.h"
#include "Edge.h"
#include "Shipping.h"

using namespace std;
class Edge;


//this class Represents a vertex in the graph
class Vertex {
private:
    Storage storage;
    vector<Edge> EdgeArray;
    void addToOldEdge(shared_ptr<Vertex>& dest, Shipping& w);
    void addNewEdge(shared_ptr<Vertex>& dest, Shipping& w);
public:
    //ctor and dtor
    Vertex();
    Vertex(Storage& temp);
    Vertex(string& name_);
    Vertex(const Vertex &v);
    Vertex(Vertex &&v);
    //getter and setter
    Storage& getInfo(){return storage;};
    vector<Edge> getEdgeArray() {return EdgeArray;};
    //operators
    friend ostream& operator<<(ostream&, const Vertex&);
    Vertex& operator=(const Vertex& rhs);
    Vertex& operator=(Vertex&& rhs);
    friend bool operator==(const Vertex& lhs,const Vertex& rhs);
    friend bool operator==(const Vertex& lhs,const Storage& rhs);
    //func
    void addEdge(shared_ptr<Vertex>& dest, Shipping& w);
    bool removeEdgeTo(shared_ptr<Vertex>& d);
    bool hasEdge(Storage& store);
    Edge getEdge(Storage& store);
    friend class Graph;
};

#endif //CLION_VERTEX_H
