#include "a03.h"
//Set everything to a 0 for the structs. 
media:: media(){
	author[0]='\0';
	title[0]='\0';
	web[0]='\0';
	text[0]='\0';
	likes=0;
	dislikes=0;
}
//Name:          void input();
//Description:   This function gets all the users media post
//input params:  none
//ouput:        none
//return:       none
void media:: input(){
	cout << "Enter Author:"<<endl << "\t--->";
	cin.get(author,MAX, '\n');	
	cin.ignore(100,'\n');

	cout << "Enter Title:"<< endl<< "\t--->";
	cin.get(title,MAX,'\n');
	cin.ignore(100,'\n');

	cout << "Enter Website:"<< endl<< "\t--->";
	cin.get(web,MAX,'\n');
	cin.ignore(100,'\n');

	cout << "Enter Text:"<< endl<< "\t--->";
	cin.get(text,MAX,'\n');
	cin.ignore(100,'\n');

	cout << "Enter Likes:"<< endl<< "\t--->";
	cin >> likes;
	cin.ignore(100,'\n');
	while(!cin || likes < 0){
	cin.clear();
	cin.ignore(100,'\n');
	cout <<"\tPlease try again: ";
	cin>> likes;	
	}
	
	cout << "Enter Dislike:"<< endl<< "\t--->";
	cin >> dislikes;
	cin.ignore(100,'\n');
	while(!cin || dislikes < 0){
	cin.clear();
	cin.ignore(100,'\n');
	cout <<"\tPlease try again: ";
	cin>> dislikes;
	}

}
//Name:       match(char find{})
//Description:  This is the find author function, finds all the match author.
//input params:   char find[]
//ouput:        none
//return:	none
bool media:: match(char find[]){
	if(strcmp(find,author) ==0){	
		return true;	
	}
	else{ 
		return false;
	}

}
//Name:        display() ;
//Description:   This function print the information
//input params:  none
//ouput:        media information
//return:       none
void media::display(){
	cout <<"\tAuthor: " <<  author <<endl;
	cout << "\tTitle: " << title<< endl;
	cout << "\tWebsite: " << web<< endl;
	cout << "\tText: " << text << endl; 
	cout <<"\tLikes: "<< likes << endl;
	cout <<"\tDislikes: " << dislikes << endl;
}
//Name:        save();
//Description:   This function print the information
//input params:   none
//ouput:        media information into exernal file.
//return:       none
void media:: save(ofstream& outfile){
	outfile << author <<"|";
	outfile << title<< "|";
	outfile << web<< "|";
	outfile << text<< "|";
	outfile << likes << "|";
	outfile << dislikes << "|";
	outfile << endl;
}
//Name:        load();
//Description:   This function get the information from a external file.
//input params:   ifstream infile and media Elon[]
//ouput:        none
//return:       returns i, which is the number of posts.
int media:: load(ifstream& infile, media Elon[]){	
	int i=0;	
	infile.get(Elon[0].author,MAX,'|');
	infile.ignore(100, '|');

	while(!infile.eof() && i <= ITEM){ 
		infile.get(Elon[i].title,MAX,'|');
		infile.ignore(100, '|');

		infile.get(Elon[i].web,MAX,'|');
		infile.ignore(100, '|');

		infile.get(Elon[i].text,MAX,';');
		infile.ignore(100, '|');

		infile >> Elon[i].likes;
		infile.ignore(100, '|');

		infile >>Elon[i].dislikes;
		infile.ignore(100, '\n');

		++i;	
		infile.get(Elon[i].author,MAX,'|');
		infile.ignore(100,'|');	
	}
	return i;
}
