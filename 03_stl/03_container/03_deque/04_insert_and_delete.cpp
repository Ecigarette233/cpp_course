#include <iostream>
using namespace std;
#include <deque>

void printDeque(deque<int> &v)
{
    for (deque<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

void test01()
{
    deque<int> d1;

    // 尾插
    d1.push_back(10);
    d1.push_back(20);

    // 头插
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);

    // 尾删
    d1.pop_back();

    // 头删
    d1.pop_front();
    printDeque(d1);
}

void test02()
{
    deque<int> d1;

    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);

    // insert插入
    d1.insert(d1.begin(), 1000);

    d1.insert(d1.begin(), 2, 10000);

    printDeque(d1);

    deque<int> d2;

    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    // 区间插入
    d1.insert(d1.begin(), d2.begin(), d2.end());

    printDeque(d1);
}

void test03()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);

    // 删除
    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);
    printDeque(d1);
}

int main()
{
    test01();

    cout << "-------------" << endl;

    test02();

    cout << "-------------" << endl;

    test03();

    return 0;
}