#pragma once
#include <iostream>
using namespace std;
#include "speaker.h"
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <functional>
#include <numeric>
#include <ctime>
#include <random>
#include <fstream>
#include <limits>

class SpeechManager
{
public:

//------------------------------------------------------------成员函数-------------------------------------------------------------

	//构造函数
	SpeechManager();

	//初始化成员属性函数
	void initSpeech();

	//创建选手函数
	void createSpeaker();

	//显示菜单
	void showMenu();

	//开始比赛
	void startSpeech();

	//抽签
	void speakerDraw();

	//进行比赛流程
	void startContest();

	//显示晋级结果
	void showScore();

	//保存记录
	void saveRecord();

	//加载记录
	void loadRecord();

	//判断文件是否为空的变量
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>> m_record;

	//显示往届记录
	void showRecord();

	//清空记录
	void clearRecord();

	//退出系统
	void exitSystem();

	//析构函数
	~SpeechManager();

//------------------------------------------------------------成员属性-------------------------------------------------------------

	//第一轮选手编号容器
	vector<int> v1;

	//第二轮选手编号容器
	vector<int> v2;

	//记录胜利选手容器
	vector<int> vVictory;

	//存放编号和对应选手容器
	map<int, Speaker> m_speaker;

	//记录比赛轮数
	int m_index;
};
