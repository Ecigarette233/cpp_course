#include <iostream>
using namespace std;
#include <string>

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }

    void operator()(string test)
    {
        cout << test << endl;
        this->count++;
    }

    int count;
};

void doPrint(MyPrint& mp,string test)
{
    mp(test);
}

void test01()
{
    MyAdd myadd;
    cout << myadd(10, 10)<<endl;
}

void test02()
{
    MyPrint myprint;
    myprint("hello world");
}

void test03()
{
    MyPrint mp;
    doPrint(mp,"hello C++");

}

int main()
{
    test01();
    
    cout<<"-------------"<<endl;

    test02();

    cout<<"-------------"<<endl;

    test03();

    return 0;
}