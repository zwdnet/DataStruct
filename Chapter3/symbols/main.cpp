#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
//Õ»µÄÓ¦ÓÃ£º·ûºÅÆ¥Åä

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
    cout << "ÊäÈëÒªÆ¥ÅäµÄ×Ö·û´®:";
    string str;
    cin>>str;
    if (Balance(str))
    {
        cout<<"·ûºÅÆ¥Åä"<<endl;
    }
    else
    {
        cout<<"·ûºÅ²»Æ¥Åä"<<endl;
    }
    return 0;
}
