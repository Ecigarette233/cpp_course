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
    //默认构造
    list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    printList(lst);

    //区间构造
    list<int> lst2(lst.begin(),lst.end());
    printList(lst2);

    //拷贝构造
    list<int>L3(lst2);
    printList(lst2);

    //n个elem
    list<int>L4(4,10);
    printList(L4);

}

int main()
{
    test01();
    return 0;
}