#include <iostream>
using namespace std;
#include <functional>

//算数仿函数

int main()
{
    //取反
    negate<int> n;
    cout<<n(50)<<endl;

    //加法
    plus<int> p;
    cout<<p(50,10)<<endl;

    return 0;
}