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
		plik.open("slownik.txt");
		int ile_linii = 0;
		int pusta = 0;
		while (getline(plik, linia))
			ile_linii++;
		plik.close();

		cout << "# S l o w n i k  (zawiera " << ile_linii << " hasel.).\t*q -wyjscie (exit)\n";
		cout << "---------------\n";
		cout << "Wpisz wyraz: ";
		getline(cin, wyraz);

		if (wyraz == "q")
			break;

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

		Sleep(500);
		system("cls");
	}
	return 0;
}
//njumen72