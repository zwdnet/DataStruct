//���ֲ���
#include <iostream>
#include "../../mylib/myclock.h"
#include "../../mylib/tool.h"
#include <vector>
#include <algorithm>

using namespace std;

//���ֲ���
int BinarySearch(const vector<int> & data, int value)
{
    int Low, Mid, High;

    Low = 0; High = data.size()-1;
    while (Low <= High)
    {
        Mid = (Low + High)/2;
        if (data[Mid] < value)
        {
            Low = Mid + 1;
        }
        else if (data[Mid] > value)
        {
            High = Mid - 1;
        }
        else
        {
            return Mid;
        }
    }
    return -1;
}

int main()
{
    cout<<"�������ݹ�ģ:";
    int N;
    cin>>N;
    vector<int> data;
    GenerateData(data, N, 0, 10000);
    sort(data.begin(), data.end());
    cout<<"����Ϊ:";
    DisplayData(data);
    cout<<"����Ҫ���ҵ���ֵ��";
    int v;
    cin>>v;
    int pos = BinarySearch(data, v);
    cout<<"Ҫ���ҵ����ݵ�λ��Ϊ:"<<pos<<endl;
    return 0;
}
