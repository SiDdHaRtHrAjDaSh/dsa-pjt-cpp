#include <iostream>
#include <fstream>
using namespace std;

struct order
{
    int id;
    float bill;
    char hotel_name[20];
};
struct customer
{
    char id[20];
    char name[20];
    char phno[20];
    char email[30];
    char address[100];
    int balance;


}c;
int main()
{
    fstream f;
    f.open("customer.dat",ios::out);
    for(i=0;i<10;i++)
    {

        cin>>c.id;
        cin>>c.name;
        cin>>c.phno;
        cin>>c.email;
        cin>>c.address;
        cin>>c.balance;
        f.write((char*)&c,sizeof(c));
    }
    f.close();

}

