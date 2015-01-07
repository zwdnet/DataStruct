#ifndef MYCLOCK_H
#define MYCLOCK_H

/*计时的类，计算程序运行时间
  2008年7月28日
  zwdnet@163.com
*/
#include <ctime>
class MyClock
{
private:
        double dBegin; //开始时间 
        double dEnd;   //结束时间 
        double Time;  //经历的时间 
        bool   fBegin; //true 为计时开始
public:
        MyClock(); //构造函数 
        void   begin(void); //计时开始
        void   end(void);   //计时结束
        double GetHowLong(void);//得到计时结果 
}; 

MyClock::MyClock(void)
{
        dBegin = dEnd = Time = 0.0;
        fBegin = false;
}

void MyClock::begin()
{
        if (fBegin == false)
        {
             dBegin = double(clock())/CLK_TCK;
             fBegin = true;
        }
}

void MyClock::end()
{
        if (fBegin == true)
        {
             dEnd = double(clock())/CLK_TCK;
             fBegin = false;
             Time = dEnd - dBegin;
        }
}

double MyClock::GetHowLong(void)
{
        if (fBegin == false)
             return Time;
        else
             return -1.0;
}

#endif
