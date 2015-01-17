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
    cout<<"�������"<<endl;
    testTree.PrintTreeInOrder();
    cout<<"�������"<<endl;
    testTree.PrintTreePreOrder();
    cout<<"�������"<<endl;
    testTree.PrintTreePostOrder();
    cout<<"���ĸ߶�Ϊ:"<<testTree.Height()<<endl;
    cout<<"����Ԫ������Ϊ:"<<testTree.Size()<<endl;
    return 0;
}
