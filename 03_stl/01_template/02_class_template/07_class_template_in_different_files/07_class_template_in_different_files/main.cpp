#include <iostream>
using namespace std;
//第一种解决方法：直接包含原文件
//#include "person.cpp"
//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp
#include "person.hpp"

void test01()
{
	Person<string, int> p("tom", 10);
	printPerson(p);
}

int main()
{
	test01();
	return 0;
}