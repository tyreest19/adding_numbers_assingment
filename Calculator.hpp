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
    
    void Print_Addition(Number array[], int length_of_array, string sum);
    string Addition_Operator(Number array[], int length_of_array, int maxium_size_of_number);
    string Addition_Operator(string array[], int length_of_array, int maxium_size_of_number);
    void Print_Multiplication(Number array[], int length_of_array, string sum);
    string Two_Number_Multiplication_Operator(Number array[], int length_of_array, const int maxium_size_of_number);
    
protected:
    string Standardize_Number(string sum, bool allows_zero);
    string Remaining_Carry(string string_of_digits, int carry);
    void Standardize_Intermediate_Steps();
    
private:
    
    string intermediate_numbers[MAXIMUM_INTERMEDIATE_STEPS];
    string Generate_Spacing(int length_of_largest_number, int length_of_array);
    
};

#endif /* Calculator_hpp */
