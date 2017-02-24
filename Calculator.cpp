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

void Calculator:: print_addition(Number array[], int length_of_array, string answer)
{
    int longest_number = get_longest_number_length(array, length_of_array);
    string preliminary_spaces = "   ";
    string lines((longest_number + 2) - 1, '-');
    
    cout << "The sum of:  \n \n";
    
    for (int i = 0; i < length_of_array; i++)
    {
        int length_of_current_number = int(array[i].get_string_representation_of_number().length());
        string spaces = generate_spacing(longest_number, length_of_current_number);

        if (i == length_of_array - 1)
        {
            cout  << "+> " << spaces << array[i].get_string_representation_of_number() << "\n";
            cout << lines << "\n";
        }
        
        else
        {
            cout << preliminary_spaces << spaces << array[i].get_string_representation_of_number() << "\n";
        }
    }
    cout << answer << "\n";
}

//============================================================================================
// Adds all the Numbers and returns their value as a long long int.
//============================================================================================

string Calculator:: addition_operator(Number *array, int length_of_array, int maxium_size_of_number)
{
    string sum(maxium_size_of_number,'0');
    int carry = 0;
    
    for (int i = 1; i < maxium_size_of_number + 1; i++)
    {
        int digit_by_digit_addition = carry;
        
        for (int j = 0; j < length_of_array; j++)
        {
            digit_by_digit_addition += array[j].digits_array[maxium_size_of_number - i] - 48;
            cout << "the actual digit is: " << array[j].digits_array[maxium_size_of_number - i]  << endl;
            cout << "digit by digit addition: " << digit_by_digit_addition << "the iteration: "<< j + 1 << "\n";
        }
        
        carry = digit_by_digit_addition/10;
        sum[maxium_size_of_number - i] = (digit_by_digit_addition % 10) + '0';
    }
    
    sum = "00000" + sum;
    int counter = 5;
    int digit_by_digit_addition;
    int second_carry = 0;
    
    while (carry > 0 || second_carry > 0)
    {
        digit_by_digit_addition = sum[counter] - 48;
        digit_by_digit_addition += carry + second_carry;
        second_carry = digit_by_digit_addition/10;
        sum[counter] =(digit_by_digit_addition % 10) + '0';
        carry /= 10;
        counter -= 1;
    }
    
    sum = Standardize_String(sum);
    return sum;
}

string Calculator:: Standardize_String(string sum)
{

    while (sum[0] == '0')
    {
        sum.erase(0,1);
    }
    
    for (int i = 3; i < sum.length(); i += 4)
    {
        sum.insert(sum.length() - i, 1, ',');
    }
    return sum;
}
