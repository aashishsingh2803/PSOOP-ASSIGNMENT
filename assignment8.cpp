#include<bits/stdc++.h>
using namespace std;

class data
{
    char name[15],bg[5],branch[5];
    int regno,dd,mm,yy,year,rno;

public:

    int reg_no()
    {
        return regno;
    }

    void getdata()
    {
        cout<<"\nEnter Registration no. Name Date of birh (DD-MM-YY) Branch year Blood group Roll No. respectively \n";
        cin>>regno>>name>>dd>>mm>>yy>>branch>>year>>bg>>rno;
    }

    void putdata()
    {

        printf("\n%-6d\t%-10s\t%d-%d-%d\t %-5s\t%d\t%-11s\t%d",regno,name,dd,mm,yy,branch,year,bg,rno);

    }
};



main()
{
    char ch;
    int c;
    data d;
    ofstream fout;
    ifstream fin;


    do
    {
        cout<<"Enter your choice : \n\t1-Add record\n\t2-Display Database \n\t3-Delete a record \n\t4-Modify a record : ";
        cin>>c;

        switch(c)
        {
        case 1: d.getdata();
                fout.open("abc.dat",ios::out|ios::app);

                fout.write((char *)&d,sizeof(d));
                fout.close();
                break;

        case 2: fin.open("abc.dat",ios::in);
               // cout<<"a";
                 printf("Reg no\tName  \t\tDOB(DD-MM-YY)\tBranch\tYear\tBlood Group\tRoll no");
                while(fin.read((char*)&d,sizeof(d)))
                {
                    //cout<<"a";
                    d.putdata();
                }
                fin.close();
                break;

         case 3: cout<<"\nEnter reg no. whose record you want to delete";
                 cin>>c;
                  fin.open("abc.dat",ios::in);
                  fout.open("abc1.dat",ios::out);

                while(fin.read((char*)&d,sizeof(d)))
                {
                   if(d.reg_no()!=c)
                   {
                      
                       fout.write((char*)&d,sizeof(d));
                   }
                   else
                    cout<<"object is deleted";
                }
					 fout.close();
                fin.close();
                
                    remove("abc.dat");
                     rename("abc1.dat","abc.dat");

               
                    break;

            case 4: cout<<"\nEnter registration no whose record you want to modify : ";
                    cin>>c;
                    fin.open("abc.dat",ios::in);
                    fout.open("abc1.dat",ios::out);

                    while(fin.read((char*)&d,sizeof(d)))
                    {
                        if(d.reg_no()==c)
                        {
                            d.getdata();
                            fout.write((char*)&d,sizeof(d));
                        }
                        else
                        {
                            fout.write((char*)&d,sizeof(d));

                        }
                    }
                    fout.close();
                fin.close();
                    
                    remove("abc.dat");
                     rename("abc1.dat","abc.dat");

                
                    break;
        }


        cout<<"\nWant to continue : ";
        cin>>ch;
    }while(ch!='n');

}
