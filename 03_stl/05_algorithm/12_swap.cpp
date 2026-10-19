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

int main()
{
    vector<int> v1;
    vector<int> v2;
    
    for(int i = 0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+100);
    }

    cout<<"before swap"<<endl;
    for_each(v1.begin(),v1.end(),MyPrint());
    cout<<endl;
    for_each(v2.begin(),v2.end(),MyPrint());

    cout<<endl;
    
    cout<<"--------------"<<endl;

    swap(v1,v2);

    cout<<"after swap"<<endl;
    for_each(v1.begin(),v1.end(),MyPrint());
    cout<<endl;
    for_each(v2.begin(),v2.end(),MyPrint());


    return 0;
}