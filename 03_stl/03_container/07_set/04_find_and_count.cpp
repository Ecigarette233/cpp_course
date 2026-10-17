#include <iostream>
using namespace std;
#include <set>

void test01()
{
    set<int> s;

    s.insert(10);
    s.insert(40);
    s.insert(70);
    s.insert(30);
    s.insert(15);

    set<int>::iterator pos = s.find(41);
    if (pos != s.end())
    {
        cout << "找到元素" << *pos << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
}

// 统计
void test02()
{
    set<int> s;
    s.insert(10);
    s.insert(40);
    s.insert(70);
    s.insert(30);
    s.insert(15);
    s.insert(15);
    s.insert(15);

    int sum = s.count(15);
    cout << sum << endl;
}

int main()
{
    test01();
    cout << "---------------" << endl;
    test02();
    return 0;
}