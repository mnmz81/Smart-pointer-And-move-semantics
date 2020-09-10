#include "Storage.h"

/************************************/
Storage::Storage():label("Amsterdam"),boxsInTheStore(0){}
/************************************/
Storage::Storage(string& label):label(label),boxsInTheStore(0){}
/************************************/
Storage::Storage(const Storage& temp):label(temp.label),enterShipping(temp.enterShipping),sendShipping(temp.sendShipping),boxsInTheStore(temp.boxsInTheStore){}
/************************************/
Storage::Storage(Storage&& temp):label(temp.label),enterShipping(temp.enterShipping),sendShipping(temp.sendShipping),boxsInTheStore(temp.boxsInTheStore){}
/************************************/
Storage::~Storage(){}
/************************************/
void Storage::getNewShipping(Shipping& temp){
    enterShipping.push_back(temp);
    boxsInTheStore+=temp.getBox();
 }
/************************************/
void Storage::sendNewShipping(ShipmentTrack& tmp){
    sendShipping.push_back(tmp);
    boxsInTheStore-=tmp.getBox();
 }
/************************************/
void Storage::BalanceByTime(Date& tmp){
    int sum=0;
    vector<Shipping>::iterator bes=enterShipping.begin();
    vector<Shipping>::iterator ees=enterShipping.end();
    vector<ShipmentTrack>::iterator bss=sendShipping.begin();
    vector<ShipmentTrack>::iterator ess=sendShipping.end();
    while (bes!=ees){
        if((*bes).getLeavingTime()<tmp) sum+=(*bes).getBox();
        bes++;
    }
    while (bss!=ess){
        if((*bss).getTime()<tmp) sum-=(*bss).getBox();
        bss++;
    }
    cout<<this->label<<","<<sum<<endl;
 }
/************************************/
ostream& operator<<(ostream& out, const Storage& temp){
    out<<temp.label<<" "<<temp.boxsInTheStore<<endl;
    return out;
 }
/************************************/
Storage& Storage::operator=(const Storage& temp){
    if(this==&temp ) return *this;
    label=temp.label;
    enterShipping.clear();
    enterShipping.assign(temp.enterShipping.begin(),temp.enterShipping.end());
    sendShipping.clear();
    sendShipping.assign(temp.sendShipping.begin(),temp.sendShipping.end());
    boxsInTheStore=temp.boxsInTheStore;
    return *this;
 }
/************************************/
bool operator==(const Storage& lhs,const Storage& rhs){
    if(lhs.label==rhs.label)return true;
    return false;
 }
 /************************************/
Storage& Storage::operator=(Storage&& temp){
    label=temp.label;
    enterShipping.clear();
    enterShipping.assign(temp.enterShipping.begin(),temp.enterShipping.end());
    sendShipping.clear();
    sendShipping.assign(temp.sendShipping.begin(),temp.sendShipping.end());
    boxsInTheStore=temp.boxsInTheStore;
    return *this;
 }
/************************************/
bool operator==(const Storage &lhs, const string &rhs) {
    if(lhs.label==rhs)return true;
    return false;
 }
/************************************/
