#include<iostream>
#include<string.h>
using namespace std;

class Person{
private:
    string name,phone;
    char gender;
    int age;
public:
    Person(string n,int a,char g,string p)
    {
        this->name=n;
        this->age=a;
        this->gender=g;
        this->phone=p;
    }
    
    string getname()
    {
        return this->name;
    }
    
    char getgender()
    {
        return this->gender;
    }
    
    string getphone()
    {
        return this->phone;
    }
    
    int getage()
    {
        return this->age;
    }
    
};