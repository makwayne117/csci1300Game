/*
    CSCI 1300
    Author: Wayne Mak
    Recitation: 106 - Sravanth Yajamanam
    Project 3 - Race
*/
#include "Player.h"
#include "Racer.h"
#include "Race.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/*
    Turns the inputted string into all uppercase, by subtracting each character in the string by 32 to get uppercase ascii values. 
    Parameters:c-The string to turn into upper case. 
    Returns:the modified string. 
*/
string toUpper (string c)
{
    for (int i=0; i<c.length(); i++) 
    {
        if(c[i]>= 97 && c[i] <= 122) //if any of the characters in the string are lowercase (decimal values between 97 and 122), subtract 32 from the character 
        {
            c[i] -= 32; //this makes the character into an upper case value. 
        }
    }
    return c; //return the modified string
}

/*
    This function takes a string and a specified seperator of the string, then divides the string into parts based on the seperator. We will
    then take the parts and place them in an array. 
    Parameters: cut-the string to be divided, sep-the character to divide (ex: a string 2/3/4 with sep / will be divided into parts 2, 3, 4), list-the array to store the parts, size-how large the array is
    Return:the number of elements in the array, unless the elements exceed the size so we'll return -1. 
*/
int split (string cut, char sep, string list [], int size)
{
    
    int iter = 0; //variable used to iterate through the string
    if(cut == "") //return 0 for empty strings
    {
        return 0; 
    }
    while(iter < size) //run this loop while the iterator is less than the string
    {
        if(cut[0] == sep)//cut the string so it doesn't start with thte seperator
        {
            
            cut = cut.substr(cut.find_first_not_of(sep)-1);
        }
        if(cut.length() <= 0) //return the iter variable if the length is <=0
        {
            return iter;
        }
        if(cut.find(sep) == -1 ) //if it can't find the seperator any more
        {
            list[iter] = cut; //set the final calue to the remaining string
            iter += 1; //increase
            return iter; //return thhe value
        }
        else
        {
            int end  = cut.find(sep); //end of the substring is the seperator
            if(cut.substr(0, end).length() > 0)//if the length is longer than 0
            {
                list[iter] = cut.substr(0, end); //set the current indicie element to 0 to the end
                iter ++; //increase iter
            }
            cut = cut.substr(end+1); //set the new string variable to cut to the end +1
            end = cut.find(sep);//set end to the first instance of the character
            
        }
    }
    if(cut.length() >0) //return -1 is the cut's length is greater than 0 even after the loop
    {
        return -1;
    }
}


//Default constructor
Race::Race()
{
        numRacers = 0;
}
//Reads a text file with all the participants in there. File also has the rankings
//Parameters:file-the file name
//Returns:number of racers in the file 
int Race::readNames(string file)
{
    //Populates the racers array
    //1.Read through each line of the file, comma separated by their name, rank, health, and attack
    //2.Set all these comma separated values in each racer
    ifstream fileHandle;
    fileHandle.open(file); //open file
    string str = "";
    string info[4];
    
    if(fileHandle.is_open())
    {
        while(getline(fileHandle, str) && numRacers < 8) //we'll only read the ratings if the numRacers variable is not full (8)
        {
            int stats = split(str, ',', info, 4); //employ split function to get information about all the riders
            for(int i=0; i<stats; i++) //iterate through the array
            {
                if(i == 0)
                {
                    racers[numRacers].setName(info[i]); //extract the name
                }
                else if(i==1)
                {
                    racers[numRacers].setRank(stoi(info[i])); //extract the rank
                }
                else if(i==2)
                {
                    racers[numRacers].setHealth(stod(info[i])); //extract and set the health
                }
                else if(i==3)
                {
                    racers[numRacers].setAttack(stod(info[i]));//extract and set the health
                }
            }
            numRacers++; //increase numRacers variable
        }
        
    }
    
}


