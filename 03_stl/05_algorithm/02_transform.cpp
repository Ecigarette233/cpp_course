#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// int Transform(int val)
// {
//     return val+100;
// }

class Transform
{
public:
    int operator()(int val)
    {
        return val+100;
    }

};

void test01()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> v2;

    v2.resize(v.size());

    transform(v.begin(), v.end(), v2.begin(), Transform());

    for(vector<int>::iterator it = v2.begin();it!=v2.end();it++)
    {
        cout<<*it<<" ";
    }
}

int main()
{
    test01();
    return 0;
}