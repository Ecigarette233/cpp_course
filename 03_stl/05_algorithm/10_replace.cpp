#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class MyPrint
{
public:
    void operator()(int value)
    {
        cout << value << " ";
    }
};

void test01()
{
    vector<int> v;

    v.push_back(20);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(20);
    v.push_back(20);

    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    replace(v.begin(), v.end(), 20, 2000);

    for_each(v.begin(), v.end(), MyPrint());
}

int main()
{
    test01();
    return 0;
}