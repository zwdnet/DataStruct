#include <iostream>
#include "../../mylib/tool.h"
#include "../../mylib/myclock.h"
#include "sort.h"

using namespace std;

//#define TEST

int main()
{
    int N;
    cout<<"输入数据规模:";
    cin>>N;
    vector<int> data, temp;
    GenerateData(data, N, 0, N*10);
    CopyData(data, temp);
    MyClock mytim;
    cout<<"插入排序:"<<endl;
    mytim.begin();
    InsertSort(temp);
    #ifdef TEST
    DisplayData(temp);
    #endif
    mytim.end();
    cout<<"耗时:"<<mytim.GetHowLong()<<endl;

    CopyData(data, temp);
    cout<<"shell排序:"<<endl;
    mytim.begin();
    ShellSort(temp);
    #ifdef TEST
    DisplayData(temp);
    #endif
    mytim.end();
    cout<<"耗时:"<<mytim.GetHowLong()<<endl;

    CopyData(data, temp);
    cout<<"堆排序:"<<endl;
    mytim.begin();
    HeapSort(temp);
    #ifdef TEST
    DisplayData(temp);
    #endif
    mytim.end();
    cout<<"耗时:"<<mytim.GetHowLong()<<endl;

    return 0;
}
