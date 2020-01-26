#include<iostream>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<sstream>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct cust
{
       char name[20];
       char phno[20];
       char email[30];
       char dob[10];
       char nationality[20];
       char state[20];
       char city[20];
       char street[20];
       string zipcode[10];
       char username[20];
       char password[20];
       string orderfile;
       string orderhis;
       string cusID;
       int balance[8];
}S;
struct Redeem
{
       char code[20];
       char value[8];
};

struct history
{
       string resname;
       int cost[7];
};
struct order
{
    char item;
    char price[7];
};
struct orderlist
{
       string OID;
       int price;
       float priority;
       struct orderlist* next;
       struct orderlist* prev;
}*start;
struct node
{
    string ID;
    struct node *left, *right;
};
struct node* root;
char treearr[20][20];




void view_queue()
{
    orderlist *temp = new orderlist;
    temp=start;
    while(temp->next!=NULL)
    {
        cout<<temp->OID<<endl;
        cout<<temp->price<<endl;
        cout<<temp->priority<<endl;
        cout<<endl;
        temp=temp->next;
    }

}

void dq()
{
    orderlist *temp=new orderlist;
    temp=start;
    start=start->next;
    temp->next=NULL;
    temp->prev=NULL;
    delete(temp);
    view_queue();

}

void process_order(string s)
{
     system("CLS");
     cout<<"WELCOME\n-------\n\n";
     cout<<"\n1)VIEW ORDER QUEUE";
     cout<<"\n2)DISPATCH ORDER";
     cout<<"\n3)EXIT";
     int ch;
     cin>>ch;
     do
     {
        switch(ch)
        {
            case 1:view_queue();break;
            case 2:dq();break;
            case 3:goto endo;
        }
        cout<<"\n\nENTER CHOICE:";
        cin>>ch;
     }while(ch!=0);
     endo:
         getch();

}



void neworder(string s)
{
    system("CLS");
    system("color 1a");
    cout<<"\n\nPLACING ORDER\n";
    cout<<"\n\nHOTEL LIST\n----------\n";

    char v[30];
    fstream f2;
    f2.open(s.c_str(),ios::in);
    f2.getline(v,30);
    f2.getline(v,30);

    int a;
     ostringstream str4;

    int random_integer = rand();
    str4 << random_integer;
     string A = str4.str();

     f2.close();
    fstream g;
    g.open(s.c_str(),ios::in);


   char q[30];
   ifstream f;
   f.open("restaurant.txt");
   while(!f.eof())
   {
	f.getline(q,30);
	cout<<q<<endl;
   }

   string P;
   cout<<"Enter restaurant name";
   cin>>P;
   //strcat(p);


   fstream f1;
   char r[30];
   f1.open(P.c_str(),ios::in);
   cout<<"\n\nMENU\n----\n\n";
   while(!f1.eof())
   {
       f1.getline(r,30);
       cout<<r<<endl;
       f1.getline(r,30);
       cout<<r<<endl;
   }
   f1.close();
   string k;
   char ch;
   int cost=0;
   fstream f6;
   fstream fx;
   string ofile;
   string B;
   B="OD";
   string C;
   C=".txt";
   ofile=B+v+A+C;
   cout<<"\nYour order number is:";
   cout<<ofile<<endl;
   fstream f9,f10;
   char e[30];
   int i;
    f9.open(s.c_str(),ios::in);
     for(i=0;i<13;i++)
     {
         f9.getline(e,30);
     }
     string E;
     E=e;
     f10.open(E.c_str(),ios::app);
     f10<<ofile<<endl;

     f9.close();
     f10.close();


   fx.open(ofile.c_str(),ios::out);
   int item=0;
   char l[30],m[20];
   string j;
   string L;
   string w;
   w=P;
   cout<<endl<<w<<endl;
   do
   {
       cout<<"Enter item to be ordered\n";
       cin>>k;

	  f6.open(w.c_str(),ios::in);
	  while(!f6.eof())
	 {
	      f6.getline(l,30);
	      L=l;

	      f6.getline(m,20);
	     if(L==k)
	     {

        fx<<k<<endl;
        fx<<m<<endl;
        j=m;
        cout<<j;
		cost=cost+atoi(j.c_str());
		item++;

	     }
	     f6.close();
	 }
       cout<<"do you want to enter something else:";
       cin>>ch;
   }while(ch!='n');
   fx.close();

   cout<<"\nYOur total price is:"<<cost<<endl;

   int pty;
   pty=cost/item;
   cout<<"\n\n\nORDER PLACED\n";

   cout<<"\nQUEUE\n";

   orderlist *Q=new orderlist;
   Q->priority=pty;
   Q->price=cost;
   Q->OID=ofile;
   orderlist *temp=new orderlist;
   temp=start;
   while(temp->next!=NULL)
   {
        if((Q->priority>=temp->priority) && (Q->priority<=temp->next->priority))
        {
             temp->next->prev=Q;
             Q->next=temp->next;
             temp->next=Q;
             Q->prev=temp;
             break;
        }
        temp=temp->next;


   }
   Q=NULL;
   temp=NULL;
   delete(Q);
   delete(temp);

   view_queue();

}

