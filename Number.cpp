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
    string_representation_of_number = user_enter_number;
    
    for (int i = 3; i < string_representation_of_number.length(); i += 4)
    {
        string_representation_of_number.insert(string_representation_of_number.length() - i, 1, ',');
    }
}


//============================================================================================
// Gets the private variable of string_representation_of_number
//============================================================================================

string Number:: get_string_representation_of_number()
{
    return string_representation_of_number;
}

void Number:: generate_char_array(string number)
{
    for (int i = 0; i < number.length(); i++) {
        
        if (i < number.length())
        {
            digits_array[i] = number[i];
        }
        
        else
        {
            digits_array[i] = '0';
        }
    }
}

//============================================================================================
// Constructs number object.
//============================================================================================
Number:: Number(string user_enter_number)
{
    amount_of_digits = int(user_enter_number.length());
    set_string_representation_of_number(user_enter_number);
    generate_char_array(user_enter_number);
}

