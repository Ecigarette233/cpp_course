#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

void print(int val)
{
    cout<<val<<" ";
}

void test01()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(60);
    v.push_back(40);

    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(),print);

}

int main()
{
    test01();
    return 0;
}