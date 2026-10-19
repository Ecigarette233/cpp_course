#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v1;

    v1.push_back(10);
    v1.push_back(50);
    v1.push_back(30);

    vector<int> v2;
    v2.resize(v1.size());

    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(), print);
}

int main()
{
    test01();
    return 0;
}