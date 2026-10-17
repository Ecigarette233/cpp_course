#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

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

    d1.push_back(6);
    d1.push_back(10);
    d1.push_back(1);
    d1.push_back(45);
    d1.push_back(5);
    d1.push_back(77);
    d1.push_back(3);

    printDeque(d1);

    //从小到大
    sort(d1.begin(),d1.end());
    cout<<"排序后"<<endl;
    printDeque(d1);
}

int main()
{
    test01();
    return 0;
}