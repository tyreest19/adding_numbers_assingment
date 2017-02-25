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
    
    sum = Standardize_Number(sum);
    return sum;
}

//============================================================================================
// Formats the string to appear as a number suitable for human eyes.
// This is done by getting rid of trailing zeros and adding commas.
//============================================================================================

string Calculator:: Standardize_Number(string sum)
{
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
        sum = "0";
    }
    
    return sum;
}

//============================================================================================
// Print multiplication design
//============================================================================================

void Calculator:: print_multiplication(Number *array, int length_of_array, string product)
{
    int longest_number = get_longest_number_length(array, length_of_array);
    string preliminary_spaces = "   ";
    string lines((longest_number + 6) - 1, '-');
    
    cout << "\nThe product of:  \n \n";
    
    for (int i = 0; i < length_of_array; i++)
    {
        int length_of_current_number = int(array[i].get_string_representation_of_number().length());
        string spaces = generate_spacing(longest_number, length_of_current_number);
        
        if (i == length_of_array - 1)
        {
            cout  << "x> " << spaces << array[i].get_string_representation_of_number() << "\n";
            cout << lines << "\n";
        }
        
        else
        {
            cout << preliminary_spaces << spaces << array[i].get_string_representation_of_number() << "\n";
        }
    }
    cout << generate_spacing(longest_number, int(product.length())) << "   " << product << "\n";
}

//============================================================================================
// Multplies Numbers in a number array.
//============================================================================================

string Calculator:: multiplication_operator(Number array[], int length_of_array, int maxium_size_of_number)
{
    string product(maxium_size_of_number,'0');
    string final_product(maxium_size_of_number,'0');
    int carry = 0;
    Number number_on_top = array[length_of_array - 1];
    Number number_being_multiplied = array[0];
    
    for (int i = 0; i < maxium_size_of_number; i++)
    {
        for (int j = 0; j < maxium_size_of_number; j++)
        {
            int digit_by_digit_multiplication =  ((number_on_top.digits_array[maxium_size_of_number - (j + 1)]  - 48) * (number_being_multiplied.digits_array[maxium_size_of_number - (i + 1)] - 48));
            digit_by_digit_multiplication += carry;
            cout << "digit by digit multply: " <<digit_by_digit_multiplication << endl;
            carry = digit_by_digit_multiplication/10;
            product[maxium_size_of_number - (i + 1)] = (digit_by_digit_multiplication % 10) + '0';
            cout << "product: " << product << endl;
        }
        product = " ";
        
        if (carry > 0)
        {
            product = remaining_carry(product, carry);
        }
        
    }
    
    cout << "im the carry: " << carry << endl;
    
    if (carry > 0)
    {
        product = remaining_carry(product, carry);
    }
    
    product = Standardize_Number(product);
    return product;
}

//============================================================================================
// Adds remaining carry to a String of digits.
//============================================================================================

string Calculator:: remaining_carry(string string_of_digits, int carry)
{
    string_of_digits = "00000" + string_of_digits;
    int counter = 4;
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
