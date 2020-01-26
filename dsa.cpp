#include<iostream>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string>
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
       char zipcode[10];
       string username[20];
       char password[20];
       string orderfile;
       string orderhis;
       string cusID;
       int balance;
};
struct Redeem
{
       char code[20];
       int value;
};

struct history
{
       string resname;
       int cost;
};
struct order
{
    char item;
    int price;
};
struct orderlist
{
       string OID;
       int price;
       double priority;
       struct orderlist* next;
       struct orderlist* previous;
}*start;
struct Node
{
    string ID;
    struct Node *left, *right;
};
struct Node* root;
char treearr[20][20];




void view_queue()
{
    orderlist *temp = new orderlist;
    temp=start;
    while(temp->next!=NULL)
    {
        cout<<temp->OID;
        cout<<temp->price;
        cout<<temp->priority;
        cout<<endl;
        temp=temp->next;
    }
    getch();
}
void dq()
{
    orderlist *temp=new orderlist;
    temp=start;
    start=start->next;
    temp->next=NULL;
    temp->previous=NULL;
    delete(temp);
    view_queue();

}

void process_order()
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
            case 2:dq();
            case 3:goto endo;
        }
     }while(ch!=0);
     endo:
         getch();

}

void neworder(char g[])
{
   char p[20],q[20];
   ifstream f;
   f.open("restaurant.txt");
   while(!f.eof())
   {
	f.read(q,20);
	puts(q);
   }

   cout<<"Enter restaurant name";
   gets(p);
   strcat(p,".dat");
   string P;
   P=p;
   fstream f1;
   order s;

   f1.open(P.c_str(),ios::in);
   while(!f1.eof())
   {
       f1.read((char*)&s,sizeof(s));
       cout<<s.item<<"\t"<<s.price<<"\n";
       f1.close();
   }
   char k[20];
   char ch;
   int cost;
   fstream fx;
   fx.open("ofile.dat",ios::app);
   int item=0;
   do
   {
       cout<<"Enter item to be ordered\n";
       gets(k);

	  f1.open(p,ios::in);
	  while(!f1.eof())
	 {
	      f1.read((char*)&s,sizeof(s));
	     if(strcmp(s,k)==0)
	     {
        fx.write((char*)&s,sizeof(s));
		cost+=s.price;
		item++;

	     }
	     f1.close();
	 }
	 fx.write((char*)&cost,sizeof(cost));
       cout<<"do you want to enter something else:";
       cin>>ch;
   }while(ch!='n');

   cout<<"YOur total price is:"<<cost;
   int pty;
   pty=cost/item;
   orderlist *Q=new orderlist;
   Q->priority=pty;
   Q->price=cost;
   Q->item=item;
   strcpy(Q->OID,ofile);
   orderlist *temp=new orderlist;
   temp=start;
   while(temp->next!=NULL)
   {
        if((Q->priority>=temp->priority) && (Q->priority<=temp->next->priority))
        {
             temp->next->previous=Q;
             Q->next=temp->next;
             temp->next=Q;
             Q->previous=temp;
        }

   }

}

void topup(char s[],int a=0)
{
     fstream f;
     f.open(s,ios::in,ios::out);
     cust S;
     int pos;
     pos=f.tellg();
     f.read((char*)&S,sizeof(S));
     S->balance+=a;
     f.seekg(pos);
     f.write((char*)&S,sizeof(S));
     cout<<"\n\nYOUR CURRENT BALANCE IS:"<<S->balance;


}

void redeem(char s[])
{
     char a[20];
     int flag=0;
     cout<<"\nENTER YOUR REDEEM CODE:";
     gets(a);
     Redeem R;
     f.open("redeem.dat",ios::in);
     while(!f.eof())
     {
         f.read((char*)&R,sizeof(R));
         if(strcmp(R->code,a)==0)
         {
           topup(s,R->value);
           flag=1;
           break;
         }

     }
     f.close();
     if(flag==0)
     cout<<"INVALID CODE";
}

