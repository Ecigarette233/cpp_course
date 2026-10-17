#include <iostream>
using namespace std;
#include <map>

class Mycompare
{
public:
    bool operator()(int v1,int v2) const
    {
        return v1>v2;
    }
};

void printMap(map<int,int,Mycompare>& m)
{
    for(map<int,int,Mycompare>::iterator it = m.begin();it!=m.end();it++)
    {
        cout<<"key = "<<it->first<<" ";
        cout<<"value = "<<it->second<<endl;
    }

    cout<<endl;
}

void test01()
{
    map<int,int,Mycompare> m;

    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));

    printMap(m);



}

int main()
{
    test01();
    return 0;
}