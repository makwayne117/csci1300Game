/*
    CSCI 1300
    Author: Wayne Mak
    Recitation: 106 - Sravanth Yajamanam
    Project 3 - Player
*/
#include <iostream> 
#include "Player.h"
#include "Racer.h"
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


Player::Player()
{
    attack = 1;
    health = 5;
    name = "";
    cash = 15.0; //player starts with 15 dollars
    distance = 5;
}

//After winning a duel, or overcoming a challenges in the travel option, the player's attack will be boosted by a factor. 
//Parameters: factor-how much your attack goes up
//Returns:the new attack value.  
double Player::boostAttack(double factor)
{
    if(attack + factor >= 5)
    {
        attack = 5;
        return attack;
    }
    else
    {
        attack += factor; //add attack by factor
        return attack;
    }
    //multiply the current attack value by the factor (ex 1.5)
    //return new attack value
}

//After winning a duel, or overcoming a challenges in the travel option, the player's attack will be boosted by a factor. 
//Parameters: factor-how much your health goes up
//Returns:the new health value.
double Player::boostHealth(double factor)
{
    if(health + factor >=10)//ensures health does not exceed 10
    {
        health =10;
        return health;
    }
    else//otherwise increase health by this factor
    {
        health += factor;
        return health;
    }
   
}

//Misfortune on your travels will lead to your attack being decreased by a factor. This can occur by losing duels or chance encounters on the travel/ 
//Parameters:factor-how much your attack goes down
//Returns: new Attack after the decrease
double Player::decreaseAttack(double factor)
{
    attack /= factor; //divide by factor
    return attack;
}

//Returns the current name value
//No parameters
//Returns name
string Player::getName()
{
    return name;
}

//Returns the current value of attack at the moment
//Parameters none
//Returns: current value of attack
double Player::getAttack()
{
    return attack;
}

//Returns the current health value
//Parameters none
//Returns health
double Player::getHealth()
{
    return health;
}

//Misfortune on your travels will lead to your health being decreased by a factor. This can occur by losing duels or chance encounters on the travel/ 
//Parameters:factor-how much your health goes down
//Returns: new health after the decrease
double Player::decreaseHealth(double factor)
{
    if(factor > health)
    {
        health = 0;
    }
    else
    {
        health -= factor;//subtract the current health value by the factor (ex 1.5)
    }
     return health;//return current health value
}

//sets the current name value to the passed parameter
//Parameters:name_-the name that you wish to change to
//returns:none
void Player::setName(string name_)
{
    name = name_;
}
//Increases cash after winning duels. The cash may be used to buy items from the shop. 
//Parameters:money-how much cash is gained
//Retruns: the new amount of money you have
double Player::increaseCash(double money)
{
    if(cash += money > 50)
    {
        cash = 50;
        return cash;
    }
    else
    {
        cash += money;
        return cash;
    }
}
//Decreases cash after losing duels. 
//Parameters:money-how much money is lost
//Retruns: the new amount of money you have
double Player::decreaseCash(double money)
{
    if(money > cash)
    {
        cash = 0;
    }
    else
    {
        cash -= money;
    }
    return cash;
}

//Decreases distance between the player and the racer in front
//Parmaeters:dist-how much distance is decreased
//Returns:the current distance between you and the racer in front
int Player::catchUp(int dist)
{
    if(dist <= distance)
    {
        distance -= dist; //distance between you and the other player will decrease by subtracting the current distance value by dist
        //This method is typically called after the travel function
        
        return distance;//returns current distance
    }
    else
    {
        distance = 0;
        return distance;
    }
}

//resets the distance to 5. Typically done after losing or winning a duel against one of the racers. 
//Parameters:none
//Returns:none
void Player::resetDistance()
{
    distance = 5;
}

//returnts the player's current amount of money
double Player::getCash()
{
    return cash; //returns the current number of cash that the player has after duels
}
//Return the current distance behind the racer in front
int Player::getDistance()
{
    return distance;
}

