#ifndef CLION_EDGE_H
#define CLION_EDGE_H

#include <iostream>
#include "Vertex.h"
#include "Shipping.h"
#include <memory>
#include <vector>
class Vertex;


//this class is Edge in the Graph

using namespace std;
class Edge {
    string from;
    shared_ptr<Vertex> dest;
    int weightBoxs;
    double weightTime;
    vector<Shipping> allShiping;
public:
    friend class Graph;
    friend class Vertex;
    //ctor and dtor
    Edge(shared_ptr<Vertex>& d,Shipping& temp);
    Edge(const Edge& temp);
    Edge(Edge&& temp);
    //getter and setter
    string getFom(){return from;};
    vector<Shipping> getAllShiping(){return allShiping;};
    int getWeightBoxs(){return weightBoxs;};
    string getDest();
    double getWeightTime(){return allShiping.size()==0 ? 0:(weightTime/allShiping.size());};
    //fun
    void upDateShipping(Shipping& newShiping);
    //operator
    Edge& operator=(const Edge& rhs);
    Edge& operator=(Edge&& rhs);
    friend bool operator==(const Edge& lhs,const Edge& rhs);
    friend bool operator==(const Edge& lhs,const string& rhs);
    friend ostream& operator<<(ostream& out,const Edge& temp);
};
#endif //CLION_EDGE_H
