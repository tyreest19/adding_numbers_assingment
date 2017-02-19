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

string Calculator:: addition_operator(Number *array, int length_of_array, int maxium_size_of_number)
{
    string sum(maxium_size_of_number, '0');
    string temp;
    
    for (int i = 0; i < length_of_array; i++)
    {
        temp = sum;
        cout << "\ntemp value: ";
        for (int j = 0; j < maxium_size_of_number; j++)
        {
            int digit_by_digit_addition =  (sum[j] - '0') + (array[i].digits_array[j] - '0');
            
            if (digit_by_digit_addition/10 == 1)
            {
                long long int carry_over_number = stoll(temp) + digit_by_digit_addition;
                temp = to_string(carry_over_number);
                cout << "carry over number: " << carry_over_number << "\n";
                cout << "temp after to string: " << temp << "\n";
                temp = string(maxium_size_of_number - temp.length(),'0') + temp;
            }
            
            else
            {
                temp[j] = digit_by_digit_addition + '0';
            }
            
            cout << "temp is: " <<temp << "\nand the iteration is: " << j + 1 << "\n";
        }
        cout << endl;
        sum = temp;
    }
    return sum;
}
