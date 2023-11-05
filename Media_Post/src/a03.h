#pragma once
#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
#include<string>
#include <iomanip>
using namespace std;

//const int for the size of the struct arrays
const int MAX = 101;
const int ITEM = 10;
const char out[]="social.txt";

//struct for the user and all the important information
struct media{
		media();
		int load(ifstream& infile, media Elon[]);
		void input();
		void display();
		void save(ofstream& outfile);
		bool match(char find[]);
		char author[MAX]; 
		char title[MAX]; 
		char web[MAX]; 
		char text[MAX]; 
		int  likes;			
		int  dislikes;
};

