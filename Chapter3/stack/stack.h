#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include <vector>
#include "../../mylib/tool.h"

using namespace std;

//¡¥’ª
template <typename T>
class LinkStack
{
    private:
        vector<T> data;
    public:
        bool IsEmpty()
        {
            return data.empty();
        }
        void MakeEmpty()
        {
            data.clear();
        }
        void Push(T x)
        {
            data.push_back(x);
        }
        T Top(void)
        {
            return data.back();
        }
        void Pop(void)
        {
            data.pop_back();
        }
};

//À≥–Ú’ª
template <typename T>
class ArrayStack
{
        private:
            vector<T> data;
            unsigned int maxSize;
            int TopPoint;
        public:
            ArrayStack()
            {
                maxSize = 1;
                TopPoint = -1;
            }
            ArrayStack(const int Size)
            {
                if (Size >= 0)
                {
                    maxSize = Size;
                    data.resize(maxSize);
                }
                else
                    maxSize = 0;
                TopPoint = -1;
            }
            bool IsEmpty()
            {
                if (TopPoint == -1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            void MakeEmpty()
            {
                data.clear();
                TopPoint = -1;
            }
            void Push(T x)
            {
                if (data.size()-1 >= maxSize)
                {
                    maxSize = maxSize*2;
                    data.reserve(maxSize);
                }
                TopPoint++;
                data.push_back(x);
            }
            T Top()
            {
                if (!IsEmpty())
                {
                    return data[TopPoint];
                }
                else
                {
                    return NULL;
                }
            }
            void Pop()
            {
                TopPoint--;
            }
};
#endif // STACK_H_INCLUDED
