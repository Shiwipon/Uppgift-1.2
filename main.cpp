#include <iostream>				/* De flesta funktioner vi ska anv�nda */
#include <cstdlib>				/* Random generator */
#include <ctime>				/* Time for super random mode */
/* Jag l�rde mig detta fr�n https://www.youtube.com/watch?v=naXUIEAIt4U och http://www.cplusplus.com/reference/cstdlib/rand/ */

using namespace std;

int main() {
	setlocale(LC_ALL,"swedish");
	srand (time(0)); /* Generate a seed based on time / Skapar en 'seed' baserad p� tid som anv�nds till random. */

	//H�r kommer alla variabler som vi ska anv�nda. 
	int loop_count = 0;				/* Antalet gissar */
	int max_number = 100;			/* H�gste nummret, och f�r inte vara mer �n 100 */
	int min_number = 1;				/* L�gsta nummret, f�r inte vara mindre �n 1 */	
	int randomnumber;				/* Nummret datorn ska gissa */
	int menu_choice;				/* Vilket steg ska anv�nderen ta */

	cout << "[---------------------------------]\n";
	cout << "V�lkommen till \"Datorn ska gissa nummret\" ! \n";
	cout << "T�nk p� ett nummer mellan 1-100. \n Tryck ENTER n�r du �r klar!\n";
	cout << "[---------------------------------]\n";
	cin.get(); /* V�ntar p� input av anv�nderen innan vi ska fors�tta med v�rt program.*/

	do
	{
		/* Skapar ett nummer (random) men alltid mellan l�gste nummret och h�gste nummret som s�tts.  */
		randomnumber = min_number + (rand() % (max_number - min_number + 1)); 
		cout << "\nJag gissar p�... (" << randomnumber << ") !\n";
		/*debug*/cout << "(" << min_number << "|" << max_number << ") -> " << loop_count << endl;
		cout << "Har jag r�tt?" << endl;
		cout << "[---------------------------------]\n";

		/* Meny till alla val av spelet. */
		cout << "[1] Nej, f�r h�g! \n";
		cout << "[2] Nej, f�r l�g! \n";
		cout << "[3] Ja, du har r�tt! \n";
		cin >> menu_choice; 
		
		/* Vi beslutar vad ska h�nda n�r man trycker n�got i menyn. */
		switch (menu_choice)
		{
			/* OM man trycker 1 - F�r h�g! s� ska vi l�gga till gissade nummret till h�gste nummer datorn f�r gissa n�sta varv. */
			case 1:
				max_number = randomnumber - 1;
				loop_count++;							/* Addera 1 till loop-r�knare */
				break;									/* G� ut denna case och k�r ett till varv */

			/* OM man trycker 2 - F�r l�g! s� ska vi l�gga till gissade nummret till l�gste nummret datorn f�r gissa n�sta varv. */
			case 2: 
				min_number = randomnumber + 1;
				loop_count++;
				break;


			/* OM man trycker 3 - Datorn har r�tt! s� ska vi g� ut detta varv och l�ta datorn fira lite.*/
			case 3:
				cout << "[---------------------------------]\n";
				cout << "Woohoo! Jag hade r�tt! \n";
				cout << "Det tog mig " << (loop_count+1) << " g�nger att gissa!\n";
				/* Datorn kan visa hur l�nge den tog. +1 eftersom verkliga datorn b�rjar gissa p� 0. */
				cout << "[---------------------------------]\n";
				break; 

			/* Om man trycker fel */
			default:
				cout << "Du tryckte fel! Tryck 1 - 2 - 3. \n\n";
				system("pause");
				break;
		}
				
		/* OM datorn har gissat 7 g�nger, s� ska datorn sluta gissa. */
		if (loop_count >= 7)
		{
			cout << "\n Aww nej, du vinner! Jag ger upp!\n";
			cout << "[---------------------------------]\n";
			break;

			/* H�r ville jag s� g�rna fr�ga anv�ndaren om de ville spela igen eller inte. Men jag har inte nog kunskap just nu */
			/* f�r att implementera detta.  Det �r ocks� m�jligt att f� programmet krascha n�r man s�ger nej till ett svar som */
			/* ligger precis mellan max_number och min_number, men jag vet inte heller hur jag kan skapa ett meddelande f�r precis */
			/* n�r detta skulle h�nda. (T.ex. 'Du skojar! Det h�r m�ste vara r�tta svaret!") eller om det skulle fixa kraschandet. */
		} 
	} 
	/* Och vi ska g�ra ett till varv av loopen bara om dessa krav uppn�tts: */
	while (menu_choice != 3 || loop_count >= 7);
	system("pause");  
	/* Vi beh�ver pausa h�r, eftersom cin.get funkar endast 1 g�ng, och annars ska sluta-meddelandet inte visas till anv�ndaren. */

	return 0;
}


