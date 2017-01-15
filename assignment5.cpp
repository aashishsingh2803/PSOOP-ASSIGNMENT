#include<bits/stdc++.h>
using namespace std;

class base
{
    protected:
              int x,y;
    public:
           void input()
           {
               cout<<"\nEnter Sides Of Shape ";
               cin>>x>>y;
           }
           virtual double calculate()=0;
};
class circle :public base
{
    double a;
    public:
            double calculate()
            {
                a=3.14*x*x;
                return a;
            }
};
class triangle :public base
{
    double a;
    public:
            double calculate()
            {
                a=0.5*x*y;
                return a;
            }
};
class rectangle :public base
{
    double a;
    public :
            double calculate()
            {
                a=x*y;
                return a;
            }
};

main()
{
    base* b;
    circle c1;
    rectangle r;
    triangle t;
    int c;
    char ch;
    double d;
do
{
     cout<<"\nEnter Your Choice :\n\t1-Area Of Circle\n\t2-Area Of Triangle\n\t3-Area Of Rectangle ";
    cin>>c;
    switch(c)
    {
        case 1:
                b=&c1;
                b->input();
                d = b->calculate();
                cout<<"\nArea Of Circle Is = "<<d;
                break;
        case 2:
                b=&t;
                b->input();
                d=b->calculate();
                cout<<"\nArea Of Triangle Is = "<<d;
                break;
        case 3:
                b=&r;
                b->input();
                d=b->calculate();
                cout<<"\nArea Of Rectangle = "<<d;
                break;
        }
        cout<<"\nWant to Enter More (y,n) ";
        cin>>ch;
    }while(ch!='n');
}
