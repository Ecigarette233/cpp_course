#include "employee.h"

#include <iostream>
using namespace std;

#include <string>

//构造函数
Employee::Employee(int ID, string Name, int departmentID)
{
	this->ID = ID;
	this->Name = Name;
	this->departmentID = departmentID;
}

//展示成员信息
void Employee::showInformation()
{
	cout << "员工编号：" << this->ID << "\t";
	cout << "员工姓名：" << this->Name << "\t";
	cout << "员工所属部门：" << this->getDepartment() << "\t";
	cout << "员工指责：" << "完成经理派发的工作" << endl;

}

//获取岗位名称
string Employee::getDepartment()
{
	return string("普通职员");
}