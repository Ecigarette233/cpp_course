//函数的具体实现
#include "WorkerManager.h"

#include <iostream>
using namespace std;

#include <fstream>

//构造函数
WorkerManager::WorkerManager()
{
	//初始化成员属性

	ifstream ifs;
	ifs.open("empfile.txt", ios::in);

	//1.文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//职工数量为0
		this->num = 0;

		//职工数组为NULL
		this->empArray = NULL;

		//文件状态改为空
		this->fileIsExist = false;

		ifs.close();
		return;
	}

	//2.文件为空
	//读取一个字符，如果读取到的字符为文件尾字符，则文件为空
	char ch;
	ifs >> ch;

	//如果读到的是文件尾字符
	if (ifs.eof())
	{
		cout << "文件为空" << endl;

		//职工数量为0
		this->num = 0;

		//职工数组为NULL
		this->empArray = NULL;

		//文件状态改为存在
		this->fileIsExist = true;

		ifs.close();
		return;
	}

	//3.文件存在，且不为空，需要记录数据
	int empNum = this->getEmpNum();
	cout << "职工人数为：" << empNum << endl;

	this->num = empNum;

	this->empArray = new Worker * [this->num];
	this->initEmp();
	
	//测试代码
	for (int i = 0;i < this->num;i++)
	{
		cout << "员工编号为:" << this->empArray[i]->ID << "  "
			<< "员工姓名为:" << this->empArray[i]->Name << "  "
			<< "员工部门编号为:" << this->empArray[i]->departmentID << endl;
	}
	this->fileIsExist = true;

}

//展示菜单
void WorkerManager::showMenu()
{
	cout << " *************************** " << endl;
	cout << " *****  职工管理系统   ***** " << endl;
	cout << " ***** 0.退出管理程序  ***** " << endl;
	cout << " ***** 1.增加职工信息  ***** " << endl;
	cout << " ***** 2.显示职工信息  ***** " << endl;
	cout << " ***** 3.删除离职职工  ***** " << endl;
	cout << " ***** 4.修改职工信息  ***** " << endl;
	cout << " ***** 5.查找职工信息  ***** " << endl;
	cout << " ***** 6.按照编号排序  ***** " << endl;
	cout << " ***** 7.清空所有文档  ***** " << endl;
	cout << " *************************** " << endl;
}

//退出系统
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::addEmp()
{
	cout << "请输入要添加的人数" << endl;

	int addnum;
	cin >> addnum;

	if (addnum > 0)
	{
		//添加职工

		//记录职工总人数
		int newSize = this->num + addnum;

		//开辟新空间
		Worker** newSpace = new Worker*[newSize];

		//将原职工复制到新职工数组里
		if (this->empArray != NULL)
		{
			for (int i = 0;i < this->num;i++)
			{
				newSpace[i] = this->empArray[i];
			}
		}
		
		for (int i = 0;i < addnum;i++)
		{
			int ID;
			string Name;
			int DepartmentID;

			cout << "请输入第" << i + 1 << "位新职工" << endl;

			cout << "员工编号为：" << endl;
			cin >> ID;

			cout << "姓名为：" << endl;
			cin >> Name;

			cout << "部门编号为：" << endl;
			cout << "总裁：1" << endl;
			cout << "经理：2" << endl;
			cout << "普通职员：3" << endl;
			cin >> DepartmentID;

			Worker* worker = NULL;

			switch (DepartmentID)
			{
			case 1:	
				worker = new Boss(ID, Name, 1);
				break;
			case 2:
				worker = new Manager(ID, Name, 2);
				break;
			case 3:
				worker = new Employee(ID, Name, 3);
				break;
			default:
				break;
			}
			
			newSpace[this->num + i] = worker;
		}

		this->num = newSize;
		delete[] this->empArray;
		this->empArray = newSpace;

		this->fileIsExist = true;

		cout << "添加成功" << endl;
		this->save();
	}
	else
	{
		//输入了错误数据
		cout << "输入数据有误，请重试" << endl;
		return;
	}

	system("pause");
	system("cls");

}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open("empfile.txt", ios::out);

	for (int i = 0;i < this->num;i++)
	{
		ofs << this->empArray[i]->ID << " "
			<< this->empArray[i]->Name << " "
			<< this->empArray[i]->departmentID << endl;
	}

	ofs.close();
}

//文件再次打开时获取人数
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string Name;
	int DepartmentID;

	int num = 0;
	while (ifs >> ID && ifs >> Name && ifs >> DepartmentID)
	{
		num++;
	}
	ifs.close();
	return num;
}

//文件再次打开时重新初始化数组
void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string Name;
	int DepartmentID;

	int index = 0;
	while (ifs >> ID >> Name >> DepartmentID)
	{
		Worker* worker = NULL;
		if (DepartmentID == 1)
		{
			worker = new Boss(ID, Name, DepartmentID);
		}
		else if(DepartmentID ==2)
		{
			worker = new Manager(ID, Name, DepartmentID);
		}
		else
		{
			worker = new Employee(ID, Name, DepartmentID);
		}

		this->empArray[index] = worker;
		index++;
	}

	ifs.close();
}

//展示所有职工
void WorkerManager::showEmp()
{
	if (!this->fileIsExist)
	{
		cout << "文件不存在或为空！" << endl;
		return;
	}
	else
	{
		for (int i = 0;i < this->num;i++) 
		{
			this->empArray[i]->showInformation();
		}
	}

	system("pause");
	system("cls");

}

