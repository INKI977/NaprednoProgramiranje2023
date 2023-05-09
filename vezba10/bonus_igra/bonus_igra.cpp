#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>

using namespace std;

char table[4][4] = { {' ','1','2','3'},{'1'},{'2'}, {'3'}};


void printmtx()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << table[i][j] << "\t|";
		}
		cout << endl;
		cout << "================================";
		cout << endl;
	}
}

enum izbor
{
	iks = 1,nula
};

class Player
{
public:
	string ime;
	void setchoice(int i)
	{
		switch (i)
		{
		case 1:
			x = static_cast<izbor>(1);
			break;
		case 2:
			x = static_cast<izbor>(2);
			break;
		}
	}
	void input()
	{
		int a, b;
		switch (x)
		{
		case iks:
			do
			{
				cin >> a;
				cin >> b;
			} while (table[a][b] == 'X' || table[a][b] == '0');
			table[a][b] = 'X';
			break;
		case nula:
			do
			{
				cin >> a;
				cin >> b;
			} while (table[a][b] == 'X' || table[a][b] == '0');
			table[a][b] = '0';
			break;
		}
	}
	bool checkwin()
	{
		string a, b, c, d, e, f, g, h;
		for (int i = 1, j = 3; i <= 3; i++, j--)
		{
			a.push_back(table[1][i]);
			b.push_back(table[2][i]);
			c.push_back(table[2][i]);

			d.push_back(table[i][1]);
			e.push_back(table[i][2]);
			f.push_back(table[i][3]);

			g.push_back(table[i][i]);
			h.push_back(table[i][j]);
		}
		if ((a == "XXX" || b == "XXX" || c == "XXX" || d == "XXX" || e == "XXX" || f == "XXX" || g == "XXX" || h == "XXX") && x == 1)
		{
			win = true;
			return true;
		}
		else if ((a == "000" || b == "000" || c == "000" || e == "000" || f == "000" || g == "000" || h == "000") && x == 2)
		{
			win = true;
			return true;
		}
		else
			return false;

	}
	void ai_input()
	{
		int a, b;
		do
		{
			a = rand() % 3 + 1;
			b = rand() % 3 + 1;
		} while (table[a][b] == 'X' || table[a][b] == '0');
		switch (x)
		{
		case iks:
			table[a][b] = 'X';
			break;
		case nula:
			table[a][b] = '0';
			break;
		}
	}
private:
	izbor x;
	bool win = false;
};


int main()
{
	srand(time(NULL));
	Player p1;
	fstream a;
	int prom,izb;
	do
	{
		cout << "Izberi 1 za 1v1, izberi 2 za igranje protiv kompjuter\n";
		cin >> prom;
	} while (prom < 1 || prom > 2);
	system("cls");
	do
	{
		cout << "Izberi 1 za X ili 2 za 0\n";
		cin >> izb;
		p1.setchoice(izb);
	} while (izb < 1 || izb>2);
	system("cls");

	Player p2;
	if (izb == 1)
		p2.setchoice(2);
	else
		p2.setchoice(1);

	switch (prom)
	{
	case 1:

		cout << "Vnesi ime za p1\n";
		cin >> p1.ime;
		cout << "Vnesi ime za p2\n";
		cin >> p2.ime;
		a.open("score.txt", ios::app);
		system("cls");

		for (int i = 1; i <= 9; i++)
		{
			printmtx();
			if (i % 2 == 1)
			{
				cout << p1.ime << " da vnesi koordinati\n";
				p1.input();
			}
			else
			{
				cout << p2.ime << " da vnesi koordinati\n";
				p2.input();
			}
			
			system("cls");
			
			if (p1.checkwin() && i > 3)
			{
				cout << "Pobedi " << p1.ime << endl;
				a << p1.ime << " vs " << p2.ime << " pobedi: " << p1.ime<< "\n";
				break;
			}
			else if (p2.checkwin() && i > 3)
			{
				cout << "Pobedi " << p2.ime << endl;
				a << p1.ime << " vs " << p2.ime << " pobedi: " << p2.ime << "\n";
				break;
			}
		}

		
			
		if (!p1.checkwin() && !p2.checkwin())
			a << p1.ime << " vs " << p2.ime << " rezultatot e nereshen";

		a.close();
		break;
	case 2:

		a.open("score.txt", ios::app);
		p2.ime = "AI";
		cout << "Vnesi ime za p1\n";
		cin >> p1.ime;
		for (int i = 1; i <= 9; i++)
		{
			printmtx();
			if (i % 2 == 1)
			{
				cout << p1.ime << " da vnesi koordinati\n";
				p1.input();
			}
			else
			{
				p2.ai_input();
			}

			if (p1.checkwin() && i > 3)
			{
				cout << "Pobedi " << p1.ime << endl;
				a << p1.ime << " vs " << p2.ime << " pobedi: " << p1.ime << "\n";
				break;
			}
			else if (p2.checkwin() && i > 3)
			{
				cout << "Pobedi " << p2.ime << endl;
				a << p1.ime << " vs " << p2.ime << " pobedi: " << p2.ime << "\n";
				break;
			}

			system("cls");
		}

		
		if (!p1.checkwin() && !p2.checkwin())
			a << p1.ime << " vs " << p2.ime << " rezultatot e nereshen\n";
		
		a.close();
		break;
	}
}