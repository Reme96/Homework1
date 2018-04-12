#include "ros/ros.h"
#include "std_msgs/String.h"
#include <homework1/select_hw1.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
	//Inizializzazione
	ros::init(argc, argv, "selector");

	//Inizializzazione nodo
	ros::NodeHandle n;

	//Dichiarazione publisher sul topic SELECT
	ros::Publisher sel_pub = n.advertise<homework1::select_hw1>("select", 1000);

	//Dichiarazione della variabile scelta da inviare poi al PRINTER
	char scelta = 'x';

	while (ros::ok())
	{
		do
		{
			//Stampa del menù per richiedere la modalità di visualizzazione all'utente
			cout << "\nEffettua una scelta: \na - Visualizza tutto\nn - Visualizza nome\ne - Visualizza eta\nc - Visualizza corso\nq - Esci\nInserisci scelta: ";
			//Lettura della variabile inserita dall'utente
			cin >> scelta;
		}		
		//Finchè l'utente non inserisce un valore corretto continuo a richiederglielo
		while (!(scelta=='a' || scelta == 'n' || scelta == 'e' || scelta == 'c' || scelta == 'q'));

		//Se viene selezionato 'q' il programma termina
		if(scelta == 'q')
			std::exit(EXIT_SUCCESS);

		//Dichiarazione del messaggio
		homework1::select_hw1 mex_sel;

		//Composizione del messaggio
		mex_sel.sel = scelta;

		//Invio del messaggio
		sel_pub.publish(mex_sel);

		ros::spinOnce();
	}
	return 0;
}
