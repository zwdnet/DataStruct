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

int main()
{
    int_test();
    return 0;
}
