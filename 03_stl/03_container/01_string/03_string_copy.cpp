#include <iostream>
using namespace std;
#include <string>

void test01()
{
    // 1.+=追加字符串
    string str1 = "我";
    str1 += "爱玩游戏";
    cout << str1 << endl;

    // 2.+=追加字符
    str1 += ':';
    cout << str1 << endl;

    // 3.字符串拼接
    string str2 = "CSGO";
    str1 += str2;
    cout << str1 << endl;

    // 4.利用成员函数append
    string str3 = "I";
    str3.append(" love ");
    cout << str3 << endl;

    // 5.前n个字符拼接进来
    str3.append("game CS", 4);
    cout << str3 << endl;

    // 6.直接追加字符串
    str3.append(str2);
    cout << str3 << endl;

    // 7.追加字符串,多2个参数
    str3.append(str2,0,2);
    cout << str3 << endl;
    str3.append(str2,2,4);
    cout << str3 << endl;
}

int main()
{
    test01();
    return 0;
}