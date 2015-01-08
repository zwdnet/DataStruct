#include <iostream>
#include <cmath>

using namespace std;

int times = 0;
int digits = 0; //输入的总位数。

void printDigit(unsigned int N, const int t)
{
    cout<<N;
    times++;
    //输出小数点
    if (digits - times == t)
    {
        cout<<".";
    }
}

void printNum(unsigned int N)
{
    if (N >= 10)
    {
        printNum(N / 10);
    }
    printDigit(N % 10, 0);
}

//习题1.3
//处理函数，处理要输出的数字，把小数、负数转换为正整数。
int dealNum(double & N)
{
    int t = 0;
    while (N != floor(N))
    {
        N = N*10.0;
        t++;
    }
    int temp = N;
    while (temp != 0)
    {
        temp = temp / 10;
        digits++;
    }
    return t;
}

void printReal(unsigned int N, const int t)
{
    if (N >= 10)
    {
        printReal(N / 10, t);
    }
    printDigit(N % 10, t);
}

int main()
{
    cout<<"输入数字:";
    double N;
    cin>>N;
    cout<<"输出为:";
    //printNum(N);
    int sig = 0;
    if (N < 0)
    {
        sig = 1; //输入为负数
        N = N*(-1.0);
    }
    if (sig == 1)
    {
        cout<<"-";
    }
    int t = dealNum(N);
    printReal(N, t);
    return 0;
}
