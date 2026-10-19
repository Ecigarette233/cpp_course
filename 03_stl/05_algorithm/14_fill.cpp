#include <iostream>
using namespace std;
#include <vector>
#include <numeric>

int main()
{
    vector<int> v;

    v.resize(10);

    fill(v.begin(),v.end(),100);

    for(vector<int>::iterator it = v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
    
    return 0;
}