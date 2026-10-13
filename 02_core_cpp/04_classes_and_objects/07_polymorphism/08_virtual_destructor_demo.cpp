#include <iostream>
using namespace std;

// 虚析构用法演示：为什么父类指针 delete 子类对象必须用虚析构
// 先用 C++17 的 if constexpr 编译期开关，方便对比两种写法

// ============ 反例：析构函数不是虚函数 ============
class BaseNoVirtual
{
public:
    BaseNoVirtual()
    {
        cout << "  [BaseNoVirtual] 构造" << endl;
    }
    // 析构函数没有 virtual —— 静态绑定，只调用本类析构
    ~BaseNoVirtual()
    {
        cout << "  [BaseNoVirtual] 析构" << endl;
    }
};

class DerivedNoVirtual : public BaseNoVirtual
{
public:
    DerivedNoVirtual()
    {
        cout << "  [DerivedNoVirtual] 构造" << endl;
        m_data = new int[100];
    }
    ~DerivedNoVirtual()
    {
        cout << "  [DerivedNoVirtual] 析构 -> delete[] m_data" << endl;
        delete[] m_data; // 堆区资源释放
    }

private:
    int *m_data;
};

// ============ 正例：析构函数是虚函数 ============
class BaseVirtual
{
public:
    BaseVirtual()
    {
        cout << "  [BaseVirtual] 构造" << endl;
    }
    // 只要类可能被继承且用父类指针 delete，就给它加 virtual
    virtual ~BaseVirtual()
    {
        cout << "  [BaseVirtual] 析构" << endl;
    }
};

class DerivedVirtual : public BaseVirtual
{
public:
    DerivedVirtual()
    {
        cout << "  [DerivedVirtual] 构造" << endl;
        m_data = new int[100];
    }
    ~DerivedVirtual()
    {
        cout << "  [DerivedVirtual] 析构 -> delete[] m_data" << endl;
        delete[] m_data; // 被正确调用，没有泄漏
    }

private:
    int *m_data;
};

// ============ 纯虚析构：既保证虚析构，又强制子类实现 ============
class AbstractBase
{
public:
    virtual void speak() = 0;
    // 纯虚析构必须"声明 + 定义"，因为子类析构结束时一定会调用它
    virtual ~AbstractBase() = 0;
};

AbstractBase::~AbstractBase() // 纯虚函数也可以有函数体
{
    cout << "  [AbstractBase] 纯虚析构实现" << endl;
}

class Dog : public AbstractBase
{
public:
    Dog()
    {
        cout << "  [Dog] 构造" << endl;
    }
    void speak() override
    {
        cout << "  汪汪" << endl;
    }
    ~Dog() override
    {
        cout << "  [Dog] 析构" << endl;
    }
};

int main()
{
    cout << "1) 析构不是 virtual：只析构了父类，子类资源泄漏" << endl;
    {
        BaseNoVirtual *p = new DerivedNoVirtual;
        delete p; // 未定义行为（实际只调用 ~BaseNoVirtual）
    }

    cout << "\n2) 析构是 virtual：子类析构 + 父类析构依次调用" << endl;
    {
        BaseVirtual *p = new DerivedVirtual;
        delete p; // 先 ~DerivedVirtual，再 ~BaseVirtual
    }

    cout << "\n3) 纯虚析构：抽象类 + 正确的多态析构" << endl;
    {
        AbstractBase *p = new Dog;
        p->speak();
        delete p; // ~Dog -> ~AbstractBase
    }

    cout << "\n4) 栈对象不受影响：本来就知道真实类型，virtual 与否都全析构" << endl;
    {
        DerivedVirtual d;
    }

    return 0;
}
