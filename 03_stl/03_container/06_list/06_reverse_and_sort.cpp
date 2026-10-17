#include <iostream>
using namespace std;
#include <list>

//降序
bool myCompare(int v1,int v2)
{
    //降序,就让第一个数>第二个数
    return v1>v2;
}

void printList(const list<int> &lst)
{
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(30);
    L1.push_back(20);

    printList(L1);

    L1.reverse();
    printList(L1);

    // 默认升序
    L1.sort();
    printList(L1);

    //降序
    L1.sort(myCompare);
    printList(L1);
}

int main()
{
    test01();
    return 0;
}