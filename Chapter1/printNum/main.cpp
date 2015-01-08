#include <iostream>
#include <cmath>

using namespace std;

int times = 0;
int digits = 0; //�������λ����

void printDigit(unsigned int N, const int t)
{
    cout<<N;
    times++;
    //���С����
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

//ϰ��1.3
//������������Ҫ��������֣���С��������ת��Ϊ��������
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
    cout<<"��������:";
    double N;
    cin>>N;
    cout<<"���Ϊ:";
    //printNum(N);
    int sig = 0;
    if (N < 0)
    {
        sig = 1; //����Ϊ����
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
