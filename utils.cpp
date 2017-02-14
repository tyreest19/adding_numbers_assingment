//
//  utils.cpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/13/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "utils.hpp"
#include <iostream>
#include <string>
using namespace std;

//============================================================================================
// Takes user inputted number as a string.
// Converts string into a int.
// Also validates the user input.
// Returns int.
//============================================================================================

int Get_Number(int maxium_amount_of_numbers, int minimum_amount_of_numbers, string prompt, string invalid_input_prompt, int
               lenght_of_number)
{
    string user_input;
    int amount_of_numbers;
    int valid_input;
    
    do
    {
        user_input = " ";
        amount_of_numbers = 0;
        valid_input = true;
        
        cout << prompt;
        getline(cin, user_input);
        
        const char *user_input_char_pointer = user_input.c_str();
        
        amount_of_numbers = String_To_Int(user_input_char_pointer);
        
        if (amount_of_numbers == -1)
        {
            cout << invalid_input_prompt;
            valid_input = false;

        }
        
        else if (user_input.length() > lenght_of_number)
        {
            cout << invalid_input_prompt;
            valid_input = false;
        }
        
        else if (!(minimum_amount_of_numbers <= amount_of_numbers &&  amount_of_numbers <= maxium_amount_of_numbers))
        {
            cout << invalid_input_prompt;
            valid_input = false;
        }
        
    } while (!valid_input);
    
    return amount_of_numbers;
}

//============================================================================================
// Takes constant char pointer and converts it into a string.
// If one of the characters are not a digit the function returns -1.
//============================================================================================

int String_To_Int(const char *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        
        if ('0' <= str[i] && str[i] <= '9')
        {
    
            result = result*10 + str[i] - '0';
            
        }
        
        else
        {
            return -1;
        }
    }
    
    return result;
}
