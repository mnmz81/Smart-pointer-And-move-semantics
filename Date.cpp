#include "Date.h"

/*************************/
Date::Date():day(1),month(1),hours(00),minutes(00){}
/*************************/
Date::Date(string& temp){
    string::iterator s=temp.begin();
    string da,mo,ho,mi;
    while (!isdigit(*s)){ s++;}
    while (isdigit(*s)) {
        da+=*s;
        s++;
    }
    s++;
    while (isdigit(*s)) {
        mo+=*s;
        s++;
    }
    s++;
    while (isdigit(*s)) {
        ho+=*s;
        s++;
    }
    s++;
    while (s != temp.end()){
        mi+=*s;
        s++;
    }
    day=stoi(da);
    month=stoi(mo);
    hours=stoi(ho);
    minutes=stoi(mi);
 }
/*************************/
Date::Date(const Date& d):day(d.day),month(d.month),hours(d.hours),minutes(d.minutes){}
/*************************/
Date::Date(Date&& temp):day(temp.day),month(temp.month),hours(temp.hours),minutes(temp.minutes){}
/*************************/
bool operator<(const Date& lhs,const Date& rhs){
    if(lhs.month<rhs.month) return true;
    else if(lhs.month>rhs.month) return false;
    if(lhs.day<rhs.day) return true;
    else if(lhs.day>rhs.day) return false;
    if(lhs.hours<rhs.hours) return true;
    else if(lhs.hours>rhs.hours) return false;
    if(lhs.minutes<rhs.minutes) return true;
    return false;    
 }
/*************************/
bool operator>(const Date& lhs,const Date& rhs){
    if(lhs.month>rhs.month) return true;
    else if(lhs.month<rhs.month) return false;
    if(lhs.day>rhs.day) return true;
    else if(lhs.day<rhs.day) return false;
    if(lhs.hours>rhs.hours) return true;
    else if(lhs.hours<rhs.hours) return false;
    if(lhs.minutes>rhs.minutes) return true;
    return false;  
 }
/*************************/
bool operator==(const Date& lhs,const Date& rhs){
    if(lhs.month!=rhs.month) return false;
    if(lhs.day!=rhs.day) return false;
    if(lhs.hours!=rhs.hours) return false;
    if(lhs.minutes!=rhs.minutes) return false;
    return true;  
 }
/*************************/
ostream& operator<<(ostream& out, const Date& tmp){
    out<<tmp.day<<"/"<<tmp.month<<" "<<tmp.hours<<":"<<tmp.minutes;
    return out;
 }
/*************************/
Date& Date::operator=(const Date& rhs){
    if(this==&rhs) return *this;
    day=rhs.day;
    month=rhs.month;
    hours=rhs.hours;
    minutes=rhs.minutes;
    return *this;
 }
/*************************/
Date& Date::operator=(const Date&& rhs){
    if(this==&rhs) return *this;
    day=rhs.day;
    month=rhs.month;
    hours=rhs.hours;
    minutes=rhs.minutes;
    return *this;
 }
/*************************/