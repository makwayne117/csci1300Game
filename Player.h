/*
    CSCI 1300
    Author: Wayne Mak
    Recitation: 106 - Sravanth Yajamanam
    Project 3 - Player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Racer.h"
#include <iostream> 
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Player
{
    private:
        double attack;//more attack you have, more likely to win duels. 
        double health; //essentially lives in a standard video game. 
        string name;//player name
        double cash;//how much money that you have
        int distance;//how far you are from the player in front
        
    public:
        //default constructor
        Player();
        //Returns the current value of attack at the moment
        //Parameters none
        //Returns: current value of attack
        double getAttack();
        //Returns the current name value
        //No parameters
        //Returns name
        string getName();
        //Returns the current health value
        //Parameters none
        //Returns health
        double getHealth();
        //After winning a duel, or overcoming a challenges in the travel option, the player's attack will be boosted by a factor. 
        //Parameters: factor-how much your attack goes up
        //Returns:the new attack value.
        double boostAttack(double factor);
        //After winning a duel, or overcoming a challenges in the travel option, the player's attack will be boosted by a factor. 
        //Parameters: factor-how much your health goes up
        //Returns:the new health value.
        double boostHealth(double factor);
        //returnts the player's current amount of money
        double getCash();
        //Misfortune on your travels will lead to your health being decreased by a factor. This can occur by losing duels or chance encounters on the travel/ 
        //Parameters:factor-how much your health goes down
        //Returns: new health after the decrease
        double decreaseHealth(double factor);
        
        //Misfortune on your travels will lead to your attack being decreased by a factor. This can occur by losing duels or chance encounters on the travel/ 
        //Parameters:factor-how much your attack goes down
        //Returns: new Attack after the decrease
        double decreaseAttack(double factor);
        //resets the distance to 5. Typically done after losing or winning a duel against one of the racers. 
        //Parameters:none
        //Returns:none
        void resetDistance();
        //sets the current name value to the passed parameter
        //Parameters:name_-the name that you wish to change to
        //returns:none
        void setName(string name_);
        //Increases cash after winning duels. The cash may be used to buy items from the shop. 
        //Parameters:money-how much cash is gained
        //Retruns: the new amount of money you have
        double increaseCash(double money);
        //Decreases cash after losing duels. 
        //Parameters:money-how much money is lost
        //Retruns: the new amount of money you have
        double decreaseCash(double money);
        //Return the current distance behind the racer in front
       int getDistance();
       //Decreases distance between the player and the racer in front
        //Parmaeters:dist-how much distance is decreased
        //Returns:the current distance between you and the racer in front
       int catchUp(int dist);
       
}
;
#endif