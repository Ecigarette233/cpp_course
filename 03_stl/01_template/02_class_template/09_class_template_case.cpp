#include <iostream>
using namespace std;
#include <string>

// 实现一个通用的数组类，要求如下:
// 可以对内置数据类型以及自定义数据类型的数据进行存储
// 将数组中的数据存储到堆区
// 构造函数中可以传入数组的容量
// 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
// 提供尾插法和尾删法对数组中的数据进行增加和删除
// 可以通过下标的方式访问数组中的元素
// 可以获取数组中当前元素个数和数组的容量[

class Person
{
public:
    Person(){};
    Person(string name,int age)
    {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};

template <class T>
class MyArray
{
public:
    // 构造函数
    MyArray(int capacity)
    {
        // cout << "MyArray的有参构造" << endl;

        this->m_capacity = capacity;

        this->m_size = 0;

        this->pAddress = new T[this->m_capacity];
    }

    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        // cout << "MyArray的拷贝构造" << endl;

        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // this->pAddress = arr.pAddress;//错误
        // 这里是将同一地址传给两个指针，一个指针释放，另一个不能再释放。也就是浅拷贝问题

        this->pAddress = new T[arr.m_capacity];

        // 将数据拷贝过来
        for (int i = 0; i < this->m_size; i++)
        {
            pAddress[i] = arr.pAddress[i];
        }
    }

    // operator防止浅拷贝问题
    MyArray &operator=(const MyArray &arr)
    {
        // cout << "MyArray的operator=调用" << endl;

        // 原来如果有数据，就先释放
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // 深拷贝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[arr.m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    void Push(const T &val)
    {
        if (this->m_capacity == this->m_size)
        {
            return;
        }
        this->pAddress[m_size] = val;
        this->m_size++;
    }

    void Pop()
    {
        if (m_size == 0)
        {
            return;
        }
        this->m_size--;
    }

    // 通过下标方式访问元素
    T &operator[](int index)
    {
        return this->pAddress[index];
    }

    // 返回数组容量
    int getCapacity()
    {
        return this->m_capacity;
    }

    // 返回数组大小
    int getSize()
    {
        return this->m_size;
    }

    // 析构函数
    ~MyArray()
    {
        // cout << "MyArray的析构构造" << endl;

        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    // 属性：1.维护数组的指针2.数组容量3.数组大小
    T *pAddress;
    int m_capacity;
    int m_size;
};

template<class T>
void printArr(MyArray<T>& arr)
{
    for(int i = 0;i<arr.getSize();i++)
    {
        cout<<"name = "<<arr[i].name<<endl;
        cout<<"age  " <<arr[i].age<<endl;
    }
}


void test01()
{
    MyArray<int> arr1(5);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(100);
    arr3 = arr1;

    cout << "---------------" << endl;

    for (int i = 0; i < arr1.getCapacity(); i++)
    {
        arr1.Push(i);
    }

    for (int i = 0; i < arr1.getSize(); i++)
    {
        cout << arr1[i] << endl;
    }

}

void test02()
{
    MyArray<Person>arr(10);
    Person p1("张三",19);
    Person p2("李四",29);
    Person p3("王五",25);

    arr.Push(p1);
    arr.Push(p2);
    arr.Push(p3);

    printArr(arr);
}

int main()
{
    test01();
    test02();
    return 0;
}