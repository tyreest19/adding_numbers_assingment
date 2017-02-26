//
//  Calculator.hpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Calculator_hpp
#define Calculator_hpp

#include <stdio.h>
#include "Number.hpp"

class Calculator
{
    
public:
    
    void print_addition(Number array[], int length_of_array, string sum);
    string addition_operator(Number array[], int length_of_array, int maxium_size_of_number);
    string addition_operator(string array[], int length_of_array, int maxium_size_of_number);
    void print_multiplication(Number array[], int length_of_array, string sum);
    string multiplication_operator(Number array[], int length_of_array, const int maxium_size_of_number);
    string two_digit_multiplication_operator(Number array[], int length_of_array, const int maxium_size_of_number);
    
protected:
    
    string Standardize_Number(string sum);
    string remaining_carry(string string_of_digits, int carry);
    void add_padding(string numbers[], int length_of_array,int longest_number);
private:
    
    string generate_spacing(int length_of_largest_number, int length_of_array);
    
};

#endif /* Calculator_hpp */
