//最大子序列和问题:给定一个数组（可能有负值），找出其中
//最大的子序列之和。
#include <iostream>
#include <vector>
#include "../../mylib/tool.h"
#include "../../mylib/Myclock.h"

using namespace std;

//算法1，蛮力法
//算法复杂度：O(N^3)
template <typename T>
T MaxSubsequenceSum1(const vector<T> & A)
{
    T ThisSum, MaxSum;
    int i, j, k;
    MaxSum = 0;
    int N = A.size();
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            ThisSum = 0;
            for (k = i; k <= j; k++)
            {
                ThisSum += A[k];
            }
            if (ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

//算法2：算法一的改进。
//复杂度:O(N^2)
template <typename T>
T MaxSubsequenceSum2(const vector<T> & A)
{
    T ThisSum, MaxSum;
    int i, j, N;
    N = A.size();

    MaxSum = 0;
    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
        for (j = i; j < N; j++)
        {
            ThisSum += A[j];

            if (ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

//算法3：分治法
//复杂度：O(NlogN)
//划分函数
template <typename T>
static T MaxSubSum(const vector<T> & A, const int Left, const int Right)
{
    T MaxLeftSum, MaxRightSum;
    T MaxLeftBorderSum, MaxRightBorderSum;
    T LeftBorderSum, RightBorderSum;
    int Center, i;

    if (Left == Right)  //基准情况
    {
        if (A[Left] > 0)
        {
            return A[Left];
        }
        else
        {
            return 0;
        }
    }

    Center = (Left + Right)/2;
    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center+1, Right);

    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = Center; i >= Left; i--)
    {
        LeftBorderSum += A[i];
        if (LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = Center +1; i <= Right; i++)
    {
        RightBorderSum += A[i];
        if (RightBorderSum > MaxRightBorderSum)
        {
            MaxRightBorderSum = RightBorderSum;
        }
    }

    T MaxBoth = MaxLeftBorderSum + MaxRightBorderSum;
    if (MaxLeftSum > MaxRightSum)
    {
        if (MaxLeftSum > MaxBoth)
        {
            return MaxLeftSum;
        }
        else
        {
            return MaxBoth;
        }
    }
    else
    {
        if (MaxRightSum > MaxBoth)
        {
            return MaxRightSum;
        }
        else
        {
            return MaxBoth;
        }
    }
}

//算法3实现
template <typename T>
T MaxSubsequenceSum3(const vector<T> & A)
{
    return MaxSubSum(A, 0, A.size()-1);
}

//算法4，复杂度O(N)
template <typename T>
T MaxSubsequenceSum4(const vector<T> A)
{
    T ThisSum, MaxSum;
    int j;
    int N = A.size();

    ThisSum = MaxSum = 0;
    for (j = 0; j < N; j++)
    {
        ThisSum += A[j];

        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
        }
        else if (ThisSum < 0)
        {
            ThisSum = 0;
        }
    }

    return MaxSum;
}

int main()
{
    cout << "输入数据规模：" << endl;
    int N;
    cin>>N;
    vector<int> data;
    GenerateData(data, N, -10, 10);
    //cout<<"原始数据为:";
    //DisplayData(data);

    MyClock mytim;
    if (N <= 3000)
    {
        mytim.begin();
        cout<<"算法1结果:"<<MaxSubsequenceSum1(data);
        mytim.end();
        cout<<"，耗时:"<<mytim.GetHowLong()<<"秒"<<endl;
    }

    mytim.begin();
    cout<<"算法2结果:"<<MaxSubsequenceSum2(data);
    mytim.end();
    cout<<"，耗时:"<<mytim.GetHowLong()<<"秒"<<endl;

    mytim.begin();
    cout<<"算法3结果:"<<MaxSubsequenceSum3(data);
    mytim.end();
    cout<<"，耗时:"<<mytim.GetHowLong()<<"秒"<<endl;

    mytim.begin();
    cout<<"算法4结果:"<<MaxSubsequenceSum4(data);
    mytim.end();
    cout<<"，耗时:"<<mytim.GetHowLong()<<"秒"<<endl;
    return 0;
}
