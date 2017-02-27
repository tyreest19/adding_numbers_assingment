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

void Calculator:: print_addition(Number array[], int length_of_array, string sum)
{
    int longest_number = get_longest_number_length(array, length_of_array);
    string preliminary_spaces = "   ";
    string lines((longest_number + 6) - 1, '-');
    
    cout << "The sum of:  \n \n";
    
    for (int i = 0; i < length_of_array; i++)
    {
        string addends = Standardize_Number(array[i].raw_number, false);
        int length_of_current_number = addends.length();
        string spaces = generate_spacing(longest_number, length_of_current_number);

        if (i == length_of_array - 1)
        {
            cout  << "+> " << spaces << addends << "\n";
            cout << lines << "\n";
        }
        
        else
        {
            cout << preliminary_spaces << spaces << addends << "\n";
        }
    }
    cout << generate_spacing(longest_number, int(sum.length())) << "   " << sum << "\n";
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
        }
        
        carry = digit_by_digit_addition/10;
        sum[maxium_size_of_number - i] = (digit_by_digit_addition % 10) + '0';
    }
    
    if (carry > 0)
    {
        sum = remaining_carry(sum, carry);
    }
    
    sum = Standardize_Number(sum, false);
    return sum;
}

//============================================================================================
// Adds all the strings and returns their value as a string.
//============================================================================================

string Calculator:: addition_operator(string array[], int length_of_array, int maxium_size_of_number)
{
    string sum(maxium_size_of_number,'0');
    int carry = 0;
    
    for (int i = 0; i < maxium_size_of_number; i++)
    {
        int digit_by_digit_addition = carry;
        
        for (int j = 0; j < length_of_array; j++)
        {
            digit_by_digit_addition += (array[j][maxium_size_of_number - (i + 1)]) - 48;
        }
        
        carry = digit_by_digit_addition/10;
        sum[maxium_size_of_number - (i + 1)] = (digit_by_digit_addition % 10) + '0';
    }
    
    if (carry > 0)
    {
        sum = remaining_carry(sum, carry);
    }
    
    sum = Standardize_Number(sum, false);
    return sum;
}


//============================================================================================
// Formats the string to appear as a number suitable for human eyes.
// This is done by getting rid of trailing zeros and adding commas.
//============================================================================================

string Calculator:: Standardize_Number(string sum, bool allow_zeros)
{
    int orginal_length = sum.length();
    
    while (sum[0] == '0')
    {
        sum.erase(0,1);
    }
    
    for (int i = 3; i < sum.length(); i += 4)
    {
        sum.insert(sum.length() - i, 1, ',');
    }
    
    if (sum == "")
    {
        sum = string(orginal_length, '0');
    }
    return sum;
}

//============================================================================================
// Print multiplication design
//============================================================================================

void Calculator:: print_multiplication(Number *array, int length_of_array, string product)
{
    Standardize_Intermediate_Steps();
    int longest_number = get_longest_number_length(intermediate_numbers, MAXIMUM_INTERMEDIATE_STEPS);
    string preliminary_spaces = "   ";
    string lines(longest_number + 2, '-');
    
    cout << "\nThe product of:  \n \n";
    
    for (int i = 0; i < length_of_array; i++)
    {
        string multiple = Standardize_Number(array[i].raw_number, false);
        string spaces = generate_spacing(longest_number - 3, multiple.length());
        
        if (i == length_of_array - 1)
        {
            cout  << "x> " << spaces << multiple << "\n";
            cout << lines << "\n";
        }
        
        else
        {
            cout << preliminary_spaces << spaces << multiple << "\n";
        }
    }
    
    for (int i = 0; i < MAXIMUM_INTERMEDIATE_STEPS; i++)
    {
        string spaces = generate_spacing(longest_number, intermediate_numbers[i].length());
        cout << spaces << intermediate_numbers[i] << "\n";
    }
    cout << lines << "\n";
    cout << generate_spacing(longest_number, int(product.length())) << product << "\n";
}

void Calculator:: Standardize_Intermediate_Steps()
{
    for (int i = 0; i < MAXIMUM_INTERMEDIATE_STEPS; i++)
    {
        intermediate_numbers[i] = Standardize_Number(intermediate_numbers[i], true);
    }
}
//============================================================================================
// Adds remaining carry to a String of digits.
//============================================================================================

string Calculator:: remaining_carry(string string_of_digits, int carry)
{
    string_of_digits = "00000" + string_of_digits;
    int counter = 0;
    while (string_of_digits[counter] != 0)
    {
        counter++;
    }
    int digit_by_digit_addition;
    int second_carry = 0;
    
    while (carry > 0 || second_carry > 0)
    {
        digit_by_digit_addition = string_of_digits[counter] - 48;
        digit_by_digit_addition += carry + second_carry;
        second_carry = digit_by_digit_addition/10;
        string_of_digits[counter] =(digit_by_digit_addition % 10) + '0';
        carry /= 10;
        counter -= 1;
    }
    
    return string_of_digits;
}

//============================================================================================
// Multiplies an array of two digits and returns their final product as a string.
//============================================================================================


string Calculator:: two_digit_multiplication_operator(Number *array, int length_of_array, int maxium_size_of_number)
{
    string product(maxium_size_of_number,'0');
    string final_product(maxium_size_of_number,'0');
    Number number_on_top = array[0];
    Number number_on_bottom = array[length_of_array - 1];
    int trailing_zeros = (maxium_size_of_number * 2) - 1;
    int digit_by_digit_multiplication = 0;
    int carry = 0;
    
    for (int i = 0; i < maxium_size_of_number; i++)
    {
        product = product + string(i,'0');
        
        for (int j = 0; j < maxium_size_of_number; j++)
        {
            digit_by_digit_multiplication =  ((number_on_top.digits_array[maxium_size_of_number - (j + 1)]  - 48) * (number_on_bottom.digits_array[maxium_size_of_number - (i + 1)] - 48));
            digit_by_digit_multiplication += carry;
            carry = digit_by_digit_multiplication/10;
            product[maxium_size_of_number - (j + 1)] = (digit_by_digit_multiplication % 10) + '0';
        }
        
        product = string(trailing_zeros - product.length(), '0') + product;
        if (carry > 0)
        {
            product = remaining_carry(product, carry);
            
        }
        intermediate_numbers[i] = product;
        product = string(maxium_size_of_number,'0');
        carry = 0;
    }
    
    cout << endl;
    
    maxium_size_of_number = (maxium_size_of_number * 2) - 1;
    
    if (array[0].digits_array[0] == '9' || array[1].digits_array[0] == '9' )
    {
        maxium_size_of_number = 34;
    }
    
    final_product = addition_operator(intermediate_numbers, MAXIMUM_INTERMEDIATE_STEPS, maxium_size_of_number);
    return final_product;
}
