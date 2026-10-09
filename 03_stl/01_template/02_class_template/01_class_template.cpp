#include <iostream>
using namespace std;
#include <string>

template<class NameType,class AgeType>
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

int main()
{
    Person<string,int> p1("zhangsan",999);
    p1.showPerson();
    return 0;
}