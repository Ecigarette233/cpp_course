#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <ctime>

// 公司今天招聘了10个员工(ABCDEFGHIJ)
// 10名员工进入公司之后，需要指派员工在那个部门工作
// 员工信息有:姓名工资组成;部门分为:策划、美术、研发
// 随机给10名员工分配部门和工资
// 通过multimap进行信息的插入key(部门编号)value(员工)
// 分部门显示员工信息

class Employee
{
public:
    Employee(string name,int dep,int salary)
    {
        this->m_name = name;
        this->m_dep = dep;
        this->m_salary = salary;
    }

    string m_name;
    int m_dep;
    int m_salary;

};

void createEmployee(vector<Employee>& v)
{
    string seedName = "ABCDEFGHIJ";
    srand(time(NULL));

    for(int i = 0;i<10;i++)
    {
        string name = "员工";
        name += seedName[i];

        //部门编号:1.策划 2.美术 3.研发
        int dep = rand()%3+1;

        int salary = rand()%3001 +3000;

        Employee employee(name,dep,salary);

        v.push_back(employee);
        
    }

    //遍历
    for(vector<Employee>::iterator it = v.begin();it!=v.end();it++)
    {
        cout<<"姓名为:"<<it->m_name<<" "
            <<"部门编号为:"<<it->m_dep<<" "
            <<"薪资为:"<<it->m_salary<<endl;
    }
}

void initMultiMap(vector<Employee>& v,multimap<int,Employee>& m) 
{
    for(int i = 0;i<10;i++)
    {
        m.insert(make_pair(v[i].m_dep,v[i]));
    }
}

void showEmployee(multimap<int,Employee>& m) 
{
    for(multimap<int,Employee>::iterator it = m.begin();it!=m.end();it++)
    {
       cout<<"员工所属部门:"<<it->first<<" "
           <<"员工姓名:"<<it->second.m_name<<" "
           <<"员工工资:"<<it->second.m_salary<<endl;
    }
}

int main()
{
    vector<Employee> v;

    createEmployee(v);

    multimap<int,Employee> m;

    initMultiMap(v,m);

    showEmployee(m);

    return 0;
}