//���ݽṹ���㷨����C�����������ʵ��
//ѡ������:��N�������ҳ���k���
#include <iostream>
#include "../../mylib/myclock.h"
#include "../../mylib/tool.h"
#include <vector>
#include <algorithm>

using namespace std;

//�㷨1���ȶ������������ҳ���k�����ݡ�
template <typename T>
T Algorithm1(const vector<T> & data, const unsigned int k)
{
    if (k < 0 || k >= data.size())
    {
        return -1;
    }
    vector<T> tempData(data.size());
    tempData = data;
    sort(tempData.begin(), tempData.end());
    return tempData[k-1];
}

//�㷨2���ȶ�ͷk��������Ȼ�����ζ���ʣ�µ�������������������
template <typename T>
T Algorithm2(const vector<T> & data, const unsigned int k)
{
    unsigned int N = data.size();
    if (k < 0 || k >= N)
    {
        return -1;
    }
    vector<T> tempData(k);
    for (unsigned int i = 0; i < k; i++)
    {
        tempData[i] = data[i];
    }
    sort(tempData.begin(), tempData.end());
    for (unsigned int j = k; j < N; j++)
    {
        //����¶�������ݴ��ڵ�k�����ݣ��Ͳ����ٽ��д˴�ѭ���ˡ�
        if (data[j] >= tempData[k-1])
        {
            continue;
        }
        for (unsigned int m = 0; m < k; m++)
        {
            //�����������С����ʱ�������ĳ��ֵ������ʱ�����д�ֵ�Ժ��ÿ��ֵ��ǰһֵ������ٲ����ֵ��
            if (data[j] < tempData[m])
            {
                for (unsigned int n = k-1; n > m; n--)
                {
                    tempData[n] = tempData[n-1];
                }
                tempData[m] = data[j];
                break;
            }
        }
    }
    return tempData[k-1];
}

int main()
{
    cout<<"�������ݹ�ģ:";
    int N, k;
    cin>>N;
    cout<<"����kֵ:";
    cin>>k;
    if (N <= 0 || k < 0 || k >= N)
    {
        cout<<"������󣬳��������"<<endl;
        return 0;
    }
    vector<int> data;
    GenerateData(data, N);

    MyClock mytim;
    //�㷨1
    mytim.begin();
    int res = Algorithm1(data, k);
    mytim.end();
    cout<<"�㷨1���Ϊ:"<<res<<"��һ����ʱ:"<<mytim.GetHowLong()<<"��"<<endl;

    //�㷨2
    mytim.begin();
    res = Algorithm2(data, k);
    mytim.end();
    cout<<"�㷨2���Ϊ:"<<res<<"��һ����ʱ:"<<mytim.GetHowLong()<<"��"<<endl;
    return 0;
}
