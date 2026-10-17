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

    list<int>l2;
    l2 = lst;
    printList(l2);

    list<int>l3;
    l3.assign(l2.begin(),l2.end());
}

void test02()
{
    list<int>lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    printList(lst);

    list<int>l2;
    l2.assign(10,100);
    printList(lst);
    printList(l2);

    lst.swap(l2);
    cout<<"after swap"<<endl;
    printList(lst);
    printList(l2);
}

int main()
{
    test01();

    test02();
    return 0;
}