//ŷ������㷨�����Լ��
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

//���������������ʵĸ���
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
    cout<<"�����������ʵĸ���Ϊ:"<<(double)Rel/Tot<<endl;
}

int main()
{
    cout << "��������������:";
    int M, N;
    cin>>M>>N;
    if (M <= 0 || N <= 0)
    {
        cout<<"�������!"<<endl;
        return -1;
    }
    cout<<M<<"��"<<N<<"�����Լ��Ϊ:"<<Gcd(M, N)<<endl;
    cout<<"������Է�Χ���ֵ:";
    cin>>N;
    Prime(N);
    return 0;
}
