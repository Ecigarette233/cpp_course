#include <iostream>
using namespace std;

void myPrint(int a,int b)
{
    cout<<"调用普通函数"<<endl;
}

template<typename T>
void myPrint(T a,T b)
{
    cout<<"调用函数模板"<<endl;
}

template<typename T>
void myPrint(T a,T b,T c)
{
    cout<<"调用重载的函数模板"<<endl;
}

int main()
{
    int a = 10,b = 20;

    myPrint(a,b);

    myPrint<>(a,b);

    myPrint(a,b,100);

    char c1 = 'a';
    char c2 = 'b';

    myPrint(c1,c2);

    return 0;
}