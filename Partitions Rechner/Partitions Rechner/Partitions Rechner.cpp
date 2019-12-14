


#include <Windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, const char* argv[])
{
	
		// Startmeldung
		cout << "Partitions Rechner\n" << "Finde heraus wo dein letzter Sektor sein muss.\n\n";
		/////////////////////
		int re = 0;
		
		int part_fehler = 0;
		int part_fehler2 = 0;

		double startsektor = 0;
		double startsektor2 = 0;
		double endsektor = 0;
		double benoetigtesektoren = 0;

		double part_groesse_gb = 0;
		double part_groesse_bytee = 0;

		char wiederholung = 's';
		do
		{
		//Abfrage Groesse
		do {
			cout << "Bitte gib an wie gross deine Partitionen sein soll in GiB: ";
			cin >> part_groesse_gb;
			system("cls");


			// Fehler ausgabe
			if (part_groesse_gb <= 0)
			{
				cout << "\n\n\nFalsche eingabe.\nIhre eingabe: " << part_groesse_gb << "\nNegative Zahlen sind nicht erlaubt.\n\n\n";
				part_fehler = 666;
			}
			//////////////////////////
		} while (part_fehler2 == 666);

		// Abfrage Startsektor
		do {
			cout << "Bitte gib deinen ersten Sektor an: ";
			cin >> startsektor;
			system("cls");


			// Fehler ausgabe
			if (startsektor <= 0)
			{
				cout << "\n\n\nFalsche eingabe.\nIhre eingabe: " << startsektor << "\nNegative Zahlen sind nicht erlaubt.\n\n\n";
				part_fehler2 = 666;
			}
			//////////////////////////
		} while (part_fehler2 == 666);


		//Berechnung  von GB in Byte, Wieviele Sektoren diese Bytes benötigen, und den Endsektor
		part_groesse_bytee = part_groesse_gb * 1024 * 1024 * 1024;
		benoetigtesektoren = part_groesse_bytee / 512;
		endsektor = startsektor + benoetigtesektoren;
		////////////////////
		cout << fixed << setprecision(1) << "Dein Endsektor ist: " << endsektor << "\n\n\n\n";

		
		//Programm Wiederholung
		cout << "Noch eine Partition?(Y/N)\n\n";
		cin >> wiederholung;
		

		switch (wiederholung)
		{
		case 'Y':
		case 'y':
			re = 1;
			break;


		case 'N':
		case 'n':
			re = 0;
			break;

		}
	} while (re == 1);

		return 0;
	}