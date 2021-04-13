/*
    CSCI 1300
    Author: Wayne Mak
    Recitation: 106 - Sravanth Yajamanam
    Project 3 - Racer
*/

#include <iostream> 
#include "Racer.h"
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//Default constructor
Racer::Racer()
{
    rank = 0;
    name = "";
    health= 5.0;
    attack = 0;
}
//Constructor that takes in the username
Racer::Racer(string name_)
{
    rank = 0;
    name = name_;
    health= 5.0;
    attack = 0;
}
//Returns the current racer's name
string Racer::getName()
{
    return name;
}
//sets the current racer's name
void Racer::setName(string name_)
{
    name = name_;
}
//returns the current rank of the user
//parameters:none
//Return:racer's current rank
int Racer::getRank()
{
    return rank;
}

double Racer::setHealth(double health_)
{
    health = health_;
    return health;
}
//sets the rank of the user. Usually done after sorting. 
void Racer::setRank(int rank_)
{
    rank = rank_;
}

//in a fight, use this method to remove health. 
//parameter:diff-how much health to decrease
//returns: new health value
int Racer::decreaseHealth(int diff)
{
    health -= diff;
    return health;
}

//Show how powerful the Racer is, so you canplan your attack accordingly
//returns: Racer's attack
double Racer::getAttack()
{
    return attack;
}
//sets the attack to the passed calue
//returns:the new attack value
//parameters:attack_-new attack value. 
double Racer::setAttack(double attack_)
{
    attack = attack_;
}
