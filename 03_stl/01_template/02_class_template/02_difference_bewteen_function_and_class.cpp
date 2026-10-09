#include <iostream>
using namespace std;
#include <string>

template<class NameType,class AgeType = int>
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        this->m_age = age;
        this->m_name = name;
    }

    void showPerson()
    {
        cout<<"name = "<<this->m_name<<endl;
        cout<<"age  = "<<this->m_age<<endl;
    }

    NameType m_name;
    AgeType m_age;
};

//1.类模板没有自动类型推导的功能
void test01()
{
    Person p1("张三",18);
}

//2.
void test02()
{
    Person<string> p2("李四",20);
}

int main()
{
    
    return 0;
}