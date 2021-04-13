/*
    CSCI 1300
    Author: Wayne Mak
    Recitation: 106 - Sravanth Yajamanam
    Project 3 - Race
*/

#ifndef RACE_H
#define RACE_H

#include <iostream> 
#include "Player.h"
#include "Racer.h"
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Race
{
    private:
        Racer racers[8]; //an array of racers
        int numRacers; //how many racers are in the race at the moment.
    public:
        Race();
        //Reads a text file with all the participants in there. File also has the rankings
        //Parameters:file-the file name
        //Returns:number of racers in the file 
        int readNames(string file);
        //Player uses their cash to buy things at the shop, cash gets substracted and item boosts attribute of player based on what was chosen (ex. beans boosts attack)
        //Parameter:choice-the choice item, cash-how much money the player has
        //returns none
        void shop(int choice, Player& you);
        //This method is called every turn to show where the player is relative to other racers. This shows where each racer is, including the player
        //Parameters:none
        //Returns:none
        void getRankings(Player& you);
        //Duel, user takes their chance on survivng to get some money to be used in the shop
        //Parameters:none
        //Returns:true if the user wins, false if user loses
        bool duel(Player& you);
        //Each time you take this travel choice, you have a high chance of catching up and overtaking your opponent. Distance decreases
        //Parameters:you-your player profile
        //Returns:none
        void travel(Player& you);
        //Adds the player into the array. 
        //Parameters:name-name of the player
        //returns true if the player was added, false if otherwise
        bool addPlayer(Player& name);
        //Adjusts your player name, should you decide to change it. 
        //parameters: you-your player stats, oldName-what your previous name used to be
        //returns: true if the name was successfully changed, false if otherwise
        bool changePlayer(Player& name, string oldName);
        //see the opponent up ahead of the player, and their attack. This was meant to be used in fights but due to time constraints and difficulty to think of an indepth
        //system for the duel, the racer attack attribute was never employed properly. 
        //Parmeters:you-the player
        //Returns none
        void scope(Player& you);
        //Check if the game has successfully ended. Prints final messages and outputs the winner to the priorWinners.txt file
        //Parameters:you-the player
        //returns true if the game has ended, false if otherwise
        bool checkEndgame(Player& you);
        
}
;
#endif