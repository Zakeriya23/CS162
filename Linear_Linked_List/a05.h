#pragma once
#include <iostream>
#include <cstring>
#include <cctype>
#include<string>
#include <iomanip>
using namespace std;

const int MAX = 100;
//struct for the user and all the important information
struct game{
    char name[MAX];
    int num;
    char type[MAX];
    char  detail[MAX];
};
//struct for the linked listed.
struct node{
    game data;
    node *next;
};  
//Functions
game read();
void display_all(node * head);
void input(node * head,game s);
     