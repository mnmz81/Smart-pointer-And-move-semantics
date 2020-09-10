#ifndef CLION_FileHandler_H
#define CLION_FileHandler_H

#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <cctype>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Shipping.h"

using namespace std;

//this class open a file and return array of all the shipments
//this class also check input of file
class FileHandler {
private:
    string fileName;
    vector<shared_ptr<Shipping>> shippingArray;
    int allBox;
    bool checkBoxs(string& temp);
    int getBoxs(string& temp);
    int getDiffInTime(Date& t1,Date& t2);
public:
    //ctor and dtor//
    FileHandler(string& name);
    FileHandler(const FileHandler& temp);
    FileHandler(FileHandler&& temp);
    ~FileHandler();
    //getter//
    vector<shared_ptr<Shipping>> getShipping(){ return  shippingArray;};
    int GetAllBox(){return allBox;};
    //operators//
    FileHandler& operator=(const FileHandler& rhs);
    FileHandler& operator=(FileHandler&& rhs);
    friend ostream& operator<<(ostream&, const FileHandler&);
    //fun//
    bool checkName(string& temp);
    bool checkTime(string& temp);
    //exception//
    class InputError{
    public:
        InputError(string& t,int s):fileName(t),line1(s) {}
        virtual void PrintError(){
            cout <<"Invalid input in file "<<fileName<<" at line "<<line1<<endl;
        }
    protected:
        string fileName;
        int line1;
    };
    class OpenFileError{
    public:
        OpenFileError(){}
        virtual void PrintError(){
            cout <<"ERROR opening/reading the specified file"<<endl;
        }
    };
};


#endif //CLION_FileHandler_H