void check_balance(char s[])
{
     fstream f;
     f.open(s,ios::in);
     cust S;
     f.read((char*)&S,sizeof(S));
     cout<<"\nYOUR CURRENT BALANCE IS :"<<S->balance;
     cout<<"\n\n1)TOP UP BALANCE";
     cout<<"\n2)REDEEM CODE";
     cout<<"\n3)GIFT SwIGGY BaLANCE";
     cout<<"\n4)EXIT TO MAIN MENU";
     int a;
     cin>>a;
     switch(a)
     {
         case 1:cout<<"Enter amount to be updated:";
                cin>>b;
                topup(s,b);
                break;
         case 2:redeem();break;
         case 3:gift();break;
         case 4:goto end;
     }
     end:
 }
void view_history(string s)
{
     cust S;
     history h;
     fstream f,f1;
     f.open(s.c_str(),ios::in);
     f.read((char*)&S,sizeof(S));
     f1.open(S.orderhis.c_str(),ios::in);
     while(!f1.eof())
     {
         f.read((char*)&h,sizeof(h));
         cout<<h.resname<<"\t"<<h.price<<endl;
     }
     f1.close();
     f.close();
     getch();


}
void view_profile(string s)
{
    cust S;
     history h;
     fstream f,f1;
     f.open(s.c_str(),ios::in);
     f.read((char*)&S,sizeof(S));
        cout<<S.name[20]<<endl;
        cout<<S.phno[20]<<endl;
        cout<<S.email[30]<<endl;
        cout<<S.dob[10]<<endl;
        cout<<S.nationality[20]<<endl;
        cout<<S.state[20]<<endl;
        cout<<S.city[20]<<endl;
        cout<<S.street[20]<<endl;
        cout<<S.zipcode[10]<<endl;
        cout<<S.username[20]<<endl;
        cout<<S.password[20]<<endl;
        cout<<S.orderfile<<endl;
        cout<<S.orderhis<<endl;
        cout<<S.cusID<<endl;
        cout<<S.balance<<endl;



}

void edit_profile(string s);
{
    cout<<"1)EDIT ADDRESS\n";
    cout<<"2)EDIT PHONE NUMBER\n";
    cout<<"3)EDIT EMAIL\n";
    int ch;
    cust S;
    f.open(s.c_str(),ios::in,ios::out);
    int pos;
    pos=f.tellg();
    f.read((char*)&S,sizeof(S));

    switch(ch)
    {
        case 3:cout<<"Enter new email address:";char e[20];
               cin>>e;strcpy(S.email,e);
               f.seekp(pos);
               f.write((char*)&S,sizeof(S));
               break;
        case 2:cout<<"Enter new state:"; char st[20];cin>>st;strcpy(S.state,st);
                cout<<"Enter new city:";char c[20];cin>>c;strcpy(S.city,c);
                cout<<"Enter new street:";char stre[20];cin>>stre;strcpy(S.street,stre);
                f.seekp(pos);
                f.write((char*)&S,sizeof(S));
                break;
        case 1: cout<<"Enter new mobile number:";char mob[20];cin>>mob;strcpy(S.phno,mob);break;
    }
    f.close();
}

void customer(string s)
{

    next:

    cout<<"WELCOME TO CUSTOMER PORTAL";
    cout<<"\nWHAT WOULD YOU LIKE TO DO";
    cout<<"\n1)PLACE NEW ORDER";
    cout<<"\n2)CHECK SWIGGY BALANCE";
    cout<<"\n3)VIEW ORDER HISTORY";
    cout<<"\n4)VIEW PROFILE";
    cout<<"\n5)EDIT PROFILE";
    cout<<"\n6)LOGOUT";

    int ch;
    cout<<"Enter choice";cin>>ch;
    switch(ch)
    {
	case 1:neworder(s);break;
	case 2:checkbalance(s);break;
	case 3:orderhistory(s);break;
	case 4:view_profile(s);break;
	case 5:edit_profile(s);break;
	case 6:goto end;
    }

	end;
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
     gets(ID);
     while(!f.eof())
     {
         f.read(p,20);
         if(strcmp(p,ID)==0)
         strcpy(q,p);
         flag=1;
         break;
     }

     if(flag==1)
        processorder(q);
     else
        {
            cout<<"invalid ID enter again";
            goto rettypeid;
        }


}

