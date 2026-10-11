#include <iostream>
using namespace std;
#include <string>

template <class T1, class T2>
class Person
{
    //类内实现
    friend void showPerson(Person<T1, T2> p)
    {
        cout << p.m_name << endl;
        cout << p.m_age << endl;
    }

    //类外实现
    friend void showPerson2<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }

private:
    T1 m_name;
    T2 m_age;
};

// 类外实现
template <class T1, class T2>
void showPerson2(Person<T1, T2> p)
{
    cout << "类外实现" << endl;
    cout << p.m_name << endl;
    cout << p.m_age << endl;
}

int main()
{
    Person<string, int> p("tom", 19);
    showPerson2(p);
    return 0;
}