#include "SpeechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
	initSpeech();

	createSpeaker();

	loadRecord();

	//测试代码
	
	/*
	
	for (map<int, Speaker>::iterator it = m_speaker.begin();it != m_speaker.end();it++)
	{
		cout << "选手编号:" << it->first << " ";
		cout << "选手姓名:" << it->second.m_name << " ";
		cout << "选手分数:" << it->second.m_score[0] << endl;
	}

	*/
}

//打印菜单
void SpeechManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "**********欢迎参加演讲比赛**********" << endl;
	cout << "**********1、开始演讲比赛***********" << endl;
	cout << "**********2、查看往届记录***********" << endl;
	cout << "**********3、清空比赛记录***********" << endl;
	cout << "**********0、退出比赛系统***********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

//初始化
void SpeechManager::initSpeech()
{
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_speaker.clear();

	m_index = 1;
}

//创建选手,存入对应容器中
void SpeechManager::createSpeaker()
{
	string seedName = "ABCDEFGHIJKL";

	for (int i = 0;i < 12;i++)
	{
		//初始化姓名
		string name = "选手";
		name += seedName[i];

		Speaker speaker;
		speaker.m_name = name;

		//初始化分数
		for (int j = 0;j < 2;j++)
		{
			speaker.m_score[j] = 0;
		}

		this->v1.push_back(10001+i);

		this->m_speaker.insert(make_pair(10001 + i, speaker));
	}
}

//开始比赛
void SpeechManager::startSpeech()
{
	this->initSpeech();
	this->createSpeaker();

	//第一轮比赛
	//1.抽签
	this->speakerDraw();

	//2.第一轮比赛流程
	this->startContest();

	//3.显示结果
	this->showScore();

	//第二轮比赛
    this->m_index++;
	//4.抽签
	this->speakerDraw();

	//5.第二轮比赛流程
	this->startContest();

	//6.显示最终结果
	this->showScore();

	//7.写入文件
	this->saveRecord();
}

//抽签
void SpeechManager::speakerDraw()
{
	mt19937 rng(random_device{}());

	if (m_index == 1)
	{
		shuffle(v1.begin(), v1.end(),rng);

		cout << "第" << m_index << "轮抽签后顺序如下:" << endl;
		for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
		{
			cout << *it << " ";
		}

	}
	else
	{
		shuffle(v2.begin(), v2.end(), rng);

		cout << "第" << m_index << "轮抽签后顺序如下:" << endl;
		for (vector<int>::iterator it = v2.begin();it != v2.end();it++)
		{
			cout << *it << " ";
		}
	}

	cout << endl;
	system("pause");
}

//进行比赛流程
void SpeechManager::startContest()
{
	//1.判断是第几轮,用对应轮数的选手容器
	//2.评委打分,去除最高分最低分取平均分,保存到容器中
	//3.创建小组容器,每6人按分数排名输出一次.随后清空容器,再按6人分数输出一次
	//4.保存每组前3名到第二轮的容器,进行下次比赛

	cout << "----------------------------第" << m_index << "轮比赛正式开始------------------------" << endl;

	//创建一个比赛容器,判断是第几轮,再把对应轮数容器赋值给比赛容器
	vector<int> src;

	if (m_index == 1)
	{
		src = v1;
	}
	else if(m_index == 2)
	{
		src = v2;
	}

	//小组容器计数器
	int num = 0;
	//创建小组容器(分数,编号)
	multimap<double,int,greater<double>> groupScore;

	//前三名晋级计数器
	int count = 0;

	//第n轮演讲比赛开始
	for (vector<int>::iterator it = src.begin();it != src.end();it++)
	{
		num++;

		deque<double> d_score;

		for (int i = 0;i < 10;i++)
		{
			double score = (rand() % 600 + 400) / (double)10.0;
			d_score.push_back(score);
		}

		sort(d_score.begin(), d_score.end(), greater<double>());

		d_score.pop_back();
		d_score.pop_front();

		//for (deque<double>::iterator it = d_score.begin();it != d_score.end();it++)
		//{
		//	cout << *it << " ";
		//}
		//cout << endl;

		double sum = accumulate(d_score.begin(), d_score.end(), 0.0);

		double avg = sum / (double)d_score.size();

		m_speaker[*it].m_score[m_index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));

		//1-6人或者7-12人已经得到平均分后,每6人输出打印一次,每遍历6人清空一次小组容器,清0小组计数器
		if (num % 6 == 0)
		{
			cout << "----------------------第" << num / 6 << "组比赛结果---------------------" << endl;

			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();it != groupScore.end();it++)
			{
				cout << "编号为" << it->second << "的选手平均分为" << it->first << endl;
			}

			//取出前三名,放到第二轮比赛的容器中
			for (multimap<double, int>::iterator it = groupScore.begin();it != groupScore.end() && count < 3;it++, count++)
			{
				if (m_index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vVictory.push_back(it->second);
				}
			}

			//遍历6人结束后清空容器
			cout << endl;
			groupScore.clear();
			count = 0;
		}
	}

	cout << "---------------------------------------------第" << m_index << "轮比赛结束---------------------------------------" << endl;
	system("pause");

	//for (map<int, Speaker>::iterator it = m_speaker.begin();it != m_speaker.end();it++)
	//{
	//	cout << "编号为" << it->first << "的选手的均分为:" << it->second.m_score[m_index - 1] << endl;
	//}
	
}