//Player uses their cash to buy things at the shop, cash gets substracted and item boosts attribute of player based on what was chosen (ex. beans boosts attack)
//Parameter:choice-the choice item, cash-how much money the player has
//returns none
void Race::shop(int choice,  Player& me)
{
    if(choice == 1 && me.getCash() >= 10) //if the choice 1 is made, and player has sufficient cash, we'll boost the attack stat accordingly. 
    {
        me.decreaseCash(10); //decrease cash
        me.boostAttack(1.5); //boost attack by this amount
        cout << "Thanks for the purchase! Your attack has been boosted to " << me.getAttack() <<"." << endl;  
    }
    else if(choice == 1 && me.getCash() < 10)
    {
        cout << "Not enough cash. You can get some more by dueling" << endl; //print this if insufficient cash to purchase
    }
    else if(choice == 2 && me.getCash() >= 10) //boosts health and decreases cash accordingly with this choice
    {
        me.decreaseCash(10);
        me.boostHealth(1);
        cout << "Thanks for the purchase! Your defense has been boosted to " << me.getHealth() <<"." << endl; 
    }
    else if(choice == 2 && me.getCash() <10) //print this if cash is insufficient
    {
        cout << "Not enough cash." << endl;
    }
    else //if player puts in an invalid choice, print this
    {
        cout << "We don't sell that here" << endl;
    }
    
        //1. take a player choice
        //2. depending on the choice and if they have sufficeint cash, modify their attack or health attribute. Deduct cash accordingly
}
//This method is called every turn to show where the player is relative to other racers. This shows where each racer is, including the player
//Parameters:none
//Returns:none
void Race::getRankings(Player& you)
{
    for(int i=0; i<numRacers; i++) //print each racer and their ranking
    {
        cout << racers[i].getName() << ", Ranked " << racers[i].getRank() << endl;
    }
    
    cout << "\n\nPlayers stats:" << endl; //print your name, attack, health, and cash. 
    cout << "Name: " << you.getName() << endl;
    cout << "Attack: " << you.getAttack() << endl;
    cout << "Health : " << you.getHealth() << endl;
    cout << "Cash: " << you.getCash() << endl;
    cout << "Distance from racer in front: " << you.getDistance() << endl;//print distance of you from the racer in front of you
}
//Duel, user takes their chance on survivng to get some money to be used in the shop
//Parameters:none
//Returns:true if the user wins, false if user loses
bool Race::duel(Player& you)//ask sravarth about this.
{
        cout << "\n\nReady... DRAW!" << endl;
        
        int chances =  (rand() %  10 + you.getAttack());//1.using probability calulated from the attack
        if(chances < 5) //player loses the duel if the chances variable turns out to be less than 7.
        {
            cout << "BANG! Unfortunately you lost. You lose some health and some cash." << endl;
            you.decreaseCash(5); //decrease cash, health, and attack accordingly. 
            you.decreaseHealth(1);
            you.decreaseAttack(2);
        }
        
        else //if you win, increase cash and health accordingly
        {
            cout << "BANG! BANG! BANG! And you won! You gained some cash and some health as a result. You gotta catch up on that race!" << endl;
            you.increaseCash(5);
            you.boostHealth(1);
            you.boostAttack(0.5);
        }
        // cout << chances << endl;

        //2.if it calculates something above a certain number, the player wins the duel. Boosts attack and defense 
        //3. if the player loses and defense is too low, the player not only loses some money, but their attack and defense as well
        //4. If their defense is high enough, the player only uses some money. 
}

//Adjusts your player name, should you decide to change it. 
//parameters: you-your player stats, oldName-what your previous name used to be
//returns: true if the name was successfully changed, false if otherwise
bool Race::changePlayer(Player& you, string oldName)
{
     bool newPlayer = true;//a boolean used to signify that this is indeed a new name
    for(int i=0; i<numRacers; i++) //iterate through the racers array
    {
        if(toUpper(racers[i].getName()) == toUpper(you.getName()))
        {
            newPlayer = false; //if we find a match, set newPlayer to false
            break;
        }
    }
    if(newPlayer == true) //this is if it's completely new
    {
        for(int i=0; i<numRacers; i++)
        {
            if(toUpper(racers[i].getName()) == toUpper(oldName))//find the racer with the old name
            {
                racers[i].setName(you.getName()); //set the name to what the player name is now
                break;
            }
        }
        return true; //returns true if successfully added
    }
    
    else
    {
        cout << "This participant already exists, please enter a new name." << endl; //print this and return false if the name is invalid
        return false;
    }
}

