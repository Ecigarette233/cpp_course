#include <iostream>
using namespace std;
#include <vector>
#include <string>

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    // 容器互换
    v2.swap(v1);

    cout << "互换后v1为" << endl;
    printVector(v1);

    cout << "v2为" << endl;
    printVector(v2);
}

// 实际用途：收缩内存空间
void test02()
{
    vector<int> v;
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(i);
    }

    cout << "v收缩前的容量：" << v.capacity() << endl;

    //用swap收缩内存
    vector<int>(v).swap(v);
    
    cout << "v收缩后的容量：" << v.capacity() << endl;
    cout << "v收缩后的大小：" << v.size() << endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}