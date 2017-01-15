#include<bits/stdc++.h>
using namespace std;

class books
{
    char* t,* p,* a;
    int price,avail,id;
    static int z,z1,z2;
public:
    books()
    {

        t=new char;
        p=new char;
        a=new char;
        price=0; avail=0;
        id=0;
    }
    void add(char* tit)
    {

        cout<<"Enter book id of book      ";
        cin>>id;
        t=new char;
        strcpy(t,tit);
        p=new char;
        cout<<"Enter publisher of book    ";
       cin>>p;
       //cin.getline(p,20);
        a=new char;
        cout<<"Enter author of book       ";
        cin>>a;
        //cin.getline(a,20);
        cout<<"Enter price of book        ";
        cin>>price;
        cout<<"Enter availability of book ";
        cin>>avail;

    }

    void display()
    {
        printf("\n  %-8d%-11s%-12s%-11s%-13d%-5d",id,t,p,a,price,avail);
    }
    char* title()
    {
        return t;
    }

    int book_id()
    {
        return id;
    }

    void modify()
    {
        int b;
        cout<<"\n\nenter what you want to modify";
        cout<<"\n\t1-BOOK ID\n\t2-TITLE\n\t3-PUBLISHER\n\t4-AUTHOR\n\t5-PRICE\n\t6-AVAILABILITY";
        cin>>b;
        switch(b)
        {
            case 1:cin>>id;
                    break;

            case 2:t=new char;
                cin>>t;
               //  cin.getline(t,20);
                 break;

            case 3:p=new char;
                cin>>p;
               // cin.getline(p,20);
                  break;

            case 4:a=new char;
                    cin>>a;
                   // cin.getline(a,20);
                     break;

            case 5:cin>>price;
                     break;

            case 6:cin>>avail;
                     break;
        }
    }

   char purchase()
    {

        char ch;
        if(avail>0)
        {
            avail--;
            z+=price;
            z1++;

            cout<<"\nBook Purchased\n"<<"Current Amount= "<<z;
             cout<<"\nDo you want to purchase more\n";
                        cin>>ch;
                        if(ch=='n')
                        {
                            cout<<"\nNo.Of Sucessful Transaction = "<<z1;
                            cout<<"\nNo.of Unsucessful transaction = "<<z2;
                            cout<<"\nCost You Have To pay = "<<z;
                            z=0;
                            return 'n';
                        }
                        else
                        {
                            return ch;

                        }
        }
        else
        {
             cout<<"\nBook Is Currently Not Available It Will Come Soon\n";
             cout<<"\nUnsucessful Transaction\n";
             z2++;
             cout<<"\nDo you want to purchase more\n";
                        cin>>ch;
             return ch;
        }
    }

    int z_()
    {
        return z;
    }
     int z1_()
    {
        return z1;
    }
     int z2_()
    {
        return z2;
    }
};

 int books::z;
