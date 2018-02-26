/************************************************
 * Program Name: ValidDouble.cpp
 * Author: Elizabeth Donato
 * Date: 2-9-2018
 * Description: This is the implementation file
 *              for the ValidDouble class.
*************************************************/

#include "ValidDouble.hpp"
#include <string>
#include <sstream>
#include <iostream>

/*************************************************
 *      ValidDouble::ValidDouble                *
 *                                              *
 * This is the constructor fot the ValidDouble  *
 * class.                                       *
 *                                              *
 * Accepts: Nothing                             *
 *                                              *
 * Returns: Nothing                             *
*************************************************/
ValidDouble::ValidDouble()
{
   //Default setting of goodInput is false.  The variable will only be changed
   //to true if valid input is entered.
   goodInput = false;

   //Sets test double to default value of 0
   testDouble = 0;
}

/*************************************************
 *      ValidDouble::is_valid_double            *
 *                                              *
 * This function determines if the user         *
 * has entered a valid double.                  *
 *                                              *
 * Accepts: string (user-entered input)         *
 *                                              *
 * Returns: bool (status of input validation)   *
*************************************************/
bool ValidDouble::is_valid_double (std::string inputString)
{
   goodInput = false;
   
   //variables to test input
   char c;
   std::istringstream testStream(inputString);

   //if input is not a double, displays an error message and boolean value is not changed
   if(!(testStream >> testDouble) || (testStream >> std::ws && testStream.get(c)))
   {
        std::cout << "\nYou have not entered a valid number." << std::endl;
   }

   //If input is a double, boolean value is changed to indicate valid input
   //and value in string is converted to double.
   else
   {
        goodInput = true;
        testDouble = std::stod(inputString);
   }

   return goodInput;
}

/*************************************************
 *      ValidDouble::is_valid_double_range      *
 *                                              *
 * This function determines if the user         *
 * has entered a valid double in the            *
 * specified range.                             *
 *                                              *
 * Accepts: string (user-entered input)         *
 *                                              *
 * Returns: bool (status of input validation)   *
 *          double (lower range boundary)       *
 *          double (upper range boundary)       *
*************************************************/
bool ValidDouble::is_valid_double_range (std::string inputString, double lowValue, double highValue)
{
   goodInput = false;
   
   //variables to test input
   char c;
   std::stringstream testStream(inputString);

   //if input is not an double in the specified range, displays an error message and boolean value is not changed
   if(!(testStream >> testDouble) || (testStream >> std::ws && testStream.get(c)) ||
     (testDouble < lowValue) || (testDouble > highValue))
   {
        std::cout << "\nYou have not entered a valid number in the specified range." << std::endl;
   }

   else
   {
        //If double input is within specified range, boolean value is changed to indicate valid inupt
        //and value in string is converted to double.
        goodInput = true;
        testDouble = std::stod(inputString);
   }

   return goodInput;
}

/*************************************************
 *      ValidInt::is_valid_double_positive      *
 *                                              *
 * This function determines if the user         *
 * has entered a positive valid double.         *
 *                                              *
 * Accepts: string (user-entered input)         *
 *                                              *
 * Returns: bool (status of input validation)   *
*************************************************/
bool ValidInt::is_valid_double_positive(std::string inputString)

{
   goodInput = false;
   
   //variables to test input
   char c;
   std::stringstream testStream(inputString);

   //if input is not a positive value, displays an error message and boolean value is not changed
   if(!(testStream >> testInt) || (testStream >> std::ws && testStream.get(c)) ||
     (testDouble < 1))
   {
        std::cout << "\nYou have not entered a positive value." << std::endl;
   }

   else
   {
        //If double input is positive, boolean value is changed to indicate valid inupt
        //and value in string is converted to integer.
        goodInput = true;
        testDouble = std::stod(inputString);
   }

   return goodInput;
}


/*************************************************
 *      ValidDouble::get_double                 *
 *                                              *
 * This function returns the user-entered       *
 * double value.                                *
 *                                              *
 * Accepts: Nothing                             *
 *                                              *
 * Returns: double (validated, user-entered)    *
*************************************************/
double ValidDouble::get_double()
{
   return testDouble;
}



