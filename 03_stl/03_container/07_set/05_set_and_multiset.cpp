#include <iostream>
using namespace std;
#include <set>

void test01()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);

    if (ret.second)
    {
        cout << "successfully insert" << endl;
    }
    else
    {
        cout<<"fail to insert"<<endl;
    }

    ret = s.insert(10);

    if (ret.second)
    {
        cout << "successfully insert" << endl;
    }
    else
    {
        cout<<"fail to insert"<<endl;
    }

    multiset<int> ms;
    
    ms.insert(10);
    ms.insert(10);

    for(multiset<int>::iterator it = ms.begin();it!=ms.end();it++)
    {
        cout<<*it<<endl;
    }

}
int main()
{
    test01();
    return 0;
}