//Each time you take this travel choice, you have a high chance of catching up and overtaking your opponent. Distance decreases
//Parameters:you-your player profile
//Returns:none
void Race::travel(Player& you)
{
        int scenario = rand() % 5 + 1; //number to generate scenarios. Scenarios determine how much you move up to catch up with your opponent
        Racer opponent;
        int index;
        
        for(int i=0; i < numRacers; i++)//simply iterate through to find the player, use this index to also find the opponent should you engage in a duel
        {
            if (racers[i].getName() == you.getName())
            {
                index = i;
                break;
            }
        }
        
        if(you.getDistance() == 0)
        {
             
            int duelChance = rand() % 2 + 1; //evaluates the chances of you ending up fighting your opponent
            if(duelChance == 1)
            {
                string spacer; //spacer used to trigger the duel
                cout << "You entered a duel with the racer ahead of you. Type any number and press return to begin the fight." << endl; //simply press any number 
                cin >> spacer;
                cout << "\n\nReady... DRAW!" << endl;
        
               int chances =  (rand() %  10 + you.getAttack());//1.using probability calulated from the attack
                int oppChances = (rand() % 10 + (int) racers[index - 1].getAttack());
                if(chances > oppChances) //if the chances is less than 10, lose
                {
                    cout << "BANG! Unfortunately you lost. You lose some cash. Your distance behind your opponent has reset." << endl;
                    you.decreaseCash(2); //decrease amount from your cash
                    you.resetDistance(); //distance resets to 5
                    
                }
                
                else//if you win
                {
                    cout << "BANG! BANG! BANG! And you won! You gained some cash and some health as a result. You move up the ranks. " << endl;
                    you.increaseCash(5); //cash increases
                    you.resetDistance();//distance resets to 5
                    for(int i=0; i < numRacers; i++)//iterate through to find the player, this will help with the swap and adjustment
                    {
                        if (racers[i].getName() == you.getName())
                        {
                            index = i;
                            break;
                        }
                    }
                    Racer temp = racers[index-1]; //swap you and the racer infront of you if you win. using a temp Racer, we do a process similar to a bubble sort
                    racers[index-1] = racers[index];//swap the two racers
                    racers[index] = temp; //set the indexed racer to the temp
                    racers[index].setRank(temp.getRank()+1);//set their ranks to their appropriate placements in the array
                    racers[index-1].setRank(index);
                    you.resetDistance();
                }
                
                
                
            }
            
            else//there's a 50% chance you can straight up avoid a duel
            {
                
                cout << "You narrowly slip past your opponent " << racers[index].getName() << ". You are now ranked " <<racers[index].getRank() << endl;
               Racer temp = racers[index-1]; //swap you and the racer infront of you if you win. using a temp Racer, we do a process similar to a bubble sort
                racers[index-1] = racers[index];//swap the two racers
                racers[index] = temp; //set the indexed racer to the temp
                racers[index].setRank(temp.getRank()+1);//set their ranks to their appropriate placements in the array
                racers[index-1].setRank(index);
                you.resetDistance();
            }
        }
        
        else//if distance is not 0, use the randomly generated scenarios to appropriately decrease the distance or any player attribute
        {
            switch(scenario)
            {
                case 1:
                {
                    cout << "You cross through the plains without a problem." << endl;
                    you.catchUp(3);
                    break;
                }
                case 2:
                {
                    cout << "Darn! Stuck in the mud. You don't move forwards at all!" << endl;
                    break;
                }
                case 3:
                {
                    cout << "THIS IS A ROBBERY! Robbers come and steal your stuff. You lose some cash." << endl;
                    you.decreaseCash(3);
                    break;
                }
                case 4:
                {
                    cout << "Bandits are in hot pursuit, but you swiftly outmanuveur them. You eventually catch up a little bit." << endl;
                    you.catchUp(1);
                    break;
                }
            }
        }
        //1. randomly generate a number between 1-5
        //2. switch statement that generates scenarios for the player, depending on this, the player could end up in battle with another racer. 
        //ex. you could end up having to travel a river, or you find a shortcut that heavily decreases the distance between you and the racer in front
        //3.Decrease distance
}
//Adds the player into the array. 
//Parameters:name-name of the player
//returns true if the player was added, false if otherwise
bool Race::addPlayer(Player& name)
{
    bool newPlayer = true;
    for(int i=0; i<numRacers; i++)
    {
        if(toUpper(racers[i].getName()) == toUpper(name.getName())) //check if we have a preexisting racer with the set name
        {
            newPlayer = false;//false if we find a preexisting racer
            break;
        }
    }
    if(newPlayer == true) //if true
    {
        numRacers++;//numRacers increases
        Racer racer(name.getName());//add a new Racer
        racer.setRank(numRacers); //set the appropriate rank to numRacers, since you will always start at last
        racers[numRacers-1] = racer;//set the last index to the playername
        return true;//return true after this is successfully done
    }
    else //otherwise return false
    {
        cout << "There's another racer with that name. Try again." << endl;
        return false;
    }
    
}


//see the opponent up ahead of the player, and their attack stat.  
//Parmeters:you-the player
//Returns none
void Race::scope(Player& you)
{
    for(int i=0; i < numRacers; i++)//iterate through the array
    {
        if (racers[i].getName() == you.getName())//if we find the player, output the name and attack of the racer before him
        {
            cout <<"Your opponent: " << racers[i-1].getName()<< ", Opponent's attack: " << racers[i-1].getAttack() <<endl;
            break;
        }
    }
}

//Check if the game has successfully ended. Prints final messages and outputs the winner to the priorWinners.txt file
//Parameters:you-the player
//returns true if the game has ended, false if otherwise
bool Race::checkEndgame(Player& you)
{
     ofstream fileHandle;
    string str = "";
    fileHandle.open("priorWinners.txt"); //the txt file
    if(you.getHealth() == 0)//game ends if player health is 0
    {
        cout << "Oh how the mighty have fallen. Your health reached 0 so you are physically unable to continue the race. Try again." << endl;//print this if player health reaches 0
       
        fileHandle << "Winner: " << racers[0].getName() <<endl;//output to the priorWinners.txt file
        fileHandle.close();  
       
        
        return true;//return true to signify the game has ended
    }
    else if(racers[0].getName() == you.getName())
    {
        cout << "Congratulations, you have won!" << endl;//print this if the player has achieved first place
        
    
        fileHandle << "Winner: " << racers[0].getName() <<endl;//print name to txt file
        fileHandle.close();
        return true;//return true
    }
    else
    {
        return false;//otherwise return false;
    }
}