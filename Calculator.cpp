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

string Calculator:: Generate_Spacing(int length_of_largest_number, int length_of_current_number)
{
    string blank_space((length_of_largest_number + 2) - length_of_current_number, ' ');
    return blank_space;
}

//============================================================================================
// Print addition design
//============================================================================================

void Calculator:: Print_Addition(Number array[], int length_of_array, string sum)
{
    int longest_number = Get_Longest_Number_Length(array, length_of_array);
    string preliminary_spaces = "   ";
    string lines((longest_number + 6) - 1, '-');
    
    cout << "The sum of:  \n \n";
    
    for (int i = 0; i < length_of_array; i++)
    {
        string addends = Standardize_Number(array[i].raw_number, false);
        int length_of_current_number = addends.length();
        string spaces = Generate_Spacing(longest_number, length_of_current_number);

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
    cout << Generate_Spacing(longest_number, int(sum.length())) << "   " << sum << "\n";
}

//============================================================================================
// Adds all the Numbers and returns their value as a long long int.
//============================================================================================

string Calculator:: Addition_Operator(Number *array, int length_of_array, int maxium_size_of_number)
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
        sum = Remaining_Carry(sum, carry);
    }
    
    sum = Standardize_Number(sum, false);
    return sum;
}

//============================================================================================
// Adds all the strings and returns their value as a string.
//============================================================================================

string Calculator:: Addition_Operator(string array[], int length_of_array, int maxium_size_of_number)
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
        sum = Remaining_Carry(sum, carry);
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
    
    while (sum[0] == '0' && allow_zeros == false)
    {
        sum.erase(0,1);
    }
    
    if (sum == "")
    {
        sum = string(orginal_length, '0');
    }
    else
    {
        for (int i = 3; i < sum.length(); i += 4)
        {
            sum.insert(sum.length() - i, 1, ',');
        }
    }
    
    return sum;
}

//============================================================================================
// Print multiplication design
//============================================================================================

void Calculator:: Print_Multiplication(Number *array, int length_of_array, string product)
{
    Standardize_Intermediate_Steps();
    int longest_number = Get_Longest_Number_Length(intermediate_numbers, MAXIMUM_INTERMEDIATE_STEPS);
    string preliminary_spaces = "   ";
    string lines(longest_number + 2, '-');
    Number temp;
    
    if (array[0].raw_number.length() < array[1].raw_number.length())
    {
        temp = array[0];
        array[0] = array[1];
        array[1] = temp;
    }
    cout << "\nThe product of:  \n \n";
    
    for (int i = 0; i < length_of_array; i++)
    {
        string multiple = Standardize_Number(array[i].raw_number, false);
        string spaces = Generate_Spacing(longest_number - 3, multiple.length());
        
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
    
    for (int i = 0; i < array[1].raw_number.length(); i++)
    {
        if (i == 0 && intermediate_numbers[i][0] == '0')
        {
            string orginal_value = array[1].raw_number;
            intermediate_numbers[i] = string(array[0].raw_number.length(), '0');
            intermediate_numbers[i] = Standardize_Number(intermediate_numbers[i], true);
            string spaces = Generate_Spacing(longest_number, intermediate_numbers[i].length());
            cout << spaces << intermediate_numbers[i] << "\n";
            
            if (orginal_value == "0")
            {
                product = intermediate_numbers[i];
            }
        }
        
        else if (intermediate_numbers[i][0] == '0')
        {
            int previous_length = intermediate_numbers[i-1].length() + 1;
            intermediate_numbers[i] = string(previous_length - (previous_length/3) + 3, '0');
            intermediate_numbers[i] = Standardize_Number(intermediate_numbers[i], true);
            longest_number = Get_Longest_Number_Length(intermediate_numbers, MAXIMUM_INTERMEDIATE_STEPS);
            string spaces = Generate_Spacing(longest_number, intermediate_numbers[i].length());
            cout << spaces << intermediate_numbers[i] << "\n";
        }
        
        else
        {
            string spaces = Generate_Spacing(longest_number, intermediate_numbers[i].length());
            cout << spaces << intermediate_numbers[i] << "\n";
        }
    }
    cout << lines << "\n";
    cout << Generate_Spacing(longest_number, int(product.length())) << product << "\n";
}

void Calculator:: Standardize_Intermediate_Steps()
{
    for (int i = 0; i < MAXIMUM_INTERMEDIATE_STEPS; i++)
    {
        intermediate_numbers[i] = Standardize_Number(intermediate_numbers[i], false);
    }
}
//============================================================================================
// Adds remaining carry to a String of digits.
//============================================================================================

string Calculator:: Remaining_Carry(string string_of_digits, int carry)
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


string Calculator:: Two_Number_Multiplication_Operator(Number *array, int length_of_array, int maxium_size_of_number)
{
    string product(maxium_size_of_number,'0');
    string final_product(maxium_size_of_number,'0');
    Number number_on_top;
    Number number_on_bottom;
    
    if (array[0].raw_number.length() > array[1].raw_number.length())
    {
        number_on_top = array[0];
        number_on_bottom = array[1];
    }
    
    else
    {
        number_on_top = array[1];
        number_on_bottom = array[0];
    }
    
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
            product = Remaining_Carry(product, carry);
            
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
    
    final_product = Addition_Operator(intermediate_numbers, MAXIMUM_INTERMEDIATE_STEPS, maxium_size_of_number);
    return final_product;
}
