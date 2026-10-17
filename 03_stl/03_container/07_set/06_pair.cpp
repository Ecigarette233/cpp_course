#include <iostream>
using namespace std;
#include <string>

void test01()
{
    pair<string, int> p("tom", 20);

    cout << p.first << endl;
    cout << p.second << endl;

    pair<string, int> p2 = make_pair("jerry",20);

    cout << p2.first << endl;
    cout << p2.second << endl;
}

int main()
{
    test01();
    return 0;
}