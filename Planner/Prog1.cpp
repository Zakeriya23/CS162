/******************************************************************************
# Author:           Zakeriya Muhumed
# Assignment:       A01 (CS162)
# Date:             October 4, 2022
# Description:      This program helps student plan for projects by taking in number of project and time spent on each project.
# Input:            option, hours,size, time per project
# Output:           #of hours per project, # of project and error message.
# Sources:          Assignment 1  instruction
#******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
const int MAX = 30;

int main(){
	//Variables
	double hour; // hours spent on projects
	int size; // store the number of project
	char option; //use or quit program
	int time[MAX]; // storing  time spent on whcih project
	int j=0; // for loop
	int i=0;//forloop
	int sum=0;// Added up all the hour entered, and check it.

	while(toupper(option) != 'Q'){
		cout << endl<< "Welcome to the planner" << endl;
		cout << "(C) to use program." << endl;
		cout << "\n(Q) quit this program." << endl;
		cin >> option;
		option = toupper(option);
		while(option!= 'Q' && option != 'C'){
			cin >> option;
			option = toupper(option);
		}
		switch (toupper(option)){
			case 'C':
				cout << "Enter hours on project: ";
				cin >> hour;
				cout << endl;
				while ((hour > 8)||(hour < 1)||(!cin)){
					cout << "You cant spend > 8 hour on project, please try again:";
					cin.clear();
					cin.ignore(100,'\n');		
					cin>> hour;
				}

				cout << "Enter the number of projects:" ;
				cin >> size;
				cout << endl;
				while((size > 100)||(size < 0)||(!cin)){
					cout << "Invaild input, please try again:";
					cin.clear();
					cin.ignore(100,'\n');	
					cin >> size;
					cout << endl;
				}

				for(i = 0; i < size; i++){
					cout <<"Enter hour spent on project " << i+1 <<" : ";
					cin>> time[i];
					cout <<endl;
					sum = sum+ time[i];
				}

				cout << "Hour on project: " << hour<< endl;
				cout << "Number of project: " <<size  << endl;
				cout << "Time on each project: ";

				for(j= 0; j< size; j++){
					cout << time[j] << " ";
				}
				cout << endl;
				if(sum> hour){
					cout << "Time on each project  going over 8 hours. Please take care of your mental health" << endl;
				}
				else if (sum< hour){
					cout << "You have some leftover time." << endl;
				}
		}
	}
	return 0;
}

