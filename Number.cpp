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

void  Number:: Set_String_Representation_Of_Number(string user_enter_number)
{
    String_Representation_Of_Number = user_enter_number;
    
    for (int i = 3; i < String_Representation_Of_Number.length(); i += 4)
    {
        String_Representation_Of_Number.insert(String_Representation_Of_Number.length() - i, 1, ',');
    }
}


//============================================================================================
// Gets the private variable of string_representation_of_number
//============================================================================================

string Number:: Get_String_Representation_Of_Number()
{
    return String_Representation_Of_Number;
}

void Number:: Generate_Char_Array(string number)
{
    reverse(number.begin(), number.end());
    for (int i = 0; i < maxium_size; i++)
    {
        
        if (i < number.length())
        {
            digits_array[maxium_size - (i + 1)] = number[i];
        }
        
        else
        {
            digits_array[maxium_size - (i + 1)] = '0';
        }
    }
}

//============================================================================================
// Constructs number object.
//============================================================================================
Number:: Number(string user_enter_number, int maxium_choosen_size)
{
    raw_number = user_enter_number;
    int counter = 0;
    
    while (raw_number[counter] == '0')
    {
        raw_number.erase(0,1);
        counter += 1;
    }
    
    if (raw_number == "")
    {
        raw_number = "0";
    }
    maxium_size = maxium_choosen_size;
    Set_String_Representation_Of_Number(user_enter_number);
    Generate_Char_Array(user_enter_number);
}

