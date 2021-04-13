/*
    CSCI 1300
    Author: Wayne Mak
    Recitation: 106 - Sravanth Yajamanam
    Project 3 - Racer
*/

#ifndef RACER_H
#define RACER_H

#include <iostream> 
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Racer
{
    private:
        string name;//racer name
        int rank;//their rank
        double health;//how powerful they are (unused)
        double attack;//how much attack they have. Higher attack means they are more likely to come out victorious. 
    public:
        //default constructor
        Racer();
        //take in a name
        Racer(string name_);
        //Returns the current racer's name
        string getName();
        //sets the current racer's name to the parameter
        void setName(string name_);
        //gets the current racer's rank
        int getRank();
        //sets the current racer's rank to the parameter
        void setRank(int rank_);
        //return the racer's current health 
        int getHealth();
        //set the current health to the health in the parameter
        double setHealth(double health_);
        //gets the currrent attack value
        double getAttack();
        //sets the current attack value
        double setAttack(double attack_);
        //decreases their health; 
        int decreaseHealth(int diff);
}
;
#endif