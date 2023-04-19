#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
using namespace std;

struct student
{
    string ime,prezime,index;
};

char tocnia[4]{'a','c','b','c'};
char tocnib[4]{'c','a','b','b'};
char tocnic[4][2] = { {'a', 'c'}, {'c', 'b'}, {'a','b'}, {'a','c'} };

void vnesistudent(student &a)
{
    cout<<"Vnesi ime: "<<endl;
    cin>>a.ime;
    cout<<"Vnesi prezime: "<<endl;
    cin>>a.prezime;
   do
   {
    cout<<"Vnesi indeks: "<<endl;
    cin>>a.index;
   }while(a.index.length()!=3);
}

void zapisodg(fstream &file,char ans1,char ans2,int prasanje)
{
    file<<prasanje<<"."<<ans1<<" "<<ans2<<endl;
}


void proverka(int br,fstream &file)
{
    char ans1,ans2;
    if(br>=1&&br<=8)
        while(ans1!='a'&&ans1!='b'&&ans1!='c')
        {
            cout<<"Vashiot odgovor: ";
            cin>>ans1;
            ans2=' ';

        }
        if(br>8&&br<=12)
        while((ans1!='a'&&ans1!='b'&&ans1!='c')||(ans2!='a'&&ans2!='b'&&ans2!='c')||(ans1==ans2))
        {
            cout<<"Vashiot odgovor: ";
            cin>>ans1;
            cin>>ans2;

        }
        zapisodg(file,ans1,ans2,br);
}
int ocenka(float poeni)
{
    if (poeni >= 0 && poeni <= 24)
        return 5;
    else if (poeni >= 25 && poeni <= 32)
        return 6;
    else if (poeni >= 32.5 && poeni <= 37)
        return 7;
    else if (poeni >= 37.5 && poeni <= 40.5)
        return 8;
    else if (poeni >= 41 && poeni <= 45)
        return 9;
    else if (poeni >= 45.5 && poeni <= 50)
        return 10;
}
int main()
{
    student a;
    vnesistudent(a);

    time_t now = time(0);
    tm* loc=localtime(&now);
    char* dt = ctime(&now);

    float poeni=0;
    string prasanje,indexproverka;
    char ans1,ans2;
    int brojach=0;
    const string ucenik=a.ime+a.prezime+"INKI"+a.index+".txt";
    fstream file,test,log;

     log.open("Students.txt",ios::in);
         while(getline(log,prasanje))
         {
             brojach++;
             copy(prasanje.end() - 3, prasanje.end(), std::back_inserter(indexproverka));
             if(indexproverka==a.index)
             {
                 cout<<"Vekje ste pravele test!"<<endl;
                 return EXIT_FAILURE;
             }
             indexproverka.erase();
         }
         cout<<indexproverka;
         log.close();
         log.open("Students.txt",ios::app);
         log<<"\n"<<brojach<<"."<<loc->tm_hour<<":"<<loc->tm_min<<":"<<loc->tm_sec<<"   "<<a.ime<<"\t"<<a.prezime<<"\t"<<a.index;
         log.close();

    file.open(ucenik,ios::out);
    brojach=1;
    test.open("prasanja.txt",ios::in);

    while(getline(test,prasanje)&&brojach<13)
    {
        for(int i=0;i<prasanje.length();i++)
        {
            if(prasanje[i]==';')
                cout<<endl;
            else
            cout<<prasanje[i];
        }
        cout<<endl;
        proverka(brojach,file);

        brojach++;
    }
        test.close();
        file.close();

        file.open(ucenik,ios::in);
        brojach=1;
         while(getline(file,prasanje))
         {
             for(int i=0;i<prasanje.length();i++)
             {
                 if(brojach<=4&&prasanje[i]==tocnia[brojach-1])
                    poeni=poeni+1.5;
                 if(brojach>4&&brojach<=8&&prasanje[i]==tocnib[brojach-5])
                    poeni=poeni+3.0;
                 if(brojach>8&&brojach<=12)
                    if((prasanje[i]==tocnic[brojach-9][0]&&prasanje[i+2]==tocnic[brojach-9][1])||(prasanje[i+2]==tocnic[brojach-9][0]&&prasanje[i]==tocnic[brojach-9][1]))
                    poeni=poeni+8.0;
             }
             brojach++;

         }
         file.close();
         now = time(0);
         loc=localtime(&now);
         file.open(ucenik,ios::app);
         file << "\nIme: " << a.ime << "\nPrezime: " << a.prezime << "\nIndeks: INKI" << a.index << "\nVreme na start: " << dt<<endl;
         file<<"Vreme na zavrshuvanje: "<<loc->tm_hour<<":"<<loc->tm_min<<":"<<loc->tm_sec<<endl;
         file<<"Osvoeni poeni: "<<poeni<<endl;
         file<<"Ocenka: "<<ocenka(poeni);
         file.close();




    return 0;
}
