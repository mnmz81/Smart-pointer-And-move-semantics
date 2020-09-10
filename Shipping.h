#ifndef CLION_SHIPPING_H
#define CLION_SHIPPING_H

//this class Represents a shipment from one city to another

#include <iostream>
#include <memory>
#include "Date.h"
#define DAYMAX 30
#define MONTHMAX 12
#define HOURSMAX 24
#define MINUTESMAX 60

class Shipping {
private:
    string source;
    string destination;
    shared_ptr<Date> leavingTime;
    shared_ptr<Date> arrivalTime;
    int numOfBoxs;
    int  timeMintet;
public:
    //ctor and dtor
    Shipping();
    Shipping(string& source_,string& destination_,Date& from_,Date& to_,int box_,int timeMintet_);
    Shipping(const Shipping& temp);
    Shipping(Shipping&& temp);
    ~Shipping();
    //getter and setter
    string getSource(){return source;};
    string getDestination(){return destination;};
    Date getLeavingTime(){return *leavingTime;};
    Date getArrivalTime(){return *arrivalTime;};
    int getBox() {return  numOfBoxs;};
    int getTime() {return  timeMintet;};
    //operator
    friend ostream& operator<<(ostream&, const Shipping&);
    Shipping& operator=(const Shipping& rhs);
    Shipping& operator=(const Shipping&& rhs);
    friend bool operator==(const Shipping& lhs,const Shipping& rhs);
};


#endif //CLION_SHIPPING_H
