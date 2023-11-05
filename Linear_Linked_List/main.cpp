/******************************************************************************
# Author:           Zakeriya Muhumed # Assignment:       A5 (CS162)
# Date:             November 29, 2022
# Description:      linked listed 
# Input:            All the information in the struct
#output             A linear listed with all the infotamtion 
# Sources:          Assignment 5 instruction
#******************************************************************************/
#include "a05.h"

//Main function
int main(){
    char yes = 'y';
    //temp struct
    game W;
    node * head = nullptr;
    head = new node;

    while(tolower (yes) == 'y'){
    input(head,W);
    cout << "\n\t\tWould you like to enter more?" << endl << "\t\t--> ";
        cin >> yes;
        cin.ignore(100,'\n'); 
    }

    display_all(head);
   
    return 0;
}

     
