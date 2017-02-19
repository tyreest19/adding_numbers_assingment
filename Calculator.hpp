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
    
    void print_addition(Number array[], int length_of_array);
    long long int addition_operator(Number array[], int length_of_array, int maxium_size_of_number);
    
private:
    
    string generate_spacing(int length_of_largest_number, int length_of_array);
    
};

#endif /* Calculator_hpp */
