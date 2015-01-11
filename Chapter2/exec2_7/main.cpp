//生成一个[i,j]范围内的数列，其数字顺序随机排列
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../../mylib/myclock.h"
#include "../../mylib/tool.h"

using namespace std;

//算法1
void RandInt1(vector<int> & data, const int a, const int b)
{
    int N = data.size();
    int ran;
    srand(time(0));
    bool good;
    for (int i = 0; i < N; i++)
    {
        good = true;
        ran = rand() % (b-a+1)+a;
        for (int j = 0; j < i; j++)
        {
            if (ran == data[j])
            {
                good = false;
                break;
            }
        }
        if (good == true)
        {
            data[i] = ran;
        }
        else
        {
            i--;
        }
    }
}

//算法2
void RandInt2(vector<int> & data, const int a, const int b)
{
    int N = data.size();
    vector<int> used(N, 0);
    int ran;
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        do
        {
            ran = rand() % (b-a+1)+a;
        }while (used[ran-a] != 0);
        data[i] = ran;
        used[ran-a] = 1;
    }
}

//算法3
void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void RandInt3(vector<int> & data, const int a, const int b)
{
    int N = data.size();
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        data[i] = a+i;
    }
    for (int i = 1; i < N; i++)
    {
        int ran = rand()%i;
        swap(data[i], data[ran]);
    }
}

//按题目要求测试算法
void test(void)
{
    int n1[] = {250, 500, 1000, 2000};
    int n2[] = {2500, 5000, 10000, 20000, 40000, 80000};
    int n3[] = {10000, 20000, 40000, 80000, 160000, 320000, 640000};
    vector<int> N1(4), N2(6), N3(7);
    for (int i = 0; i < 4; i++)
    {
        N1[i] = n1[i];
    }
    for (int i = 0; i < 6; i++)
    {
        N2[i] = n2[i];
    }
    for (int i = 0; i < 7; i++)
    {
        N3[i] = n3[i];
    }
    MyClock mytim;
    double times;
    vector<int> data;
    //测试算法1
    for (int i = 0; i < 4; i++)
    {
        data.resize(N1[i]);
        mytim.begin();
        for (int j = 0; j < 10; j++)
        {
            RandInt1(data, 0, N1[i]);
        }
        mytim.end();
        times = mytim.GetHowLong()/10.0;
        cout<<endl<<"算法1"<<" N = "<<N1[i]<<" 平均用时:"<<times<<endl;
    }
    cout<<"-------------------";

    //测试算法2
    for (int i = 0; i < 4; i++)
    {
        data.resize(N2[i]);
        mytim.begin();
        for (int j = 0; j < 10; j++)
        {
            RandInt2(data, 0, N2[i]);
        }
        mytim.end();
        times = mytim.GetHowLong()/10.0;
        cout<<endl<<"算法2"<<" N = "<<N2[i]<<" 平均用时:"<<times<<endl;
    }
    cout<<"-------------------";

    //测试算法3
    for (int i = 0; i < 7; i++)
    {
        data.resize(N3[i]);
        mytim.begin();
        for (int j = 0; j < 10; j++)
        {
            RandInt3(data, 0, N3[i]);
        }
        mytim.end();
        times = mytim.GetHowLong()/10.0;
        cout<<endl<<"算法3"<<" N = "<<N3[i]<<" 平均用时:"<<times<<endl;
    }
    cout<<"测试结束"<<endl;
}

int main()
{
//    int i, j;
//    cout<<"输入模拟范围:";
//    cin>>i>>j;
//    vector<int> data(j-i+1);
//    RandInt1(data, i, j);
//    DisplayData(data);
//    data.clear();
//    data.resize(j-i+1);
//    RandInt2(data, i, j);
//    DisplayData(data);
//    data.clear();
//    data.resize(j-i+1);
//    RandInt3(data, i, j);
//    DisplayData(data);
    cout<<"正在测试"<<endl;
    test();
    return 0;
}
