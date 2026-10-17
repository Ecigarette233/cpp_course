#include <iostream>
using namespace std;
#include <string>

// 1.查找
void test01()
{
    string str1 = "abcdefgde";

    int pos = str1.find("de");

    cout << "pos = " << pos << endl;

    pos = str1.find("fd");

    cout << "pos = " << pos << endl;

    // rfind
    // rfind是从右往左查找
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;
}

// 2.替换
void test02()
{
    string str2 = "abcdefg";

    str2.replace(1, 3, "1111");
    cout << str2 << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}