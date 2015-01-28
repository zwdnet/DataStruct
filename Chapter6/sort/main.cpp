#include <iostream>
#include "../../mylib/tool.h"
#include "../../mylib/myclock.h"
#include "sort.h"
#include <algorithm>

using namespace std;

//#define TEST

int main()
{
    int N;
    cout<<"�������ݹ�ģ:";
    cin>>N;
    vector<int> data, temp;
    GenerateData(data, N, 0, N*10);
    CopyData(data, temp);
    MyClock mytim;
    cout<<"��������:"<<endl;
    mytim.begin();
    InsertSort(temp);
    #ifdef TEST
    DisplayData(temp);
    #endif
    mytim.end();
    cout<<"��ʱ:"<<mytim.GetHowLong()<<endl;

    CopyData(data, temp);
    cout<<"shell����:"<<endl;
    mytim.begin();
    ShellSort(temp);
    #ifdef TEST
    DisplayData(temp);
    #endif
    mytim.end();
    cout<<"��ʱ:"<<mytim.GetHowLong()<<endl;

    CopyData(data, temp);
    cout<<"������:"<<endl;
    mytim.begin();
    HeapSort(temp);
    #ifdef TEST
    DisplayData(temp);
    #endif
    mytim.end();
    cout<<"��ʱ:"<<mytim.GetHowLong()<<endl;

    CopyData(data, temp);
    cout<<"�鲢����:"<<endl;
    mytim.begin();
    MergeSort(temp);
    #ifdef TEST
    DisplayData(temp);
    #endif
    mytim.end();
    cout<<"��ʱ:"<<mytim.GetHowLong()<<endl;

    CopyData(data, temp);
    cout<<"��������:"<<endl;
    mytim.begin();
    QuickSort(temp);
    #ifdef TEST
    DisplayData(temp);
    #endif
    mytim.end();
    cout<<"��ʱ:"<<mytim.GetHowLong()<<endl;

    CopyData(data, temp);
    cout<<"STL�Դ�������:"<<endl;
    mytim.begin();
    sort(temp.begin(), temp.end());
    #ifdef TEST
    DisplayData(temp);
    #endif
    mytim.end();
    cout<<"��ʱ:"<<mytim.GetHowLong()<<endl;

    return 0;
}
