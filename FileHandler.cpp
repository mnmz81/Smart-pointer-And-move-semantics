#include "FileHandler.h"
/***************************************************/
FileHandler::FileHandler(string& name):fileName(name),allBox(0){
    ifstream input1(name);
    int counter=1;
    string source,destination,leavingTime,arrivalTime, numOfBoxs;
    if (!input1.good() || input1.eof()) throw OpenFileError();
    getline(input1,source,',');
    getline(input1,leavingTime);
    while(!input1.eof()){
        getline(input1,destination,',');
        getline(input1,arrivalTime,',');
        getline(input1,numOfBoxs,',');
        if(!checkName(source)||!checkName(destination)||!checkTime(leavingTime)||!checkTime(arrivalTime)||!checkBoxs(numOfBoxs)) throw InputError(fileName,counter);
        else{
            Date leavingTime1(leavingTime);
            Date arrivalTime1(arrivalTime);
            int timeMintet=getDiffInTime(arrivalTime1,leavingTime1);
            if(timeMintet==-1) throw InputError(fileName,counter);
            shared_ptr<Shipping> newShip(new Shipping(source,destination,leavingTime1,arrivalTime1,getBoxs(numOfBoxs),timeMintet));
            allBox+=newShip->getBox();
            this->shippingArray.push_back(newShip);
            source=destination;
            getline(input1,leavingTime);
        }
    }
 }
/***************************************************/
FileHandler::FileHandler(const FileHandler &temp):fileName(temp.fileName),shippingArray(temp.shippingArray){}
/***************************************************/
FileHandler::FileHandler(FileHandler &&temp):fileName(temp.fileName),shippingArray(temp.shippingArray){}
/***************************************************/
FileHandler::~FileHandler() {}
/***************************************************/
bool FileHandler::checkName(string& temp) {
    string::iterator s=temp.begin();
    string::iterator e=temp.end();
    int count=0;
    while(s!=e){
        count++;
        if(!isalpha(*s) && *s!=' ') return false;
        s++;
    }
    return count <= 16;
 }
/***************************************************/
bool FileHandler::checkTime(string& temp) {
    string::iterator s=temp.begin();
    string::iterator e=temp.end();
    string da,mo,ho,mi;
    while (isdigit(*s)){
        da+=*s;
        s++;
    }
    if(*s !='/'|| da.length() >2) return false;
    s++;
    while (isdigit(*s)) {
        mo+=*s;
        s++;
    }
    if(*s !=' '|| mo.length() >2) return false;
    s++;
    while (isdigit(*s)) {
        ho+=*s;
        s++;
    }
    if(*s !=':'|| ho.length() >2) return false;
    s++;
    while (isdigit(*s) && s != temp.end()){
        mi+=*s;
        s++;
    }
    s++;
    if(mi.length() >2) return false;
    if((stoi(da)>31)||(stoi(da)<1)||(stoi(mo)>12)||(stoi(mo)<1)||(stoi(ho)>24)
       ||(stoi(ho)<1)||(stoi(mi)>61)||(stoi(mi)<0))
        return false;
    return true;
 }
/*********************************/
bool FileHandler::checkBoxs(string &temp){
    string::iterator s=temp.begin();
    string sum;
    while (!isdigit(*s)){ s++;}
    while (isdigit(*s)) {
        sum+=*s;
        s++;
    }
    if(s!=temp.end())return false;
    if(stoi(sum)<0) return false;
    return true;;
 }
/*********************************/
int FileHandler::getDiffInTime(Date& t1,Date& t2){
    if(t1<t2) return -1;
    int sum=0;
    sum+=((t1.getDay()-t2.getDay())*HOURSMAX*MINUTESMAX);
    sum+=((t1.getMonth()-t2.getMonth())*DAYMAX*HOURSMAX*MINUTESMAX);
    sum+=((t1.getHours()-t2.getHours())*MINUTESMAX);
    sum+=((t1.getMinutes()-t2.getMinutes()));
    return sum;
 }
/***************************************************/
int FileHandler::getBoxs(string& temp){
    string::iterator s=temp.begin();
    string::iterator e=temp.end();
    string sum;
    while (!isdigit(*s)){ s++;}
    while (s!=e) {
        sum+=*s;
        s++;
    }
    return stoi(sum);
 }
/***************************************************/
FileHandler &FileHandler::operator=(const FileHandler &rhs) {
    if(this==&rhs) return  *this;
    this->fileName=rhs.fileName;
    this->shippingArray.clear();
    this->shippingArray.assign(rhs.shippingArray.begin(),rhs.shippingArray.end());
    return *this;
 }
/***************************************************/
FileHandler &FileHandler::operator=(FileHandler &&rhs) {
    if(this==&rhs) return  *this;
    this->fileName=rhs.fileName;
    this->shippingArray.clear();
    this->shippingArray.assign(rhs.shippingArray.begin(),rhs.shippingArray.end());
    return *this;
 }
/***************************************************/
ostream &operator<<(ostream &out, const FileHandler &temp) {
    out<<temp.fileName<<endl;
    return out;
 }
/***************************************************/