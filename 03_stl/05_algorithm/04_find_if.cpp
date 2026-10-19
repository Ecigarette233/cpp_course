#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

//用find_if查找自定义数据类型
class Person
{
public:
    Person(string name,int age)
    {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;

};

class Greater24
{
public:
    bool operator()(const Person& p)
    {
        return p.age>24;
    }

};

void print(const Person& p)
{
    cout<<p.name<<" "<<p.age<<endl;
}

int main()
{
    vector<Person> v;

    Person p1("a",18);
    Person p2("b",19);
    Person p3("c",15);
    Person p4("d",25);
    Person p5("e",29);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for_each(v.begin(),v.end(),print);

    vector<Person>::iterator it = find_if(v.begin(),v.end(),Greater24());
    if(it != v.end())
    {
        cout<<"找到了"<<endl;
        cout<<it->name<<endl;
        cout<<it->age<<endl;
    }

    return 0;
}