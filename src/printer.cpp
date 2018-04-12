#include "ros/ros.h"
#include "std_msgs/String.h"
#include <homework1/message_hw1.h>
#include <homework1/select_hw1.h>
#include <iostream>

using namespace std;

//Variabile globale per selezionare la modalità di stampa
char selection = 'x';

//Funzione per stampare a video i valori
void print(const homework1::message_hw1::ConstPtr& mex)
{
	switch (selection)
	{
		case 'a':
  			ROS_INFO("Nome: [%s]", mex->nome.c_str());
			ROS_INFO("Eta: [%i]", mex->eta);
			ROS_INFO("Corso di Laurea: [%s]\n", mex->corso.c_str());
			break;
		case 'n':
  			ROS_INFO("Nome: [%s]\n", mex->nome.c_str());
			break;
		case 'e':
			ROS_INFO("eta: [%i]\n", mex->eta);
			break;
		case 'c':
			ROS_INFO("Corso di Laurea: [%s]\n", mex->corso.c_str());
			break;
	}
}

//Funzione per selezionare la modalità di stampa ricevuta dal SELECTOR
void select_case(const homework1::select_hw1::ConstPtr& mex_sel)
{
	selection = mex_sel->sel;
	cout << "\n\n";
}

int main(int argc, char **argv)
{
	//Inizializzazione
	ros::init(argc, argv, "printer");

	//Inizializzazione nodo
	ros::NodeHandle n;

	//Subscriber del SELECTOR
	ros::Subscriber sub_sel = n.subscribe("select", 1000, select_case);

	//Subsriber del GENERATOR
	ros::Subscriber sub_mex = n.subscribe("full_message", 1000, print);

	ros::spin();
	return 0;
}
