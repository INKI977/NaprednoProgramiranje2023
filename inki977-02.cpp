#include <iostream>
#include <time.h>

using namespace std;
// deklarirana enumeracija za boja
enum BOJA{
srce,
detelina,
baklava,
list,
crn,
crven
};
// deklarirana enumeracija za brojki
enum broj{
A,
DVA,
TRI,
CETIRI,
PET,
SEST,
SEDUM,
OSUM,
DEVET,
DESED,
J,
Q,
K,
JK
};
// deklarirana struktura koja vo sebe sodrzhi informacija za bojata na kartata i vrednosta
struct karta{
BOJA boja;
broj vrednost;
};

// ovde se koristi Fisher-Yates algoritam za meshanje na kartite, se izbira sluchaen broj pomegju 0 i momentalniot indeks na nizata i tie dva se menuvaat,
// so toa se postignuva meshanje na kartite
void shuffle(karta spil[]) {
for (int i=1; i<54; i++) {
int nov = rand() % i;
swap(spil[i], spil[nov]);
}
}
// funkcija za prikazhuvanje na kartite, se koristi switch bidejki dokolku pobarame direktno pechatenje na bojata ke dobieme brojka, na primer za srce 0
void display(karta spil[],int golemina) 
{
    for (int i=0; i<golemina; i++)
    {

    switch (spil[i].boja) 
    {
        case srce:
        cout<<"Srce, ";
        break;
        case baklava:
        cout<<"Baklava, ";
        break;
        case detelina:
        cout<<"Detelina, ";
        break;
        case list:
        cout<<"List, ";
        break;
        case crn:
        cout<<"Crn ";
        break;
        case crven:
        cout<<"Crven ";
    }
    switch (spil[i].vrednost)
    {
        case A:
        cout<<"A\n";
        break;
        case J:
        cout<<"J\n";
        break;
        case K:
        cout<<"K\n";
        break;
        case JK:
        cout<<"Joker\n";
        break;
        case Q:
        cout<<"Q\n";
        break;
        default:
        cout<<spil[i].vrednost+1<<endl;//dokolku ne se pecatat specijalnite karakteri, se vrshi inkrementiranje bidejki vo enumeraciite sekoj chlen zapochnnuva so 0 dokolku ne se specificira poinaku
    }
    }
}

int main() {
srand(time(0));//srand e funkcija koja ja postavuva pocetnata vrednost za generiranje na sluchajni broevi dokolku ne se promeni nejzinata vrednost e 1, time(0) go vrakja momentalnoto vreme vo sekundi

karta spil[54];
// popolnuvanje na spilot so pomosh na 2 for cikluci edniot za boite drugiot za brojkite
int a=0;
for (int j=srce; j<crn; j++)
{
    for (int i=A; i<JK; i++) 
        {
            spil[a].boja=static_cast<BOJA>(j);//za da se dodelat broevite na promenlivite od strukturata tie prvo mora da se kastiraat od integer vo boja ili broj
            spil[a].vrednost=static_cast<broj>(i);
            a++;
        }
}
spil[52].boja=crn;
spil[52].vrednost=JK;
spil[53].boja=crven;
spil[53].vrednost=JK;

display(spil,54);
shuffle(spil);
cout<<endl;
display(spil,54);

return 0;
}