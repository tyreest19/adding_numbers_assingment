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

int String_To_Int(char *str);


int Get_Number(int maxium_amount_of_numbers, int minimum_amount_of_numbers, string prompt, string invalid_input_prompt)
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
        
        char *user_input_char_pointer = new char[user_input.length() + 1];
        
        amount_of_numbers = String_To_Int(user_input_char_pointer);
        
        if (amount_of_numbers == -1)
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

int String_To_Int(char *str)
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
