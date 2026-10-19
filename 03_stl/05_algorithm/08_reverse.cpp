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
    vector<int> v;

    v.push_back(10);
    v.push_back(50);
    v.push_back(70);
    v.push_back(40);
    v.push_back(20);

    // 反转前
    for_each(v.begin(), v.end(), print);
    cout << endl;

    // 反转后
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), print);
}

int main()
{
    test01();
    return 0;
}