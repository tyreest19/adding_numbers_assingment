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

const int MAXIMUM_INTERMEDIATE_STEPS = 15;
class Calculator
{
    
public:
    
    void print_addition(Number array[], int length_of_array, string sum);
    string addition_operator(Number array[], int length_of_array, int maxium_size_of_number);
    string addition_operator(string array[], int length_of_array, int maxium_size_of_number);
    void print_multiplication(Number array[], int length_of_array, string sum);
    string two_digit_multiplication_operator(Number array[], int length_of_array, const int maxium_size_of_number);
    
protected:
    
    string Standardize_Number(string sum, bool allow_zeros);
    string remaining_carry(string string_of_digits, int carry);
    void Standardize_Intermediate_Steps();
    
private:
    string intermediate_numbers[MAXIMUM_INTERMEDIATE_STEPS];
    string generate_spacing(int length_of_largest_number, int length_of_array);
    
};

#endif /* Calculator_hpp */
