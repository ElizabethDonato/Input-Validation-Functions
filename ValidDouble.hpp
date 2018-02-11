/************************************************
 * Program Name: ValidDouble.hpp
 * Author: Elizabeth Donato
 * Date: 2-9-2018
 * Description: This is the header file
 *              for the ValidDouble class.
*************************************************/

#ifndef VALIDDOUBLE_HPP
#define VALIDDOUBLE_HPP

#include <string>

//ValidDouble Class Declaration
class ValidDouble
{
   private:
        bool goodInput;
        double testDouble;

   public:
        ValidDouble();
        bool is_valid_double(std::string);
        bool is_valid_double_range(std::string, double, double);
        double get_double();
        ~ValidDouble() {};
};

#endif
