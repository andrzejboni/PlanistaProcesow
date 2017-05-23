// PLANISTAVERVER2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct osoba
{
	int wiek;
	osoba *kolejna;
	osoba();
};

osoba::osoba()
{
	kolejna = 0;
}

struct lista
{
	osoba *pierwsza;
	osoba *ostatnia;



	void dodaj(int wiek);
	void usun(int nr);

	void wyswietl_liste();
	void czyszczenie();

	int pobierz();
	int priorytet;

	lista();

};

lista::lista()
{
	pierwsza = 0;		// kontruktory
	ostatnia = 0;
	priorytet = 0;
}



int lista::pobierz()
{
	int wynik = pierwsza->wiek;
	ostatnia = pierwsza;
	pierwsza = pierwsza->kolejna;
	return wynik;
}

void lista::wyswietl_liste()
{
	osoba *temp = pierwsza;
	cout << priorytet << ": ";

	if (pierwsza == NULL)
	{
		cout << endl;
		return;
	}

	while (temp != ostatnia)
	{
		cout << temp->wiek << ' ';
		temp = temp->kolejna;
	}
	cout << ostatnia->wiek;
	cout << endl;
}

void lista::usun(int nr)
{
	if (pierwsza == NULL)
	{
		return;
	}
	if (pierwsza == ostatnia)
	{
		if (pierwsza->wiek == nr)
		{
			delete pierwsza;
			pierwsza = NULL;
			ostatnia = NULL;
		}
		return;
	}
	else
	{
		osoba *temp = pierwsza;
		osoba *poprzednia = ostatnia;

		do
		{
			if (temp->wiek == nr)
			{
				poprzednia->kolejna = temp->kolejna;
				if (temp == pierwsza)
				{
					pierwsza = temp->kolejna;
				}
				if (temp == ostatnia)
				{
					ostatnia = poprzednia;
				}
				delete temp;
				return;
			}
			poprzednia = poprzednia->kolejna;
			temp = temp->kolejna;

		} while (temp != pierwsza);
	}
}

void lista::dodaj(int wiek)

{
	if (pierwsza == NULL)
	{
		osoba *nowa = new osoba;
		nowa->kolejna = nowa;
		nowa->wiek = wiek;
		ostatnia = nowa;
		pierwsza = nowa;
	}
	else
	{
		osoba *nowa = new osoba;
		nowa->wiek = wiek;
		nowa->kolejna = pierwsza;

		ostatnia->kolejna = nowa;
		ostatnia = nowa;
	}
}



void lista::czyszczenie()
{
	while (pierwsza != NULL)
	{
		int id;
		id = pierwsza->wiek;
		usun(id);
	}
}

int main()
{
	char wczytaj[100];
	lista baza[3];
	baza[0].priorytet = 1;
	baza[1].priorytet = 0;
	baza[2].priorytet = -1;
	while (cin.good())
	{
		cin >> wczytaj;
		switch (wczytaj[0])
		{
		case 'n':
		{
			if (baza[0].pierwsza != NULL)
			{
				int wynik = baza[0].pobierz();
				cout << wynik;
			}

			else if (baza[1].pierwsza != NULL)
			{
				int wynik2 = baza[1].pobierz();
				cout << wynik2;
			}
			else if (baza[2].pierwsza != NULL)
			{
				int wynik3 = baza[2].pobierz();
				cout << wynik3;
			}
			else
			{
				cout << "idle";
			}
			cout << endl;
			break;
		}
		case 'c':
		{
			int id, priorytet2;
			cin >> id >> priorytet2;
			if (priorytet2 == 1)
			{
				baza[0].dodaj(id);

			}
			if (priorytet2 == 0)
			{
				baza[1].dodaj(id);
			}
			if (priorytet2 == -1)
			{
				baza[2].dodaj(id);
			}
			break;
		}
		case 't':
		{
			int id;
			cin >> id;
			for (int i = 0; i < 3; i++)
			{
				baza[i].usun(id);
			}
			break;
		}
		case 'p':
		{
			int id, priorytet3;
			cin >> id >> priorytet3;
			for (int i = 0; i < 3; i++)
			{
				baza[i].usun(id);
			}

			if (priorytet3 == 1)
			{
				baza[0].dodaj(id);
			}

			if (priorytet3 == 0)
			{
				baza[1].dodaj(id);
			}

			if (priorytet3 == -1)
			{
				baza[2].dodaj(id);
			}
			break;
		}
		case 'l':
		{
			baza[0].wyswietl_liste();
			baza[1].wyswietl_liste();
			baza[2].wyswietl_liste();
			break;
		}
		}
	}

	baza[0].czyszczenie();
	baza[1].czyszczenie();
	baza[2].czyszczenie();
	return 0;

}
