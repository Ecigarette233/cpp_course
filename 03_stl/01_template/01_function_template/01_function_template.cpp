#include <iostream>
using namespace std;

//利用模板实现两个数交换的功能

template<typename T>
void mySwap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    //1.自动类型推导
    int a = 10;
    int b = 20;

    mySwap(a,b);

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    //2.显示指定类型
    int c = 100;
    int d = 200;

    mySwap<int>(c,d);

    cout<<"c = "<<c<<endl;
    cout<<"d = "<<d<<endl;
}

int main()
{
    test01();
    return 0;
}