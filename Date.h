#ifndef CLION_DATE_H
#define CLION_DATE_H

//this class presenter the time of shipping

#include <iostream>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int hours;
    int minutes;
public:
    //ctor and dtor//
    Date();
    Date(string& temp);
    Date(const Date& temp);
    Date(Date&& temp);
    ~Date() {};
    //getter and setter//
    int getDay(){return day;};
    int getMonth(){return month;};
    int getHours(){return hours;};
    int getMinutes(){return minutes;};
    //operators//
    Date& operator=(const Date& rhs);
    Date& operator=(const Date&& rhs);
    friend bool operator<(const Date& lhs,const Date& rhs);
    friend bool operator>(const Date& lhs,const Date& rhs);
    friend bool operator==(const Date& lhs,const Date& rhs);
    friend ostream& operator<<(ostream&, const Date&);
};

#endif //CLION_DATE_H
