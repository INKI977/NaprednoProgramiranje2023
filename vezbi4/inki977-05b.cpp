#include <iostream>
using namespace std;

int main()
{
    char pesna[]="creepin-the weekend";
    char *a=&pesna[0];
    char *b;
    int p;
    
    cout<<"pocetna pozicija: "<<*a<<endl;
    cout<<"pocetna adresa: "<<&a<<endl;
    for(int i=0;i<sizeof(pesna);i++)
    {
        cout<<*a;
        a++;
        if(*a=='-')
        p=++i;
    }
    cout<<endl;
    cout<<++p<<endl;
     b=&pesna[8];
    cout<<"nova pocetna pozicija: "<<*b<<endl;
    cout<<"nova pocetna adresa: "<<&b<<endl;
    for(int i=p;i<sizeof(pesna)-1;i++)
    {
        cout<<*b;
        b++;
    }
    cout<<endl;
    
}