void topup(string s,int a=0)
{
    cout<<"\nTOPPING UP\n";
    ostringstream str1;

     fstream f;
     int i;
     f.open(s.c_str(),ios::in|ios::out);
     cust S;
     char p[30];
     string q;
     int pos;
     for(i=0;i<14;i++)
     {
         f.getline(p,30);
     }
     pos=f.tellg();
     f.getline(p,30);
     q=p;

     int d;
     d=atoi(q.c_str());
     int l;
     l=a+atoi(q.c_str());
     str1 << l;

     string geek = str1.str();

     char t[30];
     strcpy(t,geek.c_str());
     f.seekp(pos);
     f<<geek<<endl;
     cout<<"\n\nYOUR CURRENT BALANCE IS:"<<geek;
     f.close();


}

void redeem(string s)
{
     char a[20];
     int flag=0;
     cout<<"\nENTER YOUR REDEEM CODE:";
     gets(a);
     fstream f;
     string l;
     char p[20],q[20];
     f.open("redeem.txt",ios::in);
     while(!f.eof())
     {
         f.read(p,20);
         f.read(q,20);
         l=q;
         if(strcmp(p,a)==0)
         {
           topup(s,atoi(l.c_str()));
           flag=1;
           break;
         }

     }
     f.close();
     if(flag==0)
     cout<<"INVALID CODE";
}

void check_balance(string s)
{
     fstream f;
     char p[30];
     int i;
     f.open(s.c_str(),ios::in);
    for(i=0;i<15;i++)
     {

         f.getline(p,30);
     }
     int x;
    f.close();


     cout<<"\nYOUR CURRENT BALANCE IS :"<<p;
     cout<<"\n\n1)TOP UP BALANCE";
     //cout<<"\n2)REDEEM CODE";
     cout<<"\n3)EXIT TO MAIN MENU";
     int a;
     cin>>a;
     switch(a)
     {
         case 1:cout<<"Enter amount to be updated:";int b;
                cin>>b;
                topup(s,b);
                break;
         case 2://redeem(s);break;
         case 3:goto end;
     }
     end:;
 }
void order_history(string s)
{

    cout<<"\n\nYOUR ORDER LIST IS\n";

     fstream f,f1;
     int i;
     char p[30];
     f.open(s.c_str(),ios::in);
     for(i=0;i<13;i++)
     {
         f.getline(p,30);
     }
     string q;
     q=p;
     f.close();
     char r[30];
     fstream f2;
     f1.open(q.c_str(),ios::in);
     while(!f1.eof())
     {
         f1.getline(p,30);
         cout<<p<<endl<<endl<<endl;
         q=p;
         f2.open(q.c_str(),ios::in);
         while(!f2.eof())
         {
             f2.getline(r,30);
             cout<<r<<endl;
         }
     }
     f1.close();
     getch();


}
string a[20];
 int N=0,START=0,END=N-1;


int search_records(char q[])
{
    int i;
    string r;
    r=q;
    for(i=0;i<N;i++)
    {

        if(r==a[i])
            return 1;

    }
}
void view_profile(string s)
{
    fstream f;
    char p[20];
     f.open(s.c_str(),ios::in);
     cout<<"\nYOUR PROFILE DETAILS\n\n";
     while(!f.eof())
     {
         f.getline(p,30);
         cout<<p<<endl;
     }

}

