//二分查找
#include <iostream>
#include "../../mylib/myclock.h"
#include "../../mylib/tool.h"
#include <vector>
#include <algorithm>

using namespace std;

//二分查找
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
    cout<<"输入数据规模:";
    int N;
    cin>>N;
    vector<int> data;
    GenerateData(data, N, 0, 10000);
    sort(data.begin(), data.end());
    cout<<"数据为:";
    DisplayData(data);
    cout<<"输入要查找的数值：";
    int v;
    cin>>v;
    int pos = BinarySearch(data, v);
    cout<<"要查找的数据的位置为:"<<pos<<endl;
    return 0;
}
