#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
}

void test01()
{
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printVector(v1);
    cout<<endl;

    // 赋值
    vector<int> v2 = v1;
    printVector(v2);
    cout << endl;

    // assign赋值
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    cout << endl;

    // n个elem方式赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}