//显示晋级结果
void SpeechManager::showScore()
{
	//创建显示结果容器,判断比赛轮数,进行对应的赋值
	vector<int> vShow;

	if (m_index == 1)
	{
		vShow = v2;
	}
	else
	{
		vShow = vVictory;
	}

	cout << "----------------------------------------第" << m_index << "比赛晋级结果如下:----------------------------------" << endl;
	for (auto it = vShow.begin();it != vShow.end();it++)
	{
		cout << "编号为" << *it << "的选手" << "分数为" << this->m_speaker[*it].m_score[m_index-1] << endl;
	}

	system("pause");
	system("cls");
}

//保存记录
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	if (!ofs.is_open())
	{
		cout << "文件保存失败" << endl;
		return;
	}

	for (vector<int>::iterator it = vVictory.begin();it != vVictory.end();it++)
	{
		ofs << *it << "," << m_speaker[*it].m_score[1] << ",";
	}

	ofs << '\n';

	ofs.close();

	if (!ofs)
	{
		cout << "文件保存失败" << endl;
		return;
	}

	loadRecord();

	//cout << "保存成功" << endl;
	system("pause");
	system("cls");
}

//查看往届记录
void SpeechManager::loadRecord()
{
	//防止重新加载时保留旧数据
	m_record.clear();
	fileIsEmpty = true;

	ifstream ifs("speech.csv", ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->fileIsEmpty = 1;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;

	//读到的是空字符,说明文件被清空
	if (ifs.eof())
	{
		//文件是空的
		this->fileIsEmpty = 1;
		cout << "文件为空" << endl;
		ifs.close();

		return;
	}

	//只能是存在且有数据
	this->fileIsEmpty = false;
	//先把字符放回来
	ifs.putback(ch);

	string data;

	//存放比赛届数
	int index = 1;

	while (ifs >> data)
	{
		//存放冠军编号
		vector<string> v;

		//查到','位置的变量
		int pos = -1;
		//查找位置
		int start = 0;

		while (1)
		{
			//查找','位置,用pos接收
			pos = data.find(',', start);
			if (pos == string::npos)
			{
				if (start < data.size())
				{
					//失败也要保存最后一个数据
					v.push_back(data.substr(start));
					//cout << data.substr(start) << endl;
				}
				
				break;
			}

			//获取data的子串
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			start = pos + 1;

			v.push_back(temp);
		}

		m_record.insert(make_pair(index, v));

		index++;
		
	}

	ifs.close();

	//for (auto it = m_record.begin();it != m_record.end();it++)
	//{
	//	cout << "--------------------第" << it->first << "届比赛记录如下------------------" << endl;
	//	cout << "冠军编号:" << it->second[0] << " " << "分数:" << it->second[1] << endl;
	//}
}

//展示往届记录
void SpeechManager::showRecord()
{
	if (m_record.empty())
	{
		cout << "暂无比赛记录" << endl;
	}

	for (auto it = m_record.begin();it != m_record.end();it++)
	{
		vector<string>& v = it->second;

		if (v.size() != 6)
		{
			cout << "第" << it->first << "届比赛记录格式有误,已跳过" << endl;
			continue;
		}

		cout << "第" << it->first << "届比赛记录" << endl;
		cout << "冠军编号" << v[0] << " 分数:" << v[1] << endl;
		cout << "亚军编号" << v[2] << " 分数:" << v[3] << endl;
		cout << "季军编号" << v[4] << " 分数:" << v[5] << endl;

	}

	system("pause");
	system("cls");


}

//删除记录
void SpeechManager::clearRecord()
{
	int choice;
	cout << "确认清空?" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	
	if (!(cin >> choice))
	{
		if (!cin.eof())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "请输入数字" << endl;
		}
		return;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (choice == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);

		if (!ofs.is_open())
		{
			cout << "文件无法打开,清空失败" << endl;
			return;
		}

		ofs.close();

		if (!ofs)
		{
			cout << "文件操作失败" << endl;
			return;
		}

		initSpeech();

		createSpeaker();

		loadRecord();

		m_record.clear();     // 清空内存里的历史记录

		fileIsEmpty = true;   // 更新状态

		cout << "清空成功!" << endl;


	}
		
	system("pause");
	system("cls");


}

//退出系统
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用!" << endl;

	system("pause");

	exit(0);
}

//析构函数
SpeechManager::~SpeechManager()
{

}
