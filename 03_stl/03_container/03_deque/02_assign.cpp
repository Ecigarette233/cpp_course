#include <iostream>
using namespace std;
#include <deque>

void printDeque(deque<int>& v)
{
    for (deque<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
}

void test01()
{
    deque<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printDeque(v1);
    cout<<endl;

    // 赋值
    deque<int> v2 = v1;
    printDeque(v2);
    cout << endl;

    // assign赋值
    deque<int> v3;
    v3.assign(v1.begin(), v1.end());
    cout << endl;

    // n个elem方式赋值
    deque<int> v4;
    v4.assign(10, 100);
    printDeque(v4);
}

int main()
{
    test01();
    return 0;
}