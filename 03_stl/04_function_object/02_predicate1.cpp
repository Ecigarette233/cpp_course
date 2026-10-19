#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 找到大于5的数字
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

    cout << *it << endl;
}

int main()
{
    test01();
    return 0;
}