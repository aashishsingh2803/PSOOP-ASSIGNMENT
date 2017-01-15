#include<iostream>
#include<stdio.h>
using namespace std;

 int p;

class weather_report
{

  int dayofmonth;
 double ht,lt,amtr,amts;

  public:

       weather_report()
       {
           dayofmonth=0;
           ht=0;
           lt=0;
           amtr=0;
           amts=0;
       }
       ~ weather_report()
       {

       }

  int dayofmonth1()
  {
  	return dayofmonth;
  }
  void getdata(int z)
  {
  dayofmonth=z;
  cout<<"\n enter high teperature ";
  cin>>ht;
  cout<<"\n enter low temperature ";
  cin>>lt;
  cout<<"\n enter amount of rain ";
  cin>>amtr;
  cout<<"\n enter amount of snow ";
  cin>>amts;
  p++;
  }

  void average()
  {

 static float htavg,ltavg,amtravg,amtsavg,k;
   htavg+=ht;
   ltavg+=lt;
   amtravg+=amtr;
   amtsavg+=amts;
  k++;

   if(k==p)
   {
   	 cout<<"Avg High Temp   Avg Low Temp   Avg Amount Of Rain   Avg Amount Of Snow";
   printf("\n%f%16f%16f%21f",htavg/p,ltavg/p,amtravg/p,amtsavg/p);
   htavg=0;ltavg=0;amtravg=0;amtsavg=0;k=0;
   }
  }
  void putdata();
  void modify();
 };
int s=1;
 void  weather_report::putdata()
 {
  printf("\n%d       %d%21f%14f%13f%14f",s,dayofmonth,ht,lt,amtr,amts);
  s++;

  }
  void weather_report::modify()
  {
     int z;
  	char ch;
  	        do
  	        {
  	        	cout<<"What You Want To Modify\n\n1-Day Of Month \n\n2-High Teperature\n\n3-Low Temperature\n\n4-Amount Of Rain\n\n5-Amount Of Snow";
  	        	cin>>z;
  	        	switch(z)
  	        	{
  	        	    case 1:cin>>dayofmonth;
                            break;
  	        		case 2:cin>>ht;
  	        		        break;
  	        		case 3:cin>>lt;
						    break;
					case 4:cin>>amtr;
						    break;
					case 5:cin>>amts;
					        break;
				  }

  	        	cout<<"Want To Modify More y-Yes ,n-No\n";
  	        	cin>>ch;
			  }while(ch=='y');
  }
  
 int  main()
  {
  int b,c,d=0,i,f,u,j,x=0,y=0,z=0,a;
  char ch;
  weather_report w1[32];

  do
   {
       cout<<"********************************************************************\n";
       cout<<"                          WEATHER   REPORT                          ";
       cout<<"\n********************************************************************";
  cout<<"\n 1-ACCEPT RECORD \n 2-DISPLAY ALL RECORD \n 3-AVERAGE RECORD \n 4-MODIFY RECORD\n 5-DELETE RECORD\n 6-DISPLAY PARTICULAR DATA  \n";
  cin>>b;
  switch(b)
      {
  case 1:
           cout<<"\n enter day of month ";
            cin>>a;
            z=0;
            if(a<32&&a>0)
            {
        for(i=0;i<p;i++)
        {
            if(w1[i].dayofmonth1()==a)
            {
                z=1;
                cout<<"this day already exist";
                break;
            }
        }
          if(z==0)
          {
              w1[d].getdata(a);
                d++;
          }

            }
            else
                cout<<"invalid day";


  	  		break;

  case 2:       s=1;
                if(p==0)
                    cout<<"NO RECORD FOUND";
                else
                {
  			   		cout<<"S.No.  Day Of Month   High Temp     Low Temp     Amt Of Rain   Amt Of Snow";
  			   		for(i=0;i<p;i++)
  			   		{
  						w1[i].putdata();
               		}
                }
			  break;
  case 3:
            for(i=0;i<p;i++)
  			{
  				w1[i].average();
			  }
   	 	  break;
  case 4:
            do
         {
  			cout<<"ENTER DAY OF DATA WHICH YOU WANT TO MODIFY  ";
  			cin>>f;
  			x=0;
  			  for(i=0;i<p;i++)
  			  {
  			  	if(w1[i].dayofmonth1()==f)
  			  	{
  			  		 w1[i].modify();
  			  		 x=1;
  			  		 break;
                }
              }
              if(x==0)
                cout<<"\nWRONG CHOICE";
            cout<<"\ndo you want to modify other day of data Yes-y  No-n ";
            cin>>ch;
         }while(ch=='y');
          break;
  case 5:
            do
            {
  			cout<<"ENTER DAY OF DATA WHICH YOU WANT TO DELETE  ";
  			cin>>f;
            u=0;
  				 for(i=0;i<p;i++)
  			  {
  			  	if(w1[i].dayofmonth1()==f)
  			  	{
  			  		w1[i].~weather_report();//destructor is called implicitly


  			  		u=1;
  			  		for(j=i;j<p;j++)
                    {
                        w1[j]=w1[j+1];
                    }
                      cout<<"object is deleted";
                    p--;
				}
				if(u==1)
                    break;
			 }
			 ch='n';
                if(u==0)
                   {
                    cout<<"WRONG CHOICE";
                    cout<<"\ndo you want to delete more Yes-y  No-n ";
                    cin>>ch;
                    }
         }while(ch=='y');

            break;
  case 6:
        do
        {
            s=1;
        cout<<"ENTER WHICH DAY RECORD YOU WANT TO DISPLAY\n";
         cin>>b;

          y=0;
		 for(i=0;i<p;i++)
		 {
		 	if(w1[i].dayofmonth1()==b)
		 	{
		 	     cout<<"S.No.  Day Of Month   High Temp     Low Temp     Amt Of Rain   Amt Of Snow";
		 		w1[i].putdata();
		 		y=1;
			 }
		}
		if(y==0)
            cout<<"\nWRONG CHOICE";
        cout<<"\ndo you want to display more Yes-y  No-n ";
        cin>>ch;
         }while(ch=='y');

      }
  cout<<"\n\nDo you want to exit-3\n\n Continue  - 1  ";
  cin>> c;

   }while(c==1);
   return 0;

}



