//
//  Calculator.cpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "Calculator.hpp"
#include "Number.hpp"

//============================================================================================
// Generates Blank spaces.
//============================================================================================

string generate_spacing(Number array[], int length_of_array)
{
    int longest_number = 0;
    
    for (int i = 0; i < length_of_array; i++)
    {
        
        int length_of_current_number = int(array[i].get_string_representation_of_number().length());
        
        if (length_of_current_number > longest_number)
        {
            
            longest_number = length_of_current_number;
            
        }
    }
    
    string blank_space((longest_number + 2), ' ');
    return blank_space;
}

//============================================================================================
// Print addition design
//============================================================================================

void Calculator:: print_addition(Number array[], int length_of_array)
{


}

//============================================================================================
// Adds all the Numbers and returns their value as a long long int.
//============================================================================================

string Calculator:: addition_operator(Number *array, int length_of_array)
{
    string sum = 0;
    
    for (int i = 0; i < length_of_array; i++)
    {
    
    }
    
    return sum;
}
