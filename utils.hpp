//
//  utils.hpp
//  numbers_assigment
//
//  Created by Tyree Stevenson on 2/13/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

long long int String_To_Int(const char *str);
string Get_Number(long long int maxium_numbers, long long int minimum_numbers, string prompt, string
                  invalid_input_prompt, int lenght_of_number);

#endif /* utils_hpp */
