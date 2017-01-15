#include<iostream>
//template class assignment,matrix arithmetic
using namespace std;
template <class t ,int size>
class matrix
{
    t p[size][size],q[size][size],z[size][size];
   
public:
    int  getdata(int m,int n,int m1,int n1)
    {
        int i,j,x;
        cout<<"\nEnter elements of matrix 1:";
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>p[i][j];
            }
        }
        cout<<"\nEnter elements of matrix 2:";
         for(i=0;i<m1;i++)
        {
            for(j=0;j<n1;j++)
            {
                cin>>q[i][j];
            }
        }
    }
   void add(int m,int n)
    {
        int i,j;
        {        for(i=0;i<m;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        z[i][j]=p[i][j]+q[i][j];
                    }
                }
         }
    }
    void sub(int m,int n)
    {
        int i,j;
        {        for(i=0;i<m;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        z[i][j]=p[i][j]-q[i][j];
                    }
                }
         }
    }
    void mul(int m,int n,int n1)
    {
        int i,j,s;
        for(i=0;i<m;i++)
            for(j=0;j<n1;j++)
            z[i][j]=0;
        for(i=0;i<m;i++)
				{
					for(j=0;j<n1;j++)
					{
						for(s=0;s<n;s++)
						{
								z[i][j]+=p[i][s]*q[s][j];
						}
					}
				}
    }
    void display(int m,int n)
    {
        int i,j;
        cout<<"\nResultant Matrix  =\n";
        for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						cout<<z[i][j]<<"\t";
					}
					cout<<"\n";
				}
    }
     void displayy(int m,int n,int m1,int n1)
    {
        int i,j;
        cout<<"\nMatrix 1 =\n";
        for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						cout<<p[i][j]<<"\t";
					}
					cout<<"\n";
				}
				cout<<"\nMatrix 2 =\n";
				 for(i=0;i<m1;i++)
				{
					for(j=0;j<n1;j++)
					{
						cout<<q[i][j]<<"\t";
					}
					cout<<"\n";
				}
    }
};
int main()
{
    int i,j,choice,choice1,z[10][10],m,n,m1,n1,r;
    
    matrix <int,10> o1;
    matrix <float,10> o2;
    float y[10][10];
    do
    {
        cout<<"\nProgram to perform arithmetic operations to matrix .\n1.integer matrix\n2.Float matrix\nEnter your choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"\n1.Addition\n2.Subtraction\n3.multiplication";
                    cin>>choice1;
                    switch(choice1)
                    {
                        case 1:cout<<"\nEnter the no of rows and column in matrix 1:  ";
                                   cin>>m>>n;
                                   cout<<"\nEnter the no of rows and column in matrix 2:  ";
                                   cin>>m1>>n1;
                                   if(m==m1&&n==n1)
                                    {
                                       o1.getdata(m,n,m1,n1);
                                       o1.add(m,n);
                                       o1.displayy(m,n,m1,n1);
                                       o1.display(m,n);
                                   }
                                   else
                                    cout<<"Addition is not possible";
                                    break;
                        case 2:cout<<"\nEnter the no of rows and column in matrix 1:  ";
                                   cin>>m>>n;
                                   cout<<"\nEnter the no of rows and column in matrix 2:  ";
                                   cin>>m1>>n1;
                                   if(m==m1&&n==n1)
                                    {
                                       o1.getdata(m,n,m1,n1);
                                       o1.sub(m,n);
                                       o1.displayy(m,n,m1,n1);
                                       o1.display(m,n);
                                   }
                                   else
                                    cout<<"\nSubtraction is not possible";
                                    break;
                        case 3:cout<<"\nEnter the no of rows and column in matrix 1:  ";
                                   cin>>m>>n;
                                   cout<<"\nEnter the no of rows and column in matrix 2:  ";
                                   cin>>m1>>n1;
                                   if(n==m1)
                                    {
                                       o1.getdata(m,n,m1,n1);
                                       o1.mul(m,n,n1);
                                       o1.displayy(m,n,m1,n1);
                                       o1.display(m,n1);
                                   }
                                   else
                                    cout<<"\nMultiplication is not possible\n";
                                    break;
                        default:
                            cout<<"ERROR!!\n";
                            break;
                    }
                   break;
           case 2:cout<<"\n1.Addition\n2.Subtraction\n3.multiplication";
                    cin>>choice1;
                    switch(choice1)
                    {
                            case 1:cout<<"\nEnter the no of rows and column in matrix 1:  ";
                                   cin>>m>>n;
                                   cout<<"\nEnter the no of rows and column in matrix 2:  ";
                                   cin>>m1>>n1;
                                   if(m==m1&&n==n1)
                                    {
                                       o2.getdata(m,n,m1,n1);
                                       o2.add(m,n);
                                       o2.displayy(m,n,m1,n1);
                                       o2.display(m,n);
                               }
                               else
                                cout<<"Addition is not possible";
                                break;
                        case 2:cout<<"\nEnter the no of rows and column in matrix 1:  ";
                               cin>>m>>n;
                               cout<<"\nEnter the no of rows and column in matrix 2:  ";
                               cin>>m1>>n1;
                               if(m==m1&&n==n1)
                                {
                                       o2.getdata(m,n,m1,n1);
                                       o2.sub(m,n);
                                       o2.displayy(m,n,m1,n1);
                                       o2.display(m,n);
                                   }
                                   else
                                    cout<<"\nSubtraction is not possible";
                                    break;
                           case 3:cout<<"\nEnter the no of rows and column in matrix 1:  ";
                                   cin>>m>>n;
                                   cout<<"\nEnter the no of rows and column in matrix 2:  ";
                                   cin>>m1>>n1;
                                   if(n==m1)
                                    {
                                       o2.getdata(m,n,m1,n1);
                                       o2.mul(m,n,n1);
                                       o2.displayy(m,n,m1,n1);
                                       o2.display(m,n1);
                                   }
                                   else
                                    cout<<"\nMultiplication is not possible";
                                    break;
                        default:cout<<"ERROR!!\n";
                                break;
                    }
                    break;
            default:cout<<"Wrong choice .\n";
                     break;
        }
        cout<<"\nPress 1 to continue .\n";
        cin>>r;
    }while(r==1);
    return 0;
}//template is foundation of generic programing ,in which we writing code which is independent of particular data type.
