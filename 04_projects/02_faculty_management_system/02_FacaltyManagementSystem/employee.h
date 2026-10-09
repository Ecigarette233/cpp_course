#pragma once
#include "worker.h"

#include <iostream>
#include <string>



class Employee :public Worker
{
public:
	//构造函数
	Employee(int ID,string Name,int departmentID);

	//展示成员信息
	void showInformation();

	//获取岗位名称
	string getDepartment();

};
