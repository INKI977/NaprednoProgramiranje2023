#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

struct temp
{
    std::string grad;
    int den, nokj;
    void sort_struct(std::vector<temp> &a,int n)
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (a.at(i).den < a.at(j).den)
                {
                    std::swap(a.at(i), a.at(j));
                }
                else if (a.at(i).nokj < a.at(j).nokj && a.at(i).den == a.at(j).den)
                {
                    std::swap(a.at(i), a.at(j));
                }
            }
        }
    }
};

int main()
{
    std::vector<temp>zapis;
    std::fstream a;
    std::vector<temp>::iterator it = zapis.begin();

    zapis.push_back({ "Bitola",22,9 });//Temperaturi spored accuweather.com
    zapis.push_back({ "Skopje",26,11 });
    zapis.push_back({ "Prilep",24,10 });
    zapis.push_back({ "Ohrid",22,8 });
    zapis.push_back({ "Veles",26,11 });
    zapis.push_back({ "Kicevo",26,10 });
    zapis.push_back({ "Kocani",28,10 });
    zapis.push_back({ "Shtip",26,10 });
    zapis.push_back({ "Debar",18,5 });
    zapis.push_back({ "Tetovo",25,12 });

    for (int i = 0; i<10; i++)
        zapis.at(i).sort_struct(zapis, i + 1);

    std::cout << "Temperaturi vo Makedonija (07.05.2023)" << std::endl;
    for (it = zapis.begin(); it != zapis.end(); ++it)
    {
        std::cout << it->grad<< "\tdenska temperatura " << it->den << " C\tvecherna temperatura " << it->nokj<<" C" << std::endl;
    };
    a.open("temperaturi.txt", std::ios::out);
    for (it = zapis.begin(); it != zapis.end(); ++it)
    {
        a << it->grad << "\tdenska temperatura " << it->den << " C\tvecherna temperatura " << it->nokj << " C\n";
    };
    a.close();

}
