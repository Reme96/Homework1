#include "ros/ros.h"
#include "std_msgs/String.h"
#include <homework1/message_hw1.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <sstream>

using std::string;

//Array contenente dei nomi 
string nomi[5] = {"Thomas Remelli","Mario Rossi","Luigi Bianchi","Carlo Verdi","Paolo Modena"};

//Array contenente dei corsi di laurea
string corsi[4] = {"Laurea in Informatica","Laurea in Economia","Laurea in Scienze Motorie","Laurea in Medicina"};

int main(int argc, char **argv)
{
	//Inizializzazione
	ros::init(argc, argv, "generator");

	//Inizializzazione nodo
	ros::NodeHandle n;

	//Dichiarazione publisher sul topic FULL_MESSAGE
	ros::Publisher msg_pub = n.advertise<homework1::message_hw1>("full_message", 1000);

	//Frequenza di invio dei messaggi (1 Hz)
	ros::Rate loop_rate(1);

	//Random
	srand(time(NULL));

	int posn;	//nome laureando
	int posc;	//corso di laurea
	int num;	//età laureando

	while (ros::ok())
	{
		//Calcolo dei valori casuali
		posn = rand()%5;
		posc = rand()%4;
		num = rand()%40 + 20;
		
		//Dichiarazione messaggio
		homework1::message_hw1 mex;

		//Composizione del messaggio
		mex.nome = nomi[posn];
		mex.eta = num;
		mex.corso = corsi[posc];

		//Stampa del valori inseriti nel messaggio
		ROS_INFO("Nome: %s", mex.nome.c_str());
		ROS_INFO("Eta: %i", mex.eta);
		ROS_INFO("Corso di Laurea: %s\n", mex.corso.c_str());

		//Invio del messaggio
		msg_pub.publish(mex);

		ros::spinOnce();

		loop_rate.sleep();
	}
	return 0;
}
