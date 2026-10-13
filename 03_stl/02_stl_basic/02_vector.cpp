#include <iostream>
using namespace std;
#include <string>
#include <vector>

//利用vector存自定的数据类型
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

void test01()
{
    vector<Person>v;

    Person p1("aaa",19);
    Person p2("aba",13);
    Person p3("aab",14);
    Person p4("baa",29);
    Person p5("abb",49);
    Person p6("bab",7);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);

    for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
    {
        cout<<"姓名"<<(*it).m_name;
        cout<<"年龄"<<(*it).m_age<<endl;
    }
}

void test02()
{
    vector<Person*>v;

    Person p1("aaa",19);
    Person p2("aba",13);
    Person p3("aab",14);
    Person p4("baa",29);
    Person p5("abb",49);
    Person p6("bab",7);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    v.push_back(&p6);

    for(vector<Person*>::iterator it = v.begin();
        it!=v.end();
        it++
    ) 
    {
        cout<<"::姓名"<<(*it)->m_name;
        cout<<"::年龄"<<(*it)->m_age<<endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}