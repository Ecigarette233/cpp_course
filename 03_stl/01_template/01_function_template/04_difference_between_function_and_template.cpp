#include <iostream>
using namespace std;

//普通函数和函数模板区别
//1.普通函数：可以隐式转换
//2.函数模板：用自动类型，不可以发生隐式转换
//3.函数模板：用显示指定类型，可以发生隐式类型转换

int myAdd01(int a,int b)
{
    return a+b;
}

template<class T>
T myAdd02(T a,T b)
{
    return a+b;
}

void test01()
{
    int a = 10;
    char c = 20;
    myAdd01(a,c);
    cout<<myAdd01(a,c)<<endl;

    //myAdd02(a,c);直接报错

    myAdd02<int>(a,c);
    cout<<myAdd02<int>(a,c)<<endl;

}

int main()
{
    test01();
    return 0;
}