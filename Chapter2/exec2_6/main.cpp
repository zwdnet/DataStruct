//��ϰ2-6
#include <iostream>
#include "../../mylib/myclock.h"

using namespace std;

void No1(const int & N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum++;
    }
}

void No2(const int & N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum++;
        }
    }
}

void No3(const int & N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N*N; j++)
        {
            sum++;
        }
    }
}

void No4(const int & N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum++;
        }
    }
}

void No5(const int & N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i*i; j++)
        {
            for (int k = 0; k < j; k++)
            {
                sum++;
            }
        }
    }
}

void No6(const int & N)
{
    int sum = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < i*i; j++)
        {
            if (j % i == 0)
            {
                for (int k = 0; k < j; k++)
                {
                    sum++;
                }
            }
        }
    }
}
int main()
{
    MyClock mytim;
    for (int i = 10; i < 2000; i = i*2)
    {
        cout<<"N = "<<i<<endl;
        mytim.begin();
        No1(i);
        mytim.end();
        cout<<"�㷨1ʱ��:"<<mytim.GetHowLong()<<endl;
        mytim.begin();
        No2(i);
        mytim.end();
        cout<<"�㷨2ʱ��:"<<mytim.GetHowLong()<<endl;
        mytim.begin();
        No3(i);
        mytim.end();
        cout<<"�㷨3ʱ��:"<<mytim.GetHowLong()<<endl;
        mytim.begin();
        No4(i);
        mytim.end();
        cout<<"�㷨4ʱ��:"<<mytim.GetHowLong()<<endl;

        if (i < 200)
        {
            mytim.begin();
            No5(i);
            mytim.end();
            cout<<"�㷨5ʱ��:"<<mytim.GetHowLong()<<endl;
        }
        mytim.begin();
        No6(i);
        mytim.end();
        cout<<"�㷨6ʱ��:"<<mytim.GetHowLong()<<endl;
        cout<<"-----------------------"<<endl;
    }
    return 0;
}
