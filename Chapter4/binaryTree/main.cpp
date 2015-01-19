#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinTree.h"
#include "AVL.h"

using namespace std;

int main()
{
    //SearchTree<int> testTree;
    AVLTree<int> testTree;
    srand(time(0));
    int N;
    cout<<"输入数据规模:";
    cin>>N;
    if (N <= 0)
    {
        N = 10;
    }
    for (int i = 0; i < N; i++)
    {
        int r = rand()%(10*N);
        testTree.Insert(r);
    }
    cout<<"中序遍历"<<endl;
    testTree.PrintTreeInOrder();
    cout<<"先序遍历"<<endl;
    testTree.PrintTreePreOrder();
    cout<<"后序遍历"<<endl;
    testTree.PrintTreePostOrder();
    cout<<"树的高度为:"<<testTree.Height()<<endl;
    cout<<"树的元素总数为:"<<testTree.Size()<<endl;
    cout<<"输入要查找的数:";
    int f;
    cin>>f;
    if (testTree.Find(f))
    {
        cout<<"找到了"<<endl;
        testTree.Delete(f);
        cout<<f<<"已删除"<<endl;
        testTree.PrintTreeInOrder();
    }
    else
    {
        cout<<"没有找到"<<f<<endl;
    }
    cout<<"最大值为:"<<testTree.FindMax()<<endl;
    cout<<"最小值为:"<<testTree.FindMin()<<endl;
    return 0;
}