void edit_profile(string s)
{
    cout<<"1)EDIT PHONE NUMBER\n";
    cout<<"2)EDIT EMAIL\n";
    int ch;
    cin>>ch;
    fstream f;
    f.open(s.c_str(),ios::in|ios::out);
    int pos;
    char p[30];

    switch(ch)
    {
        case 1:cout<<"Enter new phone number:";
                char q[30];cin>>q;
                f.getline(p,30);
                pos=f.tellg();
                f<<q<<"\n";
                break;

        case 2:cout<<"Enter new email address:";char e[30];
               cin>>e;
               f.getline(p,30);  f.getline(p,30);
               f<<e<<"\n";
               break;

    }
    f.close();
}

void customer(string s)
{
    next:
    system("CLS");
    system("color 1a");
    cout<<"WELCOME TO CUSTOMER PORTAL";
    cout<<"\nWHAT WOULD YOU LIKE TO DO";
    cout<<"\n1)PLACE NEW ORDER";
    cout<<"\n2)CHECK SWIGGY BALANCE";
    cout<<"\n3)VIEW ORDER HISTORY";
    cout<<"\n4)VIEW PROFILE";
    //cout<<"\n5)EDIT PROFILE";
    cout<<"\n6)LOGOUT";

    int ch;
    cout<<"Enter choice";cin>>ch;
    switch(ch)
    {
	case 1:neworder(s);break;
	case 2:check_balance(s);break;
	case 3:order_history(s);break;
	case 4:view_profile(s);break;
	case 5://edit_profile(s);
	    break;
	case 6:goto endy;
    }

	endy:;
}

void employee()
{
     system("CLS");
     int flag=0;
     fstream f;
     f.open("employee.txt",ios::in);
rettypeid:
     cout<<"\nEnter your employee ID:";
     char ID[20],p[20],q[20];
     cin>>ID;
     while(!f.eof())
     {
         f.getline(p,20);
         if(strcmp(p,ID)==0)
         strcpy(q,p);
         flag=1;
         break;
     }

     if(flag==1)
        process_order(q);
     else
        {
            cout<<"invalid ID enter again";
            goto rettypeid;
        }


}
int search_record(struct node* roota, char key[])
{

    if (roota->ID == key)
       {cout<<"found";
           return 1;}
     if(roota==NULL)
        {cout<<"notfound";return 0;}


    if (roota->ID < key)
        search_record(roota->right, key);

    else
     search_record(roota->left, key);
}
void login()
{
    retrya:
    cout<<"Enter your user name:";
    char q[20];
    cin>>q;

    string s;
    s=q;
    int y;
    y=search_records(q);
    if(y==1)
    {
      	customer(s);
    }
    else
    {cout<<"invalid choice please try again";return;}
}
void sort_bubble()
{
    int i,j;
    string t;
    for(i=0;i<=N;i++)
    for(j=i+1;j<=N;j++)
    {
        if(a[i]>a[j])
           {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
           }
    }
    for(i=0;i<=N;i++)
        cout<<a[i]<<endl;
}

