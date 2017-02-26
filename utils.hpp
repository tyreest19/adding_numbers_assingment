//
//  utils.hpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/13/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include "Number.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

long long int String_To_Int(const char *str);
string Get_Number(string prompt, string invalid_input_prompt, int lenght_of_number);
int get_longest_number_length(Number array[], int size_of_array);
int get_longest_number_length(string array[], int size_of_array);
int pow(int base, int exponent);
#endif /* utils_hpp */
