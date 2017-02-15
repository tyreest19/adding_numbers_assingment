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
// Print addition design
//============================================================================================

void Calculator:: print_addition(Number *array, int length_of_array)
{
    
}

//============================================================================================
// Adds all the Numbers and returns their value as a long long int.
//============================================================================================

long long int Calculator:: addition_operator(Number *array, int length_of_array)
{
    long long int sum = 0;
    
    for (int i = 0; i < length_of_array; i++)
    {
        sum += array[i].get_numeric_representation_of_number();
    }
    
    return sum;
}
