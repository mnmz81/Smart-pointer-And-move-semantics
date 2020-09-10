#ifndef CLION_STORAGE_H
#define CLION_STORAGE_H

#include <iostream>
#include <vector>
#include "Shipping.h"
#include "ShipmentTrack.h"

using namespace std;

//this class Represents a warehouse from which departs or enters deliveries

class Storage
{
private:
    string label;
    vector<Shipping> enterShipping;
    vector<ShipmentTrack> sendShipping;
    int boxsInTheStore;
public:
    //ctor and dtor
    Storage();
    Storage(string& name);
    Storage(const Storage& temp);
    Storage(Storage&& temp);
    ~Storage();
    //getter and setter
    int GetboxsInTheStore(){return boxsInTheStore;};
    string Getlabel(){return label;}
    vector<Shipping> getEnterShipping() {return enterShipping;};
    vector<ShipmentTrack> getSendShipping(){ return sendShipping;};
    void setlabel(string& temp) {label=temp;};
    //fun
    void getNewShipping(Shipping& temp);
    void sendNewShipping(ShipmentTrack& tmp);
    void BalanceByTime(Date& tmp);
    //operators
    friend ostream& operator<<(ostream&, const Storage&);
    Storage& operator=(const Storage& rhs);
    Storage& operator=(Storage&& rhs);
    friend bool operator==(const Storage& lhs,const Storage& rhs);
    friend bool operator==(const Storage& lhs,const string& rhs);
};

#endif //CLION_STORAGE_H
