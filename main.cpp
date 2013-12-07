/*##############################################

Ein "Kodeknacker"

##############################################*/



#include <iostream>

using namespace std;



//die Prototypen für die Funktionen

void dreherKnacken(string);

void caesarKnacken(string);

void gartenzaunKnacken(string);



//die Funktion zum Umdrehen

void dreherKnacken(string kette)

{

	//die Länge der ursprünglichen Zeichenkette ermitteln

	int laenge;

	laenge = kette.length();

	//length liefert die "echte" Länge

	//Daher muss 1 abgezogen werden

	laenge = laenge - 1;



    cout << "Das Umdrehen ergibt: " << endl;



	//die Zeichen von hinten nach vorne ausgeben

	for (int zaehler = laenge; zaehler >= 0; zaehler--)

        cout << kette[zaehler];



    cout << endl << endl;

}



//die Funktion zum Knacken der Cäsar-Verschlüsselung

void caesarKnacken(string kette)

{

	int laenge, verschiebung;



	//die Länge der ursprünglichen Zeichenkette ermitteln

	laenge = kette.length();

    cout << "Durchprobieren der Caesar-Verschluesselungen" << endl;



    //alle Verschiebewerte von 1 bis 255 durchgehen

    for (verschiebung = 1; verschiebung <= 255; verschiebung++)

    {

        cout << "Mit der Verschiebezahl " << verschiebung << " ist das Ergebnis : ";



        //jedes Zeichen um den angegebenen Wert verschieben, diesmal aber nach links

        for (int zaehler = 0; zaehler < laenge; zaehler++)

            cout << static_cast<char>(kette[zaehler] - verschiebung);



        cout << endl;



        //alle 10 Ausgaben auf eine Eingabe warten

        if (verschiebung % 10 == 0)

            getchar();

    }



    cout << endl << endl;

}



void gartenzaunKnacken(string kette)

{

	string dekodiert, teil1, teil2;

	int laenge;

	int mitte;



	//die Länge der ursprünglichen Zeichenkette ermitteln

	laenge = kette.length();



	//die Mitte finden

	mitte = laenge / 2;



	//wenn es eine ungerade Anzahl ist, noch 1 addieren

	if (laenge % 2 != 0)

        mitte++;



    //die Zeichenkette zerlegen

    teil1 = kette.substr(0, mitte);

    teil2 = kette.substr(mitte, laenge);



	for (int zaehler = 0; zaehler < laenge; zaehler++)

	{

		//Zeichen mit einem geraden Index kommen in die erste Zeichenkette

		if (zaehler % 2 == 0)

			dekodiert.push_back(teil1[zaehler / 2]);

		//Zeichen mit einem ungeraden Index kommen in die zweite Zeichenkette

		else

			dekodiert.push_back(teil2[zaehler / 2]);

	}

    cout << "Der Versuch mit der Gartenzaunverschluesselung ergibt: " << endl;

	cout << dekodiert << endl;

}





int main()

{

	string eingabe;



    //Die ursprüngliche Zeichenkette einlesen

	cout << "Bitte geben Sie eine Zeichenkette ein (ohne Leerzeichen): ";

	cin >> eingabe;

	cout << "Die urspruengliche Zeichenkette ist: " << eingabe << endl << endl;



    //die verschiedenen Ansätze ausprobieren

	//dreherKnacken(eingabe);

	caesarKnacken(eingabe);

	//gartenzaunKnacken(eingabe);



    return 0;

}







