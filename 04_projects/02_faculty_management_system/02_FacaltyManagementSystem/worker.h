#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker
{
public:

	//展示成员信息
	virtual void showInformation() = 0;

	//获取岗位名称
	virtual string getDepartment() = 0;

	//成员属性

	int ID;				//员工编号
	string Name;		//员工姓名
	int departmentID;	//员工所在部门编号

};
