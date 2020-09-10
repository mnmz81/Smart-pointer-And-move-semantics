#ifndef CLION_SHIPMENTTRACK_H
#define CLION_SHIPMENTTRACK_H

#include "Date.h"
#include <iostream>

//this class Represents a delivery route between cities

class ShipmentTrack {
private:
    Date timeOfStartShipment;
    int numOfBox;
public:
    //ctor and dtor
    ShipmentTrack();
    ShipmentTrack(Date& timeOfStartShipment_,int num_);
    ShipmentTrack(const ShipmentTrack& temp);
    ShipmentTrack(ShipmentTrack&& temp);
    ~ShipmentTrack(){};
    //operator
    ShipmentTrack& operator=(const ShipmentTrack& rhs);
    ShipmentTrack& operator=(ShipmentTrack&& rhs);
    friend ostream& operator<<(ostream& out,const ShipmentTrack& temp);
    //getter and setter
    Date getTime(){ return timeOfStartShipment;};
    int getBox(){ return  numOfBox;};
    void setTime(Date& t){timeOfStartShipment=t;};
    void setBox(int t){numOfBox=t;};
};


#endif //CLION_SHIPMENTTRACK_H
