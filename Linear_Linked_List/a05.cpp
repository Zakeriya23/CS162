#include "a05.h"
//This funciton calls read fucntion to read then insert into linked list
void input(node * head, game s){
    s= read();
    if(!head){
        head = new node;
        head->data = s;
        head -> next =NULL;
    } 
    else{
        node *current =head;
        while(current->next){
            current = current->next;
        }
        current->next = new node;
        current =current->next;
        current->data = s;
        current->next =NULL;
    }

} 
//This function is called on by the input functiobn and get user inputs.
game read(){
    game test;
    cout << "Enter name of game:"<<endl << "\t--->";
    cin.get(test.name,MAX, '\n');	
    cin.clear();
    cin.ignore(100,'\n');

    cout << "Enter number of player:"<< endl<< "\t--->";
    cin >> test.num;
    cin.ignore(100,'\n');

    while(!cin || test.num < 0){
        cin.clear();
        cin.ignore(100,'\n');
        cout <<"\tPlease enter number of players: ";
        cin>> test.num;
    }

    cout << "Enter type of game:"<< endl<< "\t--->";
    cin.get(test.type,MAX,'\n');
    cin.clear();
    cin.ignore(100,'\n');

    cout << "Enter description:"<< endl<< "\t--->";
    cin.get(test.detail,MAX,'\n');
    cin.clear();
    cin.ignore(100,'\n');

    return test;

}
// This function display all the user input and the linear listed list.
void display_all(node *head){

    node * current = head; 
    current= current->next;
    while(current){
        cout <<"\tName: " << current -> data.name<<endl;
        cout << "\tNumber of players: " << current -> data.num<< endl;
        cout << "\tType of game: " << current -> data.type << endl;
        cout << "\tDescription: " << current -> data.detail << endl;
        cout << endl;
        current = current -> next;
    }

}
