/************************************************
 * Program Name: UserInput.cpp
 * Author: Elizabeth Donato
 * Date: 1-27-2018
 * Description: This is the specification file
   for the UserInput class that is used to get
   information from the user about program
   specifications.  This class can easily be
   modified for use by different programs.
************************************************/

#include "UserInput.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

/*************************************************
 *              UserInput::UserInput            *
 *                                              *
 * This is the default constructor for the      *
 * UserInput class.  It sets default values     *
 * for user-entered values.                     *
 *                                              *
 *  Accepts: Nothing                            *
 *                                              *
 *  Returns: Nothing                            *
*************************************************/
UserInput::UserInput()
{
   myInt= 0;
   testString = "";
   validInput = false;
   lowest = 0;
   highest = 0;
}
/*************************************************
 *      UserInput::get_input_range              *
 *                                              *
 * This function gets input within a specified  *
 * range from the user.                         *
 * This function can be modified to check the   *
 * validity of a floating point value by        *
 * using the is_valid_double_range function.    *
 *                                              *
 * Accepts: int (lowest value)                  *
 *          int (highest value)                 *
 *                                              *
 * Returns: int (user-entered input)            *
*************************************************/
int UserInput::get_input_range(int low, int high)
{
   lowest = low;
   highest = high;
   //Gets and validates user input
   while (!validInput)
   {
        std::cout << "\nPlease enter an integer:  ";
        std::getline(std::cin, testString);
        validInput = userInt.is_valid_int_range(testString, lowest, highest);
   }

   //Returns user's input to client program as an integer
   myInt = userInt.get_int();

   return myInt;
}

/*************************************************
 *      UserInput::get_input                    *
 *                                              *
 * This function gets input with no range       *
 * from the user.                               *
 * This function can be modified to check the   *
 * validity of a floating point value by        *
 * using the is_valid_double function.          *
 *                                              *
 * Returns: int (user-entered input)            *
*************************************************/
int UserInput::get_input()
{
   lowest = low;
   highest = high;
   //Gets and validates user input
   while (!validInput)
   {
        std::cout << "\nPlease enter an integer:  ";
        std::getline(std::cin, testString);
        validInput = userInt.is_valid_int(testString);
   }

   //Returns user's input to client program as an integer
   myInt = userInt.get_int();

   return myInt;
}

