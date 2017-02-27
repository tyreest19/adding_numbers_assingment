//
//  utils.cpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/13/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//
#include "Number.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
using namespace std;

//============================================================================================
// Takes user inputted number as a string.
// Converts string into a int.
// Also validates the user input.
// Returns string.
//============================================================================================

string Get_Number(string prompt, string invalid_input_prompt, int lenght_of_number)
{
    string user_input;
    long long int user_enter_number;
    bool valid_input;
    
    do
    {
        user_input = " ";
        user_enter_number = 0;
        valid_input = true;
        
        cout << prompt;
        getline(cin, user_input);
        
        const char *user_input_char_pointer = user_input.c_str();
        user_enter_number = String_To_Int(user_input_char_pointer);
        
        if (user_input.length() > lenght_of_number && user_input.length() > 0)
        {
            cout << invalid_input_prompt;
            valid_input = false;
        }
        
        else if (user_enter_number == -1)
        {
            cout << invalid_input_prompt;
            valid_input = false;

        }
        
    } while (!valid_input);
    
    cout << "\n";
    
    return user_input;
}

//============================================================================================
// Takes constant char pointer and converts it into a string.
// If one of the characters are not a digit the function returns -1.
//============================================================================================

long long int String_To_Int(const char *str)
{
    long long int result = 0;

    if (str[0] == '\0')
    {
        return -1;
    }
    
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

//============================================================================================
// Returns the length of the longest string.
//============================================================================================

int Get_Longest_Number_Length(Number array[], int size_of_array)
{
    int longest_string = 0;
    
    for (int i = 0; i < size_of_array; i++)
    {
        int length_of_current_string = int(array[i].Get_String_Representation_Of_Number().length());
        
        if (length_of_current_string > longest_string)
        {
            longest_string = length_of_current_string;
        }
    }
    
    return longest_string;
}

//============================================================================================
// Returns the length of the longest string.
//============================================================================================
int Get_Longest_Number_Length(string array[], int size_of_array)
{
    int longest_string = 0;
    
    for (int i = 0; i < size_of_array; i++)
    {
        int length_of_current_string = int(array[i].length());
        
        if (length_of_current_string > longest_string)
        {
            longest_string = length_of_current_string;
        }
    }
    
    return longest_string;
}
