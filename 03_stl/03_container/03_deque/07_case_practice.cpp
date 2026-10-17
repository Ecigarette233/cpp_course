#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>

// 有5个选手,ABCDE,10位评委分别对每一名选手打分,去掉最高分,去掉最低分,取平均分

// 选手类
class Player
{
public:
    Player(string name, int score)
    {
        this->name = name;
        this->score = score;
    }

    string name;
    int score;
};

// 创建选手
void createPlayer(vector<Player> &p)
{
    string seedName = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += seedName[i];

        int score = 0;

        Player player(name, score);

        p.push_back(player);
    }
}

// 测试:输出打印选手
void printPlayer(vector<Player> &p)
{
    for (vector<Player>::iterator it = p.begin(); it != p.end(); it++)
    {
        cout << (*it).name << " " << (*it).score << endl;
    }
}

// 评委打分
void setScore(vector<Player> &p)
{
    srand((unsigned int)time(NULL));
    // 每个选手随机出10个分数
    for (vector<Player>::iterator it = p.begin(); it != p.end(); it++)
    {
        deque<int> s;
        for (int j = 0; j < 10; j++)
        {
            // 分数在60~100
            int score = rand() % 41 + 60;
            s.push_back(score);
        }

        // 排序
        sort(s.begin(), s.end());

        // for (int k = 0; k < 10; k++)
        // {
        //     cout << s[k] << " ";
        // }
        // cout << endl;

        // 去掉最高分和最低分
        s.pop_front();
        s.pop_back();

        // 获取平均值
        int sum = 0;
        for (deque<int>::iterator it = s.begin(); it != s.end(); it++)
        {
            sum += (*it);
        }

        int avg = sum / s.size();

        it->score = avg;
    }
}

int main()
{
    vector<Player> p;
    createPlayer(p);
    // printPlayer(p);
    setScore(p);

    printPlayer(p);

    return 0;
}