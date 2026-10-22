#include "SpeechManager.h"
#include <iostream>
using namespace std;

int main()
{
	SpeechManager sm;

	int choice;

	while (1)
	{
		sm.showMenu();

		cout << "请输入功能:" << endl;
		if (!(cin >> choice))
		{
			if (cin.eof())
			{
				break;
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "请输入数字" << endl;
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice)
		{
		case 1://开始演讲比赛
			srand((unsigned int)time(NULL));
			sm.startSpeech();
			break;

		case 2://查看往届记录
			sm.showRecord();
			break;

		case 3://清空比赛记录
			sm.clearRecord();
			break;

		case 0://退出比赛系统
			sm.exitSystem();
			break;

		default:
			system("cls");
			break;
		}

	}
	

	system("pause");

	return 0;
}
