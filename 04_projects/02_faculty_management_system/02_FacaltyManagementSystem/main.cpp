#include <iostream>
using namespace std;

#include "WorkerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
	WorkerManager wm;

	while (1)
	{
		wm.showMenu();

		int select;
		cout << "请输入需调用的功能：";
		cin >> select;

		switch (select)
		{
		case 0:		//退出系统
			wm.exitSystem();
		case 1:		//添加职工
			wm.addEmp();
			break;
		case 2:		//显示职工
			wm.showEmp();
			break;
		case 3:		//删除职工
			wm.deleteEmp();
			break;
		case 4:		//修改职工
			wm.modifyEmp();
			break;
		case 5:		//查询职工
			wm.findEmp();
			break;
		case 6:		//排序
			wm.sortEmp();
			break;
		case 7:		//清空文档
			wm.cleanEmp();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}