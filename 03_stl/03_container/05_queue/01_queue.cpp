#include <iostream>
using namespace std;
#include <queue>

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};

void test01()
{
    queue<Person> q;

    Person p1("zhangsan", 30);
    Person p2("lisi", 10);
    Person p3("wangwu", 32);
    Person p4("zhaoliu", 16);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout << q.size() << endl;

    while (!q.empty())
    {
        cout << q.front().name << " " << q.front().age << endl;

        cout << q.back().name << " " << q.back().age << endl;

        q.pop();
    }

    cout << q.size() << endl;
}

int main()
{
    test01();
    return 0;
}