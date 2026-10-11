#include <iostream>
using namespace std;
#include <string>

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);

    void showPerson();

    T1 name;
    T2 age;
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << name << endl;
    cout << age << endl;
}

void test01()
{
    Person<string, int> p("tom", 19);
    p.showPerson();
}

int main()
{
    test01();
    return 0;
}