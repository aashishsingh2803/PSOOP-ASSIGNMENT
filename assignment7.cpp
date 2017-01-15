#include<iostream>
using namespace std;
class tv
{
	int model;
	int size;
	int price;
	friend istream & operator >>(istream &input,tv& t1);
	friend ostream & operator <<(ostream &output ,tv& t1);
 };
 istream & operator >>(istream &input,tv &t1)
 {	int a1;
 		do
        {	a1=0;
 		try
 		{	cout<<"\n\nEnter Model No = ";
 			input>>t1.model;

 			if(t1.model<1||t1.model>1000)
 			{
 				throw(t1.model);
			}
 		}
 		catch(int)
		 {
		 	cout<<"\nInvalid Choice\n";
		 	a1=1;
		 }
        }while(a1==1);

		 do
         {	a1=0;
		 try
		 {		cout<<"\nEnter Size No = ";
			 input>>t1.size;
			 if(t1.size<11||t1.size>70)
 			{
 				throw(t1.size);
			 }
		 }
			  catch(int)
            {  cout<<"\nInvalid Choice\n";
                a1=1;
            }
         }while(a1==1);
         do
         {
              a1=0;
         try{
			 	cout<<"\nEnter Price No = ";
			 input>>t1.price;
			 if(t1.price<1||t1.price>50000)
 			{
 				throw(t1.price);
			 }
         }
         catch(int){
		 	cout<<"\nInvalid Choice\n";
		 	a1=1;  }
        }while(a1==1);			 
}
 ostream & operator<<(ostream& output,tv& t1)
			 {	output<<"\nmodel "<<t1.model;
			 	output<<"\nsize "<<t1.size;
			 	output<<"\nprice "<<t1.price;
			 }
 int main()
 {	tv t;
 	cin>>t;
 	cout<<t;
 	return 0;
 }

