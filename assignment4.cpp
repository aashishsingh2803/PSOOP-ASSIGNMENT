#include<bits/stdc++.h>
using namespace std;

class base1
{
protected:
    int dd,mm,yy;
    char* name,* bg;
public:
        base1()
        {
        }

        base1(int a,int b,int c,char* n,char* g)
        {
            dd=a;mm=b;yy=c;
            name=new char;
            strcpy(name,n);
            bg=new char;
            strcpy(bg,g);
        }
};

class base2
{
    protected:
    int ht,wt;
public:

    base2()
    {
    }
    base2(int a,int b)
    {
        ht=a;wt=b;
    }


};

class base3
{
    protected:
    int ipn;
    char* ad;
public:
    base3()
    {
    }

    base3(int i,char* a)
    {
        i=ipn;
        ad=new char;
        strcpy(ad,a);
    }

};

class derieved: public base1 , public base2 , public base3
{
     int tn,dn;
    static int cnt;
    public:
    derieved()
    {
    }
    derieved(int ipn1,char* ad1,int ht1,int wt1,int d1,int m1,int y1,char* name1,char* bg1,long long int a,long long int b):base3( ipn1, ad1),base2(ht1,wt1),base1(d1,m1,y1,name1,bg1)
    {
        tn=a;dn=b;
    }

    friend void add(derieved **);
    friend void display(derieved **);
    friend void modify(derieved **);
    friend void delete1(derieved **);
    friend void search(derieved **);


};

