#include <iostream>
using namespace std;
#include <string>

void test01()
{
    string str = "abcdef";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;
}

void test02()
{
    string email = "zhangsan@email.com";
    int pos = email.find("@");
    string name = email.substr(0, pos);
    cout << name << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}