void signup()
{

     char q[30],Q[30];
     int i=0;
     fstream f;
     system("CLS");
     cout<<"WELCOME TO SIGN UP PAGE\n------------------\n\n";
     cout<<"Enter your username:";
     cin>>Q;
     string p;
     p=Q;
     f.open(p.c_str(),ios::out);

     cout<<"ENTER YOUR FULL NAME:\n";
     cin>>q;
     f<<q;
     f<<endl;

     cout<<"ENTER YOUR CONTACT NUMBER:\n";
     cin>>q;
     f<<q;
     f<<"\n";

     cout<<"ENTER YOUR EMAIL ADDRESS:\n";
     cin>>q;
     f<<q;
     f<<"\n";

     cout<<"ENTER YOUR DATE OF BIRTH:\n";
     cin>>q;
     f<<q;
     f<<"\n";

     cout<<"ENTER NATIONALITY:\n";
     cin>>q;
     f<<q;
     f<<"\n";

     cout<<"ENTER STATE:\n";
     cin>>q;
     f<<q;
     f<<"\n";

     cout<<"ENTER YOUR CITY:\n";
     cin>>q;
     f<<q;
     f<<"\n";

     cout<<"ENTER YOUR STREET NAME:\n";
     cin>>q;
     f<<q;
     f<<"\n";

     cout<<"ENTER YOUR ZIP CODE:";
     cin>>q;
     f<<q;
     f<<"\n";

     cout<<"ENTER THE USER NAME:\n";
     cin>>q;
     string u;
     string v;
     v=q;
     u=q;
     f<<q;
     f<<"\n";

     cout<<"ENTER YOUR PASSWORD:";
     cin>>q;
     f<<q;
     f<<"\n";

     u=u+"ofile.txt";
     f<<u;
     f<<"\n";

     v=v+"ohis.txt";
     f<<v;
     f<<"\n";

     f<<"0";
     f<<"\n";

     f.close();
     fstream f1;
     char w[100];
     string h;
     h=p;
     cout<<"\nYOUR PROFILE INFORMATION:\n\n";
     f1.open(p.c_str(),ios::in);
     while(!f1.eof())
     {
         f1.getline(w,100);
         cout<<w<<endl;
     }

     N++;
     ::a[N]=h;


     cout<<endl;
     sort_bubble();

 }




 void createarray()
{

     fstream f;
     char P[20];
     f.open("customer.txt",ios::in);
     while(!f.eof())
     {
	 f.getline(P,20);
	 a[N]=P;
	 N++;
     }
     f.close();
     int i;
     for(i=0;i<=N;i++)
        cout<<a[i]<<endl;
        N=N-1;

}
 node* create_tree(string a[],int START,int END)
 {

    if (START > END)
    return root;


    int mid = (START + END)/2;
    root->ID=a[mid];



    root->left = create_tree(a, START, mid-1);


    root->right = create_tree(a, mid + 1, END);


}



void display()
{
    orderlist *temp=new orderlist;
    temp=start;
    while(temp->next!=NULL)
    {
        cout<<temp->OID<<endl;
        cout<<temp->price<<endl;
        cout<<temp->priority<<endl;
        temp=temp->next;
    }
}

 void create_linkedlist()
 {
     fstream f;
     char p[30][4];
     string q;
     orderlist *temp=new orderlist;

     f.open("orderlist.txt",ios::in);
         f.getline(p[0],30);
         temp->OID=p[0];
         f.getline(p[1],10);
         q=p[1];
         temp->price=atoi(q.c_str());
         f.getline(p[2],10);
         q=p[2];
         temp->priority=atoi(q.c_str());
         temp->next=NULL;
         temp->prev=NULL;
         start=temp;


     while(!f.eof())
     {
         orderlist *temp1=new orderlist;
         f.getline(p[0],30);
         temp1->OID=p[0];
         f.getline(p[1],10);
         q=p[1];
         temp1->price=atoi(q.c_str());
         f.getline(p[2],10);
         q=p[2];
         temp1->priority=atoi(q.c_str());
         temp1->next=NULL;
         temp->next=temp1;
         temp1->prev=temp;
         temp=temp->next;
        temp1=NULL;
        delete(temp1);

     }
     temp=NULL;

     f.close();
     delete(temp);
     display();
}


int main()
{

MAIN:
    system("color a");
    fstream f;
    int i;
    createarray();
    create_tree(a,START,END);
    create_linkedlist();
    system("CLS");
    //system("CLS");
    cout<<"WELCOME";
    getch();
    system("CLS");
    cout<<"WELCOME TO SWIGGY\n";
    cout<<"1) login\n2)signup\n";
    cout<<"\n\nemplyoees pree 3 to login\n";
    cout<<"\n\n\nenter choice:";
    redo:
    int a;cin>>a;
    switch(a)
    {
	case 1: login();break;
	case 2: signup();break;
	case 3: employee();break;
	default: cout<<"invalid Entry";goto redo;break;
    }
    cout<<endl<<endl;

    f.open("customer.txt",ios::trunc);
    for(i=0;i<=N;i++)
    {
        f<<::a[i]<<endl;

    }
    f.close();
    goto MAIN;



 }

