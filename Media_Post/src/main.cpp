/******************************************************************************
# Author:           Zakeriya Muhumed # Assignment:       A03 (CS162)
# Date:             November 3, 2022
# Description:      Media assignment 
# Input:            This program takes in the number of media post, the author, website, title, text, #likes, dislikes.  
# Output:           With the differnet user interfaces, it can save those file to external file or displays other outputs. 
# Sources:          Assignment 3 instruction
#******************************************************************************/
#include "a03.h"

//Main function
int main(){
	int choice = 0;
	int count =0;
	int line=0;
	int found =0;
	char find[MAX];
	ifstream infile;
	ofstream outfile;
	
	//The two struct array
	media Elon[ITEM];
	media temp;
	

	while(choice != 6){
		cout<< "Pick 1-6 options" << endl;
		cout <<"\t1) Input media post"<< endl;
		cout <<"\t2) Display all" << endl;
		cout <<"\t3) Save to external file" << endl;
		cout <<"\t4) Load from external file" << endl;
		cout <<"\t5) Find specific author" <<endl;
		cout <<"\t6) Quit" << endl;
		cout <<"\n\t\t--->";
		cin >> choice; 
		cin.ignore();	
		while((choice < 1 && choice > 6) || (!cin)){
			cin>> choice;
			cin.ignore();
		}
		switch(choice){
			case 1:
				cout <<"\nEnter number of user:"<< endl;
				cout <<"\t--->";
				cin >> count;
				cin.ignore();
				for(int i = 0; i < count; ++i){
					Elon[i].input();
				}		
				break;
			case 2:
				cout << endl;
				for(int p =0; p <count; ++p){
					Elon[p].display();
				}
				break;
			case 3:		
				outfile.open(out);
				for(int s= 0; s <  count; ++s){
					Elon[s].save(outfile);
				}
				outfile.close();
				break;
			case 4:				
				infile.open(out);
				line = temp.load(infile, Elon);
				infile.close();
				count= line;
				break;	
			case 5:
				cout <<"Enter the author you want to find: " << endl;
				cout <<"\t\t--->";
				cin.get(find,MAX,'\n');
				for(int m=0; m < count; ++m){
					if(Elon[m].match(find)){
						Elon[m].display();		
						found++;	
					}	
				}
				if(found == 0){
					cout <<"\n\tAuthor not found!!"<< endl;
				}
				break;
		}
	}	
	return 0;
}

