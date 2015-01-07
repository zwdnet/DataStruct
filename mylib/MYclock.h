#ifndef MYCLOCK_H
#define MYCLOCK_H

/*��ʱ���࣬�����������ʱ��
  2008��7��28��
  zwdnet@163.com
*/
#include <ctime>
class MyClock
{
private:
        double dBegin; //��ʼʱ�� 
        double dEnd;   //����ʱ�� 
        double Time;  //������ʱ�� 
        bool   fBegin; //true Ϊ��ʱ��ʼ
public:
        MyClock(); //���캯�� 
        void   begin(void); //��ʱ��ʼ
        void   end(void);   //��ʱ����
        double GetHowLong(void);//�õ���ʱ��� 
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