int books::z1;
int books::z2;
main()
{
    int a,c,i,q,e,u=0;
    char ch,* ch1;
    string b;
    books ob1[100];
    static int z;
    do
    {
    cout<<"\nBOOK STORE";
    cout<<"ENTER YOUR CHOICE \n\t\t1- ADMINISTRATIVE PART\n\t\t2-CUSTOMER PART\t";
    cin>>a;
    switch(a)
    {
        case 1:cout<<"\n\tENTER PASSWORD  ";
               cin>>b;
               if(b=="aashish")
               {
                   cout<<"\nl";
                   do
                   {
                       cout<<"\n*******************************************";
                       cout<<"\nENTER YOUR CHOICE\n\t1-ADD BOOKS\n\t2-DISPLAY ALL BOOKS\n\t3-MODIFY BOOK\n\t4-DELETE BOOK\n\t5-SEARCH BOOK\n";
                       cout<<"*******************************************\n\n";
                        cin>>c;
                        switch(c)
                        {
                            case 1:
                                    cout<<"Enter Book Name \t   ";
                                    ch1=new char(20);
                                    cin>>ch1;
                                    //cin.getline(ch1,20);
                                    u=0;
                                    for(i=0;i<z;i++)
                                    {
                                        if(!strcmp(ob1[i].title(),ch1))
                                            {
                                                cout<<"\nBook Already Exists\n";
                                                u=1;
                                            }
                                    }
                                    if(u==0)
                                    {
                                        ob1[z].add(ch1);
                                        z++;
                                    }

                                        break;

                            case 2:
                                    cout<<"\n Book_Id  Title     Publisher   Author     Price   Availability\n";
                                for(i=0;i<z;i++)
                                       ob1[i].display();

                                       cout<<"\n";
                                        break;

                            case 3:
                                cout<<"Enter Book Name You Want To Modify\n";
                                ch1=new char;
                                cin>>ch1;
                               //  cin.getline(ch1,20);
                                 q=0;
                                for(i=0;i<z;i++)
                                {

                                    if(!strcmp(ob1[i].title(),ch1));
                                    {
                                        ob1[i].modify();
                                        q=1;

                                        break;
                                    }
                                }
                                if(q==0)
                                    cout<<"\nBook Does Not Exist";

                                    break;

                            case 4:

                                q=0;
                                 cout<<"\n Book_Id  Title     Publisher   Author     Price   Availability\n";
                                    for(i=0;i<z;i++)
                                       ob1[i].display();

                                        cout<<"\n\nenter book name which you want to delete  ";
                                        ch1=new char;
                                cin>>ch1;
                                //      cin.getline(ch1,20);
                                for(i=0;i<z;i++)
                                {
                                     if(!strcmp(ob1[i].title(),ch1))
                                       {
                                           ob1[i].~books();

                                           u=1;
                                           q=1;
                                           z--;
                                           for(int j=i;j<z;j++)
                                           {
                                               ob1[j]=ob1[j+1];
                                           }

                                           cout<<"\nrecord is  deleted\n";
                                       }

                                       if(u==1)
                                        break;

                                }
                                if(q==0)
                                    cout<<"\nbook does not exist\n\n";
                                    break;


                            case 5:
                                     cout<<"\n\nenter book name which you want to Search  ";
                                     ch1=new char;
                                     cin>>ch1;
                                   //  cin.getline(ch1,20);
                                     u=0;
                                    for(i=0;i<z;i++)
                                    {
                                        if(!strcmp(ch1,ob1[i].title()))
                                        {
                                            cout<<"\n\tBook Found \n";
                                             cout<<"\n Book_Id  Title     Publisher   Author     Price   Availability\n";
                                            ob1[i].display();

                                            u=1;
                                        }
                                    }

                                    if(u==0)
                                        cout<<"\nBook Not Found";
                        }

                        cout<<"\n\ndo you want to continue (y/n)   ";
                        cin>>ch;
                   }while(ch=='y');
               }
               else
                cout<<"\nWRONG PASSWORD ";
               break;
         case 2:
             do
             {
               cout<<"\n Book_Id  Title     Publisher   Author     Price   Availability\n";
                            for(i=0;i<z;i++)
                               ob1[i].display();
                              int h=0,s=0;
                        cout<<"\nEnter Book Name You Want To Purchase  ";
                        ch1=new char;
                        cin>>ch1;
                       // cin.getline(ch1,20);
                        for(i=0;i<z;i++)
                        {
                            if(!strcmp(ob1[i].title(),ch1))
                            {
                                s++;
                               ch= ob1[i].purchase();
                                h=1;
                                break;
                            }
                        }
                        if(h==0)
                          {
                           cout<<"\nBook Not Found\n";

                          cout<<"\n\ndo you want to continue (y/n)   ";
                        cin>>ch;
                        if(ch=='n')
                        {
                            cout<<"\nNo.Of Sucessful Transaction = ";
                            int g1=ob1[0].z_();
                            cout<<g1;
                            cout<<"\nNo.of Unsucessful transaction = ";
                             g1=ob1[0].z1_();
                            cout<<g1;
                            cout<<"\nCost You Have To pay = ";
                             g1=ob1[0].z2_();
                            cout<<g1;
                        }
                          }
             }while(ch=='y');

    }
    cout<<"\nWant To Go To Administrative Part Or Customer Part(Yes-y,No-n) \n";
    cin>>ch;

    }while(ch=='y');

}
