#include <iostream>
using namespace std;

void test01()
{
    string str1 = "iello";
    string str2 = "hello";

    if(str1.compare(str2) == 0)
    {
        cout<<"str1 == str2"<<endl;
    }
    else if(str1.compare(str2)>0)
    {
        cout<<"str1 > str2"<<endl;
    }
    else
    {
        cout<<"str1 < str2"<<endl;

    }
}

int main()
{
    test01();
    return 0;
}