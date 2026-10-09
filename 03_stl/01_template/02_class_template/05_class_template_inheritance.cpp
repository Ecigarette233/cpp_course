#include <iostream>
using namespace std;

template <class T>
class Base
{
public:
    T m;
};

// 错误，必须知道父类中的T类型
// class Son:public Base
class Son : public Base<int>
{
};

void test01()
{
    Son S1;
}

// 如果想灵活指定父类中T类型，子类也需要变类模板
template <class T1, class T2>
class Son2 : public Base<T2>
{
public:
    Son2()
    {
        cout << "T1数据类型为" << typeid(T1).name() << endl;
        cout << "T2数据类型为" << typeid(T2).name() << endl;
    }
    T1 obj;
};

void test02()
{
    Son2<int, char> S2;
}

int main()
{
    test01();
    test02();
    return 0;
}