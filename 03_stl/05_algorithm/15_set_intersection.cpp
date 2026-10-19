#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void myPrint(int value)
{
    cout<<value<<" ";
}

int main()
{
    vector<int> v1;
    vector<int> v2;
    for(int i = 0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    vector<int> vTarget;

    vTarget.resize(min(v1.size(),v2.size()));

    //获取交集
    vector<int>::iterator itEnd = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());

    for_each(vTarget.begin(),itEnd,myPrint);  

    return 0;
}