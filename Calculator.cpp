//
//  Calculator.cpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "utils.hpp"
#include "Calculator.hpp"
#include "Number.hpp"

//============================================================================================
// Generates Blank spaces.
//============================================================================================

string Calculator:: generate_spacing(int length_of_largest_number, int length_of_current_number)
{
    string blank_space((length_of_largest_number + 2) - length_of_current_number, ' ');
    return blank_space;
}

//============================================================================================
// Print addition design
//============================================================================================

void Calculator:: print_addition(Number array[], int length_of_array)
{
    int longest_number = get_longest_number_length(array, length_of_array);
    string preliminary_spaces = "   ";
    
    cout << "The sum of:  \n \n";
    
    for (int i = 0; i < length_of_array; i++)
    {
        int length_of_current_number = int(array[i].get_string_representation_of_number().length());
        string spaces = generate_spacing(longest_number, length_of_current_number);

        if (i == length_of_array - 1)
        {
            cout  << "+> " << spaces << array[i].get_string_representation_of_number() << "\n";
            cout << "------------------" << "\n";
        }
        
        else
        {
            cout << preliminary_spaces << spaces << array[i].get_string_representation_of_number() << "\n";
        }
    }
}

//============================================================================================
// Adds all the Numbers and returns their value as a long long int.
//============================================================================================

long long int Calculator:: addition_operator(Number *array, int length_of_array, int maxium_size_of_number)
{
    long long int sum = 0;
    
    for (int i = 0; i < length_of_array; i++)
    {
        int carry_over_number = 0;
        long long int user_enter_number = stoll(array[i].digits_array);
        
        while (user_enter_number > 0)
        {
            int carry_out_number = (sum/10) + (user_enter_number/10);
            
            if (carry_out_number/10 == 0)
            {
                sum += user_enter_number % 10;
                user_enter_number /= 10;
            }
            
            else
            {
                
            }
        }
    }
    return sum;
}
