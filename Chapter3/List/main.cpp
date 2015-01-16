#include <iostream>
#include "list.h"
#include "doublelist.h"

using namespace std;

void int_test(void)
{
    int iarr[4] = {10, 20, 30, 40};
    cout<<"\n--------int test--------"<<endl;
    DoubleList<int> * pdlink = new DoubleList<int>();

    pdlink->insert(0, 20);
    pdlink->append_last(10);
    pdlink->insert_first(30);

    cout<<"empty()="<<pdlink->empty()<<endl;
    cout<<"size()="<<pdlink->size()<<endl;

    int sz = pdlink->size();
    for (int i = 0; i < sz; i++)
    {
        cout<<"pdlink("<<i<<")="<<pdlink->get(i)<<endl;
    }
}

//测试两种查找，没调通。
void find_test(void)
{
    int iarr[4] = {10, 20, 30, 40};
    cout<<"\n--------find test--------"<<endl;
    List<int> * plink = new List<int>();

    plink->Insert(iarr[0], 0);
    plink->Insert(iarr[1], 0);
    plink->Insert(iarr[2], 0);

    cout<<"empty()="<<plink->IsEmpty()<<endl;
    cout<<"size()="<<plink->Size()<<endl;

    int sz = plink->Size();
    for (int i = 0; i < sz; i++)
    {
        cout<<"plink("<<i<<")="<<plink->get(i)<<endl;
    }
    cout<<plink->Find(30)<<endl;
    cout<<plink->FindR(30)<<endl;
}

//测试逆置 还是测试有误
void reverse_test()
{
    cout<<"-----------reverse test-----------"<<endl;
    List<int> mylist;
    for (int i = 0; i < 10; i++)
    {
        mylist.Insert(i*i, 0);
    }
    for (int i = 0; i < 10; i++)
    {
        cout<<mylist.get(i)<<" ";
    }
    cout<<endl;
    mylist.Reverse();
    for (int i = 0; i < 10; i++)
    {
        cout<<mylist.get(i)<<" ";
    }
    cout<<endl;
}
int main()
{
    int_test();
    //find_test();
    reverse_test();
    return 0;
}
