#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Person
{
public:
    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    bool operator==(const Person& p)
    {
        if(this->m_name == p.m_name && this->m_age == p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string m_name;
    int m_age;
};

void test01()
{
    vector<Person> v;

    Person p1("aaa",18);
    Person p2("abb",20);
    Person p3("aab",22);
    Person p4("acc",32);
    Person p5("abc",28);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person pp("abb",20);

    vector<Person>::iterator it = find(v.begin(),v.end(),pp);

    if(it !=v.end())
    {
        cout<<"找到了"<<endl;
    }
    else
    {
        cout<<"没找到"<<endl;
    }
}

int main()
{
    test01();
    return 0;
}