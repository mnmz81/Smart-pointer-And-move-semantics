#include "Shipping.h"
/*******************************************/
Shipping::Shipping():source("Frankfurt"),destination("Frankfurt"),leavingTime(new Date()),arrivalTime(new Date()),numOfBoxs(0),timeMintet(0) {}
/*******************************************/
Shipping::Shipping(string& source_, string& destination_, Date& from_, Date& to_, int box_, int timeMintet_):source(source_),destination(destination_),leavingTime(new Date(from_)),arrivalTime(new Date(to_)),numOfBoxs(box_),timeMintet(timeMintet_){}
/*******************************************/
Shipping::Shipping(const Shipping &temp):source(temp.source),destination(temp.destination),leavingTime(new Date(*temp.leavingTime)),arrivalTime(new Date(*temp.arrivalTime)),numOfBoxs(temp.numOfBoxs),timeMintet(temp.timeMintet){}
/*******************************************/
Shipping::Shipping(Shipping &&temp):source(temp.source),destination(temp.destination),leavingTime(new Date(*temp.leavingTime)),arrivalTime(new Date(*temp.arrivalTime)),numOfBoxs(temp.numOfBoxs),timeMintet(temp.timeMintet){}
/*******************************************/
Shipping::~Shipping() {}
/*******************************************/
ostream& operator<<(ostream& out, const Shipping& temp){
    out<<temp.source<<" ";
    out<<temp.leavingTime;
    out<<" "<<temp.destination<<" "<<temp.numOfBoxs<<endl;
    return  out;
    }
/*******************************************/
Shipping& Shipping::operator=(const Shipping& rhs){ 
    if(this==&rhs) return *this;
    source=rhs.source;
    destination=rhs.destination;
    *leavingTime=*rhs.leavingTime;
    *arrivalTime=*rhs.arrivalTime;
    numOfBoxs=rhs.numOfBoxs;
    timeMintet=rhs.timeMintet;
    return *this;
 }
/*******************************************/
Shipping& Shipping::operator=(const Shipping&& rhs){
    if(this==&rhs) return *this;
    source=rhs.source;
    destination=rhs.destination;
    *leavingTime=*rhs.leavingTime;
    *arrivalTime=*rhs.arrivalTime;
    numOfBoxs=rhs.numOfBoxs;
    timeMintet=rhs.timeMintet;
    return *this;
 }
/*******************************************/
bool operator==(const Shipping& lhs,const Shipping& rhs){
    if((lhs.source==rhs.source)&&(lhs.destination==rhs.destination)) return true;
    return false;
 }
/*******************************************/