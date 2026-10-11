#pragma once
#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}

	void showPerson()
	{
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
	}

	T1 name;
	T2 age;
};

template<class T1, class T2>
void printPerson(Person<T1,T2>& p)
{
	p.showPerson();
}