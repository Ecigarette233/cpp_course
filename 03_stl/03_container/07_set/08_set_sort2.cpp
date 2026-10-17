#include <iostream>
using namespace std;
#include <string>
#include <set>

class Person
{
public:
    Person(string name,int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string m_name;
    int m_age;

};

class Mycompare
{
public:
    bool operator()(const Person& p1,const Person& p2) const
    {
        return p1.m_age > p2.m_age;
    }
};

void test01()
{
    set<Person,Mycompare> s;

    Person p1("刘备",18);
    Person p2("关羽",29);
    Person p3("张飞",25);
    Person p4("赵云",17);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for(set<Person,Mycompare>::iterator it = s.begin();it!=s.end();it++)
    {
        cout<<"姓名:"<<it->m_name
            <<"年龄:"<<it->m_age<<endl;
    }

}

int main()
{
    test01();
    return 0;
}