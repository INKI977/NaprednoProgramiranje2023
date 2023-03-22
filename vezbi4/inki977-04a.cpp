#include <iostream>

using namespace std;
void name(char* a)
{
*a='I';
a++;
*a='N';
a++;
*a='K';
a++;
*a='I';
}
void lastname(char* a)
{
*a= '9';
a++;
*a='7';
a++;
*a='7';
}
int main() {
   char ime[]{'h','r','i','s','t','i','j','a','n'};
   char prezime[]{'g','o','r','k','o','v'};
   for(char i:ime)
   cout<<i;
   cout<<endl;
   for(char i:prezime)
   cout<<i;
   name(ime);
   lastname(prezime);
   cout<<endl;
   for(char i:ime)
   cout<<i;
   cout<<endl;
   for(char i:prezime)
   cout<<i;
}