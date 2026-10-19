#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//二元谓词
class MyCompare
{
public:
    bool operator()(int v1,int v2)
    {
        return v1>v2;
    }

};

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(60);
    v.push_back(20);

    //MyCompare匿名函数
    sort(v.begin(),v.end(),MyCompare());

    for(vector<int>::iterator it = v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }

    return 0;
}