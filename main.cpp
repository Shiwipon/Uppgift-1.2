#include <iostream>				/* De flesta funktioner vi ska använda */
#include <cstdlib>				/* Random generator */
#include <ctime>				/* Time for super random mode */
/* Jag lärde mig detta från https://www.youtube.com/watch?v=naXUIEAIt4U och http://www.cplusplus.com/reference/cstdlib/rand/ */

using namespace std;

int main() {
	setlocale(LC_ALL,"swedish");
	srand (time(0)); /* Generate a seed based on time / Skapar en 'seed' baserad på tid som används till random. */

	//Här kommer alla variabler som vi ska använda. 
	int loop_count = 0;				/* Antalet gissar */
	int max_number = 100;			/* Högste nummret, och får inte vara mer än 100 */
	int min_number = 1;				/* Lägsta nummret, får inte vara mindre än 1 */	
	int randomnumber;				/* Nummret datorn ska gissa */
	int menu_choice;				/* Vilket steg ska använderen ta */

	cout << "[---------------------------------]\n";
	cout << "Välkommen till \"Datorn ska gissa nummret\" ! \n";
	cout << "Tänk på ett nummer mellan 1-100. \n Tryck ENTER när du är klar!\n";
	cout << "[---------------------------------]\n";
	cin.get(); /* Väntar på input av använderen innan vi ska forsätta med vårt program.*/

	do
	{
		/* Skapar ett nummer (random) men alltid mellan lägste nummret och högste nummret som sätts.  */
		randomnumber = min_number + (rand() % (max_number - min_number + 1)); 
		cout << "\nJag gissar på... (" << randomnumber << ") !\n";
		/*debug*/cout << "(" << min_number << "|" << max_number << ") -> " << loop_count << endl;
		cout << "Har jag rätt?" << endl;
		cout << "[---------------------------------]\n";

		/* Meny till alla val av spelet. */
		cout << "[1] Nej, för hög! \n";
		cout << "[2] Nej, för låg! \n";
		cout << "[3] Ja, du har rätt! \n";
		cin >> menu_choice; 
		
		/* Vi beslutar vad ska hända när man trycker något i menyn. */
		switch (menu_choice)
		{
			/* OM man trycker 1 - För hög! så ska vi lägga till gissade nummret till högste nummer datorn får gissa nästa varv. */
			case 1:
				max_number = randomnumber - 1;
				loop_count++;							/* Addera 1 till loop-räknare */
				break;									/* Gå ut denna case och kör ett till varv */

			/* OM man trycker 2 - För låg! så ska vi lägga till gissade nummret till lägste nummret datorn får gissa nästa varv. */
			case 2: 
				min_number = randomnumber + 1;
				loop_count++;
				break;


			/* OM man trycker 3 - Datorn har rätt! så ska vi gå ut detta varv och låta datorn fira lite.*/
			case 3:
				cout << "[---------------------------------]\n";
				cout << "Woohoo! Jag hade rätt! \n";
				cout << "Det tog mig " << (loop_count+1) << " gånger att gissa!\n";
				/* Datorn kan visa hur länge den tog. +1 eftersom verkliga datorn börjar gissa på 0. */
				cout << "[---------------------------------]\n";
				break; 

			/* Om man trycker fel */
			default:
				cout << "Du tryckte fel! Tryck 1 - 2 - 3. \n\n";
				system("pause");
				break;
		}
				
		/* OM datorn har gissat 7 gånger, så ska datorn sluta gissa. */
		if (loop_count >= 7)
		{
			cout << "\n Aww nej, du vinner! Jag ger upp!\n";
			cout << "[---------------------------------]\n";
			break;

			/* Här ville jag så gärna fråga användaren om de ville spela igen eller inte. Men jag har inte nog kunskap just nu */
			/* för att implementera detta.  Det är också möjligt att få programmet krascha när man säger nej till ett svar som */
			/* ligger precis mellan max_number och min_number, men jag vet inte heller hur jag kan skapa ett meddelande för precis */
			/* när detta skulle hända. (T.ex. 'Du skojar! Det här måste vara rätta svaret!") eller om det skulle fixa kraschandet. */
		} 
	} 
	/* Och vi ska göra ett till varv av loopen bara om dessa krav uppnåtts: */
	while (menu_choice != 3 || loop_count >= 7);
	system("pause");  
	/* Vi behöver pausa här, eftersom cin.get funkar endast 1 gång, och annars ska sluta-meddelandet inte visas till användaren. */

	return 0;
}