void add(derieved** p)
{
    char* name1,* bg1,* ad1;
    int d1,m1,y1,ipn1,ht1,wt1;
    long long int tn1,dn1;
    char ch;

    do
    {		l1:
    		cout<<"Enter Driving licence no.       : ";
	        	cin>>dn1;
	        	
	        	for(int i=0;i<p[0]->cnt;i++)
	        	{
	        		try{
	        			if(p[i]->dn==dn1)
	        			{
	        				throw(dn1);
						}
					}
					
					catch(int){
						cout<<"data already exists";
						goto l1;
					
					}
				}
    	
    	cout<<"\nEnter name ";
    	name1=new char;
    	_flushall();
    	gets(name1);


    	cout<<"\nEnter Date Of Birth (dd-mm-yy) ";
    	cin>>d1>>m1>>y1;

    	cout<<"\nEnter Blood Group  ";
    	_flushall();
    	bg1=new char;
    	cin>>bg1;

        cout<<"Enter Height And Weight  ";
        cin>>ht1>>wt1;

        cout<<"\nEnter Insurance policy no. ";
        cin>>ipn1;

        cout<<"\nEnter Contact Address ";
        _flushall();
        ad1=new char;
        gets(ad1);

        cout<<"\nEnter Telephone no. ";
        cin>>tn1;

        

        p[p[0]->cnt]=new derieved(ipn1,ad1,ht1,wt1,d1,m1,y1,name1,bg1,tn1,dn1);
        p[0]->cnt++;

    	cout<<"\nWant To Enter More  ";
    	cin>>ch;
	}while(ch!='n');
}

	void display(derieved **p)
	{
	    int i;
	    for(i=0;i<p[0]->cnt;i++)
        {
           // cout<<"aaaaaaaa";
          //  cout<<ipn<<ad<<ht,wt,dd,mm,yy,name,bg,tn,dn;
            cout<<"\nName 	                : "<<p[i]->name;
            cout<<"\nDate Of Birth		    : "<<p[i]->dd<<"/"<<p[i]->mm<<"/"<<p[i]->yy;
            cout<<"\nBlood Group            : "<<p[i]->bg;
            cout<<"\nHeight                 : "<<p[i]->ht;
			cout<<"\nWeight                 : "<<p[i]->wt;
            cout<<"\nInsurance policy no.	: "<<p[i]->ipn;
            cout<<"\nContact Address        : "<<p[i]->ad;
            cout<<"\nTelephone No.          : "<<p[i]->tn;
            cout<<"\nDriving Licemnse No.   : "<<p[i]->dn;
        }
	}
	
	void search(derieved** p )
	{
		int x,y=0;
		cout<<"\nEnter driving license no to search : ";
		cin>>x;
		
		
		for(int i=0;i<p[0]->cnt;i++)
		{
			if(x==p[i]->dn)
			{
				cout<<"\nRecord Found \n";
			cout<<"\nName 					: "<<p[i]->name;
            cout<<"\nDate Of Birth		    : "<<p[i]->dd<<"/"<<p[i]->mm<<"/"<<p[i]->yy;
            cout<<"\nBlood Group   			: "<<p[i]->bg;
            cout<<"\nHeight 				: "<<p[i]->ht;
			cout<<"\nWeight 				: "<<p[i]->wt;
            cout<<"\nInsurance policy no.	: "<<p[i]->ipn;
            cout<<"\nContact Address		: "<<p[i]->ad;
            cout<<"\nTelephone No.   		: "<<p[i]->tn;
            cout<<"\nDriving Licemnse No.   : "<<p[i]->dn;
            y=1;
			}
			
		}
		
		if(y==0)
		{
			cout<<"\nRecord not present : ";
		}
		
	}
	
	void modify(derieved** p)
	{
		char* name1,* bg1,* ad1;
    int d1,m1,y1,ipn1,ht1,wt1,x,z=0,i;
    long long int tn1,dn1;
 
		cout<<"\nEnter driving license no to modify : ";
		cin>>x;
		
		for(i=0;i<p[0]->cnt;i++)
		{
			if(x==p[i]->dn)
			{
				cout<<"\nEnter name ";
    			name1=new char;
    			_flushall();
    			gets(p[i]->name);


    	cout<<"\nEnter Date Of Birth (dd-mm-yy) ";
    	cin>>p[i]->dd>>p[i]->mm>>p[i]->yy;

    	cout<<"\nEnter Blood Group  ";
    	_flushall();
    	bg1=new char;
    	cin>>p[i]->bg;

        cout<<"Enter Height And Weight  ";
        cin>>p[i]->ht>>p[i]->wt;

        cout<<"\nEnter Insurance policy no. ";
        cin>>p[i]->ipn;

        cout<<"\nEnter Contact Address ";
        _flushall();
        ad1=new char;
        gets(p[i]->ad);

        cout<<"\nEnter Telephone no. ";
        cin>>p[i]->tn;

        cout<<"\nEnter Driving License No. ";
        cin>>p[i]->dn;
        
        	
        	cout<<"\n  ITEM IS MODIFIED  ";
        z=1;
        
			}
		}
		
		if(z==0)
		{
			cout<<"\n Record is not present  ";
		}
		
	}
	
	void delete1(derieved** p)
	{
		int x,z=0,i;
		cout<<"\nEnter driving license no to delete : ";
		cin>>x;
		for(i=0;i<p[0]->cnt;i++)
		{
			if(x==p[i]->dn)
			{
				for(int j=i;j<p[0]->cnt-1;j++)
				{
					p[j]=p[j+1];
				}
				z=1;
				p[0]->cnt--;
				break;
			}
		}
		
		if(z==0)
		{
			cout<<"\n record not present  ";
		}
		
	}

int derieved::cnt;

main()
{
    derieved* d1[100];
    int d;
    char ch;

    do
    {
        cout<<"\nEnter Your Choice\n\t1-Add Record\n\t2-Display All Record\n\t3-Search Record\n\t4-Modify Record\n\t5-Delete Record ";
        cin>>d;
        switch(d)
        {


        case 1: 
                add(&d1[0]);
                break;

        case 2:
                display(&d1[0]);
                break;

        case 3:d1[0]=new derieved;
                search(&d1[0]);
                break;

        case 4:d1[0]=new derieved;
                modify(&d1[0]);
                break;

       case 5:d1[0]=new derieved;
                delete1(&d1[0]);
                break;
        }

        cout<<"\nWant To Enter More\n";
    cin>>ch;
    }while(ch!='n');


}
