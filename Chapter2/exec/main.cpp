#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include "../../mylib/tool.h"

using namespace std;

//��ϰ3-2:������������L,P����P��Ԫ�ص�ֵ��˳�������L�����ݡ�
void PrintLots(vector<int> L, vector<int> P)
{
    int N = L.size();
    for (int i = 0; i < N; i++)
    {
        cout<<L.at(P[i])<<" ";
    }
    cout<<endl;
}

void exec3_2(const int N)
{
    vector<int> L(N, 0), P(N, 0);
    GenerateData(L, N, 1, N);
    GenerateData(P, N, 1, N);
    cout<<"L:";
    DisplayData(L);
    cout<<endl<<"P:";
    DisplayData(P);
    cout<<endl;
    PrintLots(L, P);
}

//��ϰ3-9����2^4000�ڵ�0-9�����ֲַ���Ҫ�ô����˷��ˡ�
//����a^n
vector<int> Multi(const int a, const int n)
{
    vector<int> result(1, 1);
    for (int i = 0; i < n; i++)
    {
        //��a��ÿһλ��
        for (unsigned int j = 0; j < result.size(); j++)
        {
            int temp = a*result[j];
            result[j] = temp;
        }
        //������
        for (unsigned int j = 0; j < result.size()-1; j++)
        {
            if (result[j] >= 10)
            {
                result[j+1] += result[j]/10;
                result[j] = result[j] % 10;
            }
        }
        //�������һλ�Ľ�λ��
        int k = result.size();
        if (result[k-1] >= 10)
        {
            result.push_back(result[k-1]/10);
            result[k-1] = result[k-1] % 10;
        }
    }
    return result;
}

void exec3_9(const int a, const int n)
{
    vector<int> result = Multi(a, n);
    //���ݴ���
    int N = result.size();
    map<int, int> statics; //����ͳ�ơ�
    //��ʼ��
    for (int i = 0; i < 10; i++)
    {
        statics[i] = 0;
    }
    //�ۼ�
    for (int i = 0; i < N; i++)
    {
        statics[result[i]]++;
    }
    //�����������
    cout<<a<<"^"<<n<<"�Ľ������"<<N<<"λ"<<endl;
    cout<<"��������0-9�������ֵķֲ�Ƶ��Ϊ��"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<i<<":"<<double(statics[i])/double(N)<<endl;
    }
}

int main()
{
    cout<<"��ϰ3_2:"<<endl;
    cout<<"�������ݹ�ģ :";
    int N;
    cin>>N;
    exec3_2(N);
    cout<<"��ϰ3_9:"<<endl;
    int a, n;
    cout<<"���������ָ��:";
    cin>>a>>n;
    exec3_9(a, n);
    /*
    vector<int> result = Multi(2, 100);
    for (vector<int>::reverse_iterator i = result.rbegin(); i != result.rend(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    */
    return 0;
}
