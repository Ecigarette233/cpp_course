#include <iostream>
using namespace std;
#include <string>

void test01()
{
    // 默认构造
    string s1; 

    // 有参构造
    const char *str = "helloworld";
    string s2(str);

    cout << "s2 = " << s2 << endl;

    // 拷贝构造
    string s3(s2);
    cout << "s3 = " << s3 << endl;

    string s4(10,'a');
    cout<<"s4 = "<<s4<<endl;
}

int main()
{
    test01();
    return 0;
}