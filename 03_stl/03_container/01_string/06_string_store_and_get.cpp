#include <iostream>
using namespace std;
#include <string>

void test01()
{

    string str = "hello";

    //1.通过[]访问字符
    //str.size()可以获取长度
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }

    cout<<endl;
    cout<<"-----------------"<<endl;

    //2.通过at方式访问单个字符
    for(int i = 0;i<str.size();i++)
    {
        cout<<str.at(i)<<" ";
    }

    //修改单个字符
    str[0] = 'x';

    str.at(1) = 's';
    
    cout<<str<<endl;


}

int main()
{
    test01();
    return 0;
}