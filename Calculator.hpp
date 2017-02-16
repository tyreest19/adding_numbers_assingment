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
    
    string generate_spacing(string array[], int length_of_array);
    void print_addition(Number array[], int length_of_array);
    string addition_operator(Number array[], int length_of_array);
    
};

#endif /* Calculator_hpp */
