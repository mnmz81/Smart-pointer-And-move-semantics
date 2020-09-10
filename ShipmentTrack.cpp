#include "ShipmentTrack.h"

ShipmentTrack::ShipmentTrack(){}
/*****************************************************/
ShipmentTrack::ShipmentTrack(Date& timeOfStartShipment_,int num_):timeOfStartShipment(timeOfStartShipment_),numOfBox(num_){}
/*****************************************************/
ShipmentTrack::ShipmentTrack(const ShipmentTrack& temp):timeOfStartShipment(temp.timeOfStartShipment),numOfBox(temp.numOfBox){}
/*****************************************************/
ShipmentTrack::ShipmentTrack(ShipmentTrack&& temp):timeOfStartShipment(temp.timeOfStartShipment),numOfBox(temp.numOfBox){}
/*****************************************************/
ShipmentTrack& ShipmentTrack::operator=(const ShipmentTrack& rhs){
    if(this==&rhs ) return *this;
    timeOfStartShipment=rhs.timeOfStartShipment;
    numOfBox=rhs.numOfBox;
    return *this;
}
/*****************************************************/
ShipmentTrack& ShipmentTrack::operator=(ShipmentTrack&& rhs){
    if(this==&rhs ) return *this;
    timeOfStartShipment=rhs.timeOfStartShipment;
    numOfBox=rhs.numOfBox;
    return *this;
}
/*****************************************************/
ostream& operator<<(ostream& out,const ShipmentTrack& temp){
    out<<temp.timeOfStartShipment;
    out<<" "<<temp.numOfBox<<endl;
    return out;
}
/*****************************************************/