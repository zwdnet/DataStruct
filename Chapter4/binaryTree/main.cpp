#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinTree.h"

using namespace std;

int main()
{
    SearchTree<int> testTree;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int r = rand()%1000;
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
    return 0;
}
