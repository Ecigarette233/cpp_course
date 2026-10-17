#include <iostream>
using namespace std;
#include <deque>

void printDeque(deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

void test01()
{
    deque<int> d1;

    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }

    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int> d3(d2);
    printDeque(d3);

    deque<int> d4(10,100);
    printDeque(d3);
}

int main()
{
    test01();
    return 0;
}