#include <iostream>
using namespace std;
#include <list>

void printList(const list<int>& lst)
{
    for(list<int>::const_iterator it = lst.begin();it != lst.end();it++)
    {
        cout<<*it<<" ";
    }

    cout<<endl;
}

void test01()
{
    list<int>lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    printList(lst);

    if(lst.empty())
    {
        cout<<"lst为空"<<endl;
    }
    else
    {
        cout<<"lst不为空"<<endl;
    }

    lst.resize(10);
    printList(lst);
    
}

int main()
{
    test01();

    return 0;
}