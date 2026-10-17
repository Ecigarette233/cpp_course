#include <iostream>
using namespace std;
#include <string>

void test01()
{
    // 1.char*类型字符串
    string str1;
    str1 = "hello world";
    cout << str1 << endl;

    // 2.传入string类型字符串
    string str2;
    str2 = str1;
    cout << str2 << endl;

    // 3.单个字符赋值
    string str3;
    str3 = 'a';
    cout << str3 << endl;

    // 4.成员函数赋值
    string str4;
    str4.assign("hello world");
    cout << str4 << endl;

    //5.成员函数赋值，但多个参数n
    //意思是传入前n个字符
    string str5;
    str5.assign("hello C++",5);
    cout<<str5<<endl;

    //6.类似于拷贝构造
    string str6;
    str6.assign(str5);
    cout<<str6<<endl;

    //7.传入数字和字符
    string str7;
    str7.assign(10,'w');
    cout<<str7<<endl;
}

int main()
{
    test01();
    return 0;
}