/************************************************
 * Program Name: Menu.cpp
 * Author: Elizabeth Donato
 * Date: 1-20-2018
 * Description: This is the implementation file
   for the menu class  This class can
   easily be modified for use by different
   programs.
************************************************/

#include "Menu.hpp"
#include "ValidInt.hpp"
#include <iostream>

/*************************************************
 *              Menu::Menu                      *
 *                                              *
 * This is the constructor for the Menu class.  *
 * It initializes class variables.              *
 *                                              *
 * Accepts: Nothing                             *
 *                                              *
 * Returns: Nothing                             *
*************************************************/
Menu::Menu()
{
   firstMenu = true;            //True if this is the first time user is seeing the menu
   testString = "";
   validInput = false;          //Will change to true once valid input has been entered
   lowest = 1;
   highest = 2;
}

/*************************************************
 *              Menu::get_choice                *
 *                                              *
 *                                              *
 * This function displays a menu of choices     *
 * for the user and gets the user's choice.     *
 * The function could be modified to accept     *
 * a parameter indicating which version of the  *
 * menu should be displayed.                    *
 *                                              *
 * Accepts: Nothing                             *
 *                                              *
 * Returns: int (user's choice)                 *
 *                                              *
*************************************************/
int Menu::get_choice()
{
   //Gets and validates user's choice
   while(!validInput)
   {
        //If this is the first time the menu is being displayed
        if(firstMenu == true)
        {
           std::cout << "\n\n  Program Menu";
           std::cout << "\n--------------------";
           std::cout << "\n1.  Start Program";
           std::cout << "\n2.  Quit Program";
        }

        //If the simulation has already been run at least once
        else
        {
           std::cout << "\n\n  Program Menu";
           std::cout << "\n--------------------";
           std::cout << "\n1.  Play Again";
           std::cout << "\n2.  Quit Program";
        }

        std::cout << "\n\nPlease enter your choice:  ";
        std::getline(std::cin, testString);
        validInput = userInput.is_valid_int_range(testString, lowest, highest);
   }

   //Sets boolean value to indicate the user has already executed the program once
   firstMenu = false;
   
   //Resets boolean value so menu function can be used again if needed
   validInput = false;

   //Returns user's choice to client program
   userChoice = userInput.get_int();

   return userChoice;
}
