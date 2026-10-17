#include <iostream>
using namespace std;
#include <vector>

void test01()
{
    vector<int>v;

    int num;
    int* p = NULL;

    v.reserve(10000);
    //预留空间

    for(int i = 0;i<10000;i++)
    {
        v.push_back(i);

        if(p!=&v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout<<"num = "<<num<<endl;
}

int main()
{
    test01();
    return 0;
}