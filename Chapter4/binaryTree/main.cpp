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
    cout<<"�������ݹ�ģ:";
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
    cout<<"�������"<<endl;
    testTree.PrintTreeInOrder();
    cout<<"�������"<<endl;
    testTree.PrintTreePreOrder();
    cout<<"�������"<<endl;
    testTree.PrintTreePostOrder();
    cout<<"���ĸ߶�Ϊ:"<<testTree.Height()<<endl;
    cout<<"����Ԫ������Ϊ:"<<testTree.Size()<<endl;
    cout<<"����Ҫ���ҵ���:";
    int f;
    cin>>f;
    if (testTree.Find(f))
    {
        cout<<"�ҵ���"<<endl;
        testTree.Delete(f);
        cout<<f<<"��ɾ��"<<endl;
        testTree.PrintTreeInOrder();
    }
    else
    {
        cout<<"û���ҵ�"<<f<<endl;
    }
    cout<<"���ֵΪ:"<<testTree.FindMax()<<endl;
    cout<<"��СֵΪ:"<<testTree.FindMin()<<endl;
    return 0;
}
