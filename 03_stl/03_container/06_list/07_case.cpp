#include <iostream>
using namespace std;
#include <string>
#include <list>

//案例描述:将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
//排序规则:按照年龄进行升序，如果年龄相同按照身高进行降序
class Person
{
public:
    Person(string name,int age,int height)
    {
        this->m_name = name;
        this->m_age = age;
        this->m_height = height;
    }

    string m_name;
    int m_age;
    int m_height;
};

void printPerson(list<Person>& lst)
{
    for(list<Person>::iterator it = lst.begin();it!=lst.end();it++)
    {
        cout<<"姓名:"<<(*it).m_name<<" "
            <<"年龄:"<<it->m_age<<" "
            <<"身高"<<it->m_height<<endl;
    }
}

bool myCompare(Person& p1,Person& p2)
{
    //按年龄升序,若年龄相同就按照身高降序
    if(p1.m_age == p2.m_age)
    {
        return p1.m_height>p2.m_height;
    }
    else
    {
        return p1.m_age<p2.m_age;
    }
    
}

int main()
{
    list<Person> lst;

    Person p1("刘备",35,188);
    Person p2("关羽",29,197);
    Person p3("张飞",35,178);
    Person p4("赵云",30,195);
    Person p5("孙权",42,174);
    Person p6("曹操",35,181);

    lst.push_back(p1);
    lst.push_back(p2);
    lst.push_back(p3);
    lst.push_back(p4);
    lst.push_back(p5);
    lst.push_back(p6);

    printPerson(lst);

    lst.sort(myCompare);

    cout<<"-------------------------"<<endl;

    printPerson(lst);

    return 0;
}