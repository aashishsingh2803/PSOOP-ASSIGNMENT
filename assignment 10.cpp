#include<bits/stdc++.h>
using namespace std;
class file
{	int roll,reg;
	char name[100];
	public:
		void getdata()
		{	ofstream fout;
			fout.open("marks.txt",ios::out);
			cout<<"\nEnter Name Of The Student ";
			_flushall();
			gets(name);
			cout<<"Enter registration no. : ";
			cin>>reg;
			cout<<"\nEnter Roll No. : ";
			cin>>roll;
			fout<<name<<"\t\t"<<reg<<"\t   "<<roll<<"\n";
		}
		void putdata()
		{	char a[100];	ifstream fin;
			fin.open("marks.dat",ios::in);
			fin.getline(a,80);
			cout<<"Name\t\tRoll no.  Reg no\n"; 	cout<<a;
		}
};
int main()
{
	file f;
	f.getdata();
	f.putdata();
	return 0;
}
