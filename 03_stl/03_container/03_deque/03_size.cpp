#include <iostream>
using namespace std;
#include <deque>

void printDeque(deque<int> &v)
{
    for(deque<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printDeque(v1);

    if (v1.empty())
    {
        cout << "容器为空" << endl;
    }
    

    // 重新指定大小
    // v1.resize(15);
    v1.resize(15, 100);
    printDeque(v1);

    v1.resize(5);
    printDeque(v1);
}

int main()
{
    test01();
    return 0;
}