int search_record(struct node* root, string key)
{

    if (root->key == key)
       return 1;
     if(root==NULL)
        return 0;


    if (root->key < key)
        search_record(root->right, key);

    else
     search_record(root->left, key);
}
void login()
{
    retrya:
    cout<<"Enter your user name:";
    string s,cin>>s;
    int y;
    y=search_record(root,s);
    if(y==1)
    {
      	customer(s);
    }
    else
    {cout<<"invalid choice please try again";return;}
}

void signup()
{
     clrscr();
     cust s;
     char q[20];
     int i=0;
     cout<<"WELCOME TO SIGN UP PAGE\n------------------\n\n";
     cout<<"ENTER YOUR FULL NAME:\n";
     gets(s.name);
     cout<<"ENTER YOUR CONTACT NUMBER:\n";
     gets(s.phno);
     q[i++]=s.phno[0];
     q[i++]=s.phno[1];
     q[i++]=s.phno[2];
     cout<<"ENTER YOUR EMAIL ADDRESS:\n";
     gets(s.email);
     cout<<"ENTER YOUR DATE OF BIRTH:\n";
     gets(s.dob);
     q[i++]=s.dob[0];
     q[i++]=s.dob[1];
     q[i++]=s.dob[3];
     q[i++]=s.dob[4];
     cout<<"ENTER NATIONALITY:\n";
     gets(s.nationality);
     cout<<"ENTER STATE:\n";
     gets(s.state);
     q[i++]=s.state[0];
     q[i++]=s.state[1];
     cout<<"ENTER YOUR CITY:\n";
     gets(s.city);
     cout<<"ENTER YOUR STREET NAME:\n";
     gets(s.street);
     cout<<"ENTER YOUR ZIP CODE:";
     gets(s.zipcode);
     q[i++]=s.zipcode[0];
     q[i++]=s.zipcode[1];
     q[i++]=s.zipcode[2];
     cout<<"ENTER THE USER NAME:\n";
     gets(s.uname);
     cout<<"ENTER YOUR PASSWORD:";
     gets(s.password);
     q[i]='\0';
     strcat(q,"dat");
     s.orderfile=q;
     char Q[20];
     s.balance=0;
     strcat(q,"his.dat");
     s.orderhis=q;
     fstream f,f1;
     char p[20];
     f1.open("customer.txt",ios::app);
     strcpy(p,s.uname.c_str());
     f.write(p,20);
     f.open(s.uname.c_str(),ios::out);
     f.write((char*)&s,sizeof(s));
     f.close();
     f1.close();


 }




 string a[20];
 int N=0,START=0,END=N-1;



 void createarray()
{
     fstream f;
     char P[20];
     f.open("customers.txt",ios::in);
     while(!f.eof())
     {
	 f.read(P,20);
	 a[N]=P;
	 N++;
     }
     f.close();

}
 void create_tree(string a[],int START,int END)
 {
    /* Base Case */
    if (START > END)
    return NULL;

    /* Get the middle element and make it root */
    int mid = (START + END)/2;
    root->data=a[mid];


    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = create_tree(a, START, mid-1);

    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = create_tree(a, mid + 1, END);

    return root;
}




 void create_linkedlist()
 {
     fstream f;
     orderlist o;
     orderlist *temp=new orderlist;
     orderlist *temp1=new orderlist;
     f.open("orderlist.dat",ios::in);
     f.read((char*)&o,sizeof(o));
         temp->OID=o.OID;
         temp->price=o.price;
         temp->priority=o.priority;
         temp->next=NULL;
         temp->prev=NULL;
         start=temp;
     while(!f.eof())
     {
         f.read((char*)&o,sizeof(o));
         temp1->OID=o.OID;
         temp1->price=o.price;
         temp1->priority=o.priority;
         temp1->next=NULL;
         temp->next=temp1;
         temp1->prev=temp;
         temp=temp->next;

     }
     temp=NULL;
     temp1=NULL;
     delete(temp);delete(temp1);
}


void main()
{

    createarr();
    create_tree();
    create_linkedlist();

    clrscr();
    cout<<"WELCOME";
    getch();
    clrscr();
    cout<<"WELCOME TO SWIGGY\n";
    cout<<"1) sign up\n2)login\n";
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



 }

