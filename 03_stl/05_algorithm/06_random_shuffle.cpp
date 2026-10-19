#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>

void print(int val)
{
    cout<<val<<" ";
}

void test01()
{
    vector<int> v;

    for(int i = 0;i<10;i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(),v.end(),print);

    cout<<endl;

    random_shuffle(v.begin(),v.end());

    for_each(v.begin(),v.end(),print);

}

int main()
{
    srand((unsigned int)time(NULL));

    test01();
    return 0;
}