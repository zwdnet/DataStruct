#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
//ջ��Ӧ�ã�����ƥ��

bool Balance(const string & str)
{
    int N = str.size();
    stack<char> strStack;
    for (int i = 0; i < N; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            strStack.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (strStack.empty())
            {
                return false;
            }
            else
            {
                char temp = strStack.top();
                if ((str[i] == ')' && temp == '(') ||
                    (str[i] == ']' && temp == '[') ||
                    (str[i] == '}' && temp == '{'))
                {
                    strStack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (strStack.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    cout << "����Ҫƥ����ַ���:";
    string str;
    cin>>str;
    if (Balance(str))
    {
        cout<<"����ƥ��"<<endl;
    }
    else
    {
        cout<<"���Ų�ƥ��"<<endl;
    }
    return 0;
}
