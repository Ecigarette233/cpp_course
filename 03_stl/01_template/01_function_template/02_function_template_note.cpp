#include <iostream>
using namespace std;

template<typename T>
void mySwap(T&a,T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void func()
{
    cout<<"func函数的调用"<<endl;
}

void test01()
{
    //1.必须是相同数据类型
    int a = 10;
    int b = 20;
    char c = 'c';

    mySwap(a,b);
    //mySwap(a,c);

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    //2.模板必须确定出T的数据类型，才可以使用
    func<int>();
    //func();错误


}

int main()
{
    test01();
    return 0;
}