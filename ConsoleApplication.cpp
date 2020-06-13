#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	string wyraz;
	fstream plik;
	string linia;

	while (true)
	{
		if (plik.good() == false)
			cerr << "Plik \" slownik.txt\" nie istnieje!" << endl;
		else
		{
			plik.open("slownik.txt");
			int ile_linii = 0;
			while (getline(plik, linia))
			{
				ile_linii++;
			}
			plik.close();
			cout << "*S l o w n i k* (zawiera " << ile_linii << " hasel.)\n";
			cout << "---------------\n";
			cout << "Wpisz wyraz: ";
			getline(cin, wyraz);

			plik.open("slownik.txt", ios::in);

			while (getline(plik, linia))
			{
				if (linia == wyraz)
				{
					cout << "Wyraz \"" << wyraz << "\" istnieje" << endl << endl;
					wyraz = "";
					break;
				}
			}
			plik.close();

			if (wyraz != "")
			{
				plik.open("slownik.txt", ios::out | ios::app);
				plik << wyraz << endl;
				cout << "Dodano wyraz \"" << wyraz << "\"" << endl << endl;
				plik.close();
			}
			else
			{
				plik.open("slownik.txt");
				plik.close();
			}
		}
		Sleep(1000);
		system("cls");
	}
	return 0;
}