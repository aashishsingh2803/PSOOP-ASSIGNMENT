
#include<iostream>
#include<fstream>

using namespace std;

class personal
{
	protected:
		char fn[20],ln[20];
		
		public:
			void getdata()
			{
				cout<<"\nEnter first name : ";
				cin>>fn;
				cout<<"\nEnter last name : ";
				cin>>ln;
			}
};

class professional:virtual public personal
{
	protected:
		char comp[30];
		int empno;
		
	public:	
		void getdata()
		{
			cout<<"\nEnter company name : ";
			cin>>comp;
		}
		void getemp()
		{
			cout<<"\nEnter employ no. : ";
			cin>>empno;
		}
		int emp_no()
		{
			return empno;
		}
};

class academic: virtual public personal
{
	protected:
		double percent;
		
	public:
		void getdata()
		{
			cout<<"\nEnter percent : ";
			cin>>percent;
		}
};

class employee: public professional,public academic
{
		public:
			void getdata()
			{
				personal::getdata();
				professional::getdata();
				academic::getdata();
				
			}
			void putdata()
			{
				cout<<"\nPersonal Info\n\t";
				cout<<"Name         : "<<fn<<" "<<ln;
				cout<<"\nProfessional Info\n\t";
				cout<<"Company Name : "<<comp;
				cout<<"\n\tEmplyee No.  : "<<empno;
				cout<<"\nAcademic\n\t";
				cout<<"Percent          : "<<percent;		
			}
};


main()
{
	employee e,a;
	ifstream fin;
	ofstream fout;
	int d;
	char ch;
	do
	{
		cout<<"Enter your choice ";
	cout<<"\n\t1-Accept Record ";
	cout<<"\n\t2-Display Record ";
	cin>>d;
	
	switch(d)
	{
		case 1:		l1:	
				fin.open("emp.dat",ios::in);
				a.getemp();
				while(fin.read((char*)&e,sizeof(e)))
				{
					if(e.emp_no()==a.emp_no())
					{
						cout<<"Data Already Exists ";
							fin.close();
						goto l1;
					}
				}
				fin.close();
					a.getdata();
					fout.open("emp.dat",ios::app|ios::binary);
			
				fout.write((char*)&a,sizeof(a));
				fout.close();
				break;
				
		case 2:
				fin.open("emp.dat",ios::in);
				while(fin.read((char*)&e,sizeof(e)))
				{
					e.putdata();
					cout<<"\n";
				}
				
				fin.close();
		
	}
		cout<<"\nWant To Continue";
		cin>>ch;
		
	}while(ch!='n');
	
	
}
