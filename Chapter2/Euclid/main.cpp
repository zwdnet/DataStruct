//欧几里得算法求最大公约数
#include <iostream>

using namespace std;

unsigned int Gcd(unsigned int M, unsigned int N)
{
    unsigned int Rem;

    while (N > 0)
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}

//计算两个整数互质的概率
void Prime(const int N)
{
    int Rel = 0, Tot = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            Tot++;
            if (Gcd(i, j) == 1)
            {
                Rel++;
            }
        }
    }
    cout<<"两个整数互质的概率为:"<<(double)Rel/Tot<<endl;
}

int main()
{
    cout << "输入两个正整数:";
    int M, N;
    cin>>M>>N;
    if (M <= 0 || N <= 0)
    {
        cout<<"输入错误!"<<endl;
        return -1;
    }
    cout<<M<<"和"<<N<<"的最大公约数为:"<<Gcd(M, N)<<endl;
    cout<<"输入测试范围最大值:";
    cin>>N;
    Prime(N);
    return 0;
}
