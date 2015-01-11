#include <iostream>

using namespace std;

bool IsEven(unsigned int N)
{
    if (N % 2 == 0)
    {
        return true;
    }
    return false;
}

long int Pow(long int X, unsigned int N)
{
    if (N == 0)
    {
        return 1;
    }
    if (N == 1)
    {
        return X;
    }
    if (IsEven(N))
    {
        return Pow(X*X, N/2);
    }
    else
    {
        return Pow(X*X, N/2)*X;
    }
}

int main()
{
    cout << "���������ָ����";
    long int X;
    int N;
    cin>>X>>N;
    cout<<"������Ϊ:"<<Pow(X, N)<<endl;
    return 0;
}
