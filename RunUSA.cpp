/*
    CSCI 1300
    Author: Wayne Mak
    Recitation: 106 - Sravanth Yajamanam
    Project 3 - RunUSA
*/

#include <iostream> 
#include "Player.h"
#include "Racer.h"
#include "Race.h"
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int choice;//user choice
    Race USA;
    bool nameFound = false;//ensures that a name is found for the player
    string name;//user inputted name
    bool gameEnd = false;//boolean to indicate the game has ended
    string filename;
    Player you;//your player profile
    
    USA.readNames("enemies.txt");//read this txt file to ensure player names are read
    
    while(nameFound == false)
    {
        cout << "Welcome to Run USA, racer! What's your name?" << endl;//ask user name
        cin >> name;
        you.setName(name); //set the name to the input for now
        if(USA.addPlayer(you) == true)
        {
            nameFound = true;
        }
    }

    
    cout << "\n\nWelcome to the race " << name << "! Here's how you're ranking with the rest of your opponents.\n\n" << endl;
    cout << "Good luck! Hope come back alive in one piece!\n\n" << endl;
    
    while(gameEnd == false && choice != 6)
    {
        USA.getRankings(you);//display this menu every turn
        cout << "What will you do this turn?" <<endl;
        cout << "1. Browse the Shop" << endl;
        cout << "2. Duel" << endl;
        cout << "3. Continue your race." << endl;
        cout << "4. Change registration information." << endl;
        cout << "5. Check stats of the opponent ahead of you" << endl;
        cout << "6. Quit"<<endl;
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            {
                int shopChoice; //user will input a number to buy an item. These items will boost their player stats
                cout << "\n\nTotal Cash: " << you.getCash()<<endl;
                cout << "1. Shotgun. Boosts Attack" << endl;
                cout << "2. Can of Baked Beans. Boosts Health" << endl;
                cout << "Enter a number for a choice." << endl;
                cin >> shopChoice;
                USA.shop(choice, you); //pass in their choice into the shop method
                break;
            }
            case 2://this option sets up a duel
            {
                USA.duel(you);
                break;
            }
            case 3: //this option allows the player to continue in the race
            {
                USA.travel(you);
                break;
            }
            
            case 4://this choice allows for the player to change their name
            {
                string choice;
                bool newNameMade; //this boolean checks if there has been a new name made
                string oldName = you.getName(); //this is the player's prior name
                string newName;
                cout << "Would you like to change your name? Press Y for yes or N for no. Any other choice will lead you back to the main menu." << endl;//this choice checks if they would like to continue with the name change or not
                cin >> choice;
                
                if(choice == "y" || choice == "Y") //this checks to confirm they do indeed want to change their name
                {
                    while(newNameMade == false)
                    {
                        cout << "Please enter a new name." << endl;
                        cin >> newName; //user inputs a new name
                        you.setName(newName); //player name is changed
                        if(USA.changePlayer(you, oldName) == true) //pass through the player and the oldname, check if it's indeed a new name
                        {
                            newNameMade = true; //if it is, we can break out of this loop
                        }
                        
                    }
                }
                
                
                break;
            }
            
            case 5:
            {
                USA.scope(you); //sees the attack value of the racer up ahead
                break;  
            }
            
            case 6: //quits out of the program
            {
                cout << "Farewell. Maybe one day you will see the true man's world." << endl;
                break;
            }
            default:
            {
                cout << "That's not a valid option. Please put in an option 1-6" << endl;
                break;
            }
        }
        gameEnd = USA.checkEndgame(you);//check for endgame conditions. 
        
        
    }
    
}