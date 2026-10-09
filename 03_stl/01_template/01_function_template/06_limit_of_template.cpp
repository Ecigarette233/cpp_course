#include <iostream>
using namespace std;
#include <string>

class Person
{
public:

    string m_name;
    int m_age;
    
};

template<typename T>
bool myCompare(T &a,T &b)
{
    if(a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<>bool myCompare(Person &p1,Person &p2)
{
    if(p1.m_age == p2.m_age && p1.m_name == p2.m_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Person p1 = {"Tom",18};
    Person p2 = {"Tom",18};

    bool ret = myCompare(p1,p2);
    if(ret)
    {
        cout<<"p1 == p1"<<endl;
    }
    else
    {
        cout<<"p1 != p1"<<endl;
    }
    
    return 0;
}