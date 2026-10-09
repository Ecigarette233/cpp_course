#include <iostream>
using namespace std;

// 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
// 规则排序从大到小，排序算法为选择排序
// 分别利用char数组和int数组进行测试

template <typename T>
void selectSort(T *arrayname, int length)
{
    for (int i = 0; i < length; i++)
    {
        // 假设数组最大值下标为i
        int MAX = i;

        // 找到最大值
        for (int j = i; j < length; j++)
        {
            if (arrayname[j] > arrayname[MAX])
            {
                MAX = j;
            }
        }

        // 交换两个元素
        if (MAX != i)
        {
            T temp = arrayname[i];
            arrayname[i] = arrayname[MAX];
            arrayname[MAX] = temp;
        }
    }
}

void test01()
{
    char arr1[] = "vjgshgsgacb";
    int length = sizeof(arr1) / sizeof(arr1[0]);

    selectSort(arr1, length);

    for (int i = 0; i < length; i++)
    {
        cout << arr1[i] << endl;
    }
}

void test02()
{
    int arr2[] = {5, 8, 10, 23, 77, 5, 1};
    int length = sizeof(arr2) / sizeof(arr2[0]);

    selectSort(arr2, length);

    for (int i = 0; i < length; i++)
    {
        cout << arr2[i] << endl;
    }
}

int main()
{
    test01();
    cout << "------------" << endl;
    test02();
    return 0;
}