//
//  Number.cpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "Number.hpp"
#include "utils.hpp"

//============================================================================================
// Sets the private variable of string_representation_of_number
//============================================================================================

void  Number:: set_string_representation_of_number(string user_enter_number)
{
    string string_representation_of_number = user_enter_number;
}

//============================================================================================
// Sets the private variable of numeric_representation_of_number
//============================================================================================

void Number:: set_numeric_representation_of_number(long long int user_enter_number)
{
    numeric_representation_of_number = user_enter_number;
}

//============================================================================================
// Gets the private variable of string_representation_of_number
//============================================================================================

string Number:: get_string_representation_of_number()
{
    return string_representation_of_number;
}

//============================================================================================
// Gets the private variable of numeric_representation_of_number
//============================================================================================

long long int Number:: get_numeric_representation_of_number()
{
    return numeric_representation_of_number;
}
