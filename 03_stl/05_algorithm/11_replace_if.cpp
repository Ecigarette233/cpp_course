#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class MyPrint
{
public:
    void operator()(int value)
    {
        cout<<value<<" ";
    }

};

class Greater5
{
public:
    bool operator()(int value)
    {
        return value>5;
    }
};

void test01()
{
    vector<int> v;

    for(int i = 0;i<10;i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(),v.end(),MyPrint());

    cout<<endl;

    replace_if(v.begin(),v.end(),Greater5(),2000);

    for_each(v.begin(),v.end(),MyPrint());

}

int main()
{
    test01();
    
    return 0;
}