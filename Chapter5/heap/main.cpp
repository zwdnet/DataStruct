#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "heap.h"
#include "../../mylib/tool.h"

using namespace std;

int SelectAlg5A(const int N, const int k)
{
    vector<int> data;
    GenerateData(data, N, 10, N*10);
    Heap<int> heap2(N);
    heap2.BuildHeap(data);
    for (int i = 0; i < k-1; i++)
    {
        heap2.DeleteMin();
    }
    return heap2.DeleteMin();
}

int main()
{
    int N;
    cout<<"输入数据规模:";
    cin>>N;
    if (N <= 0)
    {
        N = 10;
    }

    Heap<int> heap(N);
    srand(time(0));
    vector<int> data(N);
    for (int i = 1; i <= N; i++)
    {
        data[i-1] = rand()%N;
    }
    heap.BuildHeap(data);
    cout<<"出堆秩序为:";
    while (heap.IsEmpty() == false)
    {
        cout<<heap.DeleteMin()<<" ";
    }
    cout<<endl;

    cout<<"输入选择问题的k值:";
    int k;
    cin>>k;
    cout<<"结果为:"<<SelectAlg5A(N, k)<<endl;
    return 0;
}