//判断职工是否存在 并返回职工在数组的位置
int WorkerManager::isExist(int id)
{
	if (fileIsExist == 0)
	{
		cout << "文件不存在！" << endl;
		return -1;
	}
	else
	{
		int index = -1;
		for (int i = 0;i < this->num;i++)
		{
			if (this->empArray[i]->ID == id)
			{
				return i;
			}
		}
		return -1;
	}
}

//删除职工
void  WorkerManager::deleteEmp()
{
	
	if (fileIsExist == 0)
	{
		cout << "文件不存在！" << endl;
	}
	else
	{
		cout << "请输入员工编号" << endl;
		int id;
		cin >> id;

		int ret = isExist(id);

		if (ret!=-1)
		{
			for (int i = ret;i < this->num - 1;i++)
			{
				//移动指针
				this->empArray[i] = this->empArray[i + 1];
			}
			this->num--;
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败！" << endl;
		}

		
	}

	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::modifyEmp()
{
	if (fileIsExist == 0)
	{
		cout << "文件不存在" << endl;
		return;
	}

	cout << "请输入要修改的职工编号" << endl;
	int selectID;
	cin >> selectID;

	int ret = isExist(selectID);
	if (ret != -1)
	{
		cout << "已找到编号为" << selectID << "的职工" << endl;

		delete this->empArray[ret];

		int ID = 0;
		string Name ;
		int departmentID = 0;

		cout << "请输入员工编号：" << endl;
		cin >> ID;

		cout << "请输入员工姓名：" << endl;
		cin >> Name;

		cout << "请输入员工部门编号：" << endl;
		cin >> departmentID;

		Worker* worker = NULL;

		switch (departmentID)
		{
		case 1:
			worker = new Boss(ID, Name, departmentID);
			break;
		case 2:
			worker = new Manager(ID, Name, departmentID);
			break;
		case 3:
			worker = new Employee(ID, Name, departmentID);
			break;
		}

		this->empArray[ret] = worker;

		this->save();

		cout << "添加成功！" << endl;
	}
	else
	{
		cout << "未找到该员工信息" << endl;
		return;
	}

	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::findEmp()
{
	if (fileIsExist == 0)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1、按照姓名查找" << endl;
		cout << "2、按照编号查找" << endl;

		int select = 0;
		cin >> select;
		
		if (select == 1)
		{
			cout << "请输入姓名" << endl;
			string name;
			cin >> name;

			//标记是否找到
			bool flag = 0;

			for (int i = 0;i < this->num;i++)
			{
				if (this->empArray[i]->Name == name)
				{
					cout << "查找成功！" << endl;
					this->empArray[i]->showInformation();
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << "查找失败" << endl;
			}
			
		}
		else if (select == 2)
		{
			cout << "请输入员工编号" << endl;
			int id;
			cin >> id;

			bool flag = 0;

			for (int i = 0;i < this->num;i++)
			{
				if (this->empArray[i]->ID == id)
				{
					cout << "查找成功！" << endl;
					this->empArray[i]->showInformation();
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << "查找失败，根本没有这种员工" << endl;
			}
		}
	
	}

	system("pause");
	system("cls");
}

//排序
void WorkerManager::sortEmp()
{
	if (fileIsExist == 0)
	{
		cout << "文件不存在！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		//排序算法
		cout << "请输入排序方式：" << endl;
		cout << "1.升序排列" << endl;
		cout << "2.降序排列" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0;i < this->num;i++)
		{
			int MaxorMin = i;
			if (select == 1)
			{
				//每轮确定一个最小值
				for (int j = i;j < this->num;j++)
				{
					if (this->empArray[MaxorMin]->ID > this->empArray[j]->ID)
					{
						MaxorMin = j;
					}
				}
			}
			else
			{
				//每轮确定一个最大值
				for (int j = i;j < this->num ;j++)
				{
					if (this->empArray[MaxorMin]->ID < this->empArray[j]->ID)
					{
						MaxorMin = j;
					}
				}
			}

			if (MaxorMin != i)
			{
				Worker* worker = this->empArray[MaxorMin];
				this->empArray[MaxorMin] = this->empArray[i];
				this->empArray[i] = worker;
			}
		}

		cout << "排序成功！" << endl;
		this->save();
		this->showEmp();
	}
}

//清空文件
void WorkerManager::cleanEmp()
{
	if (fileIsExist == 0)
	{
		cout << "文件已经清空" << endl;
	}
	else
	{
		cout << "是否要清空文件？" << endl;
		cout << "1.确定" << endl;
		cout << "2.取消" << endl;

		int select;
		cin >> select;

		if (select == 1)
		{
			//将内容释放
			for (int i = 0;i < this->num;i++)
			{
				if (this->empArray[i] != NULL)
				{
					delete this->empArray[i];
					this->empArray[i] = NULL;
				}
			}

			delete[] this->empArray;
			this->empArray = NULL;
			this->num = 0;
			this->fileIsExist = 0;

			this->save();
			cout << "清空成功！" << endl;
		}
		else
		{
			return;
		}
	}
	system("pause");
	system("cls");
	
}

//析构函数
WorkerManager::~WorkerManager()
{

}


